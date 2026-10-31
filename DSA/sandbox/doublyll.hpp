#include<iostream>

struct Node{
    Node *prev;
    int data;
    Node *next;
};

class doublylist{
    private:
        Node *head;
        Node *tail;
    public:
        doublylist();
        ~doublylist();
        void addatBeg(int data);
        void addatEnd(int data);
        bool isEmpty() const;
        void display() const;
};

doublylist::doublylist(){
    head = nullptr;
    tail = nullptr;
}

doublylist::~doublylist(){
    Node *temp = head;
    while(temp != nullptr){
        Node *next = temp->next;
        delete temp;
        temp = next;
    }
}

bool doublylist::isEmpty() const{
    if(head == nullptr){
        return true;
    }
    return false;
}

void doublylist::addatBeg(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->prev = nullptr;
    temp->next = nullptr;
    if(isEmpty()){
        head = temp;
        tail = temp;
    }else{
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}  

void doublylist::addatEnd(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->prev = nullptr;
    temp->next = nullptr;
    if(isEmpty()){
        head = temp;
        tail = temp;
    }else{
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }

}

void doublylist::display() const{
    Node *temp = head;
    while(temp != nullptr){
        std::cout << temp->data <<" ";
        temp = temp->next; 
    }
}
