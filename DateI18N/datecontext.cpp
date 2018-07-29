// GoF Strategy design pattern (Page: 349)

#include "datecontext.h"

/******************************
setStrategy
Params: IDateValidator*
Returns:
******************************/
void DateContext::setStrategy(IDateValidator* aStrategy) {
	this->dateStrategy_ = aStrategy;
}

/******************************
verifyDate
Params: string, char
Returns: bool
******************************/
bool DateContext::verifyDate(string aDate, char aDelimiter) {
	if (dateStrategy_ != nullptr)
		return dateStrategy_->is_good(aDate, aDelimiter);
	else
		return false;
}