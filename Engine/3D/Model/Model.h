#pragma once
#include "Engine/Base/DirectXCore/DirectXCore.h"
#include "Engine/Base/TextureManager/TextureManager.h"
#include "Engine/3D/WorldTransform/WorldTransform.h"
#include "Engine/3D/Camera/Camera.h"
#include "Engine/Utility/Math/MyMath.h"
#include "Engine/3D/Mesh/Mesh.h"
#include "Engine/3D/Model/Material.h"
#include "Engine/3D/Light/Light.h"
#include <cassert>
#include <dxcapi.h>
#include <fstream>
#include <list>
#include <string>
#include <sstream>

#pragma comment(lib,"dxcompiler.lib")

class Model 
{
public:
	enum class RootParameterIndex 
	{
		Material,
		WorldlTransform,
		ViewProjection,
		Texture,
		Light
	};

	struct MaterialData
	{
		std::string textureFilePath;
	};

	struct ModelData 
	{
		std::vector<Mesh::VertexData> vertices;
		MaterialData material;
		std::string name;
	};

	struct ConstBufferDataTransformationMatrix 
	{
		Matrix4x4 WVP;
		Matrix4x4 World;
	};

	static void StaticInitialize();

	static void Release();

	static Model* CreateFromOBJ(const std::string& directoryPath, const std::string& filename);

	static void PreDraw();

	static void PostDraw();

	void Draw(const WorldTransform& worldTransform, const Camera& camera);

	Light* GetDirectionalLight() { return light_.get(); };

	Material* GetMaterial() { return material_.get(); };

private:
	static void InitializeDXC();

	static Microsoft::WRL::ComPtr<IDxcBlob> CompileShader(
		const std::wstring& filePath,
		const wchar_t* profile);

	static void CreatePipelineStateObject();

	ModelData LoadObjFile(const std::string& directoryPath, const std::string& filename);

	MaterialData LoadMaterialTemplateFile(const std::string& directoryPath, const std::string& filename);

private:
	static ID3D12Device* sDevice_;

	static ID3D12GraphicsCommandList* sCommandList_;

	static Microsoft::WRL::ComPtr<IDxcUtils> sDxcUtils_;
	static Microsoft::WRL::ComPtr<IDxcCompiler3> sDxcCompiler_;
	static Microsoft::WRL::ComPtr<IDxcIncludeHandler> sIncludeHandler_;
	
	static Microsoft::WRL::ComPtr<ID3D12RootSignature> sRootSignature_;

	static Microsoft::WRL::ComPtr<ID3D12PipelineState> sGraphicsPipelineState_;

	static std::list<ModelData> modelDatas_;

	std::unique_ptr<Mesh> mesh_ = nullptr;
	
	std::unique_ptr<Material> material_ = nullptr;

	std::unique_ptr<Light>light_;
	
	uint32_t textureHandle_;
};