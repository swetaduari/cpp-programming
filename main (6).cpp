#include <iostream>
using namespace std;


class Adder {
public:
    int add(int a, int b) {
        

        return a + b;
    }
};


class Subtractor {
public:
    int subtract(int a, int b) {
        
        return a - b;
    }
};


class Calculator : public Adder, public Subtractor {
public:

};

int main() {
    Calculator calc;

    int sum = calc.add(10, 5);
    std::cout << "Addition: " << sum << std::endl; 
    int difference = calc.subtract(10, 5);
    std::cout << "Subtraction: " << difference << std::endl; 
    return 0;
}