#include "Actor.h"

#include "../Graphics/Renderable.h"

#include "../Utilities/Logger/Log.h"

namespace liman {

	Actor::Actor()
	{

	}

	Actor::~Actor()
	{
		this->Destroy();
	}

	bool Actor::Init(std::string source)
	{
		m_sourceName = source;
		
		return true;
	}

	void Actor::Destroy()
	{
		m_components.clear();
	}

	void Actor::AddComponent(ActorComponent* pComponent)
	{
		std::pair<ComponentsMap::iterator, bool> success = m_components.insert(std::make_pair(pComponent->GetId(), pComponent));
		assert(success.second);
	}

	std::string Actor::ToXML()
	{
		tinyxml2::XMLDocument* outDoc = new tinyxml2::XMLDocument();
		tinyxml2::XMLElement* pActorNode = outDoc->NewElement("Actor");
		pActorNode->SetAttribute("resource", m_sourceName.c_str());
		tinyxml2::XMLElement* pCompNode = outDoc->NewElement("Components");
		for (auto it = m_components.begin(); it != m_components.end(); ++it)
		{
			ActorComponent* pComponent = it->second;
			tinyxml2::XMLElement* pComponentElement = pComponent->GenerateXML(outDoc);
			pCompNode->LinkEndChild(pComponentElement);
		}
		pActorNode->InsertEndChild(pCompNode);
		outDoc->InsertFirstChild(pActorNode);

		tinyxml2::XMLPrinter printer;
		outDoc->Accept(&printer);
		return printer.CStr();
	}

}