#pragma once

#include <iostream>
#include <string>

/**
 * The Product interface declares the operations that all concrete products must
 * implement.
 */
class IProduct
{
public:
   /**
    * Making base class destructor virtual guarantees that the object of derived
    * class is destructed properly, i.e., both base class and derived class destructors
    * are called.
    */
   virtual ~IProduct() = default;

   /** 
    * Pure virtual function. 
    * No objects can be created directly from this class. */
   virtual std::string operation() const = 0; // Pure virtual function.
};