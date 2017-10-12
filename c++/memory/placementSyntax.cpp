#include <iostream>
#include <set>

class MemoryManagement
{
public:
  void * malloc(size_t s)
  {
    char * p = new char[s];
    std::cout << "Allocate memory of size " << s << ":" << (void*)p << std::endl;
    allocated.insert((void*)p);
    return p;
  }

  template<typename T>
  void free(T * p)
  {
    std::cout << "Free memory " << p << std::endl;
    allocated.erase((void*)p);
    delete p;
  }
  
  std::set<void*> allocated;
};

void * operator new(size_t s, MemoryManagement & mm)
{
  return mm.malloc(s);
}

class A
{
public:
  A(int value=0) : a(value)
  {
    std::cout << "A::A(" << value << ")" << std::endl;
  }
  
  ~A()
  {
    std::cout << "A::~A()" << std::endl;
  }
  
  int a;
};

int main(int argc, const char ** argv)
{
  MemoryManagement mm;
  A * a = new(mm) A(1);
  mm.free(a);
}
