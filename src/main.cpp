#include <iostream>
#include <string>

int main() 
{

    std::cout << "Please provide portfolio filename (under data folder): ";
    std::string portfolioFilename;
    std::cin >> portfolioFilename;
    std::cout << "Please provide market date filename (under data folder): ";
    std::string marketFilename;
    std::cin >> marketFilename;
    std::cout << "Hello World!" << "\n";
    return 0;
}