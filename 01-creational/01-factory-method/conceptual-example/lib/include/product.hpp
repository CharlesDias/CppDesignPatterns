#pragma once

#include <iostream>
#include <string>

/**
 * The Product interface declares the operations that all concrete products must
 * implement.
 */
class Product
{
public:
   /**
    * Making base class destructor virtual guarantees that the object of derived
    * class is destructed properly, i.e., both base class and derived class destructors
    * are called.
    */
   virtual ~Product() = default;

   /** 
    * Pure virtual function. Any object can be create directly from this class
    * can not. */
   virtual std::string Operation() const = 0; // Pure virtual function.
};