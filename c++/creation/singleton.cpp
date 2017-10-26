#include <memory>
#include <iostream>

class OnlyOneInstance
{
public:
  static std::shared_ptr<OnlyOneInstance> getInstance()
  {
    if(!instance)
    {
      instance = std::shared_ptr<OnlyOneInstance>(new OnlyOneInstance());
    }
    return instance;
  }

private:
  OnlyOneInstance()
  {}
  static std::shared_ptr<OnlyOneInstance> instance;
};

std::shared_ptr<OnlyOneInstance> OnlyOneInstance::instance;

int main()
{
  auto inst1 = OnlyOneInstance::getInstance();
  auto inst2 = OnlyOneInstance::getInstance();
  std::cout << "inst1=" << inst1.get() << std::endl;
  std::cout << "inst2=" << inst2.get() << std::endl;
  return 0;
}

