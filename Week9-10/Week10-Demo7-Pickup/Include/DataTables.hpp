#pragma once

#include <ResourceIdentifiers.hpp>

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Color.hpp>

#include <vector>
#include <functional>


class Aircraft;

struct Direction
{
	Direction(float angle, float distance)
	: angle(angle)
	, distance(distance)
	{
	}

	float angle;
	float distance;
};

struct AircraftData
{
	int								hitpoints;
	float							speed;
	Textures::ID					texture;
	sf::Time						fireInterval;
	std::vector<Direction>			directions;
};

struct ProjectileData
{
	int								damage;
	float							speed;
	Textures::ID					texture;
};

#pragma region step 3
struct PickupData
{
	std::function<void(Aircraft&)>	action;
	Textures::ID					texture;
};
#pragma endregion




std::vector<AircraftData>	initializeAircraftData();
std::vector<ProjectileData>	initializeProjectileData();

#pragma region step 4
std::vector<PickupData>		initializePickupData();
#pragma endregion



