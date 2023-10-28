#include <iostream>
#include <chrono>
#include "array_list.hpp"

int main() {
    unsigned n;
    std::cin >> n;
    array_list l1;
    auto beg = std::chrono::high_resolution_clock::now();
    for (unsigned int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        l1.push_front(x);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = end - beg;
    if (not (l1.size() == n)) {
        std::cerr << "[ERROR] check push_front method!\n";
        exit(1);
    }
    std::cerr << "[INFO] " << "Elapsed time for "
        << n << " pushes front :"
        << elapsed.count() << std::endl;

    std::cout << l1.percent_occupied() << std::endl;
    // for (unsigned int i = 0; i < l1.size(); ++i)
    //     std::cout << i << " -> " << l1.get_at(i) << " ";
    // std::cout << "}";

    // l1.insert_at(6, 13);
    std::cout << std::endl;
    
    std::cout << std::endl;

    std::cout << "Fim algoritmo" << std::endl;
    return 0;
}