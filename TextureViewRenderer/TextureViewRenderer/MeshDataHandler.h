#pragma once
#include "Content\ShaderStructures.h"
using namespace TextureViewRenderer;

class MeshDataHandler
{
public:
	enum MeshType
	{
		PLANE,
		CUBE,
		RABBIT,

		NUM_MESH_TYPES
	};
	struct MeshData
	{
		MeshType type;
		TextureViewRenderer::VertexData * vertexData;
		unsigned short * indexData;
		unsigned short numVertices;
		unsigned short numIndices;
	};

	MeshData meshData[NUM_MESH_TYPES];

	const MeshDataHandler::MeshData * MeshDataHandler::GetMeshData(MeshType type);
	static MeshDataHandler * GetInstance();
	~MeshDataHandler();
private:
	template <typename T, unsigned S>
	inline unsigned arraysize(const T(&v)[S]) { return S; }
	MeshDataHandler();
};