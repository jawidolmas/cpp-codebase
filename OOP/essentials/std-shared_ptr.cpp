#include<iostream>
#include<memory>        // shared_ptr


/*  
    Shared pointers behaves exactly like unique_ptr. it both helps us to not care about new and delete. But shared_ptr is different in one way, it have a copy constructor 
    and it let us to point to a reference with more than one pointer. 
    and that is called reference count. 

    Suppose we have an object called resource and ptr1 and ptr2 both pointing to resource, so how many pointers is pointing to resource? just 2, so the reference count 
    is literally 2. we can access that using obj.use_count(); reference count is thread safe. 

    One important thing we need to care about is the life time of an object in shared pointers behaves differently than unique. The life time of the object is again within
    the scope, but when we have a resource and the ptr1 is pointing to resource and ptr2 = ptr1, then the life time of the object resource will depend on ptr2. 
    whenever ptr2 came at the end of its scope, then the resource will be deleted and destroyed. 
 
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
    std::shared_ptr<UDT> ptr2;
    // creating an object ptr1. actaully a pointer which is pointing to a resource UDT. 
    {
        std::shared_ptr<UDT> ptr1 = std::make_shared<UDT>();
    
    // Copying ptr1 to ptr2.
    ptr2 = ptr1;
    // lets see resource count
    std::cout << "Use count = " << ptr2.use_count() << std::endl;   // Use count = 2, coz ptr1 as well as ptr2 is pointing to resource. 
    }  std::cout << "Destroy After this line\n";
    // in here, the life time of UDT is belong to ptr2. lets see withina scope. 
    // when we run the program, the destructor will run after our message which is the outer scope block.
    // We can see in here that the object's lifetime belongs to scope and the one which is go as far as within its scope. 


    //Now, lets see the resource inside scope and outside inner scope.
    std::cout << "Use count = " << ptr2.use_count() << std::endl;  // use count = 1, coz only ptr2 is pointing to resource. ptr1 is out of scope and died.
    return 0;
}



