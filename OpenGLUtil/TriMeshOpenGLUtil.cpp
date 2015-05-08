#include "TriMeshOpenGLUtil.h"
#include "../Extern/glut/include/glut.h"

namespace Graphics{ namespace OpenGL{ 

	const float PI = 3.14f;

	void TriMeshOpenGLUtil::DrawLine(const point& start, const point& end, const Color& color)
	{
		glColor3f(color[0], color[1], color[2]);
		//glLineWidth(1.F);
		glBegin(GL_LINES);
		glVertex3f(start[0], start[1], start[2]);
		glVertex3f(end[0], end[1], end[2]);
		glEnd();
	}

	void TriMeshOpenGLUtil::DrawPoint(const point& startPoint, const Color& color)
	{
		glColor3f(color[0], color[1], color[2]);
		glBegin(GL_POINTS);
		glVertex3f(startPoint[0], startPoint[1], startPoint[2]);
		glEnd();
	}

	void TriMeshOpenGLUtil::DisplayWireMesh(const TriMesh& mesh)
	{
		for (unsigned int count = 0; count < mesh.faces.size(); ++count) {
			glBegin(GL_LINE_LOOP);
			glVertex3f(mesh.vertices[mesh.faces[count][0]][0], 
				mesh.vertices[mesh.faces[count][0]][1], 
				mesh.vertices[mesh.faces[count][0]][2]);
			glVertex3f(mesh.vertices[mesh.faces[count][1]][0], 
				mesh.vertices[mesh.faces[count][1]][1], 
				mesh.vertices[mesh.faces[count][1]][2]);
			glVertex3f(mesh.vertices[mesh.faces[count][2]][0], 
				mesh.vertices[mesh.faces[count][2]][1], 
				mesh.vertices[mesh.faces[count][2]][2]);
			glEnd();
		}
	}


	void TriMeshOpenGLUtil::DisplayMesh(TriMesh& mesh)
	{
		mesh.need_normals();

		for (unsigned int  count = 0; count < mesh.faces.size(); ++count) {
			glBegin(GL_TRIANGLES);
			glNormal3f(mesh.normals[mesh.faces[count][0]][0], 
				mesh.normals[mesh.faces[count][0]][1], 
				mesh.normals[mesh.faces[count][0]][2]);
			glVertex3f(mesh.vertices[mesh.faces[count][0]][0], 
				mesh.vertices[mesh.faces[count][0]][1], 
				mesh.vertices[mesh.faces[count][0]][2]);
			glNormal3f(mesh.normals[mesh.faces[count][1]][0], 
				mesh.normals[mesh.faces[count][1]][1], 
				mesh.normals[mesh.faces[count][1]][2]);
			glVertex3f(mesh.vertices[mesh.faces[count][1]][0], 
				mesh.vertices[mesh.faces[count][1]][1], 
				mesh.vertices[mesh.faces[count][1]][2]);
			glNormal3f(mesh.normals[mesh.faces[count][2]][0], 
				mesh.normals[mesh.faces[count][2]][1], 
				mesh.normals[mesh.faces[count][2]][2]);
			glVertex3f(mesh.vertices[mesh.faces[count][2]][0], 
				mesh.vertices[mesh.faces[count][2]][1], 
				mesh.vertices[mesh.faces[count][2]][2]);	
			glEnd();
		}
	}


	void TriMeshOpenGLUtil::DisplayPoint(const TriMesh& mesh)
	{
		glBegin(GL_POINTS);
		for (unsigned int  i = 0; i < mesh.vertices.size(); ++i) {
			glVertex3f(mesh.vertices[i][0], mesh.vertices[i][1], mesh.vertices[i][2]);
		}
		glEnd();
	}

	void TriMeshOpenGLUtil::DrawBoxALL(const TriMesh::BBox* box)
	{
		_ASSERTE(box);

		glColor3f(1.0, 0, 0);

		glBegin(GL_LINE_LOOP);
		glVertex3f(box->min[0], box->min[1], box->min[2]);
		glVertex3f(box->max[0], box->min[1], box->min[2]);
		glVertex3f(box->max[0], box->min[1], box->max[2]);
		glVertex3f(box->min[0], box->min[1], box->max[2]);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glVertex3f(box->min[0], box->max[1], box->min[2]);
		glVertex3f(box->max[0], box->max[1], box->min[2]);
		glVertex3f(box->max[0], box->max[1], box->max[2]);
		glVertex3f(box->min[0], box->max[1], box->max[2]);
		glEnd();


		glBegin(GL_LINE_LOOP);
		glVertex3f(box->min[0], box->min[1], box->min[2]);
		glVertex3f(box->min[0], box->max[1], box->min[2]);
		glVertex3f(box->min[0], box->max[1], box->max[2]);
		glVertex3f(box->min[0], box->min[1], box->max[2]);
		glEnd();


		glBegin(GL_LINE_LOOP);
		glVertex3f(box->max[0], box->min[1], box->min[2]);
		glVertex3f(box->max[0], box->max[1], box->min[2]);
		glVertex3f(box->max[0], box->max[1], box->max[2]);
		glVertex3f(box->max[0], box->min[1], box->max[2]);
		glEnd();


		glBegin(GL_LINE_LOOP);
		glVertex3f(box->min[0], box->min[1], box->min[2]);
		glVertex3f(box->min[0], box->max[1], box->min[2]);
		glVertex3f(box->max[0], box->max[1], box->min[2]);
		glVertex3f(box->max[0], box->min[1], box->min[2]);
		glEnd();

		glBegin(GL_LINE_LOOP);
		glVertex3f(box->max[0], box->min[1], box->max[2]);
		glVertex3f(box->max[0], box->max[1], box->max[2]);
		glVertex3f(box->min[0], box->max[1], box->max[2]);
		glVertex3f(box->min[0], box->min[1], box->max[2]);
		glEnd();

		glColor3f(0.5, 0.5, 0.5);
	}

}}
