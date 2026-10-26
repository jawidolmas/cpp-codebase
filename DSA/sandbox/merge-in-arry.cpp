#include<iostream>
#include<vector>


// Merging two array
// Usually a merge is O(n+m), which it n is size for one array and m for another. but as its deg is 1, we call it O(n);

void merge(std::vector<int>& A, std::vector<int>& B){
    std::vector<int> C;
    int i, j;
    i = j = 0;
    while(i < A.size() && j < B.size()){
        if(A[i] < B[j]){
            C.push_back(A[i++]);  
        }else {
            C.push_back(B[j++]);
        } 
    }
    for(; i<A.size(); i++){
        C.push_back(A[i]);
    }
    for(; j<B.size(); j++){
        C.push_back(B[j]);
    }
    for(int i = 0; i<C.size(); ++i){
        std::cout <<  C[i] << " ";
    }
    std::cout << std::endl;
}


int main()
{
    std::vector<int> A = {1, 2, 3, 4, 5, 6};
    std::vector<int> B = {10, 11, 12, 13, 15};
    merge(A,B);

    return 0;
}