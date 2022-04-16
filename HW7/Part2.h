#pragma once
#include<memory>
#include"Part1.h"

std::shared_ptr<Date> maxDate(const std::shared_ptr<Date>& date1, const std::shared_ptr<Date>& date2);
void swapDate(std::shared_ptr<Date>& date1, std::shared_ptr<Date>& date2);