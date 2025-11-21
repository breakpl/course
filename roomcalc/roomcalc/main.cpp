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
    std::cout << roomLenght;
    
    std::cout << "The area of the room is: " << roomWidth * roomLenght << "sq feet." << std::endl;
    return EXIT_SUCCESS;
}
