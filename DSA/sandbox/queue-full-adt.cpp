#include<iostream>


struct node{
    int data;
    node *next;
};


class Queue{
    private:
        node *front;
        node *rear;
    public:
        Queue();
        ~Queue();
        void enqueue(int data);
        int dequeue();
        bool isFull() const;
        bool isEmpty() const;
        void display() const;
};

Queue::Queue(){
    front = rear = nullptr;
}

bool    Queue::isEmpty() const{
    if(front == rear){
        return true;
    }
    return false;
}

bool Queue::isFull() const{
    node *temp = new node;
    if(temp == nullptr){
        return true;
    }
    return false;
}

void Queue::enqueue(int data){
    if(isFull()){
        std::cout << "Queue is full\n";
        return;
    }
    node *temp = new node;
    temp->data = data;
    if(front == nullptr){
        front = rear = temp;
        temp->next = nullptr;
    }else{
        rear->next = temp;
        rear = temp;
    }
}

int Queue::dequeue(){
    if(isEmpty()){
        return -1;
    }
    node *temp = front;
    front = front->next;
    int x = temp->data;
    delete temp;
    temp = nullptr;
    return x;
}

Queue::~Queue(){
    node *temp = front;
    while(temp != nullptr){
        node *next = temp->next;
        delete temp;
        temp = next;
    }
}

void Queue::display() const{
    node *temp = front;
    while(temp != nullptr){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}


int main(){
    Queue q1;
    q1.enqueue(10);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.display();
    std::cout << "Deleted: " << q1.dequeue() << std::endl;
    q1.display();
    return 0;
}