#include "TriMeshOpenGLUtil.h"
#include "../Extern/glut/include/glut.h"

namespace Graphics{ namespace OpenGL{ 

	const float PI = 3.14f;

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