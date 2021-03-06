// GoF Strategy pattern (Page: 349)

#include "context.h"
#include "concretestrategyA.h"
#include "concretestrategyB.h"
#include "concretestrategyC.h"

int main()
{
	ConcreteStrategyA strategyA_;
	ConcreteStrategyB strategyB_;
	ConcreteStrategyC strategyC_;
	Context context_;

	context_.setStrategy(&strategyA_);
	context_.ContextInterface();
	context_.setStrategy(&strategyB_);
	context_.ContextInterface();
	context_.setStrategy(&strategyC_);
	context_.ContextInterface();

	return 0;
}

