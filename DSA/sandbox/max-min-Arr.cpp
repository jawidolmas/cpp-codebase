#include<iostream>
#include<vector>


int Max(std::vector<int> &A){
    int max = INT_MIN;
    for(int i = 0; i<A.size(); i++){
        if(A[i] > max){
            max = A[i];
        }else{

        }
    }
    return max;
}

int Min(std::vector<int> &A){
    int min = INT_MAX;
    for(int i = 0; i<A.size(); i++){
        if(A[i] < min){
            min = A[i];
        }
    }
    return min;
}



int main()
{
    std::vector<int> A = {1, 2, 3, 4, 5};
    std::cout << Max(A) << std::endl;
    std::cout << Min(A) << std::endl;
    
    return 0;
}


