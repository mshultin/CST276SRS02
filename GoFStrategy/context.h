#pragma once
#include "strategy.h"

class Context {
public:
	void setStrategy(Strategy*);
	void ContextInterface();

private:
	Strategy * strategy_{nullptr};
};