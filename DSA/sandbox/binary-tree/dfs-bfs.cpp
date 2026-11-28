#include<iostream>
#include<stack>
#include<queue>


struct node
{
    char data;
    node* left;
    node* right;
};

class bfs{
    private:
        node* root;
    public:
        bfs();
        ~bfs();
        void create();
        void breadth_first_search(char targer) const;
        void depth_first_search(char target) const;
        void display_bfs()const;
        void display_dfs()const;
};

bfs::bfs(){
    root = nullptr;
}

// create tree
void bfs::create(){
    std::queue<node*> q1;
    char value; 
    std::cout << "Enter the root of the tree: ";
    std::cin >> value;
    node* temp, *p;
    temp = new node;
    temp->data = value;
    temp->left = temp->right = nullptr;
    q1.push(temp);
    root = temp;
    while(!q1.empty()){
        p = q1.front(); q1.pop();
        std::cout << "Enter the left child of " << p->data << ": ";
        std::cin >> value;
        if(value != 'x'){
            temp = new node;
            temp->data = value;
            temp->left = temp->right = nullptr;
            p->left = temp;
            q1.push(temp);
        }
        std::cout << "Enter the right child of " << p->data << ": ";
        std::cin >> value;
        if(value != 'x'){
            temp = new node;
            temp->data = value;
            temp->left = temp->right = nullptr;
            p->right = temp;
            q1.push(temp);
        }
    } 
}

//BFS - QUEUE

void bfs::breadth_first_search(char target) const{
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
            std::cout << "Target '" << target << "' found at: " << current << ".\n";
            return;
        }
        if(current->left) q1.push(current->left);
        if(current->right) q1.push(current->right);
    }
    std::cout << "Target '"<< target << "' not found\n";
}


// DFS - STACK
void bfs::depth_first_search(char target) const{
    std::stack<node*> s1;
    if(root == nullptr){
        std::cout << "Empty tree\n";
        return;
    }
    s1.push(root);
    while(!s1.empty()){
        node* current = s1.top(); s1.pop();
        if(current->data == target){
            std::cout << "Target '" << target << "' found at: " << current << ".\n";
            return;
        }
        if(current->right) s1.push(current->right);
        if(current->left) s1.push(current->left);
    }
    std::cout << "Target '"<< target << "' not found\n";
}

// Display - BFS
void bfs::display_bfs()const{
    std::queue<node*> q1;
    if(root == nullptr){
        std::cout << "Empty tree\n";
        return;
    }
    q1.push(root);
    while(!q1.empty()){
        node* current = q1.front(); q1.pop();
        std::cout << current->data << " ";
        if(current->left) q1.push(current->left);
        if(current->right) q1.push(current->right);
    }
    std::cout << std::endl;
}

// Display - DFS
void bfs::display_dfs()const{
    std::stack<node*> s1;
    if(root == nullptr){
        std::cout << "Empty tree\n";
        return;
    }
    s1.push(root);
    while(!s1.empty()){
        node* current = s1.top(); s1.pop();
        std::cout << current->data << " ";
        if(current->right) s1.push(current->right);
        if(current->left) s1.push(current->left);
    }
    std::cout << std::endl;
}


bfs::~bfs(){
        if (!root) {
            return;
        }

        std::queue<node*> q;
        q.push(root);

        while (!q.empty()) {
            node* current = q.front();
            q.pop();

            if (current->left) {
                q.push(current->left);
            }
            if (current->right) {
                q.push(current->right);
            }

            delete current;
        }

        root = nullptr;
}


int main()
{

    bfs b1;
    b1.create();
    std::cout << "BFS:";
    b1.breadth_first_search('c');
    std::cout << "DFS:";
    b1.depth_first_search('c');
    std::cout << "BFS Traversal: ";
    b1.display_bfs();
    std::cout << "DFS Traversal: ";
    b1.display_dfs();

    return 0;
}

    /*...
            BFS:Target 'c' found at: 0x59421d133ae0.
            DFS:Target 'c' found at: 0x59421d133ae0.
            BFS Traversal: a b c d e f 
            DFS Traversal: a b d e c f
    */