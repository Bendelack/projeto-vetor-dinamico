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
    int elemento = l1.get_at(0);
    auto beg = std::chrono::high_resolution_clock::now();

    int contador = l1.count(elemento);
    std::cout << elemento << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << contador << std::endl; // show sum
    std::cout << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = end - beg;

    if (not (contador)) {
        std::cerr << "[ERROR] check count method!\n";
        exit(1);
    }
    std::cerr << "[INFO] " << "Elapsed time for "
        << n << " count success : "
        << elapsed.count() << std::endl;
    return 0;
}
