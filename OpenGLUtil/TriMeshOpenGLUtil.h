#ifndef OpenGLUtil_TriMeshOpenGLUtil_H_
#define OpenGLUtil_TriMeshOpenGLUtil_H_

#include <memory>
#include "../TriMesh/TriMesh.h"
#include "../BasicUtil/UnCopyable.h"

namespace Graphics{ namespace OpenGL{ 

	using std::tr1::shared_ptr;
	using BasicUtils::UnCopyable;
	using namespace TriMeshSpace;

	class TriMeshOpenGLUtil : private UnCopyable
	{
	public:
		static void DisplayPoint(const TriMesh& mesh);
		static void DisplayMesh(TriMesh& mesh);
		static void DisplayWireMesh(const TriMesh& mesh);
		static void DrawBoxALL(const TriMesh::BBox* box);
		static void DrawLine(const point& start, const point& end, const Color& color = Color::red());
		static void DrawPoint(const point& startPoint, const Color& color = Color::red());
	};

}}

#endif //OpenGLUtil_TriMeshOpenGLUtil_H_
