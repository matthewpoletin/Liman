#pragma once

#include "ActorComponent.h"

namespace liman {

	typedef ActorComponent* (*ComponentCreationFunction)(void);

	template <class BaseClass, class SubClass>
	BaseClass* GenericObjectCreationFunction(void) { return new SubClass; }
	
	typedef std::map<ComponentId, ComponentCreationFunction> ComponentCreationMap;

	class ComponentFactory
	{
	public:
		ComponentFactory() {}
		virtual ~ComponentFactory() {}

		template <class ComponentType>
		bool RegisterComponent(ComponentId id)
		{
			auto findIt = m_creationFunctions.find(id);
			if (findIt == m_creationFunctions.end())
			{
				ComponentCreationFunction pFunc = GenericObjectCreationFunction<ActorComponent, ComponentType>;
				m_creationFunctions.insert(std::make_pair(id, pFunc));

				//m_creationFunctions[id] = &pFunc;
				return true;
			}
			return false;
		}

		//template <class ActorComponent, class ComponentId>
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
		ComponentCreationMap m_creationFunctions;

	};

}