#include<iostream>
#include<vector>


/*
    Problem: Search a 2D MatrixYou are given an MxN integer matrix matrix with 
    the following two properties:Each row is sorted in non-decreasing order.
    The first integer of each row is strictly greater than the last integer 
    of the previous row.Given an integer target, return true if target is in
    matrix or false otherwise.You must write a solution in O(log nxm) time complexity.
*/

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target){
    if(matrix.empty() || matrix[0].empty()) return false;
    int m = matrix.size();
    int n = matrix[0].size();
    int l = 0, h = (n*m)-1, mid = 0;
    int row = 0, col = 0;
    while(l <= h){
        mid = l + (h-l)/2;
        row = mid/n;
        col = mid % n;
        if(matrix[row][col] == target){
            return true;
        }else if(matrix[row][col] < target){
            l = mid+1;
        }else{
            h = mid-1;
        }
    }
    return false;
}



int main()
{

    std::vector<std::vector<int>> A = {{5, 6},
                                       {7, 8}, 
                                       {9, 10}, 
                                       {11, 12} 
                                    };

    std::cout << searchMatrix(A, 22);


    return 0;
}
