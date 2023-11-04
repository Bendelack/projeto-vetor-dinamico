#include <iostream>
#include <chrono>
#include "linked_list.hpp"


int main() {
    unsigned int n;
    std::cin >> n;
    linked_list l1;
    std::cout << "Reading..." << std::endl;
    l1.clear();
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
