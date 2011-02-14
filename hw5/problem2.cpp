int main()
{
    int i;
    int *ip = new int[10];
    //The first deletion of i(delete &i) is not correct since i is a static variable.
    //Its memory is allocated during compiling and its lifetime extends across the entire run of the program,
    //which means the memory will be freed automatically after the program ends
    //and cannot be deleted in this way by "delete"
    /*delete &i;*/
    
    //The second deletion of ip(delete ip) is not correct either,
    //which just free the first elemment's memory and leave the rest memory unfreed.
    //We should use the array's deleting method to free the whole memory.
    /*delete ip;*/
    delete [] ip;
} 