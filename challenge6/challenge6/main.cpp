//
//  main.cpp
//  challenge6
//
//  Created by Kalita, Dariusz on 23/11/2025.
//

#include <iostream>

int main(int argc, const char * argv[]) {

    int smallRommsCount {0};
    int largeRommsCount {0};
    int customerCost {0};
    const int smallRoomPrice {25};
    const int largeRoomPrice {35};
    const double saleTax {.06};
    const int offerDays {30};
    
    std::cout << "Wilkomen" << std::endl;
    std::cout << "# of small rooms ($25 each): ";
    std::cin >> smallRommsCount;
    std::cout << "# of large rooms ($35 each: ";
    std::cin >> largeRommsCount;

    customerCost = (smallRommsCount * smallRoomPrice) + (largeRommsCount * largeRoomPrice);
    
    std::cout << std::endl << "Cost: " << customerCost << "$" <<  std::endl;
    std::cout << std::endl << "Tax: " << saleTax * customerCost << "$" << "\n" <<  std::endl;
    std::cout << std::endl << "Total: " << (saleTax * customerCost) + customerCost << "$" <<  std::endl;
    std::cout << "The offer is valid for " << offerDays << " days from now." << std::endl;
    
    return EXIT_SUCCESS;
}
