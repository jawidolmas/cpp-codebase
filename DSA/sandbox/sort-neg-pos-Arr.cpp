#include<iostream>
#include<vector>

// Sort negative values in one side and positive on another.
void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}


void sortNegPos(std::vector<int> &nums){
    if(nums.empty()){
        std::cout << "Array is empty\n";
        return;
    }
    int i = 0, j = nums.size() - 1;
    while(i < j){
        while(i < j && nums[i] < 0){
            i++;
        }
        while(i < j && nums[j] >= 0){
            j--;
        }
        if(i < j){
            swap(nums[i], nums[j]);
        }
    }
    for(int i : nums){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}


int main()
{
    std::vector<int> A = {1, 2, 3, 4, 5 ,6, -8, -9, 5, -8, 3, 2, 5, -120};
    sortNegPos(A);


    return 0;
}