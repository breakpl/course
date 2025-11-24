//
//  main.cpp
//  vectors
//
//  Created by Kalita, Dariusz on 23/11/2025.
//

#include <iostream>

int main(int argc, const char * argv[]) {

//    std::vector<int> test_vector {};
//    int newValue {};
//
//    for(int i=0; i < 5; i++) {
//        std::cout << i << "#: ";
//        std::cin >> newValue;
//        test_vector.push_back(newValue);
//        test_vector.at(10) = 12;
//    }
//
//    std::cout << "vector: ";
//    for (int i=0; i < test_vector.size(); i++) {
//        std::cout << test_vector.at((i));
//    }
//    std::cout << "\nsize: " << sizeof(test_vector) << std::endl;
    
  
    std::vector<int> vector1, vector2;
    std::vector <std::vector<int>> vector2d;
    
    vector1.push_back(10);
    vector1.push_back(20);

    for (int i=0; i < vector1.size(); i++) {
        std::cout << vector1.at(i) << std::endl;
    }
    
    vector2.push_back(100);
    vector2.push_back(900);

    for (int i=0; i < vector2.size(); i++) {
        std::cout << vector2.at(i) << std::endl;
    }
    
    vector2d.push_back(vector1);
    vector2d.push_back(vector2);
    
    std::cout << vector2d.size() << std::endl;
    for (int s=0; s < vector2d.size(); s++) {
        for (int i=0; i < vector2d[s].size(); i++) {
            std::cout << vector2d[s].at(i) << std::endl;
        }
    }
    return EXIT_SUCCESS;
}
