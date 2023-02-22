#pragma once

#include "product.hpp"

#include <iostream>
#include <string>

/**
 * Concrete Products provide various implementations of the Product interface.
 */
class ConcreteProduct1 : public Product
{
public:
   std::string Operation() const override;
};