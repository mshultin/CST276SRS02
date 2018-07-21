// Minimum year: 1901
// Maximum year: 2001
#include "datevalidatorI18N.h"

int main() {
	DateValidatorI18N date_validator;
	string date{ "" };
	bool test{ false };
	
	// YMD testing
	date = "2100-12-31";
	test = date_validator.validateDate(DateValidatorI18N::Format::YMD, date, '-');
	date = "2200-12-31";
	test = date_validator.validateDate(DateValidatorI18N::Format::YMD, date, '-');

	// DMY testing
	date = "28/2/2019";
	test = date_validator.validateDate(DateValidatorI18N::Format::DMY, date, '/');
	date = "12/30/2019";
	test = date_validator.validateDate(DateValidatorI18N::Format::DMY, date, '/');
	
	// MDY testing
	date = "2-27-2059";
	test = date_validator.validateDate(DateValidatorI18N::Format::MDY, date, '-');
	date = "2-29-2059";
	test = date_validator.validateDate(DateValidatorI18N::Format::MDY, date, '-');
	
	return 0;
}
