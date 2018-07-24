#include "datecontext.h"

void DateContext::setStrategy(IDateValidator* aStrategy) {
	this->dateStrategy_ = aStrategy;
}

bool DateContext::verifyDate(string aDate, char aDelimiter) {
	if (dateStrategy_ != nullptr)
		return dateStrategy_->is_good(aDate, aDelimiter);
	else
		return false;
}