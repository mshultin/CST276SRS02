// Minimum year: 1901
// Maximum year: 2001
#include "datevalidatorI18N.h"

int main() {
	DateValidatorI18N date_validator;
	string date{ "" };
	bool test{ false };

	date = "2200-12-31";
	// YMD: fail; DMY: fail; MDY: fail
	test = date_validator.validateDate(DateValidatorI18N::Format::YMD, date, '-');
	test = date_validator.validateDate(DateValidatorI18N::Format::DMY, date, '-');
	test = date_validator.validateDate(DateValidatorI18N::Format::MDY, date, '-');
	// New test for YDM: fail
	test = date_validator.validateDate(DateValidatorI18N::Format::YDM, date, '-');

	date = "2100-12-31";
	// YMD: pass; DMY: fail; MDY: fail
	test = date_validator.validateDate(DateValidatorI18N::Format::YMD, date, '-');
	test = date_validator.validateDate(DateValidatorI18N::Format::DMY, date, '-');
	test = date_validator.validateDate(DateValidatorI18N::Format::MDY, date, '-');
	// New test for YDM: fail
	test = date_validator.validateDate(DateValidatorI18N::Format::YDM, date, '-');

	date = "28/2/2019";
	// YMD: fail; DMY: pass; MDY: fail
	test = date_validator.validateDate(DateValidatorI18N::Format::YMD, date, '/');
	test = date_validator.validateDate(DateValidatorI18N::Format::DMY, date, '/');
	test = date_validator.validateDate(DateValidatorI18N::Format::MDY, date, '/');
	// New test for YDM: fail
	test = date_validator.validateDate(DateValidatorI18N::Format::YDM, date, '/');
	
	date = "12/30/2019";
	// YMD: fail; DMY: fail; MDY: pass
	test = date_validator.validateDate(DateValidatorI18N::Format::YMD, date, '/');
	test = date_validator.validateDate(DateValidatorI18N::Format::DMY, date, '/');
	test = date_validator.validateDate(DateValidatorI18N::Format::MDY, date, '/');
	// New test for YDM: fail
	test = date_validator.validateDate(DateValidatorI18N::Format::YDM, date, '/');
	
	date = "2.27.2059";
	// YMD: fail; DMY: fail; MDY: pass
	test = date_validator.validateDate(DateValidatorI18N::Format::YMD, date, '.');
	test = date_validator.validateDate(DateValidatorI18N::Format::DMY, date, '.');
	test = date_validator.validateDate(DateValidatorI18N::Format::MDY, date, '.');
	// New test for YDM: fail
	test = date_validator.validateDate(DateValidatorI18N::Format::YDM, date, '.');
	
	date = "2.29.2059";
	// YMD: fail; DMY: fail; MDY: fail (non-leap year)
	test = date_validator.validateDate(DateValidatorI18N::Format::YMD, date, '.');
	test = date_validator.validateDate(DateValidatorI18N::Format::DMY, date, '.');
	test = date_validator.validateDate(DateValidatorI18N::Format::MDY, date, '.');
	// New test for YDM: fail
	test = date_validator.validateDate(DateValidatorI18N::Format::YDM, date, '.');

	date = "2.29.2020";
	// YMD: fail; DMY: fail; MDY: pass (leap year)
	test = date_validator.validateDate(DateValidatorI18N::Format::YMD, date, '.');
	test = date_validator.validateDate(DateValidatorI18N::Format::DMY, date, '.');
	test = date_validator.validateDate(DateValidatorI18N::Format::MDY, date, '.');
	// New test for YDM: fail
	test = date_validator.validateDate(DateValidatorI18N::Format::YDM, date, '.');

	date = "12-12-1999";
	// YMD: fail; DMY: pass; MDY: pass;
	test = date_validator.validateDate(DateValidatorI18N::Format::YMD, date, '-');
	test = date_validator.validateDate(DateValidatorI18N::Format::DMY, date, '-');
	test = date_validator.validateDate(DateValidatorI18N::Format::MDY, date, '-');
	// New test for YDM: fail
	test = date_validator.validateDate(DateValidatorI18N::Format::YDM, date, '-');

	date = "1999-12-12";
	// YMD: pass; DMY: fail; MDY: fail;
	test = date_validator.validateDate(DateValidatorI18N::Format::YMD, date, '-');
	test = date_validator.validateDate(DateValidatorI18N::Format::DMY, date, '-');
	test = date_validator.validateDate(DateValidatorI18N::Format::MDY, date, '-');
	// New test for YDM: pass
	test = date_validator.validateDate(DateValidatorI18N::Format::YDM, date, '-');

	return 0;
}