#include"Part2.h"

std::shared_ptr<Date> maxDate(const std::shared_ptr<Date>& date1, const std::shared_ptr<Date>& date2)
{
	if (date1.get()->getYear() > date2.get()->getYear()) return std::shared_ptr<Date>(date1);
	else if (date1.get()->getYear() < date2.get()->getYear()) return std::shared_ptr<Date>(date2);
	else if (date1.get()->getMonth() > date2.get()->getMonth()) return std::shared_ptr<Date>(date1);
	else if (date1.get()->getMonth() < date2.get()->getMonth()) return std::shared_ptr<Date>(date2);
	else if (date1.get()->getDay() > date2.get()->getDay()) return std::shared_ptr<Date>(date1);
	else return std::shared_ptr<Date>(date2);
}

void swapDate(std::shared_ptr<Date>& date1, std::shared_ptr<Date>& date2)
{
	auto tmp = move(date1);
	date1 = move(date2);
	date2 = move(tmp);
}