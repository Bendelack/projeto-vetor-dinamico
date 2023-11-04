#include <iostream>
#include <chrono>
#include "linked_list.hpp"


int main() {
    unsigned int n;
    unsigned int ind;
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
    for (unsigned int i = 0; i < n; ++i) {
	ind = l1.size()/2;
        l1.remove_at(ind);
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << std::endl;
    std::cout << std::endl;

    //for ( unsigned int i = 0; i < l1.size(); i++ )
	//std::cout << l1.get_at(i) << " ";

    std::cout << std::endl;

    auto elapsed = end - beg;

    if (not (l1.size() == 0)) {
        std::cerr << "[ERROR] check remove_at method!\n";
        exit(1);
    }
    std::cerr << "[INFO] " << "Elapsed time for "
        << n << " remove_at  success : "
        << elapsed.count() << std::endl;
    return 0;
}
