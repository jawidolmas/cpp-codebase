#include<iostream>
#include<array>

    // std::array
   //  A fixed-size array mostly in stack

int main()
{   

    std::array<int, 10> num;
    num[0] = 25;
    std::cout << num[0] << " " <<  num[2] << std::endl; // 25 and some garbage value. 
    std::cout << num.size() << std::endl; 
    //std::cout << num.capacity() << std::endl; // Compiler error : num has no memeber capacity. The reason for this is that the std::array 
                                              // is a fixed size array 
    std::cout << num.back() << std::endl; // last element. 
    std::cout << num.front() << std::endl;  // first element.
    std::cout << num.data() << std::endl;  // first element's address. Doable -> data(), size + something
                                            // If size() is 0, data() may or may not return a null pointer. 

    return 0;
}


// For full view of functions: https://en.cppreference.com/cpp/container/array