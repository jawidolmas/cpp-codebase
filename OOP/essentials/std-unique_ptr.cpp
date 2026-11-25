#include<iostream>
#include<memory>        // unique_ptr


/*
    -We all know about pointers, they are some varaibles where they point to an address, which helps us to have access to external sources. 
    But, we have some problems with raw pointers. First, they create a lot of room for a lot of errors, for example, the allocation and deallocation of the memory 
    in heap. suppose we have int *ptr = new int(10). If we do not delete this at the end of the program, the memory will be leaked definitely. 
    Or another example is when we have an array in heap such as, int *ptr = new int[10], if we deallocate it like delete ptr, it will show us that the memory is not leaked,
    but in fact, the memory is leaked coz we do have an array of integers so we need to delete []ptr. These are the problems that is raw pointers are very open for errors. 
    There can be other disadvantages like its ownership. if we have a ptr = array, and then delete the array and ptr2 = ptr, there will be a crash despite we delete the array,
    not the ptr. **What I mean by ownership is that its not known that who is the owner of who? for example, we can have two pointer like ptr = array and ptr2 = ptr, so 
    in here they are both pointing to the same address. but this is impossible in smart pointers. 

    -What can be the solutions? 
        -It is Smart pointers. 
        -In c++, scopes are very important, which is RAII. When we have a class and we have a constructor and destructor, they will be automatically called when an object is
         created and will be automatically destroy the object when it reach to the scope, so it destroys before going out of the scope and then exits. The same scopes 
         are important in smart pointers. 
        -How they are good? 
            -Whenever we allocate a memory using smart pointers, we do not need to worry about the deallocation of the memory, smart pointers will do that automatically when
             they reach the related scope. this way, we are less open to make raw pointer errors, which the small errors will be rutheless when we work on a big software or program. 
             there are ownership.    
*/

class UDT{
    public:
        UDT(){
            std::cout << "UDT CREATED\n";
        }
        ~UDT(){
            std::cout << "UDT DESTROYED\n";
        }
};

int main()
{
    UDT jawid;      // UDT CREATED\n UDT DESTROYED. // in here, when we created the obj jawid, it called the constructor and destryod jawid exactly when it meet the scope. 

    // Lets do it using unique_ptr
    std::unique_ptr<UDT> jawid1 = std::unique_ptr<UDT>(new UDT);
    // In here, the object is created in heap, but what about deletion? as we allocate, we need to delete it from heap. lets do it.
    delete jawid1;  // in here, we will get an error, coz there is nothing in heap tp delete, smart pointers automatically delete them after scope. 
    /*Error:
        main.cpp:41:12: error: type 'class std::unique_ptr<UDT>' argument given to 'delete', expected pointer
        41 |     delete jawid1;
        |            ^~~~~~
        make: *** [Makefile:5: main.exe] Error 1
    */

    // Now what about in arrays?
    std::unique_ptr<UDT[]> jawid2 = std::unique_ptr<UDT[]>(new UDT[10]);
    delete []jawid2; // we definitely get the same error for deleting the memory that already automatically will be deleted. 


    // We have other better design syntax for doing the exact same thing. 
    std::unique_ptr<UDT[]> jawid12 = std::make_unique<UDT[]>(10); // in big programs and better design, make_unique mostly prefered for creating unique_ptrs.

    // We cannot share the ownership. means, there is no copy constructor in unique_ptr class. 
    std::unique_ptr<UDT> owner = jawid1; // this is impossible and we will get compiler error of cannot be referenced 

    // But we can move the ownership. for example, we can move the ownership of jawid1 to owner and then jawid will no longer have the data or ownership to the UDT. 
    std::unique_ptr<UDT> owner2 = std::move(jawid1); // this is truely possible and now jawid1 is null and owner2 is the new owner of jawid1's data. 
    return 0;
}




// To conclude the smart pointers advantages:
    // There is ownership and we cannot copy a smart pointer to another smart pointer. 
    // We dont have to delete the allocated memory coz they do it automatically within the scope.
    // moving the ownership is allowd in smart pointers. 