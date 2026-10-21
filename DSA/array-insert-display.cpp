#include<iostream>
#include<vector>


// Inserting and display
// We know that, the way we implemented array is ambigous, becuase we used std::vector and implemented our own array from scratch
// That is ridicolus as we can directly do A.inser(begin + index, key). So here we did that anyway
// If we wanted to implement the function from scratch, we needed to handle the memory from scratch too. 
// Both insert and display is O(n) in time.

class Array{
    private:
        std::vector<int> A;
    public:
        Array(int cap);         // No destructor needed, as vector handles the memory itself
        void insert(int index, int key);
        void display() const;
};

Array::Array(int cap){
        A.reserve(cap);
}


void Array::insert(int index, int key){
    if (index < 0 || static_cast<std::size_t>(index) > A.size()){
        std::cout << "Invalid index\n";
        return;
    }
    if(A.size() == A.capacity()){
        std::cout << "Array is full\n";
        return;
    }
    A.resize(A.size() + 1);
    for(int i = static_cast<int>(A.size()) - 1; i > index; --i){
        A[i] = A[i - 1];
    }
    A[index] = key;
    
}

void Array::display() const{
    if(A.size() == 0){
        std::cout << "Array is empty\n";
        return;
    }
    for(int i = 0; i < A.size(); ++i){
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}


int main()
{
    std::vector<int> B = {1, 2, 3, 4, 5, 6, 7, 8};
    Array arr(15);
    for(int i  = 0; i<B.size(); i++){
        arr.insert(i, B[i]);
    }
    arr.insert(3, 5);
    arr.display();


    return 0;
}