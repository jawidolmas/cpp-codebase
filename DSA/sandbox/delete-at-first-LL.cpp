#include<iostream>
#include "singlyll.hpp"
#include "doublyll.hpp"


// Delete at first in a singly linked list
void linkedlist::deleteFirst(){
    if(isEmpty()){
        std::cout << "List is empty\n";
        return;
    }
    int x = 0;
    node *temp = head;
    head = head->next;
    x = temp->data;
    std::cout << "Value " << x << " is deleted\n";
    delete temp;
    temp = nullptr;
    
}




int main()
{
    linkedlist l1;
    // l1.addatBeg(10);
    // l1.addatBeg(20);
    // l1.addatBeg(30);
    // l1.addatEnd(50);
    l1.insert(0, 10);
    l1.insert(1, 20);
    l1.insert(2, 30);
    l1.deleteFirst();
    l1.display();

    return 0;
}