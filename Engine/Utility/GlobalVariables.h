#pragma once
#include "Engine/Base/ImGuiManager/ImGuiManager.h"
#include "Engine/Utility/Math/MyMath.h"
#include "Engine/externals/nlohmann/json.hpp"
#include <variant>
#include <map>
#include <string>
#include <fstream>

using json = nlohmann::json;

class GlobalVariables
{
public:
	static GlobalVariables* GetInstance();

	void Update();

	int32_t GetIntValue(const std::string& groupName, const std::string& key);

	float GetFloatValue(const std::string& groupName, const std::string& key);

	Vector3 GetVector3Value(const std::string& groupName, const std::string& key);

	void SetValue(const std::string& groupName, const std::string& key, int32_t value);

	void SetValue(const std::string& groupName, const std::string& key, float value);

	void SetValue(const std::string& groupName, const std::string& key, Vector3& value);

	void CreateGroup(const std::string& groupName);

	void SaveFile(const std::string& groupName);

	void LoadFiles();

	void LoadFile(const std::string& groupName);

	void AddItem(const std::string& groupName, const std::string& key, int32_t value);

	void AddItem(const std::string& groupName, const std::string& key, float value);

	void AddItem(const std::string& groupName, const std::string& key, Vector3& value);

public:
	struct Item
	{
		std::variant<int32_t, float, Vector3> value;
	};

	struct Group
	{
		std::map<std::string, Item> items;
	};

	std::map<std::string, Group> datas_;

private:
	GlobalVariables() = default;

	~GlobalVariables() = default;

	GlobalVariables(const GlobalVariables& obj) = default;

	GlobalVariables& operator=(const GlobalVariables& obj) = default;

	const std::string kDirectoryPath = "resource/GlobalVariables/";
};