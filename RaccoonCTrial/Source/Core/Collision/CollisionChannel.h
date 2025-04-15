#pragma once

enum class ECollisionChannel
{
	Player,
	Monster,
	Wall,
	EndPoint,
	None
};

enum class ECollisionResponse
{
	Block,
	Overlap,
	Ignore
};