#include<iostream>

// COUNT AND SUM

struct node{
    int data;
    node* left;
    node *right;

    node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

node* create(){
    int value;
    std::cin >> value;
    if(value == -1){
        return nullptr;
    }
    node* root =new  node(value);

    std::cout << "Left child of " << root->data << ": ";
    root->left = create();
    std::cout << "Right child of " << root->data << ": ";
    root->right = create();

    return root;
}

void traversal(node* root){
    if(root == nullptr){
        return;
    }
    traversal(root->left);
    std::cout << root->data << " ";
    traversal(root->right);
}

int count(node* root){
    int x = 0, y = 0;
    if(root != nullptr){
        x = count(root->left);
        y = count(root->right);
        return x + y + 1;
    }
    return 0;
}

int sum(node* root){
    int x = 0, y = 0;
    if(root!=nullptr){
        x = sum(root->left);
        y = sum(root->right);
        return x+y+root->data;
    }
    return 0;
}



int main(){
    std::cout << "Enter the root of tree(-1 is empty tree or leaf): ";
    node *root = create();
    std::cout << "\nInorder Traversal: ";
    traversal(root);
    std::cout << "\nCount of Nodes: " << count(root);
    std::cout << "\nSum of Nodes: " << sum(root) << std::endl;


    return 0;
}