#include "PlayerWeapon.h"
#include <cassert>

void PlayerWeapon::Initialize()
{
	playerWeaponModel_.reset(Model::CreateFromOBJ("resource/hammer", "hammer.obj"));

	worldTransform_.Initialize();
	collisionWorldTransform_.Initialize();

	worldTransform_.scale.x = 0.5f;
	worldTransform_.scale.y = 0.5f;
	worldTransform_.scale.z = 0.5f;

	SetCollisionAttribute(kCollisionAttributePlayerWeapon);
	SetCollisionMask(kCollisionMaskPlayerWeapon);
	SetCollisionPrimitive(kCollisionPrimitiveAABB);

	AABB aabbSize =
	{
		{-collisionWorldTransform_.scale.x,-collisionWorldTransform_.scale.y,-collisionWorldTransform_.scale.z},
		{collisionWorldTransform_.scale.x,collisionWorldTransform_.scale.y,collisionWorldTransform_.scale.z},
	};

	SetAABB(aabbSize);
}

void PlayerWeapon::Update()
{
	Vector3 direction{ 0.0f,0.0f,4.0f };
	direction = TransformNormal(direction, worldTransform_.parent_->matWorld);
	collisionWorldTransform_.translation = { worldTransform_.matWorld.m[3][0],worldTransform_.matWorld.m[3][1],worldTransform_.matWorld.m[3][2] };
	collisionWorldTransform_.translation = Add(collisionWorldTransform_.translation, direction);


	worldTransform_.UpdateMatrix();
	collisionWorldTransform_.UpdateMatrix();
}

void PlayerWeapon::Draw(const Camera& camera)
{
	playerWeaponModel_->Draw(worldTransform_, camera);
}

void PlayerWeapon::OnCollision(Collider* collider, float damage)
{

}

Vector3 PlayerWeapon::GetWorldPosition()
{
	Vector3 pos{};
	pos.x = collisionWorldTransform_.matWorld.m[3][0];
	pos.y = collisionWorldTransform_.matWorld.m[3][1];
	pos.z = collisionWorldTransform_.matWorld.m[3][2];
	return pos;
}

void PlayerWeapon::AttackInitialize()
{

}

void PlayerWeapon::Attack()
{
	if (isAttack_ == false)
	{
		isAttack_ = true;
	}
}