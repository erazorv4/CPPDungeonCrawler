#pragma once
class Directions
{
public:
	static enum Direction : int
	{
		None = -1,
		Up = 0,
		Right = 1,
		Down = 2,
		Left = 3
	};
	static Direction ReverseDirection(Direction direction);
};

