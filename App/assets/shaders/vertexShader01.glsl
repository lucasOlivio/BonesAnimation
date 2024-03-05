// Vertex shader
#version 420

//uniform mat4 MVP;
uniform mat4 matView;
uniform mat4 matProjection;
uniform mat4 matModel;	
uniform mat4 matModel_IT;	

uniform vec2 UVOffset;
uniform vec2 HeightMapOffset;

// Height texture
uniform float heightScale;
uniform bool bUseHeightMapTexture;
uniform sampler2D heightMapTexture;

// Normal texture
uniform bool bUseNormalTexture;
uniform sampler2D normalTexture;

// Bones info
uniform mat4 matBones[50];
uniform bool bUseBones;

// Vertex variables
in vec4 vCol;		
in vec4 vPos;	
in vec4 vNormal;
in vec2 vTextureCoords;
in vec4 vBoneIds;
in vec4 vBoneWeights;

// Fragment shader variables
out vec4 colour;
out vec4 vertexWorldPos;	
out vec4 vertexWorldNormal;
out vec2 textureCoords;

void main()
{
	// Rotate the normal by the inverse transpose of the model matrix
	// (so that it only is impacted by the rotation, not translation or scale)
	vertexWorldNormal = matModel_IT * vec4(vNormal.xyz, 1.0f);
	vertexWorldNormal.xyz = normalize(vertexWorldNormal.xyz);
	vertexWorldNormal.w = 1.0f;

	vec4 vertexModelPosition = vPos;

	if (bUseBones)
	{
		mat4 boneTransform = matBones[int(vBoneIds[0])] * vBoneWeights[0];
		boneTransform += matBones[int(vBoneIds[1])] * vBoneWeights[1];
		boneTransform += matBones[int(vBoneIds[2])] * vBoneWeights[2];
		boneTransform += matBones[int(vBoneIds[3])] * vBoneWeights[3];

		vertexModelPosition = boneTransform * vertexModelPosition;
	}

	vec2 UVFinal = vTextureCoords.st + UVOffset.yx;
	vec2 HeightMapFinal = vTextureCoords.st + HeightMapOffset.yx;

	if (bUseHeightMapTexture)
	{
		// Greyscale (black and white) heightmap image
		vec4 height = texture(heightMapTexture, HeightMapFinal.st);

		// Adjust the height of the normal relative axis from this vertice
		vertexModelPosition += normalize(vertexWorldNormal * height) * heightScale;
	}

	if (bUseNormalTexture)
	{
		vec3 normalMapColor = texture(normalTexture, textureCoords).xyz;

		// Convert normal map color from [0,1] to [-1,1] range
		vertexWorldNormal = vec4(normalize(normalMapColor * 2.0 - 1.0), 1.0);
	}

	mat4 matMVP = matProjection * matView * matModel;
	gl_Position = matMVP * vec4(vertexModelPosition.xyz, 1.0);
	
	vertexWorldPos = matModel * vec4(vertexModelPosition.xyz, 1.0f);
	colour = vCol;
	textureCoords = vTextureCoords.st;
}

