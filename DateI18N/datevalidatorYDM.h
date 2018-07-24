#pragma once

#include <string>
#include "idatevalidator.h"

using namespace std;

class DateValidatorYDM : public IDateValidator
{
public:
	bool is_good(std::string const aDate, const delimiter aDelimter) const override;
};