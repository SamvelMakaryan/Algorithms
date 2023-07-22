#include "MRU.hpp"

int main() {
    MRU<int> cache(3);
    cache.add(4);
    cache.add(3);
    cache.add(1);
    cache.add(25);
    cache.display();
    cache.get(3);
    cache.display();
}