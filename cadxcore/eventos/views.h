/*
 * This file is part of Ginkgo CADx
 *
 * Copyright (c) 2015-2016 Gert Wollny
 * Copyright (c) 2008-2014 MetaEmotion S.L. All rights reserved.
 *
 * Ginkgo CADx is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser Public License
 * along with Ginkgo CADx; if not, see <http://www.gnu.org/licenses/>.
 *
 */

#pragma once

#include <api/ievento.h>
#include "eventosginkgo.h"

namespace GNC
{
namespace GCS
{
class IVista;
namespace Events
{

class EXTAPI EventView : public GNC::GCS::Events::IEvent
{

public:
        typedef enum {
                Creation,
                Initialized,
                Destruction
        } EventViewType;

        EventView(GNC::GCS::IVista* pView = NULL, EventViewType type = Creation) : GNC::GCS::Events::IEvent(ginkgoEVT_Core_Views, 0, 100, NULL)
        {
                m_Nombre = "EventView";
                m_pView = pView;
                m_type = type;
        }

        ~EventView()
        {
        }

        EventViewType GetType()
        {
                return m_type;
        }

        GNC::GCS::IVista* GetView()
        {
                return m_pView;
        }

        virtual void pushInfo(std::ostream& /*out*/) const
        {
        }

private:
        GNC::GCS::IVista* m_pView;
        EventViewType m_type;

};
}
}
}
