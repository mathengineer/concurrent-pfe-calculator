#ifndef MARKET_DATA_H
#define MARKET_DATA_H

#include <string>
#include <unordered_map>

class MarketData
{
    public:
        // Copy construct
        MarketData(const MarketData &source);
        // Copy assignment
        MarketData &operator=(const MarketData &source);
        // Default construct and destructor
        MarketData() {}
        ~MarketData() {}
        double riskFreeRate;
        std::unordered_map<std::string, double> vols;
        std::unordered_map<std::string, double> prices;
};

#endif