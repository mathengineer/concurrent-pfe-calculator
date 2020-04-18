#include "MarketData.h"

MarketData::MarketData(const MarketData &source) : riskFreeRate(source.riskFreeRate)
{
    
    for (auto it=source.prices.begin(); it!=source.prices.end(); ++it)
    {
        prices[it->first] = it->second;
    }

    for (auto it=source.vols.begin(); it!=source.vols.end(); ++it)
    {
        vols[it->first] = it->second;
    }
}

MarketData &MarketData::operator=(const MarketData &source)
{
    if (this == &source) return *this;
    
    riskFreeRate = source.riskFreeRate;
    for (auto it=source.prices.begin(); it!=source.prices.end(); ++it)
    {
        prices[it->first] = it->second;
    }

    for (auto it=source.vols.begin(); it!=source.vols.end(); ++it)
    {
        vols[it->first] = it->second;
    }
    return *this;
}