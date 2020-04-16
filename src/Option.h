#ifndef OPTION_H
#define OPTION_H

#include <string>

// Equity European Option class
class Option
{
    public:
        enum OptionType {call, put};
        Option(std::string ticker, OptionType optionType, double strike, double expiry);
        std::string getUnderlyingName() const;
        bool isExpired(double t) const; // Check whether the option is expired at time t
        double NPV(double t, double stockPrice, double riskFreeRate) const; // Calculate NPV of the option

    private:
        std::string _tiker;
        OptionType _type;
        double _strike;
        double _expiry; // Number of years from today to expiration date of the option
        double _vol;
};

#endif