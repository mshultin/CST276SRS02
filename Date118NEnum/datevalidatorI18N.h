#pragma once

#include <array>
#include <cassert>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class DateValidatorI18N {
public:
	using delimiter = char;
	using year = string;
	using month = string;
	using day = string;

	enum class Format {YMD, DMY, MDY};
	bool validateDate(Format, string, delimiter);

private:
	bool isYearGood(const year);
	bool isMonthGood(const month);
	bool isDayGood(const day, const month, const year);
	static int getMaxDays(const month, const year);
};