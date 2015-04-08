#include "render3dview.h"

namespace Render3D{

    Render3DView::Render3DView(
        const OrthogonalViewBox& orthogonalViewBox,
        const PerspectiveView& perspectiveView,
        const Camera& camera,
        const Lights& lights,
        const ViewPort& viewPort
    ) :
    m_OrthogonalViewBox(orthogonalViewBox),
    m_PerspectiveView(perspectiveView),
    m_Camera(camera),
    m_Lights(/*lights*/),
    m_ViewPort(viewPort)
    {
    }

    Render3DView::~Render3DView()
    {
    }

    void Render3DView::SetProjection(const OrthogonalViewBox& orthogonalViewBox)
    {
        m_OrthogonalViewBox = orthogonalViewBox;
    }

    void Render3DView::SetProjection(const PerspectiveView& perspectiveView)
    {
        m_PerspectiveView = perspectiveView;
    }

    void Render3DView::SetLight(const Lights& lights)
    {
        m_Lights = lights;
    }

    void Render3DView::SetCamera(const Camera& camera)
    {
        m_Camera = camera;
    }

    void Render3DView::SetViewPort(const ViewPort& viewPort)
    {
        m_ViewPort = viewPort;
    }

    const Lights& Render3DView::GetLight()
    {
        return m_Lights;
    }

    const Camera& Render3DView::GetCamera()
    {
        return m_Camera;
    }

    const OrthogonalViewBox& Render3DView::GetOrthogonalProjection()
    {
        return m_OrthogonalViewBox;
    }

    const PerspectiveView& Render3DView::SetPerpectiveProjection()
    {
        return m_PerspectiveView;
    }

    const ViewPort& Render3DView::GetViewPort()
    {
        return m_ViewPort;
    }
}
