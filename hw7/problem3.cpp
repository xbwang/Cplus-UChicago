/*******************
hw7 Final Submission
Xiangbo Wang
2/28/2011
********************/
#include <thread>
#include <numeric>
//[problem3] modification
#include <future>  
#include <vector>
#include <iostream>
#include <iterator>
#include <boost/shared_ptr.hpp>
using namespace std;

template<typename Iterator,typename T>
struct accumulate_block
{
    //[problem3] modification
    T operator()(Iterator first,Iterator last,T result) {
        return std::accumulate(first,last,result);
    }
    typedef T result_type;
};

template<typename Iterator,typename T>
T
parallel_accumulate(Iterator first,Iterator last,T init)
{
    unsigned long const length=std::distance(first,last);
    if(!length)
        return init;
    unsigned long const min_per_thread=25;
    unsigned long const max_threads = (length+min_per_thread-1)/min_per_thread;

    // hardware_concurrency may return 0 if it doesn't choose to answer
    unsigned long const hardware_threads = std::thread::hardware_concurrency();
    unsigned long const num_threads
       = std::min(hardware_threads!=0?hardware_threads:2,max_threads);
    unsigned long const block_size=length/num_threads;
    std::vector<T> results(num_threads);
    std::vector<future<T> > futures(num_threads);  //[problem3] modification
    Iterator block_start=first;
    for(unsigned long i=0;i<(num_threads-1);++i) {
        Iterator block_end=block_start;
        std::advance(block_end,block_size);
        //[problem3] modification
        futures[i]
          = std::async
              (accumulate_block<Iterator,T>(),
               block_start,
               block_end,
               results[i]);
        block_start=block_end;
    }

    //[problem3] modification
    futures[num_threads-1] 
        = std::async(accumulate_block<Iterator,T>(), block_start,last,results[num_threads-1]);
    //[problem3] modification
    for(unsigned long i = 0; i < num_threads; ++i){
        results[i] = futures[i].get();
    }

    return std::accumulate(results.begin(),results.end(),init);
}

int main()
{
    vector<int> v;
    int result = 0;
    
    for(int i = 1; i < 1000; i++){
        v.push_back(i);
    }
    
    cout << parallel_accumulate(v.begin(),v.end(),result) << endl;
    return 0;
}