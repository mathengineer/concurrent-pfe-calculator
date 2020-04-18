#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "InputParser.h"
#include "Instruments.h"
#include "MarketData.h"

int main() 
{

    std::cout << "Please provide portfolio filename (under data folder): ";
    std::string portfolioFilename;
    std::cin >> portfolioFilename;
    std::vector<Option> portfolio;
    InputParser::readPortfolio(portfolioFilename, portfolio);

    std::cout << "Please provide market date filename (under data folder): ";
    std::string marketFilename;
    std::cin >> marketFilename;
    MarketData marketData;
    InputParser::readMarketData(marketFilename, marketData);
    
    for (Option &option : portfolio)
    {
        option.setMarket(marketData);
        std::cout << option.getTradeInfo() << " price = " 
        << std::setprecision(2) << std::fixed
        << option.NPV(0, marketData.stockPrices[option.getUnderlyingName()]) 
        << " when current stock price is " << marketData.stockPrices[option.getUnderlyingName()] 
        << std::endl; 
    }

    return 0;
}