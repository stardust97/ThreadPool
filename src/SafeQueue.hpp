#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <iostream>

namespace tc{
template<typename T>
class SafeQueue{
public:
  explicit SafeQueue(){

  }

  ~SafeQueue();

  void push(const T& task){
    std::unique_lock<std::mutex> lock(mutex_);
    queue.push(task);
    cond_.notify_one();
  }

  void push(T&& task){
    std::unique_lock<std::mutex> lock(mutex_);
    queue.push(std::move(task));
    cond_.notify_one(); 
  }

  void pop(T& task);

  std::size_t size();

  bool empty();

  voi stop();
  
private:
  std::queue<T> queue_;
  std::condition_variable cond_;
  std::mutex mutex_;
  bool stopped_;
};

} // namespace tc