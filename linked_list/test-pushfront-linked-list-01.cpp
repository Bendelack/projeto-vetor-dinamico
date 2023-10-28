#include <iostream>
#include <chrono>
#include "linked_list.hpp"

int main() {
    int n;
    std::cin >> n;
    linked_list l1;
    auto beg = std::chrono::high_resolution_clock::now();
    for ( int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        // l1.push_front(x);
        l1.push_back(x);
    }



    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = end - beg;
    if (not (l1.size() == n)) {
        std::cerr << "[ERROR] check push_front method!\n";
        exit(1);
    }

    l1.insert_at(1, 4);
    //     std::cout << "insertiu" << std::endl;
    // else
    //     std::cout << "não insertiu" << std::endl;

    for (int i = 0; i < n; ++i) {
        std::cout << l1.get_at(i) << " ; ";
    }
    std::cerr << "[INFO] " << "Elapsed time for "
        << n << " pushes front :"
        << elapsed.count() << std::endl;
    return 0;
}