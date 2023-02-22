#pragma once

#include "product.hpp"

#include <iostream>
#include <string>

class ConcreteProduct2 : public Product
{
public:
   std::string Operation() const override;
};