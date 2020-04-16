#include <cmath>
#include "Option.h"

Option::Option(std::string ticker, OptionType optionType, 
double strike, double expiry, double vol) :
_ticker(ticker), _type(optionType), 
_strike(strike), _expiry(expiry), _vol(vol) {}

std::string Option::getUnderlyingName() const
{
    return _ticker;
}

bool Option::isExpired(double t) const
{
    return t >= _expiry;
}

double normalCDF(double x) // N(x)
{
    return std::erfc(-x/std::sqrt(2))/2;
}

double Option::NPV(double t, double stockPrice, double riskFreeRate) const
{
    if (isExpired(t))
    {
        return 0.0;
    }
    else
    {
        // Classical Black Scholes formula for option pricing assuming no dividend for the stock
        // See https://en.wikipedia.org/wiki/Black%E2%80%93Scholes_model
        const double d1 = 1 / (_vol * std::sqrt(_expiry-t)) * 
        (std::log(stockPrice/_strike) + (riskFreeRate + std::pow(_vol, 2)/2) * (_expiry-t));
        const double d2 = d1 - _vol * std::sqrt(_expiry-t);
        if (_type == call)
        {
            return normalCDF(d1) * stockPrice 
            - normalCDF(d2) * _strike * std::exp(-riskFreeRate*(_expiry-t));
        }
        else
        {
            return normalCDF(-d2) * _strike * std::exp(-riskFreeRate*(_expiry-t))
            normalCDF(-d1) * strockPrice;
        }
    }
}