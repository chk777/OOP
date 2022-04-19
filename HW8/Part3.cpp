#include "Part3.h"

void Robot::move(Direction dir)
{
	switch (dir)
	{
	case Direction::RIGHT:
		if (++currPos.x >= SIZE_FIELD)
		{
			--currPos.x;
			throw OffTheField(currPos, dir);
		}
		break;
	case Direction::LEFT:
		if (--currPos.x < 0)
		{
			++currPos.x;
			throw OffTheField(currPos, dir);
		}
		break;
	case Direction::DOWN:
		if (++currPos.y >= SIZE_FIELD)
		{
			--currPos.y;
			throw OffTheField(currPos, dir);
		}
		break;
	case Direction::UP:
		if (--currPos.y < 0)
		{
			++currPos.y;
			throw OffTheField(currPos, dir);
		}
		break;
	default: throw IllegalCommand();
		break;
	}
}

void Robot::print()
{
	for (size_t i = 0; i < SIZE_FIELD; i++)
	{
		for (size_t j = 0; j < SIZE_FIELD; j++)
		{
			if (j == currPos.x && i == currPos.y) std::cout << "X";
			else std::cout << "_";
		}
		std::cout << std::endl;
	}
}