#pragma once
#include<cstdint>
#include<ostream>
#include<iomanip>

class Date
{
public:
	Date(uint16_t d = 1, uint16_t m = 1, uint16_t y = 1800);

	uint16_t getDay() const;
	uint16_t getMonth() const;
	uint16_t getYear() const;

private:
	uint16_t day, month, year;
};

std::ostream& operator<<(std::ostream& out, const Date& date);