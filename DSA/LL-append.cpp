#include<iostream>
#include<vector>


// Singly linked list
// Appending a data in linked list


struct node{
    int data;
    node *next;
} *head = nullptr;




// Append (Adding at the end)
void append(int data){
    node *temp = new node;
    temp->data = data;
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
    
    append(43);
    append(44);
    append(45);
    
    
    display();

    return 0;
}