#include "entity/strategies/strategy.h"

Strategy::Strategy(/* args */)
{
};

Strategy::~Strategy()
{
};

std::vector<Strategy*> emptyStrHdl(){
    std::vector<Strategy*> strategyHandler;
    for (int i = 0; i < NB_STRATEGY; i++)
    {
        strategyHandler.push_back(nullptr);
    }
    return strategyHandler;
}
