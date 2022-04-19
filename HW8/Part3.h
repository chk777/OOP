#include <cstdint>
#include <stdexcept>
#include <string>
#include <iostream>

#define SIZE_FIELD 10


struct Pos
{
	int16_t x, y;
};

enum class Direction
{
	RIGHT, LEFT, DOWN, UP, other
};

class OffTheField : public std::exception
{
public:
	OffTheField(Pos pos, Direction dir)
	{
		error = "current position robot (";
		error += std::to_string(pos.x);
		error += ",";
		error += std::to_string(pos.y);
		error += ") direction of travel: ";
		switch (dir)
		{
		case Direction::RIGHT:
			error += "right";
			break;
		case Direction::LEFT:
			error += "left";
			break;
		case Direction::DOWN:
			error += "down";
			break;
		case Direction::UP:
			error += "up";
			break;
		default:
			break;
		}
	};

	const char* what() const noexcept { return error.c_str(); };

private:
	std::string error;
};

class IllegalCommand : public std::exception
{
public:
	IllegalCommand() = default;
};

class Robot
{
public:
	Robot() : currPos{}
	{};

	void move(Direction dir);
	void print();

private:
	Pos currPos;
}; 
