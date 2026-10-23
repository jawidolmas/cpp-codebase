#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<forward_list>

//Question 1. Step 1.
void PushtheValue(std::vector<int> &A, int data){
    for(int i = 0; i<data; i++){
        A.push_back(i);
    }
}

void display(std::vector<int> &A){
    for(int i = 0; i<A.size(); i++){
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

void Adds(std::vector<int> &A){
    for(int i = 0; i<A.size(); i++){
        std::cout << &A[i] << "\n";
    }
    std::cout << std::endl;
}
/*
Output:
    0 1 2 3 4 5 6 7 8 9 
    0x1de6182f6b0
    0x1de6182f6b4
    0x1de6182f6b8
    0x1de6182f6bc
    0x1de6182f6c0
    0x1de6182f6c4
    0x1de6182f6c8
    0x1de6182f6cc
    0x1de6182f6d0
    0x1de6182f6d4

    As we can see in here, the output shows a pattern. Our data type is integer so it takes 4 bytes of memory in my compiler. 
    in here, the pattern is b0, b4, b8... in fact we can see the ROW MAJOR MAPPING in here. THE REASON THAT CLEARLY SHOWS ARRAYS 
    ARE CONTINGOUS. 

*/

//END OF QUESTION 1. STEP 1.

//Question 1. STEP 2.
void linkedlist(std::list<int> Mylist, int data){
    for(int i = 0; i<data; i++){
        Mylist.push_back(i);
    }
    // display
    for(int i:Mylist){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Addresses
    for(const int& i:Mylist){
        std::cout << &i << "\n";
    }
    std::cout << std::endl;

    /*
    Output:
        0 1 2 3 4 5 6 7 8 9 
        0x1de61837d40
        0x1de61837d80
        0x1de61837c40
        0x1de61837da0
        0x1de61837dc0
        0x1de61837be0
        0x1de61837c60
        0x1de61837e00
        0x1de61837e20
        0x1de61837ae0

        Conversly to arrays, we can see some complex and unorganized pattern in adds of linked list. In here the adds are random coz they 
        are all stored in heap(a pool of memory). This is the reason that linked list in non-contigous
    
    
    */
// End of question 1. step 2
}


// Question 1. step 4
void PushtheValueDouble(std::vector<double> &A, double data){
    for(double i = 0; i<data; i++){
        A.push_back(i);
    }
}

void displayDouble(std::vector<double> &A){
    for(double i = 0; i<A.size(); i++){
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

void AddsDouble(std::vector<double> &A){
    for(double i = 0; i<A.size(); i++){
        std::cout << &A[i] << "\n";
    }
    std::cout << std::endl;
}
/*
    0 1 2 3 4 5 6 7 8 9 
    0x1cd6ef3ec50
    0x1cd6ef3ec58
    0x1cd6ef3ec60
    0x1cd6ef3ec68
    0x1cd6ef3ec70
    0x1cd6ef3ec78
    0x1cd6ef3ec80
    0x1cd6ef3ec88
    0x1cd6ef3ec90
    0x1cd6ef3ec98
        The addresses changes when I changed the datatype to double. in my compiler, its 8 bytes, so we can see the pattern 50, 58,... 
        and the pattern we see is contingous. 
*/

void linkedlistDouble(std::list<double> Mylist, double data){
    for(double i = 0; i<data; i++){
        Mylist.push_back(i);
    }
    // display
    for(double i:Mylist){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Addresses
    for(const double& i:Mylist){
        std::cout << &i << "\n";
    }
    std::cout << std::endl;
    
    /*
    Output:

    0x1bcc4ab7b60
    0x1bcc4ab7820
    0x1bcc4ab7920
    0x1bcc4ab7b40
    0x1bcc4ab7b80
    0x1bcc4ab7860
    0x1bcc4ab7960
    0x1bcc4ab7980
    0x1bcc4ab79c0
    0x1bcc4ab79e0
    This is linked list with double data type. Though it makes no sense in terms of adds, coz the adds are non contigous and we can not
    clearly see how much bit or byte pattern exist in here. However, we know that double also takes 8  bytes plus pointers. 
    
    END OF  QUESTION 1. STEP 4
    */
}


// QUESTION 2. 

void twoDArray(std::vector<std::vector<int>> &A){
    int dimensionRow, dimensionCol;
    std::cout<< "The dimension of 2D array?(ROW):";
    std::cin >> dimensionRow;
    std::cout<< "The dimension of 2D array?(COL):";
    std::cin >> dimensionCol;
    A.assign(dimensionRow, std::vector<int>(dimensionCol, 0));

    for (int i = 0; i < dimensionRow; i++) {
        for (int j = 0; j < dimensionCol; j++) {
            std::cout << "A[" << i << "][" << j << "] = ";
            std::cin >> A[i][j];
        }
    }

    // Display
    
    for (std::size_t i = 0; i < A.size(); i++) {
        for (std::size_t j = 0; j < A[i].size(); j++) {
            std::cout << "A[" << i << "][" << j << "] = "
                      << A[i][j]
                      << ", address = " << &A[i][j] << '\n';
        }
        std::cout << '\n';
    }

    // Total Amount of memory:

    std::size_t totalMemory = dimensionRow * dimensionCol * sizeof(int);

    std::cout << "\nTotal amount of memory used: "
              << totalMemory << " bytes\n";

}
// End of QUESTION 2;


// Question 3
void Question3(std::vector<int> &A){
    std::cout << "Size of vector:" << A.size() << "\n";
    std::cout << "Vector elements are given below:\n";
    for(int i : A){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    A.insert(A.begin(), 20);
    std::cout << "Size of vector:" << A.size() << "\n";
    std::cout << "Updated vecotr elements: ";
    for(int j : A){
        std::cout << j << " ";
    }
    std::cout << std::endl;

    std::reverse(A.begin(), A.end());
    std::cout << "Output reverse vector array: ";
    for(int i : A){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    A.erase(A.begin() + 0);
    std::cout << "Output after remove last element: ";
    std::reverse(A.begin(), A.end());
    for(int i : A){
        std::cout << i << " ";
    }
    std::cout << std::endl;

}


// Question 4
std::forward_list<int> orderedUnion( 

    const std::forward_list<int>& firstList, 
    const std::forward_list<int>& secondList) 
{
    std::forward_list<int> result;

    std::forward_list<int>::const_iterator first = firstList.begin();
    std::forward_list<int>::const_iterator second = secondList.begin();

    while (first != firstList.end() && second != secondList.end()) {
        if (*first < *second) {
            result.push_front(*first);
            ++first;
        } else if (*second < *first) {
            result.push_front(*second);
            ++second;
        } else {
            result.push_front(*first);
            ++first;
            ++second;
        }
    }
    while (first != firstList.end()) {
        result.push_front(*first);
        ++first;
    }
    while (second != secondList.end()) {
        result.push_front(*second);
        ++second;
    }
    result.reverse();
    return result;
}

void printList(const std::forward_list<int>& list)
{
    for (std::forward_list<int>::const_iterator it = list.begin();
         it != list.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << "\n";
}



// Question 1.b: ordered union of two doubly linked lists
std::list<int> question1_1(
    const std::list<int>& A1,
    const std::list<int>& A2,
    int& commonCount,
    int& totalSize)
{
    std::list<int> result;
    commonCount = 0;

    std::list<int>::const_iterator it1 = A1.begin();
    std::list<int>::const_iterator it2 = A2.begin();

    while (it1 != A1.end() && it2 != A2.end()) {
        if (*it1 < *it2) {
            result.push_back(*it1);
            ++it1;
        }
        else if (*it2 < *it1) {
            result.push_back(*it2);
            ++it2;
        }
        else {
            result.push_back(*it1);
            commonCount++;
            ++it1;
            ++it2;
        }
    }

    while (it1 != A1.end()) {
        result.push_back(*it1);
        ++it1;
    }

    while (it2 != A2.end()) {
        result.push_back(*it2);
        ++it2;
    }

    totalSize = result.size();
    return result;
}

// Print
void printDoubleLinkedList(const std::list<int>& list)
{
    for (std::list<int>::const_iterator it = list.begin();
         it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}



// Question 1.c: 
void question1_2()
{
    std::cout << "Array list:\n";
    std::cout << "- Elements are stored contiguously in memory.\n";
    std::cout << "- Random access is O(1).\n";
    std::cout << "- Insertion or deletion in the middle is O(n) because elements must shift.\n\n";

    std::cout << "Singly linked list:\n";
    std::cout << "- Each node stores data and a next pointer.\n";
    std::cout << "- Memory is non-contiguous.\n";
    std::cout << "- Traversal is only forward.\n";
    std::cout << "- Insertion and deletion are O(1) if the previous node is known.\n\n";

    std::cout << "Doubly linked list:\n";
    std::cout << "- Each node stores data, next pointer, and prev pointer.\n";
    std::cout << "- Memory is non-contiguous.\n";
    std::cout << "- Traversal is possible in both forward and backward directions.\n";
    std::cout << "- It uses more memory than a singly linked list.\n";
    std::cout << "- It is useful for ordered union and palindrome checking.\n";
}

// Question 2: 
bool question2_1(const std::list<int>& myList)
{
    if (myList.empty()) {
        return true;
    }
    std::list<int>::const_iterator left = myList.begin();
    std::list<int>::const_iterator right = myList.end();
    --right;
    while (left != right) {
        if (*left != *right) {
            return false;
        }

        ++left;

        if (left == right) {
            break;
        }

        --right;
    }

    return true;
}

int main()
{
    // QUESTION 1

    // Step 1: vector<int> addresses
    std::vector<int> intVector;
    PushtheValue(intVector, 10);

    std::cout << "Question 1 - Step 1: vector<int>\n";
    display(intVector);
    Adds(intVector);
    std::cout << "\n";

    // Step 2: list<int> addresses
    std::cout << "Question 1 - Step 2: list<int>\n";
    linkedlist(std::list<int>(), 10);
    std::cout << "\n";

    // Step 4: vector<double> addresses
    std::vector<double> doubleVector;
    PushtheValueDouble(doubleVector, 10);

    std::cout << "Question 1 - Step 4: vector<double>\n";
    displayDouble(doubleVector);
    AddsDouble(doubleVector);
    std::cout << "\n";

    // Step 4 continued: list<double> addresses
    std::cout << "Question 1 - Step 4 continued: list<double>\n";
    linkedlistDouble(std::list<double>(), 10);
    std::cout << "\n";

    //QUESTION 2

    std::cout << "Question 2: 2D array\n";
    std::vector<std::vector<int>> matrix;
    twoDArray(matrix);
    std::cout << "\n";

    //QUESTION 3

    std::cout << "Question 3: vector operations\n";
    std::vector<int> question3Vector = {1, 2, 3, 4, 5};
    Question3(question3Vector);
    std::cout << "\n";

    //QUESTION 4

    std::cout << "Question 4: ordered union using forward_list\n";
    std::forward_list<int> firstForwardList = {1, 3, 5, 7};
    std::forward_list<int> secondForwardList = {2, 3, 5, 8};

    std::forward_list<int> forwardUnion =
        orderedUnion(firstForwardList, secondForwardList);

    printList(forwardUnion);
    std::cout << "\n";

    // Question 1.b
    // This function returns the number of common numbers in two list, not the common number itself. 
    // For example, in list, there is two 3 and two 5. so here is two nunmbers that are repeated in both list. prints 2
    std::cout << "Question 1.b: ordered union using list\n";
    std::list<int> A1 = {1, 3, 5, 7};
    std::list<int> A2 = {2, 3, 5, 8};

    int commonCount = 0;
    int totalSize = 0;

    std::list<int> unionList = question1_1(A1, A2, commonCount, totalSize);

    printDoubleLinkedList(unionList);

    std::cout << "Common elements: " << commonCount << "\n";
    std::cout << "Total size: " << totalSize << "\n\n";

    //Question 1.c

    std::cout << "Question 1.c: array list vs linked lists\n";
    question1_2();
    std::cout << "\n";

    //Question 2. Palindrome

    std::cout << "Question 2: palindrome check using list\n";
    std::list<int> palindromeList = {1, 2, 3, 2, 1};

    printDoubleLinkedList(palindromeList);

    if (question2_1(palindromeList)) {
        std::cout << "The linked list is a palindrome.\n";
    }
    else {
        std::cout << "The linked list is not a palindrome.\n";
    }

    return 0;
}