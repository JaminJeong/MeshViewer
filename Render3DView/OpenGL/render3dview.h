#ifndef RENDER3DVIEW_H
#define RENDER3DVIEW_H

#include "../../RenderEngine/UnCopyable.h"
#include "../../RenderEngine/light.h"
#include "../../RenderEngine/camera.h"
#include "../../RenderEngine/projection.h"
#include "../../RenderEngine/viewport.h"

namespace Render3D{

    using RenderEngine::OrthogonalViewBox;
    using RenderEngine::PerspectiveView;
    using RenderEngine::Lights;
    using RenderEngine::Camera;
    using RenderEngine::ViewPort;

    class Render3DView// : private UnCopyable
    {
    public:
        Render3DView(
            const OrthogonalViewBox& orthogonalViewBox,
            const PerspectiveView& perspectiveView,
            const Camera& camera,
            const Lights& lights,
            const ViewPort& viewPort
        );

        virtual ~Render3DView();

    protected:
        OrthogonalViewBox m_OrthogonalViewBox;
        PerspectiveView m_PerspectiveView;
        Camera m_Camera;
        Lights m_Lights;
        ViewPort m_ViewPort;

    public:
        void SetProjection(const OrthogonalViewBox& orthogonalViewBox);
        void SetProjection(const PerspectiveView& perspectiveView);
        void SetLight(const Lights& lights);
//        setMatrial();
        void SetCamera(const Camera& camera);
        void SetViewPort(const ViewPort& viewPort);

    public:
        const Lights& GetLight();
        const Camera& GetCamera();
        const OrthogonalViewBox& GetOrthogonalProjection();
        const PerspectiveView& SetPerpectiveProjection();
        const ViewPort& GetViewPort();
    };

}
#endif // RENDER3DVIEW_H
