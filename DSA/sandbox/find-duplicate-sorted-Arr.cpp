#include<iostream>
#include<vector>

// Find duplicate of numbers in sorted array


void findDuplicate_Sorted(std::vector<int>& nums){
    if(nums.empty()){
        std::cout << "Array is empty\n";
        return;
    }
    int j = 0;
    size_t n = nums.size();
    for(int i = 0; i + 1< n; i++){
        if(nums[i] == nums[i+1]){
            j = i+1;
            while(j < n && nums[j] == nums[i]){     // j < n is just a bound check which we do in vector only, coz of how we access a value in vector
                j++;
            }
            std::cout << nums[i] << " appeared " << j-i << " times in array\n";
            i = j-1;
        }
    }
}


int main()
{
    std::vector<int> A = {1, 2, 3, 4, 4, 4, 4, 4, 4, 5, 5, 5, 7};
    findDuplicate_Sorted(A);


    return 0;
}