#include "btree_map.h"

#include <iostream>
#include <cstdio>
#include <chrono>

int main()
{
    // std::chrono::high_resolution_clock clock;
    // auto start = clock.now();
    // freopen("0.in", "r", stdin);
    // freopen("0.out", "w", stdout);
    tlx::btree_map<int, int> Btree;
    int n, m, p, q;
    std::cin >> n >> m >> p >> q;
    int key, value;
    for (int i = 0; i < n; i++)
    {
        std::cin >> key >> value;
        Btree.insert2(key, value);
    }
    for (int i = 0; i < m; i++)
    {
        std::cin >> key;
        auto it = Btree.find(key);
        if (it != Btree.end())
            std::cout << it->second << std::endl;
        else
            std::cout << "NOT FOUND" << std::endl;
    }
    for (int i = 0; i < p; i++)
    {
        std::cin >> key >> value;
        Btree[key] = value;
    }
    int lvalue, rvalue;
    for (int i = 0; i < q; i++)
    {
        std::cin >> lvalue >> rvalue;
        auto lit = Btree.lower_bound(lvalue);
        auto rit = Btree.upper_bound(rvalue);
        int counter = 0;
        for (auto it = lit; it != rit; it++)
        {
            counter++;
        }
        std::cout << counter << std::endl;
    }
    // auto end = clock.now();
    // freopen("/dev/tty", "r", stdin);
    // freopen("/dev/tty", "w", stdout);
    // std::cout << "time = " << std::chrono::duration_cast<std::chrono::seconds>(end - start).count() << " s" << std::endl;
    return 0;
}