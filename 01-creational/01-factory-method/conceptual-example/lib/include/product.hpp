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
   virtual ~Product() {}
   virtual std::string Operation() const = 0; // Pure virtual function.
};