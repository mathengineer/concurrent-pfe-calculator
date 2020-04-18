#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "InputParser.h"
#include "Instruments.h"
#include "MarketData.h"
#include "RiskEngine.h"

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
    
    // Load the market data and validate the pricing
    for (Option &option : portfolio)
    {
        option.setMarket(marketData);
        // Validate the input and the pricing
        std::cout << option.getTradeInfo() << " price = " 
        << std::setprecision(2) << std::fixed
        << option.calculatePV(0, marketData.prices[option.getUnderlyingName()], 0.000000001, 0.0) 
        << " when current stock price is " << marketData.prices[option.getUnderlyingName()] 
        << " and zero vol and zero risk free rate." << std::endl; 
    }

    RiskSimulator riskSimulator(marketData);
    riskSimulator.template trimMarketData<Option> (portfolio);

    return 0;
}