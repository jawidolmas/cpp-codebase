#include<iostream>
#include<stack>



void display(std::stack<int>& s){
    while(!s.empty()){
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}


//Question One:

void question_one(){
    std::stack<int> s1;
    
    // Empty state check
    std::cout << "Check stack initail state: ";
    if(s1.empty()){
        std::cout << "Empty\n";
    }else{
        std::cout << "Not Empty\n";
    }
    std::cout << std::endl;

    // Add element 
    std::cout << "Add elements to stack: ";
    s1.push(25);
    s1.push(24);
    s1.push(22);
    s1.push(21);
    //print
     std::stack<int> temp = s1;
    while(!temp.empty()){
        std::cout << temp.top() << "-";
        temp.pop();
    }
    std::cout << std::endl;

    // First in - Last out
    std::cout << "\nshow stack elements(print first in last out):\n";
    std::stack<int> temp2 = s1;
    while(!temp2.empty()){
        std::cout << temp2.top() << " ";
        temp2.pop();
    }
    
    // Last in First out
    std::cout << "\n\nshow stack elements(print last in first out):\n";
    std::stack<int> temp5 = s1;
    std::stack<int> temp3;
    while(!temp5.empty()){
        temp3.push(temp5.top());
        temp5.pop();
    }
    while(!temp3.empty()){
        std::cout << temp3.top() << " ";
        temp3.pop();
    }

    // Delete first two, then print last in first out.
    std::cout << "\n\nDelete two elements(print last in first out):\n";
    std::stack<int> temp4;
    std::stack<int> temp7 = s1;
    while(!temp7.empty()){
        temp4.push(temp7.top());
        temp7.pop();
    }
    temp4.pop();
    temp4.pop();
    while(!temp4.empty()){
        std::cout << temp4.top() << " ";
        temp4.pop();
    }
    std::cout << std::endl;

}



// Question 2
void sort(std::stack<int> s2){
    std::cout << "Sorted stack: " << std::endl;
    std::stack<int> temp;
    while(!s2.empty()){
        int current = s2.top();
        s2.pop();
        while(!temp.empty() && temp.top() > current){
            s2.push(temp.top());
            temp.pop();       
        }
    temp.push(current);
    }
    
    display(temp);
}


// Question 3
bool isPalindrome(std::string word){
    const char* left = word.c_str();
    const char* right = word.c_str() + word.size()-1;

    while(left < right){
        if(*left != *right){
            return false;
        }
        left++;
        right--;
    }
    return true;    
}

bool isPalindromeStack(std::string word){
    const char* first = word.c_str();
    std::stack<char> s1;
    while(*first != '\0'){
        s1.push(*first);
        first++;
    }
    first = word.c_str();
    while(!s1.empty()){
        if (*first == s1.top()){
            first++;
            s1.pop();
        }else{
            return false;
        }
    }
    return true;

}


// Question 4
void paranthesisCheck(std::string expression){
    std::stack<char> s;
    const char* left = expression.c_str();
    bool foundParanthesis = false;
    while(*left != '\0'){
        if(*left == '(' || *left == '[' || *left == '{'){
            foundParanthesis = true;
            s.push(*left);
        }else if(*left == ')' || *left == ']' || *left == '}'){
            if(s.empty()){
                std::cout << "Paranthesis not matched\n";
                return;
            }
            bool matches = ((*left == ')' && s.top() == '(')||
                            (*left == ']' && s.top() == '[') ||
                            (*left == '}' && s.top() == '{' ));
                        
            if(matches){
                foundParanthesis = true;
                s.pop();
            }else{
                std::cout << "Paranthesis not matched\n";
                return;
            }
        }       
        left++;    
    }
    if(!foundParanthesis){
        std::cout << "No paranthesis found at all\n";
    }
    else if(s.empty()){
        std::cout << "Paranthesis matched\n";
    }else{
        std::cout << "Paranthesis not matched\n";
    }
}




int main(){
    question_one();
    std::stack<int> s1;
    s1.push(10);
    s1.push(8);
    s1.push(50);
    s1.push(1);
    sort(s1);
    std::string word = "jaan";
    if(isPalindromeStack(word)){
        std::cout << "Palindrome\n";
    }else{
        std::cout << "Not palindrome\n";
    }

    paranthesisCheck(word);
    return 0;
}