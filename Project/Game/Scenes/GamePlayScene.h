#pragma once
#include "IScene.h"
#include "Engine/3D/WorldTransform/WorldTransform.h"
#include "Engine/3D/Camera/Camera.h"
#include "Engine/Components/Input/Input.h"
#include "Engine/Components/Audio/Audio.h"
#include "Engine/Base/TextureManager/TextureManager.h"
#include "Engine/Utility/Collision/CollisionManager.h"
#include "Engine/3D/Particle/ParticleModel.h"
#include "Engine/2D/Sprite/Sprite.h"

#include "Project/GameObject/Character/Player/Player.h"
#include "Project/GameObject/Character/Enemy/Enemy.h"
#include "Project/GameObject/Skydome/Skydome.h"
#include <memory>

class GamePlayScene : public IScene
{
public:
	GamePlayScene();

	~GamePlayScene();

	void Initialize(SceneManager* sceneManager)override;

	void Update(SceneManager* sceneManager)override;

	void Draw(SceneManager* sceneManager)override;

	void UpdateNumberSprite();

private:
	WorldTransform worldTransform_;

	Camera camera_;

	TextureManager* textureManager_ = nullptr;

	std::unique_ptr<CollisionManager> collisionManager_;

	Input* input_ = nullptr;

	Audio* audio_ = nullptr;

	std::unique_ptr<Player>player_;

	std::unique_ptr<Enemy>enemy_;

	std::unique_ptr<Skydome>skydome_;

	int round_ = 1;
	int migrationTimer_;
	int PlayerWinCount_ = 0;
	int EnemyWinCount_ = 0;

	std::unique_ptr<Model>ground_;

	std::unique_ptr<Sprite>numberTensSprite_ = nullptr;
	std::unique_ptr<Sprite>numberOnesSprite_ = nullptr;
	uint32_t tensTextureHandle_;
	uint32_t onesTextureHandle_;

	std::unique_ptr<Sprite>roundSprite_[3];
	uint32_t roundTextureHandle_[3];

	std::unique_ptr<Sprite>fightSprite_ = nullptr;
	uint32_t fightTextureHandle_;

	std::unique_ptr<Sprite>roundGetSprite_[4];
	uint32_t roundGetTextureHandle_;

	std::unique_ptr<Sprite>winSprite_ = nullptr;
	uint32_t winTextureHandle_;

	std::unique_ptr<Sprite>loseSprite_ = nullptr;
	uint32_t loseTextureHandle_;

	std::unique_ptr<Sprite>drowSprite_ = nullptr;
	uint32_t drowTextureHandle_;

	std::unique_ptr<Sprite>UICommandListSprite_ = nullptr;
	uint32_t UICommandListTextureHandle_ = 0;

	std::unique_ptr<Sprite>generalCommandListSprite_ = nullptr;
	uint32_t generalCommandListTextureHandle_ = 0;

	std::unique_ptr<Sprite>attackCommandListSprite_ = nullptr;
	uint32_t attackCommandListTextureHandle_ = 0;

	int currentSeconds_;

	float frameTime = 1.0f / 60.0f;  // 60FPSを仮定
	float elapsedTime = 0.0f;

	float roundStartTimer_ = 100.0f;

	bool isPlayerWin_ = false;
	bool isDrow_ = false;

	uint32_t selectSoundHandle_ = 0u;

	int spriteCount_ = 0;
	bool isOpen_ = false;
};
