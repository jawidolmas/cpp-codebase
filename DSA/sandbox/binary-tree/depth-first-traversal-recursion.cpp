#include<iostream>
// Depth First Values: This is not a search, it is just a traversal and printing algorithm. 
// For Depth first search or Depth first values, we difinitely need a stack. either programmers stack or stack frame of recursion. 

struct node{
    char data;
    node* left;
    node *right;

    node(char value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

node* create(){
    char value;
    std::cin >> value;

    if(value == 'x'){
        return nullptr;
    }

    node *root = new node(value);
    std::cout << "Enter Left child of " << root->data << ": ";
    root->left = create();
    std::cout << "Enter Right child of "<< root->data << ": ";
    root->right = create();

    return root;
}


node* depth_first_traversal_recursion(node* root){
    if(root == nullptr){
        return nullptr;
    }
    std::cout << root->data << " ";
    // Recursive does not return until all of the function finished, once it reaches the scope, then it returns. that is why we first traversed the left, then right.
    // while returning, the right will be at the top of stack(LIFO) and will be printed.
    depth_first_traversal_recursion(root->left);
    depth_first_traversal_recursion(root->right);
    return root;
}




int main(){
    std::cout << "Enter the root of tree(x is empty tree or leaf): ";
    node *root = create();
    std::cout << "\nDepth First Traversal: ";
    depth_first_traversal_recursion(root);
    return 0;
}

/*

    Enter the root of tree(x is empty tree or leaf): a
    Enter Left child of a: b
    Enter Left child of b: d
    Enter Left child of d: x
    Enter Right child of d: x
    Enter Right child of b: e
    Enter Left child of e: x
    Enter Right child of e: x
    Enter Right child of a: c
    Enter Left child of c: x
    Enter Right child of c: f
    Enter Left child of f: x
    Enter Right child of f: x

    Depth First Traversal: a b d e c f
*/