//
//  main.cpp
//  roomcalc
//
//  Created by Kalita, Dariusz on 21/11/2025.
//

#include <iostream>

int main(int argc, const char * argv[]) {

    int roomWidth {0};
    int roomLenght {0};

    std::string dupa = "";
    
    std::cout << "Enter width of the room: ";
    std::cin >> roomWidth;
    std::cout << "Enter lenght of the room: ";
    std::cin >> roomLenght;
    
    std::cout << "The area of the room is: " << roomWidth * roomLenght << "sq feet." << std::endl;
        
    double a = 0.1 + 0.2001;
//    double a = 0.1 + 0.2000000000001; eq
    double b = 0.3;

    if (fabs(a - b) < 1e-9) {  // Check if the difference is within a small epsilon
        std::cout << "a and b are approximately equal" << std::endl;
    } else {
        std::cout << "a and b are not equal" << std::endl;
    }


    return 0;
    
    return EXIT_SUCCESS;
}
