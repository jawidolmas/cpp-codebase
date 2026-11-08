#include<iostream>
#include<vector>

/*
You are given an integer array height of length n. 
There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
O(n) time
*/

int max(int a, int b){
    if(a > b){
        return a;
    } else {
        return b;
    }
}

int min(int a, int b){
    if(a < b){
        return a;
    } else {
        return b;
    }
}


int container_With_Most_Water(std::vector<int>& nums){
    int best = 0;
    int n = nums.size();
    int l = 0;
    int r = n - 1;
    while(l < r){
        int width = r - l;
        int hieght = min(nums[l], nums[r]);
        int area = width * hieght;
        best = max(best, area);
        if(nums[l] < nums[r]){
            l++;
        }else{
            r--;
        }
    }
    return best;
}



int main()
{
    std::vector<int> A = {1,8,6,2,5,4,8,3,9};
    std::cout << container_With_Most_Water(A);
    

    return 0;
}