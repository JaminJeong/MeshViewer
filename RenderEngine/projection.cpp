#include "projection.h"

namespace RenderEngine {
    PerspectiveView::PerspectiveView(
            Float angle,
            vec2 ratio,
            Float zNear,
            Float zFar
    ) :
        m_Angle(angle),
        m_Ratio(static_cast<Float>(ratio[0] / ratio[1])),
        m_ZNear(zNear),
        m_ZFar(zFar)
    {
    }

    PerspectiveView::~PerspectiveView()
    {
    }

    Float PerspectiveView::GetAngle() const
    {
        return m_Angle;
    }

    Float PerspectiveView::GetRatio() const
    {
        return m_Ratio;
    }

    Float PerspectiveView::GetZNear() const
    {
        return m_ZNear;
    }

    Float PerspectiveView::GetZFar() const
    {
        return m_ZFar;
    }

}
