/*********************************************************************************
* AuroraSource
* Copyright(C) 2021 Duncan Bauer <duncanebauer@gmail.com>
*
* This program is free software : you can redistribute itand /or modify
* it under the terms of the GNU Affero General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
* GNU Affero General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public License
* along with this program.If not, see <http://www.gnu.org/licenses/>.
*********************************************************************************/

#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <thread>
#include <queue>

namespace Utils
{
  typedef std::shared_ptr<std::vector<std::shared_ptr<std::thread>>> Threads;

  template<typename T>
  class ThreadPool
  {
  public:
    template<typename T>
    inline ThreadPool(size_t _min, size_t _max) : minThreads(_min), maxThreads(_max) 
    {
      for (int i = 0; i < this->minThreads; ++i)
      {
        std::thread thread()
      }
    }

    template<typename T>
    inline size_t getMinThreads() const { return this->minThreads; }

    template<typename T>
    inline size_t getMaxThreads() const { return this->maxThreads; }

    //template<typename T>
    //inline void addThread(void (*func)()) { this->threads->push_back(std::move(std::thread(func))); }

    //template<typename T>
    //inline void removeThread() { this->threads->pop_back(); }

    template<typename T>
    inline Threads getThreads() const { return this->threads; }

    template<typename T>
    inline std::shared_ptr<std::thread> getThread(size_t i) const { return this->threads[i]; }

  private:
    size_t minThreads;
    size_t maxThreads;
    Threads threads;
    std::priority_queue<T> workQueue;
  };
}

#endif