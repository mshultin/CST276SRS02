// GoF Strategy design pattern (Page: 349)
//

#include "datecontext.h"
#include "datevalidatorDMY.h"
#include "datevalidatorMDY.h"
#include "datevalidatorYDM.h"
#include "datevalidatorYMD.h"

int main()
{
	DateContext date_validator;
	DateValidatorYMD validateYMD;
	DateValidatorDMY validateDMY;
	DateValidatorMDY validateMDY;
	DateValidatorYDM validateYDM;


	string date{ "" };
	bool test{ false };

	date = "2200-12-31";
	// YMD: fail; DMY: fail; MDY: fail
	date_validator.setStrategy(&validateYMD);
	test = date_validator.verifyDate(date, '-');
	date_validator.setStrategy(&validateDMY);
	test = date_validator.verifyDate(date, '-');
	date_validator.setStrategy(&validateMDY);
	test = date_validator.verifyDate(date, '-');
	// New test for YDM: fail
	date_validator.setStrategy(&validateYDM);
	test = date_validator.verifyDate(date, '-');

	date = "2100-12-31";
	// YMD: pass; DMY: fail; MDY: fail
	date_validator.setStrategy(&validateYMD);
	test = date_validator.verifyDate(date, '-');
	date_validator.setStrategy(&validateDMY);
	test = date_validator.verifyDate(date, '-');
	date_validator.setStrategy(&validateMDY);
	test = date_validator.verifyDate(date, '-');
	// New test for YDM: fail
	date_validator.setStrategy(&validateYDM);
	test = date_validator.verifyDate(date, '-');

	date = "28/2/2019";
	// YMD: fail; DMY: pass; MDY: fail
	date_validator.setStrategy(&validateYMD);
	test = date_validator.verifyDate(date, '/');
	date_validator.setStrategy(&validateDMY);
	test = date_validator.verifyDate(date, '/');
	date_validator.setStrategy(&validateMDY);
	test = date_validator.verifyDate(date, '/');
	// New test for YDM: fail
	date_validator.setStrategy(&validateYDM);
	test = date_validator.verifyDate(date, '/');

	date = "12/30/2019";
	// YMD: fail; DMY: fail; MDY: pass
	date_validator.setStrategy(&validateYMD);
	test = date_validator.verifyDate(date, '/');
	date_validator.setStrategy(&validateDMY);
	test = date_validator.verifyDate(date, '/');
	date_validator.setStrategy(&validateMDY);
	test = date_validator.verifyDate(date, '/');
	// New test for YDM: fail
	date_validator.setStrategy(&validateYDM);
	test = date_validator.verifyDate(date, '/');

	date = "2.27.2059";
	// YMD: fail; DMY: fail; MDY: pass
	date_validator.setStrategy(&validateYMD);
	test = date_validator.verifyDate(date, '.');
	date_validator.setStrategy(&validateDMY);
	test = date_validator.verifyDate(date, '.');
	date_validator.setStrategy(&validateMDY);
	test = date_validator.verifyDate(date, '.');
	// New test for YDM: fail
	date_validator.setStrategy(&validateYDM);
	test = date_validator.verifyDate(date, '.');

	date = "2.29.2059";
	// YMD: fail; DMY: fail; MDY: fail (non-leap year)
	date_validator.setStrategy(&validateYMD);
	test = date_validator.verifyDate(date, '.');
	date_validator.setStrategy(&validateDMY);
	test = date_validator.verifyDate(date, '.');
	date_validator.setStrategy(&validateMDY);
	test = date_validator.verifyDate(date, '.');
	// New test for YDM: fail
	date_validator.setStrategy(&validateYDM);
	test = date_validator.verifyDate(date, '.');

	date = "2.29.2020";
	// YMD: fail; DMY: fail; MDY: pass (leap year)
	date_validator.setStrategy(&validateYMD);
	test = date_validator.verifyDate(date, '.');
	date_validator.setStrategy(&validateDMY);
	test = date_validator.verifyDate(date, '.');
	date_validator.setStrategy(&validateMDY);
	test = date_validator.verifyDate(date, '.');
	// New test for YDM: fail
	date_validator.setStrategy(&validateYDM);
	test = date_validator.verifyDate(date, '.');

	date = "12-12-1999";
	// YMD: fail; DMY: pass; MDY: pass;
	date_validator.setStrategy(&validateYMD);
	test = date_validator.verifyDate(date, '-');
	date_validator.setStrategy(&validateDMY);
	test = date_validator.verifyDate(date, '-');
	date_validator.setStrategy(&validateMDY);
	test = date_validator.verifyDate(date, '-');
	// New test for YDM: fail
	date_validator.setStrategy(&validateYDM);
	test = date_validator.verifyDate(date, '-');

	date = "1999-12-12";
	// YMD: pass; DMY: fail; MDY: fail;
	date_validator.setStrategy(&validateYMD);
	test = date_validator.verifyDate(date, '-');
	date_validator.setStrategy(&validateDMY);
	test = date_validator.verifyDate(date, '-');
	date_validator.setStrategy(&validateMDY);
	test = date_validator.verifyDate(date, '-');
	// New test for YDM: pass
	date_validator.setStrategy(&validateYDM);
	test = date_validator.verifyDate(date, '-');

	return 0;
}