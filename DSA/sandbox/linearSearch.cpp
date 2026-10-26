#include<iostream>
#include<vector>

// Linear Search

int linearSearch(std::vector<int>& A, int key){
    if(A.size() == 0) return -1;
    for(int i = 0; i<A.size(); i++){
        if(key == A[i]){
            return i;
        }
    }
    return -1;
}


int main(){

    std::vector<int> A = {1, 2, 3, 4, 5, 6, 7};
    std::cout << linearSearch(A, 4);

    return 0;
}