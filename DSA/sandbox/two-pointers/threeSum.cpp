#include<iostream>
#include<vector>
#include<algorithm>
// Two pointers pattern.
// Three sum

// Let's see how we can detect the pattern in here. 
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, 
// and nums[i] + nums[j] + nums[k] == 0.
// In here, I am going to use two pointer, becuase if I use bruteforce, it will definitely take O(n^3) in time, but we will use 2 pointers
// to bring it to O(n^2). But in here, we need to have a sorted array, so first we will sort it using algorithm library. 
//we will put i in first, j in second and k in last index. if A[i] + A[j] = -A[k], push the triplets to the list we return,
// if it is bigger, move k-- as it is sorted and else move j++;
// Lets code

// O(n^2) in time. 

std::vector<std::vector<int>> threeSum(std::vector<int> &nums){
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> triplets;
    for(int i = 0; i<nums.size()-2; i++){
        if(i > 0 && nums[i] == nums[i-1]){
            continue;
        }
        int j = i+1;
        int k = nums.size() - 1;
        while(j < k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum == 0){
                triplets.push_back({nums[i], nums[j], nums[k]});
            
                while(j < k && nums[j] == nums[j+1]){
                    j++;
                }
                while(j < k && nums[k] == nums[k-1]){
                    k--;
                }
                j++; k--;
            }else if(sum < 0){
                j++;
            }else{
                k--;
            }
        }
    }

    return triplets;
}

int main()
{
    std::vector<int> A = {-1,0,1,2,-1,-4}; // -4, -1, -1, 0, 1, 2 
    std::vector<std::vector<int>> result = threeSum(A);
    for (const auto& triplet : result) {
        for (int value : triplet) {
            std::cout << value << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}