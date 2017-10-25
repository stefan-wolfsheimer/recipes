#include <string>
#include <queue>

#include <iostream>

#include <mutex>
#include <thread>
#include <condition_variable>

std::mutex queueMutex;
std::queue<std::string> messageQueue;
std::condition_variable conditionVariable;

void consumer()
{
  bool run = true;
  while(run)
  {
    std::unique_lock<std::mutex> lock(queueMutex);
    conditionVariable.wait(lock); // release lock and relock on wakeup
    while(!messageQueue.empty())
    {
      auto message = messageQueue.front();
      messageQueue.pop();
      if(!message.empty())
      {
        std::cout << message << std::endl;
      }
      else
      {
        run = false;
      }
    }
    lock.unlock();
  }
}

void producer()
{
  for(std::size_t i = 0; i < 10000; i++)
  {
    std::unique_lock<std::mutex> lock(queueMutex);
    messageQueue.push(std::string("Task ") + std::to_string(i));
    conditionVariable.notify_one();
  }
  std::unique_lock<std::mutex> lock(queueMutex);
  messageQueue.push("");
  conditionVariable.notify_one();
}

int main(int argc, char ** argv)
{
  std::thread consumerThread(consumer);
  producer();
  consumerThread.join();
  return 0;
}

