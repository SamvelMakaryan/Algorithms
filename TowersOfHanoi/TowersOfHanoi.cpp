#include <iostream>

void towersOfHanoi(char a, char b, char c, int count) {
    if (count == 0) {
        return;
    }
    towersOfHanoi(a, c, b, count - 1);
    std::cout << a << "->" << c << std::endl;
    towersOfHanoi(b, a, c, count - 1);
}

void towersOfHanoi(int count) {
    std::cout << "The steps to solve is `" << std::endl;
    towersOfHanoi('A', 'B', 'C', count);
}

int main() {
    int count;
    do {
        std::cout << "Input positive count" << std::endl;
        std::cin >> count;
    } while(count <= 0);
    towersOfHanoi(count);
}