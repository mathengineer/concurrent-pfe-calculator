#ifndef MARKET_DATA_H
#define MARKET_DATA_H

#include <string>
#include <unordered_map>

struct MarketData
{
    double riskFreeRate;
    std::unordered_map<std::string, double> stockVols;
    std::unordered_map<std::string, double> stockPrices;
};

#endif