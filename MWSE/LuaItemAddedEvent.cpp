#include "LuaItemAddedEvent.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3Reference.h"
#include "TES3MobileActor.h"
#include "TES3Object.h"
#include "TES3ItemData.h"
//TES3::PhysicalObject *obj, int count, bool overwrite, TES3::ItemData **dataRef
namespace mwse::lua::event
{
	ItemAddedEvent::ItemAddedEvent(TES3::MobileActor *actor, TES3::PhysicalObject *obj, int count, bool overwrite, TES3::ItemData **dataRef):
		ObjectFilteredEvent("itemAdded", actor->reference->baseObject),
		m_actor(actor),
		m_item(obj),
		m_count(count),
		m_overwrite(overwrite),
		m_itemData(dataRef ? *dataRef : nullptr)
	{

	}

	sol::table ItemAddedEvent::createEventTable() {
		const auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		auto &state = stateHandle.getState();
		auto eventData = state.create_table();

		eventData["mobile"] = m_actor;
		eventData["item"] = m_item;
		eventData["itemData"] = m_itemData;
		eventData["count"] = m_count;
		eventData["overwrite"] = m_overwrite;

		return eventData;
	}
}
