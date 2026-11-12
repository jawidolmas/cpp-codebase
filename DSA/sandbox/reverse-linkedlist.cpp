#include<iostream>

using namespace std;

struct node
{
    int data;
    node* next;
};


class linkedlist{
    private:
        node *head;
    public:
        linkedlist() : head(nullptr){}
        ~linkedlist();
        void create(int data);
        void display() const;
        void checkDuplicate();
        void reverse();


};

linkedlist::~linkedlist(){
    node *temp = head;
    while(temp != nullptr){
        node *next = temp->next;
        delete temp;
        temp = next;
    }
}

void linkedlist::create(int data){
    node *temp = new node;
    temp->data = data;
    temp->next = nullptr;

    if(head == nullptr){
        head = temp;
        return;
    }
    node *p = head;
    while(p->next != nullptr){
        p = p->next;
    }
    p->next = temp;

}

void linkedlist::display() const{
    if(head == nullptr){
        cout << "empty\n";
        return;
    }
    node *temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}



void linkedlist::reverse(){
    if(head ==  nullptr){
        cout << "list is empty\n";
        return;
    }
    node *prev = nullptr;
    node *curr = head;
    node *next = nullptr;
    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}


int main(){
    linkedlist l1;
    l1.create(1);
    l1.create(2);
    l1.reverse();
    l1.display();
}



