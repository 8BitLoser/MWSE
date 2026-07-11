#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event
{
	class ItemAddedEvent : public ObjectFilteredEvent, public DisableableEvent<ItemAddedEvent> {
	public:
		ItemAddedEvent(TES3::MobileActor *actor, TES3::PhysicalObject *obj, int count, bool overwrite, TES3::ItemData **dataRef = nullptr);
		sol::table createEventTable();

	protected:
		TES3::MobileActor *m_actor;
		TES3::PhysicalObject *m_item;
		int m_count;
		bool m_overwrite;
		TES3::ItemData *m_itemData;
	};
}
