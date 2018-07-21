#include "context.h"

void Context::setStrategy(Strategy* aStrategy) {
	this->strategy_ = aStrategy;
}

void Context::ContextInterface() {
	if (strategy_ != nullptr)
		strategy_->AlgorithmInterface();
}