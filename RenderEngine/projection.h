#ifndef PROJECTION_H
#define PROJECTION_H

#include "renderengine.h"

namespace RenderEngine {

    class PerspectiveView
    {
    public:
        PerspectiveView(
                Float angle,
                vec2 ratio,
                Float zNear,
                Float zFar
        );

        ~PerspectiveView();

    public:
        Float GetAngle() const;
        Float GetRatio() const;
        Float GetZNear() const;
        Float GetZFar() const;

    private:
        Float m_Angle;
        Float m_Ratio;
        Float m_ZNear;
        Float m_ZFar;
    };
}
#endif // PROJECTION_H
