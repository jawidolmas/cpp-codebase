#include<iostream>
#include<stack>
//Depth First Search


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


// Search Algorithm
void Depth_First_Search(node* root, char target){
    if(root == nullptr){
        std::cout << "Empty tree\n";
        return;
    }
    std::stack<node*> stack;
    stack.push(root);
    while(!stack.empty()){
        node* current = stack.top();
        stack.pop();
        if(current->data == target){
            std::cout << "Target found at " << current << " ";
            return;
        }
        if(current->right){
            stack.push(current->right);
        }
        if(current->left){
            stack.push(current->left);
        }
    }
    std::cout << "Target not found in tree\n";
}



int main(){
    std::cout << "Enter the root of tree(x is empty tree or leaf): ";
    node *root = create();
    std::cout << "\nDepth First search: ";
    Depth_First_Search(root, 'w');
    return 0;
}

