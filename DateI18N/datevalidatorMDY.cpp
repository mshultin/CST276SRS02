#include "datevalidatorMDY.h"

bool DateValidatorMDY::is_good(string const aDate, const delimiter aDelimiter) const {
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

	/* Change these to match the pattern */
	// 12-31-1999
	mDay = str_itr[1];
	mMonth = str_itr[0];
	mYear = str_itr[2];

	if (isYearGood(mYear))
		if (isMonthGood(mMonth))
			if (isDayGood(mDay, mMonth, mYear))
				dateTest = true;

	return dateTest;
}