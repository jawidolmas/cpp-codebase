 #include<iostream>

// Find function in arrrays;
// O(n);

class Array{
    private:
        int *A;
        int capacity;
        int size;
    public:
        Array(int cap);
        ~Array();
        void append(int data);
        void display() const;
        int find(int value) const;
};

Array::Array(int cap){
    capacity = cap;
    A = new int[capacity];
    size  = 0;
}

Array::~Array(){
    delete []A;
}

void Array::append(int data){
    if(size == capacity){
        std::cout <<  "Array is full\n";
        return;
    }
    A[size] = data;
    size++;
}

void Array::display() const{
    if(size == 0){
        std::cout << "Array is empty\n";
        return;
    }
    for(int i = 0; i<size; ++i){
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

}

int Array::find(int value) const{
    for(int i = 0; i < size; ++i){
        if(A[i] == value){
            return i;
        }
    }
    return -1;
}



int main(){

    int arr[5] = {1, 2, 3, 4, 5};
    Array arr1(5);
    for(int i = 0; i<5; i++){
        arr1.append(arr[i]);
    }
    arr1.display();
    std::cout << arr1.find(10);



    return 0;
}