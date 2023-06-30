#pragma once

#include "creator.hpp"
#include "concrete_product2.hpp"

#include <memory>

/**
 * Concrete Creators override the factory method in order to change the
 * resulting product's type.
 */
class ConcreteCreator2 : public Creator
{
   /**
    * Note that the signature of the method still uses the abstract product type,
    * even though the concrete product is actually returned from the method. This
    * way the Creator can stay independent of concrete product classes.
    */
public:
   std::unique_ptr<Product> FactoryMethod() const override
   {
      return std::make_unique<ConcreteProduct2>();
   }
};