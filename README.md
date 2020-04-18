# Concurrent PFE Calculator
This is a simple PFE calculator for Udacity C++ Nanodegree Capstone Project.

## Compiling and Running

### Compiling
To compile the project, first, create a `build` directory and change to that directory:
```
mkdir build && cd build
```
From within the `build` directory, then run `cmake` and `make` as follows:
```
cmake ..
make
```
### Running
The executable will be placed in the `build` directory. From within `build`, you can run the project as follows:
```
./pfe_calculator
```
The program will ask for the location of **portfolio** and **market** data. Sample data is include.
```
Please provide portfolio filename (under data folder): portfolio
Please provide market date filename (under data folder): market
```

### Input file format
* **Portfolio** file: 
This file must contain inform for a portfolio of options. Each line represents an option. The information on each line must be as following (space in between):

stock_ticker option_type option_strike_price option_expiry notional

* **Market** data file:
This file must contain market data enough for market scenario generation and option pricing. First line is risk free rate and the following lines are stock vol like following (space in between):

risk_free_rate

stock1_ticker stock1_price stock1_vol

stock2_ticker stock2_price stock2_vol

## C++ Capstone Project Requirements Fullfilled

### Loops, Functions, I/O
1. Function, control structure and etc: it is everywhere
2. Read data from file: InputParser.cpp
3. Accept user inputs: main.cpp

### Object Oriented Programming
1. In Instruments.h and Instruments.cpp, Option class inherits from Instrument class that meets different requirements expect the last one about Templates.
2. Template function used in RiskSimulator class in RiskEngine.h

