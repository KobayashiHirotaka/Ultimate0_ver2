#pragma once
#include "Engine/3D/Model/Model.h"
#include "Engine/3D/WorldTransform/WorldTransform.h"
#include "Engine/3D/Camera/Camera.h"

class Skydome
{
public:
	void Initialize();

	void Update();

	void Draw(const Camera camera);

private:
	std::unique_ptr<Model>model_ = nullptr;

	WorldTransform worldTransform_;
};

