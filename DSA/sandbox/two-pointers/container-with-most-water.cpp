#include<iostream>
#include<vector>
// Two pointers pattern.
// Container With Most Water

// Let's see how we can detect the pattern in here. 
// We have an array, not sorted, and we are returning the maximum capacity vertically and horizantally that can take maximum water.
// We want to do this in O(n) time, so I difinitely want to use two pointer pattern, I add i to 0th index, j at last index. 
// I calculate the highet and take minimum of them, as we are not able to slant coz water will overflow. I will have a varible max_area 
// which will be 0 initially, and then anytime I find better area, I update it. 
// We may need external functions like max and min. 
// Lets code

int min(int &a, int &b){
    return a < b ? a : b;
}
int max(int &a, int &b){
    return a > b ? a : b;
}

// O(n) in time and O(1) in space
int maxArea(std::vector<int> &hieght){
    int max_area = 0;
    int i = 0;
    int j = hieght.size() - 1;
    while(i < j){
        int length = j - i;
        int h = min(hieght[i], hieght[j]);  
        int area = length * h;
        max_area = max(max_area, area);
        if(hieght[i] < hieght[j]){
            i++;
        }else{
            j--;
        }
    }
    return max_area;
}

int main()
{
    std::vector<int> A = {1,8,6,2,5,4,8,3,7};
    std::cout << maxArea(A);


    return 0;
}