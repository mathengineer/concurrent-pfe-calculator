# Concurrent PFE Calculator

## Input file format
* Portfolio file: 
This file must contain inform for a portfolio of options. Each line represents an option. The information on each line must be as following (space in between):
stock_ticker option_type option_strike_price option_expiry stock_vol
* Market data file:
This file must contain market data enough for market scenario generation and option pricing. First line is risk free rate and the following lines are stock vol like following (space in between):
risk_free_rate
stock_ticker1 stock_vol1
stock_ticker2 stock_vol2