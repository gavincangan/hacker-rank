
#include <iostream>
#include <string>
#include <memory>

class Person
{
std::string name_;
public:
Person(const std::string& name) : name_(name)
{
std::cout << "ctor::" << name_ << std::endl;
}

~Person()
{
    std::cout << "dtor::" << name_ << std::endl;
}
    std::shared_ptr<Person> best_friend;
};

void makeFriends(std::shared_ptr<Person> a, std::shared_ptr<Person> b)
{
a->best_friend = b;
b->best_friend = a;
}
int main(int argc, char** argv)
{
    std::cout << "start" << std::endl;
    try
    {
    auto a = std::make_shared<Person>("a");
    auto b = std::make_shared<Person>("b");
    makeFriends(a,b);
    }catch(...)
    {
    std::cout << "exception" << std::endl;
    }
    std::cout << "end" << std::endl;
    return 0;
}