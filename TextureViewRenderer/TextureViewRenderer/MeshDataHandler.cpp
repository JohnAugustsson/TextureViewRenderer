#include "pch.h"
#include "MeshDataHandler.h"

MeshDataHandler::MeshDataHandler()
{
	const unsigned short cubeIndices[] =
	{
		0,2,1, // -x
		1,2,3,

		4,5,6, // +x
		5,7,6,

		0,1,5, // -y
		0,5,4,

		2,6,7, // +y
		2,7,3,

		0,4,6, // -z
		0,6,2,

		1,3,7, // +z
		1,7,5,
	};

	const unsigned short planeIndices[] =
	{
		0,2,1, // -x
		1,2,3,

		4,5,6, // +x
		5,7,6,

		0,1,5, // -y
		0,5,4,

		2,6,7, // +y
		2,7,3,

		0,4,6, // -z
		0,6,2,

		1,3,7, // +z
		1,7,5,
	};

	const unsigned short rabbitIndices[] =
	{
		0,2,1, // -x
		1,2,3,

		4,5,6, // +x
		5,7,6,

		0,1,5, // -y
		0,5,4,

		2,6,7, // +y
		2,7,3,

		0,4,6, // -z
		0,6,2,

		1,3,7, // +z
		1,7,5,
	};

	const TextureViewRenderer::VertexData cubeData[] =
	{
		{ DirectX::XMFLOAT3(-0.5f, -0.5f, -0.5f), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f) },
		{ DirectX::XMFLOAT3(-0.5f, -0.5f,  0.5f), DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f) },
		{ DirectX::XMFLOAT3(-0.5f,  0.5f, -0.5f), DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f) },
		{ DirectX::XMFLOAT3(-0.5f,  0.5f,  0.5f), DirectX::XMFLOAT3(0.0f, 1.0f, 1.0f) },
		{ DirectX::XMFLOAT3(0.5f, -0.5f, -0.5f), DirectX::XMFLOAT3(1.0f, 0.0f, 0.0f) },
		{ DirectX::XMFLOAT3(0.5f, -0.5f,  0.5f), DirectX::XMFLOAT3(1.0f, 0.0f, 1.0f) },
		{ DirectX::XMFLOAT3(0.5f,  0.5f, -0.5f), DirectX::XMFLOAT3(1.0f, 1.0f, 0.0f) },
		{ DirectX::XMFLOAT3(0.5f,  0.5f,  0.5f), DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f) },
	};

	const TextureViewRenderer::VertexData planeData[] =
	{
		{ DirectX::XMFLOAT3(-0.5f, -0.5f, -0.5f), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f) },
		{ DirectX::XMFLOAT3(-0.5f, -0.5f,  0.5f), DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f) },
		{ DirectX::XMFLOAT3(-0.5f,  0.5f, -0.5f), DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f) },
		{ DirectX::XMFLOAT3(-0.5f,  0.5f,  0.5f), DirectX::XMFLOAT3(0.0f, 1.0f, 1.0f) },
		{ DirectX::XMFLOAT3(0.5f, -0.5f, -0.5f), DirectX::XMFLOAT3(1.0f, 0.0f, 0.0f) },
		{ DirectX::XMFLOAT3(0.5f, -0.5f,  0.5f), DirectX::XMFLOAT3(1.0f, 0.0f, 1.0f) },
		{ DirectX::XMFLOAT3(0.5f,  0.5f, -0.5f), DirectX::XMFLOAT3(1.0f, 1.0f, 0.0f) },
		{ DirectX::XMFLOAT3(0.5f,  0.5f,  0.5f), DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f) },
	};

	const TextureViewRenderer::VertexData rabbitData[] =
	{
		{ DirectX::XMFLOAT3(-0.5f, -0.5f, -0.5f), DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f) },
		{ DirectX::XMFLOAT3(-0.5f, -0.5f,  0.5f), DirectX::XMFLOAT3(0.0f, 0.0f, 1.0f) },
		{ DirectX::XMFLOAT3(-0.5f,  0.5f, -0.5f), DirectX::XMFLOAT3(0.0f, 1.0f, 0.0f) },
		{ DirectX::XMFLOAT3(-0.5f,  0.5f,  0.5f), DirectX::XMFLOAT3(0.0f, 1.0f, 1.0f) },
		{ DirectX::XMFLOAT3(0.5f, -0.5f, -0.5f), DirectX::XMFLOAT3(1.0f, 0.0f, 0.0f) },
		{ DirectX::XMFLOAT3(0.5f, -0.5f,  0.5f), DirectX::XMFLOAT3(1.0f, 0.0f, 1.0f) },
		{ DirectX::XMFLOAT3(0.5f,  0.5f, -0.5f), DirectX::XMFLOAT3(1.0f, 1.0f, 0.0f) },
		{ DirectX::XMFLOAT3(0.5f,  0.5f,  0.5f), DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f) },
	};

	meshData[PLANE].vertexData = new TextureViewRenderer::VertexData[arraysize(planeData)];
	meshData[CUBE].vertexData = new TextureViewRenderer::VertexData[arraysize(cubeData)];
	meshData[RABBIT].vertexData = new TextureViewRenderer::VertexData[arraysize(rabbitData)];

	meshData[PLANE].indexData = new unsigned short[arraysize(planeIndices)];
	meshData[CUBE].indexData = new unsigned short[arraysize(cubeIndices)];
	meshData[RABBIT].indexData = new unsigned short[arraysize(rabbitIndices)];

	for (int i = 0; i < arraysize(planeData); i++)
	{
		meshData[PLANE].vertexData[i] = planeData[i];
	}
	for (int i = 0; i < arraysize(cubeData); i++)
	{
		meshData[CUBE].vertexData[i] = cubeData[i];
	}
	for (int i = 0; i < arraysize(rabbitData); i++)
	{
		meshData[RABBIT].vertexData[i] = rabbitData[i];
	}

	for (int i = 0; i < arraysize(planeIndices); i++)
	{
		meshData[PLANE].indexData[i] = planeIndices[i];
	}

	for (int i = 0; i < arraysize(cubeIndices); i++)
	{
		meshData[CUBE].indexData[i] = cubeIndices[i];
	}

	for (int i = 0; i < arraysize(rabbitIndices); i++)
	{
		meshData[RABBIT].indexData[i] = rabbitIndices[i];
	}

	meshData[PLANE].numVertices = arraysize(planeData);
	meshData[CUBE].numVertices = arraysize(cubeData);
	meshData[RABBIT].numVertices = arraysize(rabbitData);
	
	meshData[PLANE].numIndices = arraysize(planeIndices);
	meshData[CUBE].numIndices = arraysize(cubeIndices);
	meshData[RABBIT].numIndices = arraysize(rabbitIndices);
}

const MeshDataHandler::MeshData * MeshDataHandler::GetMeshData(MeshType type)
{
	return &meshData[type];

	return nullptr;
}

MeshDataHandler * MeshDataHandler::GetInstance()
{
	static MeshDataHandler instance;
	return &instance;
}

MeshDataHandler::~MeshDataHandler()
{
	for (MeshDataHandler::MeshData data : meshData)
	{
		delete[] data.indexData;
		delete[] data.vertexData;
	}
}
