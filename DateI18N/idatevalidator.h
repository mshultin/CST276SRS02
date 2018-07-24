#pragma once

#include <array>
#include <cassert>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class IDateValidator
{
public:
	using delimiter = char;
	using year = string;
	using month = string;
	using day = string;

	virtual bool is_good(std::string const aDate, delimiter const aDelimiter) const = 0;

protected:
	bool isYearGood(const year) const;
	bool isMonthGood(const month) const;
	bool isDayGood(const day, const month, const year) const;

private:
	static int getMaxDays(const month, const year);
};