/**
 * @brief Factory for components creation
 * @file ComponentFactory.h
 * @author matthewpoletin
 */

#pragma once

#include <map>

#include "ActorComponent.h"

namespace liman {

	typedef ActorComponent* (* ComponentCreationFunction)();

	template<class BaseClass, class SubClass>
	BaseClass* GenericObjectCreationFunction() { return new SubClass; }

	typedef std::map<ComponentId, ComponentCreationFunction> ComponentCreationMap;

	class ComponentFactory {
	public:
		ComponentFactory() = default;

		virtual ~ComponentFactory() = default;

		template<class ComponentType>
		bool RegisterComponent(ComponentId id) {
			auto findIt = m_creationFunctions.find(id);
			if (findIt == m_creationFunctions.end()) {
				ComponentCreationFunction pFunc = GenericObjectCreationFunction<ActorComponent, ComponentType>;
				m_creationFunctions.insert(std::make_pair(id, pFunc));
				return true;
			}
			return false;
		}

		ActorComponent* CreateComponent(ComponentId id) {
			auto findIt = m_creationFunctions.find(id);
			if (findIt != m_creationFunctions.end()) {
				ComponentCreationFunction pFunc = findIt->second;
				return pFunc();
			}
			return nullptr;
		}

	private:
		ComponentCreationMap m_creationFunctions;

	};

}