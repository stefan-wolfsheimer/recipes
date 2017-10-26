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

class ColoredShape : public Shape
{
public:
  ColoredShape(const std::string & _color,
               std::shared_ptr<Shape> _s) :
    color(_color), shape(_s)
  {}

  std::string str() override
  {
    return shape->str() + std::string(" which is coloured ") + color;
  }

private:
  std::string color;
  std::shared_ptr<Shape> shape;
};

int main(int argc, const char ** argv)
{
  auto circle = std::make_shared<Circle>(15.0f);
  std::cout << circle->str() << std::endl;
  ColoredShape coloredCircle("red", circle);
  std::cout << coloredCircle.str() << std::endl;
}
