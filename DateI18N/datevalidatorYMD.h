#pragma once

#include <string>
#include "idatevalidator.h"

using namespace std;

class DateValidatorYMD : public IDateValidator
{
public:
	bool is_good(std::string const aDate, const delimiter aDelimter) const override;
};