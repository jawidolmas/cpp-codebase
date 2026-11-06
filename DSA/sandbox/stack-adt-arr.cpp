#include<iostream>

class stack{
    private:
        int capacity;
        int *A;
        int size;
        int top;
    public:
        stack(int cap) : capacity(cap), A(new int[capacity]), size(0), top(-1){}; 
        ~stack();
        void push(int key);
        int pop();
        int Top() const;
        bool isEmpty() const;
        bool isFull() const;
        void display() const;
};

stack::~stack(){
    delete []A;
}

bool stack::isEmpty() const{
    if(top == - 1){
        return true;
    }
    return false;
}

bool stack::isFull() const{
    if(top == capacity-1){
        return true;
    }
    return false;
}

void stack::push(int key){
    if(isFull()){
        std::cout << "Stack is Full\n";
        return;
    }
    top++;
    A[top] = key;
    size++;
}

int stack::pop(){
    if(isEmpty()){
        return -1;
    }
    int index = top;
    top--;
    return A[index];
}

int stack::Top() const{
    if(isEmpty()){
        return -1;
    }
    return A[top];
}

void stack::display() const{
    if(isEmpty()){
        std::cout << "Stack is empty\n";
        return;
    }
    for(int i = size-1; i>=0; i--){
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}


int main(){
    stack s1(10);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.display();



    return 0;
}