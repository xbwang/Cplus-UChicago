/*******************
hw7 Final Submission
Xiangbo Wang
2/28/2011
********************/
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

std::mutex some_mutex; //i tried to push it into ListHead, 
                        //but Segmentation Fault will come up while printing

struct ListItem
{
    ListItem *next;
    int value;
};

struct ListHead
{
public:
    int pop();
    void push(int);
    ListHead() {}
    ListHead(ListItem *l) : link(l) {}
    ListItem *link;
};

int
ListHead::pop()
{
    int value;
    std::lock_guard<std::mutex> guard(some_mutex);
    if(link == 0){
        return 0;
    }else{
        value = link->value;
        link = link->next;
        return value;
    }
}

void
ListHead::push(int val)
{
    ListItem *newItem = new ListItem();
    newItem->value = val;
    newItem->next = link;
    std::lock_guard<std::mutex> guard(some_mutex);
    (*this).link = newItem;
}

int main()
{

    ListHead testHead;
    //five pushes
    for(int i = 5; i < 10; i++)
        testHead.push(i);
    ListItem *printItem;
    cout << "- Current Stack(after 5 pushes): ";
    for(printItem = testHead.link; printItem != 0; printItem = printItem->next){
        cout << printItem->value << " ";
    }
    cout << endl;
    //one pop
    testHead.pop();
    cout << "- Current Stack(after 1 pop): ";
    for(printItem = testHead.link; printItem != 0; printItem = printItem->next){
        cout << printItem->value << " ";
    }
    cout << endl;
    //one more push
    testHead.push(10);
    cout << "- Current Stack(after 1 push): ";
    for(printItem = testHead.link; printItem != 0; printItem = printItem->next){
        cout << printItem->value << " ";
    }
    cout << endl;
    //two more pops
    testHead.pop();
    testHead.pop();
    cout << "- Current Stack(after 2 pops): ";
    for(printItem = testHead.link; printItem != 0; printItem = printItem->next){
        cout << printItem->value << " ";
    }
    cout << endl;
    
    return 0;
}