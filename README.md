# Design Patterns in Modern C++

[![License](https://img.shields.io/badge/License-MIT-blue.svg)](https://shields.io/) [![Language](https://img.shields.io/badge/Made%20with-C++-blue.svg)](https://shields.io/)

## 1. Creational patterns

### 1.1. Factory method

Factory Method is a creational design pattern that provides an interface for creating objects in a superclass, but allows subclasses to alter the type of objects that will be created.

* Encapsulates the creation of related objects.
* Provides an interface to create an object but defers the creation to subclasses.
* Extensible to include objects.

#### Conceptual example

* [Code for 01-conceptual-example](01-creational/01-factory-method/01-conceptual-example/).
  
##### UML class diagram

```plantuml
@startuml

abstract class IProduct {
  {abstract} +operation() : std::string
}

class ConcreteProduct1 {
  +operation() : std::string
}

class ConcreteProduct2 {
  +operation() : std::string
}

abstract class Creator {
  {abstract} +factoryMethod() : std::unique_ptr<IProduct>
  +SomeOperation() : std::string
}

class ConcreteCreator1 {
  +factoryMethod() : std::unique_ptr<IProduct>
}

class ConcreteCreator2 {
  +factoryMethod() : std::unique_ptr<IProduct>
}

IProduct <|-- ConcreteProduct1
IProduct <|-- ConcreteProduct2
IProduct <.. Creator : <<dependency>>
Creator <|-- ConcreteCreator1
Creator <|-- ConcreteCreator2

@enduml

@enduml
```

#### UART and USB example

* [Code for 02-uart-and-usb](01-creational/01-factory-method/02-uart-and-usb/)

##### UML class diagram

```plantuml
@startuml

class IConnection {
  {abstract} +connect() : void
}

class UART {
  +connect() : void
}

class USB {
  +connect() : void
}

class ConnectionFactory {
  {abstract} +createHandler() : std::unique_ptr<IConnection>
}

class UARTFactory {
  +createHandler() : std::unique_ptr<IConnection>
}

class USBFactory {
  +createHandler() : std::unique_ptr<IConnection>
}

IConnection <|.. UART : <<realization>>
IConnection <|.. USB
ConnectionFactory <|-- UARTFactory : <<inheritance>>
ConnectionFactory <|-- USBFactory
IConnection <.. ConnectionFactory : <<dependency>>

@enduml
```