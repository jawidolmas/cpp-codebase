#include<iostream>


// BINARY TREE. WE NEED TO KNOW THAT WE CANNOT CREATE A BINARY TREE OR EVEN A TREE WITHOUT A STACK OR A QUEUE. BECUASE WE NEED TO REMEMBER WHO IS THE PARENT OF WHO. 
// WE CAN IMPLEMENT IT USING RECURSION, THANKS TO STACK CALL OF RECURSIONS. 


struct node
{
    int data;
    node *left_child;
    node *right_child;

    node(int data){
        this->data = data;
        left_child = nullptr;
        right_child = nullptr;
    }
};




node* create(){
    int value;
    std::cin >> value;

    if(value == -1){
        return nullptr;
    }

    node* root = new node(value);

    std::cout << "Enter left child of " << value << ": ";
    root->left_child = create();
    std::cout << "Enter right child of " << value << ": ";
    root->right_child = create();

    return root;
}

void traversal(node* root) {
    if (root == nullptr) {
        return;
    }

    std::cout << root->data << " ";
    traversal(root->left_child);
    traversal(root->right_child);
}

int main(){
    std::cout << "Enter the root of tree(-1 is empty tree or leaf): ";
    node *root = create();
    std::cout << "\nPreorder Traversal: ";
    traversal(root);


    return 0;
}