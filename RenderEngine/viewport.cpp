#include "viewport.h"

namespace RenderEngine{

    ViewPort::ViewPort(const vec2& startPoint, const vec2& size) :
        m_StartPoint(startPoint),
        m_Size(size)
    {

    }


//    ViewPort::ViewPort(const ViewPort& viewPort)
//    {
//    }

    ViewPort::~ViewPort()
    {

    }

    const vec2& ViewPort::GetStartPoint() const
    {
        return m_StartPoint;
    }

    const vec2& ViewPort::GetSize() const
    {
        return m_Size;
    }

}
