#include<iostream>
#include<vector>


void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void reverse(std::vector<int>& nums){
    int i = 0, j = nums.size() - 1;
    while(i < j){
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
}



int main()
{
    std::vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8};
    reverse(A);
    for(const auto& i:A){
        std::cout << i << " ";
    }

    return 0;
}