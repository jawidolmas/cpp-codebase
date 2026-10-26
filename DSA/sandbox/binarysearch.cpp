#include <iostream>
using namespace std;


int BinSearch(int A[], int l, int h, int key){
    int mid;
    int i = 0, j = h-1;
    while(i < j){
        mid = l + (h - l)/2;
        if(key == A[mid]){
            return mid;
        }
        else if(key > A[mid]){
            l = mid+1;
        }
        else{
            h = mid-1;
        }
    }
    return -1;
}

int binSearchRecursive(int A[], int l, int h, int key){
    int mid = l + (h-l)/2;
    if(key == A[mid]){ 
        return mid;
    }
    else if(key > A[mid]){
        return binSearchRecursive(A, mid+1, h, key);
    }
    else{
        return binSearchRecursive(A, l, mid-1, key);
    }
    return -1;
}


int main() {
    int Arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout <<"The key found in index(if -1, not found): " << binSearchRecursive(Arr, 0, 10, 7);

    return 0;
}