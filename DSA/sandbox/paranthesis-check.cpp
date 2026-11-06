


// Paranthesis check with stack

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