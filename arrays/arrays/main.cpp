//
//  main.cpp
//  arrays
//
//  Created by Kalita, Dariusz on 23/11/2025.
//

#include <iostream>

int main(int argc, const char * argv[]) {

    char vowels[] {'i','o','w','a'};
    int dupa{};
    
    std::cout << vowels[0];
    std::cout << vowels[3];
    std::cout << std::endl;
    std::cin >> vowels[4];
    
    std::cout << "\n\n" << vowels << std::endl;
//    std::cout << "\n\n" << vowels << std::endl;
    std::cout << "\n\n" << dupa << std::endl;
    return EXIT_SUCCESS;
}
