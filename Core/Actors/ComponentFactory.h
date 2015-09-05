#pragma once

#include "ActorComponent.h"

namespace liman {

	typedef ActorComponent* (*ComponentCreationFunction(void));

	template <class ActorComponent, class ComponentType>
	ActorComponent* GenericObjectCreationFunction(void) { return new ComponentType; }
	
	typedef std::map<ComponentId, ComponentCreationFunction> ComponentMap;

	class ComponentFactory
	{
	public:
		ComponentFactory();
		~ComponentFactory();

		template <class ActorComponent, class ComponentId>
		bool RegisterComponent(ComponentId id)
		{
			auto findIt = m_creationFunctions.find(id);
			if (findIt == m_creationFunctions.end())
			{
				m_creationFunctions[id] = &GenericObjectCreationFunction<ActorComponent, ComponentType>;
				return true;
			}
			return false;
		}

		template <class ActorComponent, class ComponentId>
		ActorComponent* CreateComponent(ComponentId id)
		{
			auto findIt = m_creationFunctions.find(id);
			if (findIt != m_creationFunctions.end())
			{
				ComponentCreationFunction pFunc = findIt->second;
				return pFunc();
			}

			return nullptr;
		}

	private:
		ComponentsMap m_creationFunctions;

	};

}