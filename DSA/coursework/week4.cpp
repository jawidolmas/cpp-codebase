#include<iostream>


// Question 1.A

int factorial(int n){
    if(n < 0) return -1;
    if(n == 0) return 1;
    if(n == 1) return 1;
    return factorial(n-1) * n;
}

//Question 1.B
int factorailIterative(int n){
    int result = 1;
    if(n < 0) return -1;
    if(n == 0 || n == 1) return 1;
    for(int i = 1; i<=n; i++){
        result *= i;
    }
    return result;
}

// Question 2.A
void multiplicationTable(int n){
    for(int i = 1; i<=10; i++){
        std::cout << i << "*" <<  n  << " = " << i*n << "\n";
    }
}

// Question 2.B
void multiplicationTableUser_defined(){
    int n;
    std::cout << "Enter a number dude:";
    std::cin >> n;
    for(int i = 1; i<=10; i++){
        std::cout << i << "*" <<  n  << " = " << i*n << "\n";
    }
}


// Question 3
int Staircase(int n, int prev){
    if (n == 0) return 1;
    if (n <  0) return 0;
    int total = 0;
    if(prev != 1) total += Staircase(n -1, 1);
    if(prev != 2) total += Staircase(n -2, 2);
    if(prev != 3) total += Staircase(n -3, 3);

    return total;   
}

// Question 4
int sumOfDigit(int n){
    if (n==0) return 0;
    int sum = 0;
    while(n > 0){
        sum += n % 10;
        n = n / 10;
    }
    return sum;
}


int main()
{

    std::cout << "Factorail with recursion: took 5 as input: " << factorial(5) << std::endl;
    std::cout << "Factorial with loop: took 5 as input: " << factorailIterative(5) << std::endl;
    std::cout << "Multiplication Table: input: 10 \n"; multiplicationTable(10);
    std::cout << "Multiplication Table with User defined input  "; multiplicationTableUser_defined();
    std::cout << "Staircase problem: input 4, previous step 0(coz there was no step when starting): result: " <<  Staircase(4, 0) << std::endl;
    std::cout << "Sum of digits: " << sumOfDigit(24535) << std::endl;


    return 0;
}