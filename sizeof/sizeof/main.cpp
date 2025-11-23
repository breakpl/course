//
//  main.cpp
//  sizeof
//
//  Created by Darek Kalita on 22/11/2025.
//

#include <iostream>
#include <climits>

int main(int argc, const char * argv[]) {
    
    std::cout << "sizoef(int): " << sizeof(int) << std::endl;
    std::cout << "sizoef(char): " << sizeof(char) << std::endl;
    std::cout << "sizoef(short): " << sizeof(short) << std::endl;
    std::cout << "sizoef(long): " << sizeof(long) << std::endl;
    std::cout << "sizoef(long long): " << sizeof(long long) << std::endl;

    std::cout << "sizoef(float): " << sizeof(float) << std::endl;
    std::cout << "sizoef(double): " << sizeof(double) << std::endl;
    std::cout << "sizoef(long double): " << sizeof(long double) << std::endl;
    return 0;
    
}
