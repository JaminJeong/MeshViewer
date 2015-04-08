#ifndef CAMERA_H
#define CAMERA_H

#include "renderengine.h"

namespace RenderEngine {

    class Camera
    {
    public:
        Camera(
            const vec3& eye,
            const vec3& target,
            const vec3& up
        );

        Camera(const Camera& camera);

        ~Camera();

    public:
        const vec3& GetEye() const;
        const vec3& GetTarget() const;
        const vec3& GetUp() const;

    private:
        vec3 m_Eye;
        vec3 m_Target;
        vec3 m_Up;
    };

}
#endif // CAMERA_H
