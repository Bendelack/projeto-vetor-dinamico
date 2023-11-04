#include <iostream>
#include <chrono>
#include "linked_list.hpp"


int main() {
    unsigned int n;
    std::cin >> n;
    linked_list l1;
    std::cout << "Reading..." << std::endl;
    l1.clear();
    for (unsigned int i = 0; i < n; ++i){
        int x;
        std::cin >> x;
        l1.push_back(x);
    }


    std::cout << std::endl;
    std::cout << std::endl;
    int soma = 0;
    int ind = n/2;
    //for ( unsigned int i = 0; i < l1.size(); i++ )
	//soma += l1.get_at(i);
    auto beg = std::chrono::high_resolution_clock::now();
    std::cout << l1.get_at(ind) << "\n";
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = end - beg;

    std::cout << std::endl;


    if (not (l1.size() == n)) {
        std::cerr << "[ERROR] check get_at method!\n";
        exit(1);
    }
    std::cerr << "[INFO] " << "Elapsed time for "
        << n << " get_at  success : "
        << elapsed.count() << std::endl;
    return 0;
}
