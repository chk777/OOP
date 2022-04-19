#pragma once
#include<stdexcept>

class DivisionByZero : public std::exception
{
public:
	DivisionByZero(const std::string& err = "Division by zero detected!") : error(err)
	{};

	const char* what() const noexcept { return error.c_str(); }

private:
	std::string error;
};


template <typename T>
double_t div(T dividend, T divider)
{
	if (divider == 0) throw DivisionByZero();
	return static_cast<double_t>(dividend) / divider;
}