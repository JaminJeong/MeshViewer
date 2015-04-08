#ifndef VIEWPORT_H
#define VIEWPORT_H

#include "renderengine.h"

namespace RenderEngine {

    class ViewPort
    {
    public:
        ViewPort(const vec2& startPoint, const vec2& size);
        // default constructer
        // ViewPort(const ViewPort& viewPort);
        ~ViewPort();

    public:
        const vec2& GetStartPoint() const;
        const vec2& GetSize() const;

    private:
        vec2 m_StartPoint;
        vec2 m_Size;
    };

}
#endif // VIEWPORT_H
