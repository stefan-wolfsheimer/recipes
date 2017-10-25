#include <vector>
#include <algorithm>

#include <iostream>

#include <thread>
#include <future>

int accumulate(std::vector<int>::const_iterator begin,
               std::vector<int>::const_iterator end)
{
  return std::accumulate(begin, end, 0);
}

/***********************************************************
 * Future with threads
 ***********************************************************/
void future_thread(const std::vector<int> & data)
{
  std::promise<int> calcPromise;
  std::future<int> calcFuture = calcPromise.get_future();
  std::thread th([&calcPromise](std::vector<int>::const_iterator begin,
                                std::vector<int>::const_iterator end){
                   calcPromise.set_value(accumulate(begin,end));
                 },
                 data.begin(),
                 data.end());
  std::cout << "sum: " << calcFuture.get() << std::endl;
  th.join();
}

/***********************************************************
 * Future with packaged_task
 ***********************************************************/
void future_packaged_task(const std::vector<int> & data)
{
  typedef int taskType(std::vector<int>::const_iterator,
                       std::vector<int>::const_iterator);

  std::packaged_task<taskType> pTask0(accumulate);
  std::packaged_task<taskType> pTask1(accumulate);
  std::future<int> future0 = pTask0.get_future();
  std::future<int> future1 = pTask1.get_future();

  // move required because packaged_task cannot be copied
  std::thread t1(move(pTask0),
                 data.begin(),
                 data.begin() + data.size() / 2);
  std::thread t2(move(pTask1),
                 data.begin() + data.size() / 2,
                 data.end());

  std::cout << "sum: " << future0.get() + future1.get() << std::endl;
  t1.join();
  t2.join();
}

/***********************************************************
 * Future with async
 ***********************************************************/
void future_async(const std::vector<int> & data)
{
  std::future<int> future0 = std::async(accumulate,
                                        data.begin(),
                                        data.begin() + data.size() / 2);
  std::future<int> future1 = std::async(accumulate,
                                        data.begin() + data.size() / 2,
                                        data.end());
  std::cout << "sum: " << future0.get() + future1.get() << std::endl;
}

int main(int argc, char ** argv)
{
  std::vector<int> data {1,2,3,4,5,6,7,8,9,10};

  future_thread(data);
  future_packaged_task(data);
  future_async(data);
  return 0;
}

