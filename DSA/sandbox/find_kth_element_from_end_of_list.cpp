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
        int find_kth_element_from_end_of_list(int k);


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


int linkedlist::find_kth_element_from_end_of_list(int k){
    if(head == nullptr){
        return -1;
    }
    if(k <= 0){
        return -1;
    }
    node* first = head;
    node *kth = head;
    for(int i = 0; i<k; i++){
        if(kth == nullptr){
            return -1;
        }
        kth = kth->next;
    }
    while(kth != nullptr){
        kth = kth->next;
        first = first->next;
    }
    return first->data;
}



int main(){
    linkedlist l1;
    l1.create(10);
    l1.create(20);
    l1.create(30);
    l1.create(40);
    l1.create(50);
    cout << l1.find_kth_element_from_end_of_list(10);
    //l1.display();
}


