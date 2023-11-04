#include <iostream>
#include <chrono>
#include <random>
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
    unsigned int removed = 0, not_removed = 0;

    //std::cout << std::endl << "before remove_at" << std::endl;
    auto beg = std::chrono::high_resolution_clock::now(); // inicio da contagem do tempo
    if (l1.remove(m))
        removed++;
    else
        not_removed++;
    auto end = std::chrono::high_resolution_clock::now(); // fim da contagem do tempo

    auto elapsed = end - beg;
    std::cerr << "[DEBUG] Tried to remove number " << m << " element\n";
    std::cerr << "[DEBUG] removed " << removed << " element(s)\n";
    std::cerr << "[DEBUG] not removed " << not_removed << " element(s)\n";
    if (not (l1.size() == n - removed)) {
        std::cerr << "[ERROR] check remove method!\n";
        exit(1);
    }
    std::cerr << "[INFO] " << "Elapsed time for "
        << removed << " remove success : "
        << elapsed.count() << std::endl;
    return 0;
}
