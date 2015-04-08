
// MeshViewerView.cpp : implementation of the CMeshViewerView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MeshViewer.h"
#endif

#include "MeshViewerDoc.h"
#include "MeshViewerView.h"

#include "../Render3DView/OpenGL/render3dopenglview.h"

#include "../OpenGLUtil/TriMeshOpenGLUtil.h"

using namespace RenderEngine;
using namespace Render3D;
using namespace Graphics::OpenGL; 

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMeshViewerView

IMPLEMENT_DYNCREATE(CMeshViewerView, CView)

BEGIN_MESSAGE_MAP(CMeshViewerView, CView)
	ON_WM_CHAR()
	ON_WM_CREATE()
	ON_WM_MOUSEMOVE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CMeshViewerView construction/destruction

CMeshViewerView::CMeshViewerView()
{
	// TODO: add construction code here

}

CMeshViewerView::~CMeshViewerView()
{
}

BOOL CMeshViewerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMeshViewerView drawing

void CMeshViewerView::OnDraw(CDC* /*pDC*/)
{
	CMeshViewerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	glTranslatef(m_fPosX, m_fPosY, 0.0f);
	glScalef(m_fZoom,m_fZoom,m_fZoom);
	
	glTranslatef(m_SimulationBox.center()[0], 
		m_SimulationBox.center()[1], 
		m_SimulationBox.center()[2]);

	glRotatef(m_fRotX, 1.0f, 0.0f, 0.0f);
	glRotatef(m_fRotY, 0.0f, 1.0f, 0.0f);

	glTranslatef(-m_SimulationBox.center()[0], 
		-m_SimulationBox.center()[1], 
		-m_SimulationBox.center()[2]);


	Draw_With_OpenGL();

	Invalidate(false);
}


void CMeshViewerView::Draw_With_OpenGL(void)
{
	// 깊이 설정
	glEnable(GL_DEPTH_TEST);

	// 컬러버퍼와 깊이버퍼를 초기화
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Turn on depth testing
	glDepthFunc(GL_LEQUAL);

	// rendering code
	DrawScene();	
}	

// COpenGL_MFC_VeiwerView diagnostics


BOOL CMeshViewerView::SetupPixelFormat(PIXELFORMATDESCRIPTOR* pPFD)
{
	PIXELFORMATDESCRIPTOR pfd = {
		sizeof( PIXELFORMATDESCRIPTOR ),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		32,
		0, 0, 0, 0, 0, 0,
		0, 0, 0, 
		0, 0, 0, 0, 
		16,
		0, 0, 
		PFD_MAIN_PLANE,
		0, 0, 0, 0 };

		int pixelformat;

		//PIXELFORMATDESCRIPTOR* pPFDtoUse;

		//pPFDtoUse = (0 == pPFD)? &pfd : pPFD;

		if ( 0 == ( pixelformat = ::ChoosePixelFormat( m_pDC->GetSafeHdc(), &pfd ) ) ) 
		{
			::AfxMessageBox(_TEXT( "ChoosePixelFormat failed" ), MB_OK ,0);
			return FALSE;
		}

		if ( FALSE == ::SetPixelFormat( m_pDC->GetSafeHdc(), pixelformat, &pfd ) ) 
		{
			::AfxMessageBox(_TEXT( "SetPixelFormat failed" ), MB_OK ,0);
			return FALSE;
		}

		return TRUE;
}


void CMeshViewerView::DrawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT); 
	//glutSolidTorus(5.0, 10.0, 600, 600);
	//glutSolidSphere(100.0, 10, 10);
	//glutWireSphere(100.0, 10, 10);

	//glPointSize(2.0);
	//glColor3f(view_color[0],view_color[1],view_color[2]);

	if(m_OnCharNum[1]) {
		TriMeshOpenGLUtil::DisplayMesh(*(triMesh.get()));
	}
	if(m_OnCharNum[2]) {
		TriMeshOpenGLUtil::DisplayPoint(*(triMesh.get()));
	}
	if(m_OnCharNum[3]) {
		TriMeshOpenGLUtil::DisplayWireMesh(*(triMesh.get()));
	}
	if(m_OnCharNum[4]) {
		glutWireSphere(triMesh->bsphere.r, 10, 10);
	}
	if(m_OnCharNum[5]) {
		glutWireCube(len(triMesh->bbox.size()));
	}

	SwapBuffers(wglGetCurrentDC()); 
}

void CMeshViewerView::SetSimulationSpace(const TriMesh& mesh, const TriMesh::BBox& box)
{
	glMatrixMode(GL_MODELVIEW);

	// 경계박스에 맞춰서 물체 이동
	point boxCenter = (box.min + box.max);
	boxCenter /= 2.F ;

	point meshCenter = (mesh.bbox.min + mesh.bbox.max);
	meshCenter /= 2.F ;

	glTranslatef(meshCenter[0], meshCenter[1], meshCenter[2]);

	float box_dist = dist(box.max, box.min);
	float mesh_dist = dist(mesh.bbox.max, mesh.bbox.min);

	// 경계박스에 맞춰서 물체 크기 조정
	float scaleFactor = (box_dist / mesh_dist);
	glScalef(scaleFactor, scaleFactor, scaleFactor);
}

// CMeshViewerView diagnostics

#ifdef _DEBUG
void CMeshViewerView::AssertValid() const
{
	CView::AssertValid();
}

void CMeshViewerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMeshViewerDoc* CMeshViewerView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMeshViewerDoc)));
	return (CMeshViewerDoc*)m_pDocument;
}
#endif //_DEBUG


// CMeshViewerView message handlers


void CMeshViewerView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	

	switch(nChar)
	{
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case '0':
		m_OnCharNum[nChar - '0'] = !m_OnCharNum[nChar - '0'];
		break;
	}

	CView::OnChar(nChar, nRepCnt, nFlags);
}

int CMeshViewerView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	
	m_pDC = new CClientDC(this);	// get device context
	if( m_pDC == NULL )
	{
		::AfxMessageBox(_TEXT( "fail to get device context" ), MB_OK ,0);
		return FALSE;
	}

	if( !SetupPixelFormat(NULL) )	// setup pixel format
	{
		::AfxMessageBox(_TEXT( "SetupPixelFormat failed" ), MB_OK ,0);
		return FALSE;
	}

	// get rendering context
	if( ( m_hRC = wglCreateContext(m_pDC->GetSafeHdc()) ) == 0 )
	{
		::AfxMessageBox(_TEXT( "wglCreateContext failed" ), MB_OK ,0);
		return FALSE;
	}

	// make current rendering context
	if( wglMakeCurrent(m_pDC->GetSafeHdc(), m_hRC) == FALSE )
	{
		::AfxMessageBox(_TEXT( "wglMakeCurrent failed" ), MB_OK ,0);
		return FALSE;
	}

	m_cx = lpCreateStruct->cx;
	m_cy = lpCreateStruct->cy;

	triMesh = auto_ptr<TriMesh>(TriMesh::read("../Data/bunny.obj"));
	triMesh->need_bbox();
	triMesh->need_bsphere();
	triMesh->need_normals();

	Render3DOpenGLView::SetLight(Lights());

	m_SimulationBox.max = point(10.F, 10.F, 10.F);
	m_SimulationBox.min = point(-10.F, -10.F, -10.F);

	SetSimulationSpace(*(triMesh.get()), triMesh->bbox);

	m_fZoom = 1.F;
	m_fPosX = 0.F;
	m_fPosY = 0.F;

	return 0;
}




void CMeshViewerView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	
	int diffX = (int)(point.x - m_fLastX);
	int diffY = (int)(point.y - m_fLastY);
	m_fLastX  = (float)point.x;
	m_fLastY  = (float)point.y;

	// Left mouse button
	if (nFlags & MK_LBUTTON)
	{
		m_fRotX += (float)2.0f * diffY;

		if ((m_fRotX > 360.0f) || (m_fRotX < -360.0f))
		{
			m_fRotX = 0.0f;
		}

		m_fRotY += (float)0.5f * diffX;

		if ((m_fRotY > 360.0f) || (m_fRotY < -360.0f))
		{
			m_fRotY = 0.0f;
		}
	}

	// Right mouse button
	else if (nFlags & MK_RBUTTON)
	{
		m_fZoom -= (float)0.05f * diffY;
	}

	// Middle mouse button
	else if (nFlags & MK_MBUTTON)
	{
		m_fPosX += (float)0.05f * diffX;
		m_fPosY -= (float)0.05f * diffY;
	}

	OnDraw(NULL);
	CView::OnMouseMove(nFlags, point);
}


void CMeshViewerView::OnDestroy()
{
	CView::OnDestroy();

	if( wglMakeCurrent(0,0) == FALSE)
		::AfxMessageBox(_TEXT("wglMakeCurrent failed"), MB_OK ,0);

	if( m_hRC && (wglDeleteContext(m_hRC) == FALSE ))
		::AfxMessageBox(_TEXT("wglDeleteContext failed"), MB_OK ,0);

	if( m_pDC )
		delete m_pDC;
}



void CMeshViewerView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	
	if (0 >= cx || 0 >= cy || nType == SIZE_MINIMIZED) return;

	// Model view
	glMatrixMode(GL_MODELVIEW);
	
	Render3DOpenGLView::SetCamera(
		Camera(
			point(0.F, 10.F, 0.F),
			point(0.F, 0.F, 0.F),
			point(0.F, 1.F, 0.F)
			)
		);

	Render3DOpenGLView::SetProjection(m_SimulationBox);

	Render3DOpenGLView::SetViewPort(ViewPort(vec2(0, 0), vec2(cx, cy)));

	// Model view
	glMatrixMode(GL_MODELVIEW);
}
