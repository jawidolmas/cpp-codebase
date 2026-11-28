#include<iostream>
#include<stack>
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

void Depth_First_Values(node* root){
    std::stack<node*> stack;
    if(root != nullptr){
        stack.push(root);
    }
    while(!stack.empty()){
        node* current = stack.top();
        stack.pop();
        std::cout << current->data << " ";
        if(current->right){
            stack.push(current->right);
        }    
        if(current->left){
            stack.push(current->left);
        }
    }
}





int main(){
    std::cout << "Enter the root of tree(x is empty tree or leaf): ";
    node *root = create();
    std::cout << "\nDepth First Traversal: ";
    Depth_First_Values(root);
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