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
	using date = string;
	using year = string;
	using month = string;
	using day = string;

	// Modified enum class Format for YDM
	//enum class Format {YMD, DMY, MDY};
	enum class Format {YMD, DMY, MDY, YDM};
	bool validateDate(Format, date, delimiter);

private:
	bool isYearGood(const year);
	bool isMonthGood(const month);
	bool isDayGood(const day, const month, const year);
	static int getMaxDays(const month, const year);
};