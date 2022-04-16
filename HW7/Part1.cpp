#include "Part1.h"

Date::Date(uint16_t d, uint16_t m, uint16_t y) : day(d), month(m), year(y)
{}

uint16_t Date::getDay() const
{
	return day;
}

uint16_t Date::getMonth() const
{
	return month;
}

uint16_t Date::getYear() const
{
	return year;
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	out << std::setw(2) << std::setfill('0') << date.getDay() << "."
		<< std::setw(2) << std::setfill('0') << date.getMonth() << "."
		<< std::setw(4) << std::setfill('0') << date.getYear() << "." << std::endl;
	return out;
}