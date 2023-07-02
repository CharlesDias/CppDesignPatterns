#include <memory>
#include <iostream>

// Abstract base class
class IConnection
{
public:
   virtual ~IConnection() = default;
   virtual void connect() = 0;
};

// UART class
class UART : public IConnection
{
public:
   void connect() override
   {
      std::cout << "UART connection established.\n";
   }
};

// USB class
class USB : public IConnection
{
public:
   void connect() override
   {
      std::cout << "USB connection established.\n";
   }
};

// Connection factory
class ConnectionFactory
{
public:
   virtual ~ConnectionFactory() = default;
   virtual std::unique_ptr<IConnection> createHandler() = 0;
};

class UARTFactory : public ConnectionFactory
{
public:
   std::unique_ptr<IConnection> createHandler() override
   {
      return std::make_unique<UART>();
   }
};

class USBFactory : public ConnectionFactory
{
public:
   std::unique_ptr<IConnection> createHandler() override
   {
      return std::make_unique<USB>();
   }
};

void connect_pass_factory(ConnectionFactory &factory)
{
   auto handler = factory.createHandler();
   handler->connect();
}

void connect_pass_interface(std::unique_ptr<IConnection> &connection)
{
   connection->connect();
}

// Usage
int main()
{
   UARTFactory uartFactory;
   connect_pass_factory(uartFactory);

   USBFactory usbFactory;
   connect_pass_factory(usbFactory);

   std::cout << "--------------------------------" << std::endl;

   auto uart = uartFactory.createHandler();
   connect_pass_interface(uart);

   auto usb = usbFactory.createHandler();
   connect_pass_interface(usb);

   return 0;
}