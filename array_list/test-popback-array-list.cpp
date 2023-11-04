#include <iostream>
#include <chrono>
#include "array_list.hpp"


int main() {
    unsigned int n;
    std::cin >> n;
    array_list l1;
    std::cout << "Reading..." << std::endl;
    l1.clear();
    for (unsigned int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        l1.push_back(x);
    }

    std::cout << std::endl;
    std::cout << std::endl;
    auto beg = std::chrono::high_resolution_clock::now();
    for ( unsigned int i = 0; i < n; i++ )
        l1.pop_back();
    auto end = std::chrono::high_resolution_clock::now();

    //for ( unsigned int i = 0; i < l1.size(); i++ )
	//std::cout << l1.get_at(i) << " ";

    std::cout << std::endl;

    auto elapsed = end - beg;

    if (not (true)) {
        std::cerr << "[ERROR] check pop_front method!\n";
        exit(1);
    }
    std::cerr << "[INFO] " << "Elapsed time for "
        << n << " pop_front  success : "
        << elapsed.count() << std::endl;
    return 0;
}
