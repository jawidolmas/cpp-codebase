#include<iostream>
#include "singlyll.hpp"
#include "doublyll.hpp"

// Delete by value in a singly linked list
void linkedlist::deleteByValue(int data){
    if(isEmpty()){
        std::cout << "List is empty\n";
        return;
    }
    node *temp = head;
    node *p = nullptr;
    int x = 0;
    if(head->data == data){
        head = head->next;
        x = temp->data;
        delete temp;
        temp = nullptr;
        std::cout << x << " Deleted\n";
    }else{
        while(temp != nullptr && temp->data != data){
            p = temp;
            temp = temp->next;
        }
        if(temp && temp->data == data){
            p->next = temp->next;
            x = temp->data;
            delete temp;
            temp = nullptr;
            std::cout << x << " Deleted\n";
        }else{
            std::cout << "Value not found\n";
            return;
        }   

    }
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
    l1.deleteByValue(10);
    l1.display();

    return 0;
}