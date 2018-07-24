#include "idatevalidator.h"

bool IDateValidator::isYearGood(const year aYear) const {
	auto mMinYear = 1901;
	auto mMaxYear = 2100;
	auto mYear = stoi(aYear);
	if (mYear >= mMinYear && mYear <= mMaxYear)
		return true;
	else
		return false;
}

bool IDateValidator::isMonthGood(const month aMonth) const {
	int mMonth = stoi(aMonth);
	if (mMonth <= 12)
		return true;
	else
		return false;
}

bool IDateValidator::isDayGood(const day aDay, const month aMonth, const year aYear) const {
	int mDayMax = getMaxDays(aMonth, aYear);
	int mDay = stoi(aDay);
	if (mDay <= mDayMax)
		return true;
	else
		return false;
}

// getMaxDays is a variation of Professor Besser's code
int IDateValidator::getMaxDays(const month aMonth, const year aYear) {
	auto mMonth = stoi(aMonth) - 1;
	auto mYear = stoi(aYear);
	static constexpr array<int, 12> days{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int result{ days.at(mMonth) };
	if (mMonth == 1 && mYear % 4 == 0) {
		result = 29;
	}
	return result;
}