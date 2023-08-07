// Code example from Refactoring Guru
// Code example modified to avoid the 'new' and 'delete'
// Link: https://refactoring.guru/design-patterns/adapter/cpp/example#example-0

#include <iostream>
#include <algorithm> // std::reverse
#include <memory> // smart pointers

/**
 * This is the Target class, which represents the interface your code understands.
 */ 
class Target
{
public:
    virtual ~Target() = default;
    
    virtual std::string request() const
    {
        return "Target: The default target's behavior.";
    }
};

/**
 * The Adaptee contains some useful behavior, but its interface is incompatible
 * with the existing client code. The Adaptee needs some adaptation before the
 * client code can use it.
 */
class Adaptee
{
public:
    std::string specificRequest()
    {
        return ".eetpadA eht fo roivaheb laicepS";
    }
};

/**
 * The Adapter makes the Adaptee's interface compatible with the Target's
 * interface.
 */
class Adapter : public Target
{
public:
    // Adapter(Adaptee* adaptee) : m_adaptee(adaptee) {}
    Adapter(std::unique_ptr<Adaptee> adaptee) : m_adaptee(std::move(adaptee)) {}

    std::string request() const override
    {
        std::string to_reverse = this->m_adaptee->specificRequest();
        std::reverse(to_reverse.begin(), to_reverse.end());
        return "Adapter: (TRANSLATED) " + to_reverse;
    }

private:
    // Adaptee* m_adaptee;
    std::unique_ptr<Adaptee> m_adaptee;
};

class Client
{
public:
    void code(const Target *target)
    {
        std::cout << target->request();
    }
};

int main(int argc, char **argv)
{
    Client client;
    std::cout << "Client: I can work just fine with the Target objects:\n";
    // Target *target = new Target;
    std::unique_ptr<Target> target = std::make_unique<Target>();
    client.code(target.get());
    std::cout << "\n\n";

    // Adaptee *adaptee = new Adaptee;
    std::unique_ptr<Adaptee> adaptee = std::make_unique<Adaptee>();
    std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
    std::cout << "Adaptee: " << adaptee->specificRequest();
    std::cout << "\n\n";
    std::cout << "Client: But I can work with it via the Adapter:\n";
    
    // Adapter *adapter = new Adapter(adaptee);
    std::unique_ptr<Adapter> adapter = std::make_unique<Adapter>(std::move(adaptee));
    client.code(adapter.get());
    std::cout << "\n";

    // delete target;
    // delete adaptee;
    // delete adapter;

    std::cout << "\n";
    return 0;
}