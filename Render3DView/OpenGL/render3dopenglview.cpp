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
		float ambLight[] = {0.6f, 0.6f, 0.6f, 1.0f}; //Ambient 값을 설정해 준다. 
		float specular[] = {1.0f, 1.0f, 1.0f, 1.0f}; //Specular 값을 설정해 준다. 
		float specref[] = {1.0f, 1.0f, 1.0f, 1.0f}; //Specular 재질값을 설정한다.

		glEnable(GL_LIGHTING); //조명을 사용하도록 한다.

		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambLight); //저장된 값으로 주변광을 설정한다.

		glLightfv(GL_LIGHT0, GL_DIFFUSE, ambLight); //Diffuse설정Ambient와 동일한 값으로 줘도 되고 다른 값을 줘도 된다.
		glLightfv(GL_LIGHT0, GL_SPECULAR, specular); //Specular 설정
		glLightfv(GL_LIGHT0, GL_POSITION, lightPos0); //위치 설정

		glLightfv(GL_LIGHT1, GL_DIFFUSE, ambLight); //Diffuse설정Ambient와 동일한 값으로 줘도 되고 다른 값을 줘도 된다.
		glLightfv(GL_LIGHT1, GL_SPECULAR, specular); //Specular 설정
		glLightfv(GL_LIGHT1, GL_POSITION, lightPos0); //위치 설정

		glEnable(GL_COLOR_MATERIAL); //재질에 영향을 받도록 한다.

		glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE); //재질 색상을 오브젝트의 색상으로 한다.

		glMaterialfv(GL_FRONT, GL_SPECULAR, specref); //Specular 설정
		glMateriali(GL_FRONT, GL_SHININESS, 128);

		glEnable(GL_LIGHT0); //0번 조명 사용
		glEnable(GL_LIGHT1); //1번 조명 사용

		glShadeModel(GL_SMOOTH); //GL_FLAT을 주면 각져 보인다.
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
