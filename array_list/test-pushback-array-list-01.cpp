#include <iostream>
#include <chrono>
#include "array_list.hpp"

int main() {
    int n;
    std::cin >> n;
    array_list l1;
    auto beg = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        l1.push_back(x);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = end - beg;
    if (not (l1.size() == n)) {
        std::cerr << "[ERROR] check push_front method!\n";
        exit(1);
    }
    std::cerr << "[INFO] " << "Elapsed time for "
        << n << " pushes back :"
        << elapsed.count() << std::endl;

    std::cout << std::endl;
    /*std::cout << "{ ";
    for (unsigned int i = 0; i < l1.size(); ++i)
        std::cout << "[" << i << "]=" << l1.get_at(i) << " ";
    std::cout << "}";*/

    /*l1.insert_at(3, 13);
    l1.insert_at(3, 13);
    l1.insert_at(3, 13);
    l1.push_front(13);
    l1.push_back(13);
    l1.push_back(13);
    l1.pop_back();
    l1.pop_front();
    l1.remove(13);
    std::cout << l1.front() << " " << l1.back() << " " << l1.count(13) << l1.sum() << l1.find(13) << std::endl;
    std::cout << std::endl;
    std::cout << "{ ";
    for (unsigned int i = 0; i < l1.size(); ++i)
        std::cout << "[" << i << "]=" << l1.get_at(i) << " ";
    std::cout << "}";*/
    
    std::cout << std::endl;

    std::cout << "Fim algoritmo" << std::endl;
    return 0;
}
