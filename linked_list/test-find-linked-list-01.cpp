#include <iostream>
#include <chrono>
#include <random>
#include "linked_list.hpp"


int main() {
    unsigned int n;
    std::cin >> n;
    linked_list l1;
    std::cout << "Reading..." << std::endl;
    for (unsigned int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        l1.push_back(x);
    }

    //int m = 1;
    std::string zero;
    std::random_device rd;
    std::mt19937 mt(rd());
    //std::cout << n << "\n";
    std::uniform_int_distribution<> dist(1, n*2);
    //for (int i=0 ; i<n ; ++i)
    int ind = n/2;
    int m = l1.get_at(ind);

    std::cout << m << std::endl;

    //std::cout << std::endl << "before remove_at" << std::endl;
    auto beg = std::chrono::high_resolution_clock::now(); // inicio da contagem do tempo
    std::cout << l1.find(m) << "\n";
    auto end = std::chrono::high_resolution_clock::now(); // fim da contagem do tempo

    auto elapsed = end - beg;
    std::cerr << "[DEBUG] Tried to find number " << m << " element\n";
    if (not (m)) {
        std::cerr << "[ERROR] check find method!\n";
        exit(1);
    }
    std::cerr << "[INFO] " << "Elapsed time for "
        << m << " find success : "
        << elapsed.count() << std::endl;
    return 0;
}
