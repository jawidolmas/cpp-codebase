#include<iostream>
#include<vector>
#include<algorithm>
// Two pointers pattern.
// Three sum

// Let's see how we can detect the pattern in here. 
// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
// Note that you must do this in-place without making a copy of the array.

// Obviousely it is two pointers problem. we put i and j in first index, and move j to the end iteratively, if it sees any non zero, 
// we swap that with i and move i++; thats it. 
// Lets code

// O(n) in time. 

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void moveZeroes(std::vector<int> &nums){
    int i = 0, j = 0;
    for(; j<nums.size(); j++){
        if(nums[j] != 0){
            swap(nums[i], nums[j]);
            i++;
        }
    }
    }



int main()
{
    std::vector<int> A = {0}; 
    moveZeroes(A);
    for(int j : A){
        std::cout << j <<  " ";
    }

    return 0;
}