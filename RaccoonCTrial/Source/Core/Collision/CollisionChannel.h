#pragma once

enum class ECollisionChannel
{
	Player,
	Monster,
	Wall,
	EndPoint,
	Mesh,
	None
};

enum class ECollisionResponse
{
	Block,
	Overlap,
	Ignore
};