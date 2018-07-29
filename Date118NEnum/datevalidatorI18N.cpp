// 1901-2100; %4 for leap years

#include "datevalidatorI18N.h"

/******************************
validateDate
Params: Format, date, delimiter
Returns: bool
******************************/
bool DateValidatorI18N::validateDate(Format aFormat, date aDate, delimiter aDelimiter) {
	istringstream iss{ aDate };
	vector<string> str_vector;
	bool dateTest{ false };
	string mDay;
	string mMonth;
	string mYear;

	while (iss.good()) {
		string buffer;
		getline(iss, buffer, aDelimiter);
		str_vector.push_back(buffer);
	}
	assert(str_vector.size() == 3);

	vector<string>::iterator str_itr = str_vector.begin();

	switch (aFormat)
	{
	case DateValidatorI18N::Format::YMD: // 1999-12-31
		mDay = str_itr[2];
		mMonth = str_itr[1];
		mYear = str_itr[0];
		
		if (isYearGood(mYear))
			if (isMonthGood(mMonth))
				if (isDayGood(mDay, mMonth, mYear))
					dateTest = true;
		break;
	case DateValidatorI18N::Format::DMY: // 31-12-1999
		mDay = str_itr[0];
		mMonth = str_itr[1];
		mYear = str_itr[2];
		
		if (isYearGood(mYear))
			if (isMonthGood(mMonth))
				if (isDayGood(mDay, mMonth, mYear))
					dateTest = true;
		break;
	case DateValidatorI18N::Format::MDY: // 12-31-1999
		mDay = str_itr[1];
		mMonth = str_itr[0];
		mYear = str_itr[2];
		
		if (isYearGood(mYear))
			if (isMonthGood(mMonth))
				if (isDayGood(mDay, mMonth, mYear))
					dateTest = true;
		break;

	/* New switch case for YDM */
	case DateValidatorI18N::Format::YDM: // 1999-31-12
		mDay = str_itr[1];
		mMonth = str_itr[2];
		mYear = str_itr[0];

		if (isYearGood(mYear))
			if (isMonthGood(mMonth))
				if (isDayGood(mDay, mMonth, mYear))
					dateTest = true;
		break;
	/* End new switch case */

	default:
		dateTest = false;
		break;
	}
	return dateTest;
}

/******************************
isYearGood
Params: year
Returns: bool
******************************/
bool DateValidatorI18N::isYearGood(const year aYear) {
	auto mMinYear = 1901;
	auto mMaxYear = 2100;
	auto mYear = stoi(aYear);
	if (mYear >= mMinYear && mYear <= mMaxYear)
		return true;
	else
		return false;
}

/******************************
isMonthGood
Params: month
Returns: bool
******************************/
bool DateValidatorI18N::isMonthGood(const month aMonth) {
	int mMonth = stoi(aMonth);
	if (mMonth <= 12)
		return true;
	else
		return false;
}

/******************************
isDayGood
Params: day, month, year
Returns: bool
******************************/
bool DateValidatorI18N::isDayGood(const day aDay, const month aMonth, const year aYear) {
	int mDayMax = getMaxDays(aMonth, aYear);
	int mDay = stoi(aDay);
	if (mDay <= mDayMax)
		return true;
	else
		return false;
}

/******************************
getMaxDays
Params: month, year
Returns: int
******************************/
// getMaxDays is a variation of Professor Besser's code
int DateValidatorI18N::getMaxDays(const month aMonth, const year aYear) {
	auto mMonth = stoi(aMonth) - 1;
	auto mYear = stoi(aYear);
	static constexpr array<int, 12> days{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int result{ days.at(mMonth) };
	if (mMonth == 1 && mYear % 4 == 0) {
		result = 29;
	}
	return result;
}