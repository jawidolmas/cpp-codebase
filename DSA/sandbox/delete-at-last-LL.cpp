#include<iostream>
#include "singlyll.hpp"
#include "doublyll.hpp"

// Delete a value in last of the list
void linkedlist::deleteLast(){
    if(isEmpty()){
        std::cout << "List is empty\n";
        return;
    }
   
    node *temp = head;
    node *prev = nullptr;
    while (temp->next != nullptr)
    {
        prev = temp;
        temp = temp->next;
    }
     int x = temp->data;
    if(prev == nullptr){
        head = nullptr;
    }else{
        prev->next = nullptr;
    }
    delete temp;
    temp = nullptr;
    std::cout << "Value " << x << " is deleted\n";
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
    l1.deleteLast();
    l1.display();

    return 0;
}