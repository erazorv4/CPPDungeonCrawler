#include "stdafx.h"
#include "Directions.h"

Directions::Direction Directions::ReverseDirection(Direction direction)
{
	if (direction == Direction::Up)
		return Direction::Down;
	else if (direction == Direction::Right)
		return Direction::Left;
	else if (direction == Direction::Down)
		return Direction::Up;
	else if (direction == Direction::Left)
		return Direction::Right;
	else
		return Direction::None;
}
