#include <iostream>
#include <chrono>
#include "array_list.hpp"


int main() {
    unsigned int n;
    std::cin >> n;
    array_list l1;
    std::cout << "Reading..." << std::endl;
    for (unsigned int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        l1.push_back(x);
    }
    auto beg = std::chrono::high_resolution_clock::now();

    int soma = l1.sum();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << soma << std::endl; // show sum
    std::cout << std::endl;
    std::cout << std::endl;
    

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = end - beg;

    if (not (soma)) {
        std::cerr << "[ERROR] check sum method!\n";
        exit(1);
    }
    std::cerr << "[INFO] " << "Elapsed time for "
        << n << " sum success : "
        << elapsed.count() << std::endl;
    return 0;
}
