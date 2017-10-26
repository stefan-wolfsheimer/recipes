#include <memory>
#include <vector>
#include <string>
#include <iostream>

class Vehicle
{
public:
  Vehicle(const std::string & _serial);
  virtual ~Vehicle() {}

  std::string getSerial() const;
  virtual int getWheels() const = 0;
  virtual std::string getType() const = 0;

  static std::shared_ptr<Vehicle> create(const std::string & type,
                                         const std::string & serial);
private:
  std::string serial;
};

int main(int argc, const char ** argv)
{
  std::vector<std::shared_ptr<Vehicle> > vehicles
  {
    Vehicle::create("Car","NL-SU-73"),
    Vehicle::create("Car","NL-SU-74"),
    Vehicle::create("Bicycle","NL-BI-84"),
    Vehicle::create("Bus","NL-PU-91")
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

Vehicle::Vehicle(const std::string & _serial)
  : serial(_serial)
{}

std::string Vehicle::getSerial() const
{
  return serial;
}


std::shared_ptr<Vehicle> Vehicle::create(const std::string & type,
                                         const std::string & serial)
{
  if(type == "Car")
  {
    return std::shared_ptr<Vehicle>(new Car(serial));
  }
  if(type == "Bicycle")
  {
    return std::shared_ptr<Vehicle>(new Bicycle(serial));
  }
  if(type == "Bus")
  {
    return std::shared_ptr<Vehicle>(new Bus(serial));
  }
  return std::shared_ptr<Vehicle>();
}

