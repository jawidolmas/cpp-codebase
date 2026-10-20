#include<iostream>
#include<vector>


// Singly linked list
// Creating a list and display functions


struct node{
    int data;
    node *next;
} *head = nullptr;

void create(int n){
    node *temp = new node;
    temp->data = n;
    temp->next = nullptr;
    if(head == nullptr){
        head = temp;
        return;
    }
    node *current = head;
    while(current->next != nullptr){
        current = current->next;
    }

    current->next = temp;
}


// Add at the beginning
void addatBeg(int key)
{
    node *temp = new node;
    temp->data = key;
    temp->next = nullptr;
    if(head == nullptr){
        head = temp;
        return;
    }
    temp->next = head;
    head = temp;



}
void display(){
    if(head == nullptr){
        std::cout << "List is empty\n";
        return;
    }
    node* temp = head;
    while(temp != nullptr){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}




int main(){

    create(15);
    create(10);
    addatBeg(40);
    addatBeg(55);
    display();

    return 0;
}