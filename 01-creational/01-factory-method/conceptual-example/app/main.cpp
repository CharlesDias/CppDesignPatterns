// Code example from Refactoring Guru
// Code example modified to avoid the 'new' and 'delete'
// Link: https://refactoring.guru/design-patterns/factory-method/cpp/example#example-0

#include "concrete_creator1.hpp"
#include "concrete_creator2.hpp"

#include <iostream>

/**
 * The client code works with an instance of a concrete creator, albeit through
 * its base interface. As long as the client keeps working with the creator via
 * the base interface, you can pass it any creator's subclass.
 */
void ClientCode(const Creator &creator)
{
   // ...
   std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
             << creator.SomeOperation() << std::endl;
   // ...
}

int main(int argc, char **argv)
{
   std::cout << "App: Launched with the ConcreteCreator1.\n";
   Creator *creator = new ConcreteCreator1();
   ClientCode(*creator);
   std::cout << std::endl;
   std::cout << "App: Launched with the ConcreteCreator2.\n";
   Creator *creator2 = new ConcreteCreator2();
   ClientCode(*creator2);

   delete creator;
   delete creator2;
   return 0;
}