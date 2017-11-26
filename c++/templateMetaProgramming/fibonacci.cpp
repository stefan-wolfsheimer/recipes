template<unsigned int n>
struct Fibonacci
{
  static constexpr int value = Fibonacci<n-1>::value + Fibonacci<n-2>::value;
};

//specialization
template<>
struct Fibonacci<0>
{
  static constexpr int value = 0;
};

template<>
struct Fibonacci<1>
{
  static constexpr int value = 1;
};

#include <iostream>
int main()
{
  std::cout << "Fib(0)=" << Fibonacci<0>::value << std::endl;
  std::cout << "Fib(1)=" << Fibonacci<1>::value << std::endl;
  std::cout << "Fib(2)=" << Fibonacci<2>::value << std::endl;
  std::cout << "Fib(3)=" << Fibonacci<3>::value << std::endl;
  std::cout << "Fib(4)=" << Fibonacci<4>::value << std::endl;
  std::cout << "Fib(5)=" << Fibonacci<5>::value << std::endl;
  std::cout << "Fib(6)=" << Fibonacci<6>::value << std::endl;
}

