#include<iostream>
#include<vector>
#include<type_traits>
using namespace std;


// std::is_const | std::decletpye | const in function

void PassByReferancec(const std::vector<int> &nums){    // Whenever we pass by referance, we are saving the memory from copying a very big chunk of data which we dont need to. 
                                                        // To make it safe where niether we want to copy a big data, nor want to  make changes in it, we use const and pass by referance. 
                                                        // This way, we will save in space, time and security

    nums[0] = 25;
    /*
        In here, we will get an error from compiler that the expression is not modifiable. 
        
        Actual error:
        main.cpp: In function 'void PassByReferancec(const std::vector<int>&)':
        main.cpp:10:13: error: assignment of read-only location '(& nums)->std::vector<int>::operator[](0)'
        10 |     nums[0] = 25;
        make: *** [Makefile:5: main.exe] Error 1
    */
}


int main()
{
    // const for by referance
    std::vector<int> A(100000000);
    PassByReferancec(A);
    
    // When we declare anything as const, it will be read-only, so we cannot change anyhting. 
    const int x = 25;
    x = 35; // Impossible. coz x is const. 

    // How to check if a data is const or not?  using st::is_const and decletype from stl type_traits
    std::cout << std::is_const_v<int> << std::endl;         // Return 0, coz int is not const. 
    std::cout << std::is_const_v<const int> << std::endl;   // Return 1, coz const int is  const. 
    
    // But, how we can check if we have a data like x and check if its const or not. decletpye. 
    std::cout << std::is_const<decltype(x)>::value << std::endl;    // 1 coz x is const.
    return 0;
}