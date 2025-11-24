//
//  main.cpp
//  challenge74
//
//  Created by Kalita, Dariusz on 24/11/2025.
//

#include <iostream>

int main(int argc, const char * argv[]) {

    const int dollar {100};
    const int quarter {25};
    const int dime {10};
    const int nickel {5};
    const int penny {1};
    int amount {};
    int remainingAmount {};
    int numDollar {}, numQuarter {}, numDime {}, numNickel {}, numPenny {};
    std::cout << "Enter an amount in cents: ";
    std::cin >> amount;
    remainingAmount = amount;
    numDollar = remainingAmount / dollar;
    remainingAmount = remainingAmount % dollar;
    numQuarter = remainingAmount / quarter;
    remainingAmount = remainingAmount % quarter;
    numDime = remainingAmount / dime;
    remainingAmount = remainingAmount % dime;
    numNickel = remainingAmount / nickel;
    remainingAmount = remainingAmount % nickel;
    numPenny = remainingAmount / penny;
    remainingAmount = remainingAmount % penny;
    std::cout << "Your amount " << amount << " consists of \n"
                << numDollar << " dollars\n"
                << numQuarter << " quarters\n"
                << numDime << " dimes\n"
                << numNickel << " nickels\n"
                << numPenny << " pennies\n";  return EXIT_SUCCESS;
    
}
