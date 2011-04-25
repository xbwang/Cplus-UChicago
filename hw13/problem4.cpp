/*********************
* hw13-4
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/bind.hpp>
#include <boost/lambda/lambda.hpp>
#include <cstdlib>
#include <string>
#include <iostream>
#include <numeric>
#include <cmath>
using namespace boost;
using namespace boost::interprocess;

typedef allocator<double, managed_shared_memory::segment_manager> SharedAllocator;
typedef vector<double, SharedAllocator> SharedVector;

int main(int argc, char *argv[])
{
    if(argc == 1){
        //remover
        struct sh_remove{
            sh_remove() { shared_memory_object::remove("SharedMemory"); }
            ~sh_remove() { shared_memory_object::remove("SharedMemory"); }
        }remover;
        //create segment
        managed_shared_memory segment(create_only, "SharedMemory", 65536);
        //initilize segment
        const SharedAllocator alloc_init(segment.get_segment_manager());
        SharedVector *v = segment.construct<SharedVector>("MyVector")(alloc_init);
        //parent process
        for(double i = 1.0; i < 10.0; ++i){
            std::cout << "- parent process: adding " << i << std::endl;
            v->push_back(i);
        }
        //create a child precess
        std::string s(argv[0]);
        s += " child";
        if(0 != std::system(s.c_str()))
            return 1;
        if(segment.find<SharedVector>("SharedVector").first)
            return 1;
    }else{
        managed_shared_memory segment(open_only, "SharedMemory");
        SharedVector *v = segment.find<SharedVector>("MyVector").first;
        std::cout << "- child process: " << std::sqrt(std::accumulate(v->rbegin(), v->rend(), 0.0, boost::lambda::_1+boost::lambda::_2*boost::lambda::_2)) << std::endl;
        segment.destroy<SharedVector>("MyVector");
    }
    return 0;
}