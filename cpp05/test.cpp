#include <iostream>

class Test {
private:
    int n = 0;  // default value

public:
    int getNum() const {
        return n;
    }

    void setNum(int value) {
        n = value;
    }

    Test operator+(const Test& t) const {
        Test result;    // default object
        result.n = n + t.n;  // add values manually
        return result;  // safe return by value
    }
};

int main() {
    Test t1, t2;
    t1.setNum(3);
    t2.setNum(5);

    Test t3 = t1 + t2;
    std::cout << "--> " << t3.getNum() << std::endl; // --> 8

    return 0;
}
