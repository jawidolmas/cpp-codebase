#include<iostream>
#include<vector>

// Remove Duplicates in a sorted array
/*
Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice.
The relative order of the elements should be kept the same.
Return k after placing the final result in the first k slots of nums.*/
    int remove_duplicates(std::vector<int>& nums){
        int write = 2;
        int read = 2;
        if(nums.size() <= 2) return nums.size();
        while(read < nums.size()){
            if(nums[read] == nums[write-2]){
                read++;
            }else{
                nums[write] =  nums[read];
                read++;
                write++;
            }
        }
        return write;
    }







int main()
{

    std::vector<int> A = {1, 1, 1, 2, 2, 2, 2, 2, 3, 3};
    std::cout << remove_duplicates(A);
    return 0;
}