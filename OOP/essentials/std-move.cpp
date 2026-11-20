#include<iostream>
#include<string>
#include<vector>



// std::move 
// This is a standard library funcs that let us to transfer the data in a varaible, container, or an object charecter by charecter or bit by
// bit to another varaible, container, or object respectively. 

// Why we need this?
// Whenever we have two strings like st1 and st2, if st1 = "JAWID" and we do st2 = st1, it uses the defualt copy constructor of the 
// class string. This can waste time, as well as space for copying the exact same thing bit by bit twice in two place. 
// THis is the reason we use std::move in most cases when we want to transfer the data from one object to another. 




int main()
{

    std::string st1 = "I am a good guy\n";
    std::string st2; // defualt constructor. empty string

    std::cout << st1 << std::endl;  // I am a...
    std::cout << st2 << std::endl; // empty

    // Now, if we copy it, the exact same data will be in both of them. Now we have two exact same string in two place of memory. 
    st2 = st1;
    std::cout << st1 << std::endl;  // I am a...
    std::cout << st2 << std::endl; //  I am a...
     
    // what if we move st1's data into st2? now in here, st1 is empty and st2 has I am a..., so a real transfer occured in here. 
    st2 = std::move(st1);
    std::cout << st1 << std::endl;  // empty
    std::cout << st2 << std::endl; //  I am a...
    // We only do have the data inside st2 right now, so we dont have any data inside the st1. 

    // Suppose we want to do an opeartion in array which we need a auxilary(helper) array to do the operation, and we need to return the original array
    // In here, we do the opeartion in helper array(eg. hash tables) and move them back to original array.
    std::vector<int> A = {1,2, 3, 4, 5, 6};
    int i = A.size();
    std::vector<int> helperArray;
    while(i > 0){
        helperArray.push_back(i);
        --i;
    }
    A = std::move(helperArray);
    for(const auto& element:A){
        std::cout << element << " ";
    }std::cout << std::endl;
    // In here, we reversed the A in a helper array and then moved everything back to A in reversed version. Now, helperArray is empty;
    std::cout << helperArray.empty() << std::endl;  // returns 1. empty.
    return 0;
}