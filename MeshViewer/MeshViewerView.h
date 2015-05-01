
// MeshViewerView.h : interface of the CMeshViewerView class
//

#pragma once

#include <glut.h>
#include <memory>
#include <string>
#include <bitset>
#include "../TriMesh/TriMesh.h"

using std::auto_ptr;
using std::bitset;
using std::string;
using Graphics::TriMeshSpace::TriMesh;

#pragma comment( lib, "opengl32.lib" )       // Search For OpenGL32.lib While Linking
#pragma comment( lib, "glu32.lib" )        // Search For GLu32.lib While Linking


class CMeshViewerView : public CView
{
protected: // create from serialization only
	CMeshViewerView();
	DECLARE_DYNCREATE(CMeshViewerView)

// Attributes
public:
	CMeshViewerDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CMeshViewerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

public:
	float	 m_fLastX;
	float	 m_fLastY;
	float	 m_fPosX;
	float	 m_fPosY;
	float	 m_fZoom;
	float	 m_fRotX;
	float	 m_fRotY;

	float m_cx;
	float m_cy;

	auto_ptr<TriMesh> triMesh;
	bitset<256> m_OnCharNum;
	TriMesh::BBox m_SimulationBox;

public:
	CDC *m_pDC;                                   //device context
	HGLRC m_hRC;                                  //rendering context

	BOOL SetupPixelFormat(PIXELFORMATDESCRIPTOR* pPFD);
	void DrawScene(void);
	void Draw_With_OpenGL(void);
	void SetSimulationSpace(const TriMesh& mesh, const TriMesh::BBox& box);

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // debug version in MeshViewerView.cpp
inline CMeshViewerDoc* CMeshViewerView::GetDocument() const
   { return reinterpret_cast<CMeshViewerDoc*>(m_pDocument); }
#endif

