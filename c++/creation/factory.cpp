#include <memory>
#include <vector>
#include <string>
#include <iostream>

class Vehicle
{
public:
  Vehicle(const std::string & _serial)
    : serial(_serial)
  {}
  virtual ~Vehicle() {}

  std::string getSerial() const
  {
    return serial;
  }

  virtual int getWheels() const = 0;
  virtual std::string getType() const = 0;

private:
  std::string serial;
};

class VehicleFactory
{
public:
  VehicleFactory() : counter(0) {}
  std::shared_ptr<Vehicle> create(const std::string & type);
private:
  std::string nextSerial(const std::string & prefix);
  int counter;
};

int main(int argc, const char ** argv)
{
  VehicleFactory factory;
  std::vector<std::shared_ptr<Vehicle> > vehicles
  {
    factory.create("Car"),
    factory.create("Car"),
    factory.create("Bicycle"),
    factory.create("Bus")
  };
  for(auto v : vehicles)
  {
    std::cout << v->getType() << " "
              << v->getSerial() << " "
              << v->getWheels() << std::endl;
  }
  return 0;
};

////////////////////////////////////////////
//
// Implementation
//
////////////////////////////////////////////
class Car : public Vehicle
{
public:
  Car(const std::string & serial) : Vehicle(serial) {}
  virtual int getWheels() const override
  {
    return 4;
  }
  
  std::string getType() const override
  {
    return "Car";
  }
};

class Bus : public Vehicle
{
public:
  Bus(const std::string & serial) : Vehicle(serial) {}
  virtual int getWheels() const override
  {
    return 6;
  }

  std::string getType() const override
  {
    return "Bus";
  }
};

class Bicycle : public Vehicle
{
public:
  Bicycle(const std::string & serial) : Vehicle(serial) {}
  virtual int getWheels() const override
  {
    return 2;
  }

  std::string getType() const override
  {
    return "Bicycle";
  }
};

std::string VehicleFactory::nextSerial(const std::string & prefix)
{
  return prefix + std::to_string(++counter);
}

std::shared_ptr<Vehicle> VehicleFactory::create(const std::string & type)
{
  if(type == "Car")
  {
    return std::shared_ptr<Vehicle>(new Car(nextSerial("C")));
  }
  if(type == "Bicycle")
  {
    return std::shared_ptr<Vehicle>(new Bicycle(nextSerial("Bi")));
  }
  if(type == "Bus")
  {
    return std::shared_ptr<Vehicle>(new Bus(nextSerial("B")));
  }
  return std::shared_ptr<Vehicle>();
}

