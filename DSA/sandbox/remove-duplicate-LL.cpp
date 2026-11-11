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

void linkedlist::checkDuplicate(){
    if(head == nullptr){
        cout << "empty\n";
        return;
    }
    node *p = head;
    while(p != nullptr && p->next != nullptr){
        node *t = p;
        node *q = p->next;
        while(q != nullptr){
            if(p->data == q->data){
                node* temp = q;
                t->next = q->next;
                delete temp;
                temp = nullptr;
                q = q->next;
            }else{
                t = q;
                q = q->next;
            }
        }
        p = p->next;
    }
}


int main(){
    linkedlist l1;
    l1.create(1);
    l1.create(2);
    l1.create(2);
    l1.create(1);
    l1.create(3);
    l1.checkDuplicate();
    l1.display();
}


