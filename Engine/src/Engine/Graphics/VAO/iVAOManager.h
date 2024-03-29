#pragma once

#include "Engine/Graphics/GraphicsProperties.h"

namespace MyEngine
{
	class iVAOManager
	{
	public:
		iVAOManager() {};
		virtual ~iVAOManager() {};

		virtual void DestroyVBO(std::string modelName) = 0;

		virtual sMesh* LoadModelIntoVAO(std::string& fileName, bool bIsDynamicBuffer,
									    bool hasNormals, bool hasTexture) = 0;
		// Normals and texture as default
		virtual sMesh* LoadModelIntoVAO(std::string& fileName, bool bIsDynamicBuffer) = 0;

		// Load mesh and duplicates it with custom name
		virtual sMesh* LoadModelCopyIntoVAO(std::string& fileName, bool bIsDynamicBuffer,
											bool hasNormals, bool hasTexture, std::string& copyName) = 0;

		virtual bool UpdateVAOBuffers(std::string& fileName, sMesh* pUpdatedMesh) = 0;

		virtual sMesh* FindMeshByModelName(std::string& filename) = 0;

		virtual void SetBasePath(std::string basePath) = 0;
	};
}
