#include <iostream>
#include <memory>
class Member {
public:
Member() {
std::cout << "Member::ctor" << std::endl;
throw "Exception";
}
~Member() {
std::cout << "Member::dtor" << std::endl;
}
};

class Base {
public:
Base() {
std::cout << "Base::ctor" << std::endl;
}
virtual ~Base() {
std::cout << "Base::dtor" << std::endl;
}
};
class Derived : public Base {
Member* m_;
public:
Derived() : m_(new Member()) {
std::cout << "Derived::ctor" << std::endl;
}
~Derived() {
if(m_) delete m_;
std::cout << "Derived::dtor" << std::endl;
}
};
int main(int argc, char** argv) {
    try
    {
        std::unique_ptr<Base> b = std::make_unique<Derived>();
        std::cout << "No Exception" << std::endl;
    }
    catch(...)
    {
        std::cout << "Exception" << std::endl;
    }
}