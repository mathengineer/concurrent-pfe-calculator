#ifndef RISK_ENGINE_H
#define RISK_ENGINE_H

#include <vector>
#include <set>
#include <string>
#include <iostream>

#include "MarketData.h"

class RiskSimulator
{
    public:
        RiskSimulator() {}
        RiskSimulator(MarketData initialMarketData);
        // Let's do some template functions for fun
        // Template function to trim down the _initialMarketData to only these relevant to contracts
        template<typename T> void checkMarketData(std::vector<T> &contracts) const;
        template<typename T> void trimMarketData(std::vector<T> &contracts);  

    private:
        MarketData _initialMarketData;
};

// Have to keep implementation of template function in header file
// https://stackoverflow.com/questions/10632251/undefined-reference-to-template-function
template<typename T> void RiskSimulator::checkMarketData(std::vector<T> &contracts) const
{
    for (const auto &contract : contracts)
    {
        if(_initialMarketData.prices.find(contract.getUnderlyingName())
        == _initialMarketData.prices.end()) 
        {
            throw std::runtime_error("Missing martket data for " + contract.getUnderlyingName() + "!");
        }
    }
}

template<typename T> void RiskSimulator::trimMarketData(std::vector<T> &contracts)
{
    // First check whether all market data needed are in _marketDataTrimed
    checkMarketData(contracts);

    // Get all underlyings that are used for contracts
    std::set<std::string> underlyings;
    for (const auto &contract : contracts)
    {
        underlyings.emplace(contract.getUnderlyingName());
    }

    // Trim market data. Both prices and vols covers the same kind of underlyings.    
    for (auto it=_initialMarketData.prices.begin(); 
    it!=_initialMarketData.prices.end(); ++it)
    {
        if (underlyings.find(it->first)==underlyings.end())
        {
            std::cout << "Delete " << it->first << " price!" << std::endl;
            _initialMarketData.prices.erase(it);
        }
    }

    for (auto it=_initialMarketData.vols.begin(); 
    it!=_initialMarketData.vols.end(); ++it)
    {
        if (underlyings.find(it->first)==underlyings.end())
        {
            std::cout << "Delete " << it->first << " vol!" << std::endl;
            _initialMarketData.vols.erase(it);
        }
    }
}

#endif