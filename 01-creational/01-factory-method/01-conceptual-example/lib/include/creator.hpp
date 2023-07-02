#pragma once

#include "i_product.hpp"

#include <iostream>
#include <memory>

/**
 * Note that the Creator may also provide some default implementation of the
 * factory method.
 */
class Creator
{
public:
   /**
    * Making base class destructor virtual guarantees that the object of derived
    * class is destructed properly, i.e., both base class and derived class destructors
    * are called.
    */
   virtual ~Creator() = default;

   /** 
    * Pure virtual function.
    * No objects can be created directly from this class. */
   virtual std::unique_ptr<IProduct> factoryMethod() const = 0;

   /**
    * Also note that, despite its name, the Creator's primary responsibility is
    * not creating products. Usually, it contains some core business logic that
    * relies on Product objects, returned by the factory method. Subclasses can
    * indirectly change that business logic by overriding the factory method and
    * returning a different type of product from it.
    */
   std::string SomeOperation() const
   {
      // Call the factory method to create a Product object.
      std::unique_ptr<IProduct> product = this->factoryMethod();

      // Now, use the product.
      std::string result = "Creator: The same creator's code has just worked with " + product->operation();

      return result;
   }
};
