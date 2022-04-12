#pragma once
#include <iosfwd>

std::ostream& endll(std::ostream& out)
{
	char enter = out.widen('\n');
	out.put(enter);
	out.put(enter);
	out.flush();
	return out;
}