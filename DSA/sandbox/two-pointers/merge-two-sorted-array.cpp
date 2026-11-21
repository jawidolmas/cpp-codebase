#include<iostream>
#include<vector>
// Two pointers pattern.
// Merge two sroted array
// Let's see how we can detect the pattern in here. 
// 2 arrays, non-decreasing order, merge sort in place, O(n), do not use extra space, return original first array, sizeof(nums1) = m+n
// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3     Output: [1,2,2,3,5,6]
// In here, the problem asked us to solve this in place and return the first array, which first array has m+n size. 
// What we can see in here is, O(n) and array, it is highly exposing us the two pointer pattern.
// Lets see that, both of arrays are sorted in non-dec order, and if I put a pointer in m-1 which is 3 in value and another pointer in 
// n-1 which is 6 in value. I can directly compare the values in nums1 and nums2 from end of both of them. but when I checked and 6 > 3 
// where I am going to add that? in 0 after 3 or in 0 at the end of nums1? well both arrays are sorted non-dec. can anything be bigger than
// 6 in nums2? hell no, coz its the biggest and that is why we started from end of nums2. but if we want to add it at last 0 of nums1, 
// we need another pointer there so can we reach it, so we will have a pointer which is equal to m+n-1; that is the whole idea. 
// We continue this until either of j or i becomes zero. 

// Lets code

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n){
    int i = m-1;
    int j = n-1;
    int k = m+n-1;
    while(j >= 0){
        if(i>=0 && nums1[i] > nums2[j]){
            nums1[k--] = nums1[i--];
        }else{
            nums1[k--] = nums2[j--];
        }
    }   //O(n) of time and O(1) of space
}

void display(std::vector<int>& nums){
    for(const auto& element : nums){
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> A = {4, 5, 6, 0, 0, 0};
    std::vector<int> B = {1, 2, 3};
    merge(A, 3, B, 3);
    display(A);


    return 0;
}