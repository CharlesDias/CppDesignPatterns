#pragma once

#include "i_product.hpp"

#include <iostream>
#include <string>

/**
 * Concrete Products provide various implementations of the Product interface.
 */
class ConcreteProduct1 : public IProduct
{
public:
   std::string operation() const override
   {
      return "{Do stuff on the ConcreteProduct1}";
   }
};