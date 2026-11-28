#include<iostream>
#include<queue>
//  Breadth First Search is a kind of search or traversal that we go to traverse the like we do in level order. 
//  Conversely to DFS, Breadth First Traversal uses Queue to be implemented and is too hard, uneffiecient and not recommended to be implemented using Recursion coz
// recursion uses stack under the hood. 

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

// Breadth First Search
void Breadth_First_Search(node* root, char target){
    if(root == nullptr){
        std::cout << "Empty tree\n";
        return;
    }
    std::queue<node*> q1;
    q1.push(root);
    while(!q1.empty()){
        node* current = q1.front();
        q1.pop();
        if(current->data == target){
            std::cout << "Target found in " << current << " ";
            return;
        }
        if(current->left) q1.push(current->left);
        if(current->right) q1.push(current->right);
    }
    std::cout << "Target not found\n";
}


void freeMem(node*& root) {
    if (!root) {
        return;
    }

    freeMem(root->left);
    freeMem(root->right);

    delete root;
    root = nullptr; 
}


int main(){
    std::cout << "Enter the root of tree(x is empty tree or leaf): ";
    node *root = create();
    std::cout << "\nBreadth First search: ";
    Breadth_First_Search(root, 'c');    // Breadth First search: Target found in 0x5e90b5d7f8c0


    freeMem(root);  // Deletes all allocated memory recursively
    return 0;
}
