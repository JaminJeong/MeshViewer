#include "render3dopenglview.h"
#include "../../Extern/glut/include/glut.h"
#include "../../TriMesh/Vec.h"

//#include "../../RenderEngine/light.h"
//#include "../../RenderEngine/camera.h"
//#include "../../RenderEngine/projection.h"
//#include "../../RenderEngine/viewport.h"

namespace Render3D{

    using RenderEngine::Camera;
    using RenderEngine::OrthogonalViewBox;
    using RenderEngine::PerspectiveView;
    using RenderEngine::Lights;
    using RenderEngine::ViewPort;

    using namespace Graphics::TriMeshSpace;

    void Render3DOpenGLView::SetLight(const Lights& /*lights*/)
	{
		GLfloat lightPos0[] = {0.0,100.0,100.0,1.0};
		GLfloat lightPos1[] = {100.0,100.0,0.0,1.0};
		float ambLight[] = {0.6f, 0.6f, 0.6f, 1.0f}; //Ambient ���� ������ �ش�. 
		float specular[] = {1.0f, 1.0f, 1.0f, 1.0f}; //Specular ���� ������ �ش�. 
		float specref[] = {1.0f, 1.0f, 1.0f, 1.0f}; //Specular �������� �����Ѵ�.

		glEnable(GL_LIGHTING); //������ ����ϵ��� �Ѵ�.

		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambLight); //����� ������ �ֺ����� �����Ѵ�.

		glLightfv(GL_LIGHT0, GL_DIFFUSE, ambLight); //Diffuse����Ambient�� ������ ������ �൵ �ǰ� �ٸ� ���� �൵ �ȴ�.
		glLightfv(GL_LIGHT0, GL_SPECULAR, specular); //Specular ����
		glLightfv(GL_LIGHT0, GL_POSITION, lightPos0); //��ġ ����

		glLightfv(GL_LIGHT1, GL_DIFFUSE, ambLight); //Diffuse����Ambient�� ������ ������ �൵ �ǰ� �ٸ� ���� �൵ �ȴ�.
		glLightfv(GL_LIGHT1, GL_SPECULAR, specular); //Specular ����
		glLightfv(GL_LIGHT1, GL_POSITION, lightPos0); //��ġ ����

		glEnable(GL_COLOR_MATERIAL); //������ ������ �޵��� �Ѵ�.

		glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE); //���� ������ ������Ʈ�� �������� �Ѵ�.

		glMaterialfv(GL_FRONT, GL_SPECULAR, specref); //Specular ����
		glMateriali(GL_FRONT, GL_SHININESS, 128);

		glEnable(GL_LIGHT0); //0�� ���� ���
		glEnable(GL_LIGHT1); //1�� ���� ���

		glShadeModel(GL_SMOOTH); //GL_FLAT�� �ָ� ���� ���δ�.
		glFrontFace(GL_CCW);
		//	glEnable(GL_CULL_FACE);
		glDisable(GL_CULL_FACE);
	}

    void Render3DOpenGLView::SetCamera(const Camera& camera)
    {
        glMatrixMode(GL_MODELVIEW);

        glLoadIdentity();

        vec3 eye = camera.GetEye();
        vec3 target = camera.GetTarget();
        vec3 up = camera.GetUp();

        gluLookAt(
            eye[0], eye[1], eye[2],
            target[0], target[1], target[2],
            up[0], up[1], up[2]
        );
}

    void Render3DOpenGLView::SetProjection(const OrthogonalViewBox& orthogonalViewBox)
    {

        // Use the projection matrix
        glMatrixMode(GL_PROJECTION);

        // Defines the perspective projection
        glLoadIdentity();

        glOrtho(
            orthogonalViewBox.min[0], orthogonalViewBox.max[0],
            orthogonalViewBox.min[1], orthogonalViewBox.max[1],
            orthogonalViewBox.min[2], orthogonalViewBox.max[2]
        );
    }

    void Render3DOpenGLView::SetProjection(const PerspectiveView& perspectiveView)
    {
        float aspectRatio = 1; // (float) width / (float) height;

        glMatrixMode(GL_PROJECTION);

        glLoadIdentity();

//        gluPerspective(45, aspectRatio, 1, 100);
        gluPerspective(
               perspectiveView.GetAngle(),
               perspectiveView.GetRatio(),
               perspectiveView.GetZNear(),
               perspectiveView.GetZFar()
        );

    }

    void Render3DOpenGLView::SetViewPort(const ViewPort& viewPort)
    {
           glViewport(
                viewPort.GetStartPoint()[0], viewPort.GetStartPoint()[1],
                viewPort.GetSize()[0], viewPort.GetSize()[1]
            );
    }
}
