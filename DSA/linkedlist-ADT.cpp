#include<iostream>


struct node{
    int data;
    node *next;
};

class linkedlist{
    private:
        node *head;
    public:
        linkedlist();
        ~linkedlist();
        bool isEmpty() const;
        bool isFull() const;
        int length() const;
        void create(int data);
        void display() const;
        int search(int key) const;
        void insert(int index, int data);
        void remove(int data);
};

linkedlist::linkedlist(){
    head = nullptr;
}

linkedlist::~linkedlist(){
    node *current = head;
    while(current != nullptr){
        node *next = current->next;
        delete current;
        current = next;
    }
}

bool linkedlist::isEmpty() const{
    if(head == nullptr){
        return true;
    }
    return false;
}

bool linkedlist::isFull() const{
    node *temp = new node;
    if(temp == nullptr){
        return true;
    }
    return false;
}

int linkedlist::length() const{
    int count = 0;
    node *temp = head;
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}

void linkedlist::create(int data){
    node *temp = new node;
    temp->data = data;
    temp->next = nullptr;

    if(isEmpty()){
        head = temp;
    }else{
        node *addNew = head;
        while(addNew->next != nullptr){
            addNew = addNew->next;
        }
        addNew->next = temp;
    }
}

void linkedlist::display() const{
    if(isEmpty()){
        std::cout << "Array is empty\n";
        return;
    }
    node *temp = head;
    while(temp != nullptr){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int linkedlist::search(int key) const{
    node *temp = head;
    while(temp != nullptr){
        if(temp->data == key){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void linkedlist::insert(int index, int data){
    if(index < 0 || index > length()){
        std::cout << "Invalid index\n";
        return;
    }
    if(isFull()){
        std::cout << "Heap is full\n";
        return;
    }
    node *temp = new node;
    temp->data = data;
    temp->next = nullptr;
    if(index == 0){
        if(isEmpty()){
            head = temp;
        }else{
            temp->next = head;
            head = temp;
        }
    }else{
        node *p = head;
        for(int i = 0; i<index-1; i++){
            p = p->next;
        }
        if(p){
            temp->next = p->next;
            p->next = temp;
        }
    }
}


void linkedlist::remove(int index){
    int x;
    if(index < 0 || index > length()){
        std::cout << "Invalid index\n";
        return;
    }
    if(isEmpty()){
        std::cout << "List is empty\n";
        return;
    }
    node *temp = head;
    if(index == 0){
        if(head->next == nullptr){
            x = head->data;
            delete head;
            head = nullptr;
        }else{
            head = head->next;
            x = temp->data;
            delete temp;
            temp = nullptr;
        }
    }else{
        node *p = nullptr;
        
        for(int i = 0; i<index-1; i++){
            p = temp;
            temp = temp->next;
            
        }
        if(temp){
            p->next = temp->next;
            x = temp->data;
            delete temp;
            temp = nullptr;
        }
    }
    std::cout << "Value " << x << " deleted\n";
}






int main()
{
    linkedlist l1;
    l1.create(15);
    l1.create(16);
    l1.create(17);
    l1.insert(0,14);
    l1.insert(4, 20);
    l1.remove(5);
    l1.display();
    std::cout << l1.search(20);
}