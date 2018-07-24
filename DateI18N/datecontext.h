#pragma once

#include "idatevalidator.h"

class DateContext {
public:
	void setStrategy(IDateValidator*);
	bool verifyDate(string, char);

private:
	IDateValidator * dateStrategy_{ nullptr };
};