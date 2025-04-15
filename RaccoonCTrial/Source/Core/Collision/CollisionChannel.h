#pragma once

enum class ECollisionChannel
{
	Player,
	Monster,
	Wall,
	None
};

enum class ECollisionResponse
{
	Block,
	Overlap,
	Ignore
};