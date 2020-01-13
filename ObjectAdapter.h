#include <iostream>
#include <string>
#include <unordered_map>
#include <hash_map>

class A {
public:
    ~A() = default;
private:
    int d = 88;
};

class B: public A {

};

int main() {
    A a1;
    A* b1 = new B();

    std::hash<A> hash_f;
    std::cout << hash_f(a1) << std::endl;
    std::cout << hash_f(b1) << std::endl;

}
