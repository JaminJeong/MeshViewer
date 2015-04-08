#include "camera.h"

namespace RenderEngine {

    Camera::Camera(
            const vec3& eye,
            const vec3& target,
            const vec3& up
        ) :
        m_Eye(eye),
        m_Target(target),
        m_Up(up)
    {

    }

    Camera::Camera(const Camera& camera) :
        m_Eye(camera.m_Eye),
        m_Target(camera.m_Target),
        m_Up(camera.m_Up)
    {

    }

    Camera::~Camera()
    {

    }

    const vec3& Camera::GetEye() const
    {
        return m_Eye;
    }

    const vec3& Camera::GetTarget() const
    {
        return m_Target;
    }

    const vec3& Camera::GetUp() const
    {
        return m_Up;
    }


}
