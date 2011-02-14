#include <iostream>
using namespace std;

// Linked list of integers
struct ListItem {
    ListItem *next; // Next item, 0 if this is last
    int value;
};

struct ListHead {
    int pop();
    void push(int);
    ListHead() {}
    ListHead(ListItem *l, unsigned c) : link(l), count(c) {} 
    ListItem *link;      // First item, 0 if list empty
    unsigned count;      // How many times the list has changed (see lecture notes)
};
// It is useful to be able to compare ListHeads
bool
operator==(ListHead &l, ListHead &r)
{
    // The same if all fields are the same
    return l.link == r.link && l.count == r.count;
}

// As in the lecture notes, this function atomically does the following
//   If head != expectedVal, returns false
//   If head == expectedVal, sets head to newVal and returns true
bool compareAndExchange(ListHead &head, ListHead &newVal, ListHead &expectedVal)
{
    // If you want to try the just::threads implementation of C++0x
    // concurrency (extra credit), replace the code below with an 
    // appropriate call to std::atomic_compare_exchange_weak

    // Here is a thread-unsafe version that you can use for
    // simple single-threaded testing of your solution.
    if(head == expectedVal) {
        head = newVal;
        return true;
    } else {
        return false;
    }
}

// Pop value off list
int
ListHead::pop()
{
    ListHead expected;
    bool succeeded = false;
    while(!succeeded) {
        if(link == 0) {
            return 0; // List is empty
        }
        // What the head will be if nothing messed with it
        expected = *this;
        // What the head will be after the pop:
        ListHead newHead(link->next, count + 1);
        succeeded = compareAndExchange(*this, newHead, expected);
    }
    int value = expected.link->value;
    delete expected.link;
    return value;
}

// Push an item onto the list with the given head
void
ListHead::push(int val)
{
    // Exercise 5.4
    ListHead expected;
    bool succeeded = false;
    ListItem *newItem = new ListItem();
    newItem->value = val;
    while(!succeeded){
        expected = *this;
        ListHead newHead(newItem, count + 1);
        succeeded = compareAndExchange(*this, newHead, expected);
    }
    newItem->next = expected.link;
}

int main()
{
    ListHead testHead;
    testHead.count = 0;
    //five pushes
    for(int i = 5; i < 10; i++)
        testHead.push(i);
    ListItem *printItem;
    cout << "- Current Stack(after 5 pushes): ";
    for(printItem = testHead.link; printItem != 0; printItem = printItem->next){
        cout << printItem->value << " ";
    }
    cout << endl;
    cout << "- Current Count(after 5 pushes): " << testHead.count << endl;
    //one pop
    testHead.pop();
    cout << "- Current Stack(after 1 pop): ";
    for(printItem = testHead.link; printItem != 0; printItem = printItem->next){
        cout << printItem->value << " ";
    }
    cout << endl;
    cout << "- Current Count(after 1 pop): " << testHead.count << endl;
    //one more push
    testHead.push(10);
    cout << "- Current Stack(after 1 push): ";
    for(printItem = testHead.link; printItem != 0; printItem = printItem->next){
        cout << printItem->value << " ";
    }
    cout << endl;
    cout << "- Current Count(after 1 push): " << testHead.count << endl;
    //two more pops
    testHead.pop();
    testHead.pop();
    cout << "- Current Stack(after 2 pops): ";
    for(printItem = testHead.link; printItem != 0; printItem = printItem->next){
        cout << printItem->value << " ";
    }
    cout << endl;
    cout << "- Current Count(after 2 pops): " << testHead.count << endl;
    
    return 0;
}