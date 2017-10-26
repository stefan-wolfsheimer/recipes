#include <memory>
#include <set>
#include <vector>

#include <iostream>

#include <mutex>
#include <thread>

class Observer
{
public:
  virtual ~Observer() {}
  virtual void notify()=0;
};

class Observable
{
public:
  void registerObserver(std::shared_ptr<Observer> observer)
  {
    observers.insert(observer);
  }

  void unregisterObserver(std::shared_ptr<Observer> observer)
  {
    observers.erase(observer);
  }

protected:
  void notifyObservers()
  {
    std::unique_lock<std::mutex> lock(mutex);
    for(auto observer : observers)
    {
      observer->notify();
    }
  }

private:
  std::mutex mutex;
  std::set<std::shared_ptr<Observer> > observers;
};

////////////////////////////////////////
//
// Implementation
//
////////////////////////////////////////
class MyObservable : public Observable
{
public:
  void run()
  {
    std::thread th1([this](){ notifyObservers(); });
    std::thread th2([this](){ notifyObservers(); });
    std::thread th3([this](){ notifyObservers(); });
    std::thread th4([this](){ notifyObservers(); });
    th1.join();
    th2.join();
    th3.join();
    th4.join();
  }
};

class MyObserver : public Observer
{
public:
  void notify() override
  {
    std::cout << "task finished" << std::endl;
  }
};

int main(int argc, const char ** argv)
{
  MyObservable observable;
  auto observer = std::make_shared<MyObserver>();
  observable.registerObserver(observer);
  observable.run();
  return 0;
}

