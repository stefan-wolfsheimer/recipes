#include <memory>
#include <iostream>
#include <string>

class Shape
{
public:
  virtual ~Shape() {}
  virtual std::string str() = 0;
};

class Circle : public Shape
{
public:
  Circle(float r=10.0f) : radius(r)
  {}

  void resize(float factor)
  {
    radius *= factor;
  }

  std::string str() override
  {
    return std::string("A circle of radius ") + std::to_string(radius);
  }

private:
  float radius;
};

template<typename T> class ColoredShape : public T
{
public:
  ColoredShape(const std::string & _color) :
    color(_color)
  {}

  std::string str() override
  {
    return T::str() + std::string(" which is coloured ") + color;
  }

private:
  std::string color;
};

int main(int argc, const char ** argv)
{
  ColoredShape<Circle> coloredCircle("red");
  coloredCircle.resize(1.5);
  std::cout << coloredCircle.str() << std::endl;
}
