#pragma once

#include "i_product.hpp"

#include <iostream>
#include <string>

class ConcreteProduct2 : public IProduct
{
public:
   std::string operation() const override
   {
      return "{Do stuff on the ConcreteProduct2}"; 
   }
};