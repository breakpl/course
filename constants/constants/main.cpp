//
//  main.cpp
//  constants
//
//  Created by Kalita, Dariusz on 22/11/2025.
//

#include <iostream>

int main(int argc, const char * argv[]) {

    int numberOfRooms {0};
    
    std::cout << "Wilkomen" << std::endl;
    std::cout << "how many rooms to clean? ";
    
    const double tax {0.06};
    const double roomPrice {30};
    
    std::cin >> numberOfRooms;
    
    std::cout << "\nEstimated cost" << std::endl;
    std::cout << "Number of rooms: " << numberOfRooms << std::endl;
    std::cout << "Price per room: " << 30 << std::endl;
    std::cout << "Cost: " << roomPrice * numberOfRooms << "$" << std::endl;
    std::cout << "tax: " << 0.06 * (roomPrice * numberOfRooms) << "$" << std::endl;
    std::cout << "Total: " << ((30 * numberOfRooms) * 0.06) + (30 * numberOfRooms) << "$" << std::endl;
    return EXIT_SUCCESS;
}
