#include<iostream>
#include<queue>
#include<iomanip>
#include<deque>


// Question 1
void sumofAvg(){
    std::cout << "Enter queue size: ";
    int count;
    std::cin >> count;
    std::queue<int> q1;
    std::cout << "Enter numbers: ";
    for(int i = 0; i<count; i++){
        int value;
        std::cin >> value;
        q1.push(value);
    }
     int sum = 0;
    while(!q1.empty()){
      sum   +=  q1.front();
       q1.pop();
    }
    std::cout << "Sum: " << sum << std::endl;
    double average =  static_cast<double>(sum)/count;
    std::cout << "Average: " << std::fixed << std::setprecision(1) << average << std::endl;
}


// Question 2
void simple_bank_customer(){
    std::queue<std::string> q1;
    const int customer = 4;
    std::cout << "Name of Customers: \n";
    for(int i = 0; i<customer; i++){
        std::cout << "Customer Name" << i+1 << ": ";
        std::string name;
        std::cin >> name;
        q1.push(name);
    }
    std::cout << "First Customer: " << q1.front() << " Last Customer: " << q1.back() << " Total: " << q1.size() << std::endl;
    std::cout << "Customer " << q1.front() << " Served. "; q1.pop();
    std::cout << "Customer " << q1.front() << " Served. "; q1.pop();
    std::cout << "Total Customer Remaining: " << q1.size() << std::endl;   
    std::cout << "Current Customers: "; 
    while(!q1.empty()){
        std::cout  << q1.front() << "   ";
        q1.pop();
    }   
    std::cout << std::endl;
}


// Question 3
void seperate_odd_even_numbers(){
    std::queue<int> q1;
    int count;
    std::cout << "Enter size of queue: ";
    std::cin>> count;
    std::cout << "Enrer Numbers: \n";
    for(int i = 0; i<count; i++){
        int value;
        std::cin >> value;
        q1.push(value);
    }
    std::queue<int> even, odd;
    while(!q1.empty()){
        if(q1.front() % 2 == 0){
            even.push(q1.front());
            q1.pop();
        }else{
            odd.push(q1.front());
            q1.pop();
        }
    }
    std::cout << "Even Queue: ";
    while(!even.empty()){
       std::cout <<  even.front() << " ";
       even.pop();
    }std::cout<<std::endl;
    std::cout << "Odd Queue: ";
    while(!odd.empty()){
       std::cout <<  odd.front() << " ";
       odd.pop();
    }
    std::cout << std::endl;
}



// Question 4
void palindrom_check() {
    std::string word;
    std::queue<char> q1;

    std::cout << "Enter a word (no spaces, uppercase letters, or punctuation): ";
    std::cin >> word;
    const char* ptr = word.c_str();
    while (*ptr != '\0') {
        q1.push(*ptr);
        ++ptr;
    }

    bool palindrome = true;
    ptr = word.c_str() + word.size() - 1;
    while (!q1.empty()) {
        if (q1.front() != *ptr) {
            palindrome = false;
        }

        q1.pop();
        --ptr;
    }
    if (palindrome) {
        std::cout << "Word is a palindrome\n";
    } else {
        std::cout << "Word is not a palindrome\n";
    }
}


// EXTENDED PALINDROME USING DOUBLE ENDED QUEUE FOR INSTRUCTORS REQUEST
void imporved_palindrome(){
    std::deque<char> q1;
    std::string word;
    std::cout << "Enter a word: (No spaces, no uppercase, no puntuations): ";
    std::cin >> word;
    const char* ptr = word.c_str();
    while(*ptr != '\0'){
        q1.push_front(*ptr);
        ptr++;
    }
    bool palindrome = true;
    std::size_t left = 0;
    std::size_t right = q1.size() - 1;
    while(left < right){
        if(q1[left] != q1[right]){
            palindrome = false;
            break;
        }
        left++;
        right--;
    }
    if(palindrome){
        std::cout << "Word is Palindrome\n";
    }else{
        std::cout <<"Word is not palindrome\n";
    }

    
    std::cout << std::endl; 
}


// Question 5
struct Node {
    int data;
    Node* left;
    Node* right;
};

void createBinaryTree() {
    Node* root = new Node;
    root->data = 10;
    root->left = nullptr;
    root->right = nullptr;

    Node* leftChild = new Node;
    leftChild->data = 5;
    leftChild->left = nullptr;
    leftChild->right = nullptr;

    Node* rightChild = new Node;
    rightChild->data = 15;
    rightChild->left = nullptr;
    rightChild->right = nullptr;

    root->left = leftChild;
    root->right = rightChild;

    std::cout << "Root: " << root->data << std::endl;
    std::cout << "Left child: " << root->left->data << std::endl;
    std::cout << "Right child: " << root->right->data << std::endl;

    delete root->left;
    delete root->right;
    delete root;

    root = nullptr;
    leftChild = nullptr;
    rightChild = nullptr;
}











int main(){

         sumofAvg();
         simple_bank_customer();
         seperate_odd_even_numbers();
         palindrom_check();
         createBinaryTree();
        imporved_palindrome();
        return 0;
}