#include<iostream>
#include<vector>
// Two pointers pattern.
// Two Sum II - Input Array Is Sorted

// Let's see how we can detect the pattern in here. 
// An array given, non-dec sorted, find and return two indices which is sum up to given target. 
//Input: numbers = [2,7,11,15], target = 9    Output: [1,2]
// In here, we can use two pointers which is very obvious. We will add a pointer in 0th index, and last index, after that 
// we will check if it is bigger than target or smaller, as it is non-dec order, if smaller than target, we will move first pointer, if 
// bigger, we will move last pointer. thats the whole idea. 
// Lets code

std::vector<int> twosum(std::vector<int>& numbers, int target){
    int i = 0;
    int j = numbers.size()-1;
    while(i < j){
        if(numbers[i] + numbers[j] == target){
            return {i+1, j+1};
        }else if(numbers[i] + numbers[j] < target){
            i++;
        }else{
            j--;
        }
    }
    return {-1, -1};
}

int main()
{
    std::vector<int> A = {2,7,11,15};
    std::vector<int> result = twosum(A, 9);
    for (int x : result) {
    std::cout << x << ' ';
    }


    return 0;
}