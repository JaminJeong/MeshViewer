#ifndef RENDER3DOPENGLVIEW_H
#define RENDER3DOPENGLVIEW_H

#include "../../RenderEngine/renderengine.h"

#include "../../RenderEngine/light.h"
#include "../../RenderEngine/camera.h"
#include "../../RenderEngine/projection.h"
#include "../../RenderEngine/viewport.h"

//namespace RenderEngine{
//    class Lights;
//    class Camera;
//    class PerspectiveView;
//    class ViewPort;
//}

namespace Render3D{

    using RenderEngine::Float;

    using RenderEngine::Camera;
    using RenderEngine::OrthogonalViewBox;
    using RenderEngine::PerspectiveView;
    using RenderEngine::Lights;
    using RenderEngine::ViewPort;

    class Render3DOpenGLView
    {
    public:
        static void SetLight(const Lights& lights);
        static void SetCamera(const Camera& camera);
        static void SetProjection(const OrthogonalViewBox& orthogonalViewBox);
        static void SetProjection(const PerspectiveView& perspectiveView);
        static void SetViewPort(const ViewPort& viewPort);
    };

}
#endif // RENDER3DOPENGLVIEW_H
