#pragma once

class Ex
{
public:
	Ex(double_t arg) : x(arg)
	{};
	double_t what() const noexcept { return x; };

private:
	double_t x;
};

class Bar
{
public:
	Bar() : y(0)
	{};

	void set(double_t a)
	{
		if (y + a > 100) throw Ex(a * y);
		else y = a;
	}

private:
	double_t y;
};