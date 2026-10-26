#include <iostream>
using namespace std;



void Question1A(){

    int Arr[10];
    for (int i = 0; i<10; i++){
        Arr[i] = i+1;
    }
    
    for(int j = 0; j<10; j++){
        cout << Arr[j] << " ";
    }
    cout << endl;
    cout << endl;
    cout << "As we can see, we have two for loops, and each of them runs for n+1 unit of time, so we will have\n";
    cout << "2n+2 unit of time as our time function T(n)\n";
    cout << "To conclude, The time complexity for this program is O(n)\n";
    cout << "About space compelxity, the space taken by input is not considered while analysing complexity, so we have i and j of extra varaibles\n";
    cout << "so the space complexity is O(1)\n";
    cout << "Program returned in 53ms\n";
}

void Question1B(){

    int Arr[10000];
    for (int i = 0; i<10000; i++){
        Arr[i] = i+1;
    }
    
    for(int j = 0; j<10000; j++){
        cout << Arr[j] << " ";
    }
    cout << endl;
    cout << endl;
    cout << "As there will be no change in complexity, there are still O(n) in time and O(1) in space, BUT\n";
    cout << "YEAH: when I add the size of m as 10000, there was a huge difference in time, it got 422ms, approx 8x more than m = 10\n";
}

void Question2A(){
    int A[10][10];
    for(int i = 0; i<10; i++){
        for(int j = i; j<10; j++){
            A[i][j] = i;
        }
    }
    for(int k = 0; k<10; k++){
        for(int m = k; m<10; m++){
            cout << A[k][m] << " ";
        }
    }
    cout << endl;
    /*
        This is clear that we have two nested loop in here, so both of them does real work. So, it is n into n, nxn, at the end of the 
        day, we will get O(n^2), as the time function will be T(n) = 2n^2 + 4, which 4 comes from 4 for loops, while they hit the upper limit
        and comes out of loop.
        About time cmoplexity, it is O(1), becuase we only have i, j, k, m extra varaibles, and it takes 16bytes in my device
        It runs in 61ms in my machine.
    */

}

void Question2B(){
    int A[100][100];
    for(int i = 0; i<100; i++){
        for(int j = i; j<100; j++){
            A[i][j] = i;
        }
    }
    for(int k = 0; k<100; k++){
        for(int m = k; m<100; m++){
            cout << A[k][m] << " ";
        }
    }
    cout << endl;
    /*
       The time and space complexity is same, but it TOOK 239ms when I went from 10 to 100.
    */

}

void Question3A(){
    int A[10][10][10];
    for(int i = 0; i<10; i++){
        for(int j = i; j<10; j++){
            for(int r = j; r<10; r++){
                A[i][j][r] = i;
            }
        }
    }
    for(int k = 0; k<10; k++){
        for(int m = k; m<10; m++){
            for(int o = m; o<10; o++){
                cout << A[k][m][o] << " ";
            }
        }
    }
    cout << endl;

    /*
        This function has 2 loops with 3 inner loops inside each. so this is n into n into n, becuase all of the loops nestedly does a real work. 
        so time complexity for this function is O(n^3)
        
        About space complexity, this is O(1) coz we have constant number of extra variables, i, j,k,m,r,o; 
        it run 79ms in my machine for size of 10;
    
    */
}

void Question3B(){
    int A[50][50][50];
    for(int i = 0; i<50; i++){
        for(int j = i; j<50; j++){
            for(int r = j; r<50; r++){
                A[i][j][r] = i;
            }
        }
    }
    for(int k = 0; k<50; k++){
        for(int m = k; m<50; m++){
            for(int o = m; o<50; o++){
                cout << A[k][m][o] << " ";
            }
        }
    }
    cout << endl;

    /*
        The time ans space complexity remains O(n^3) and O(1); but there is a huge difference, In my mchine, it ran 806ms when I 
        make the size of m = 50; 
    
    */
}


//PART2:
void Pt2_Question1A(){
    int num;
    cout << "Enter a number:";
    cin >> num;
    for(int i = num; i>0; --i){
        cout << i;
    }
    cout << endl;
    /*
        This function is O(n) in terms of time, coz we have only one loop and it runs for n units. In fact, the time function 
        T(n) =  n + 1 + 1; so this is O(n) in time
        Also, this is O(1) in terms of space as we have only num and i as extra space.
        I really cannot see how much time elapsed it took, coz when adding the input it takes time coz of user delay(for ex: the program
        waits for an input "Enter a number:" and it delays coz we(humans) are not that much fast), thats why I cannot see how much 
        time it really returned. I can guess around 20-30ms for num = 10;
    
    */

}

void Pt2_Question1B(){
    int num;
    int sum = 0;
    cout << "Enter a number:";
    cin >> num;
    while(num > 0){
        sum += num;
        num--;
    }
    cout << "SUM:" << sum;

    /*
        This function is O(n) in terms of time, coz we have a while loop and it runs from num to 0, does sum and decrements the num; 
        so this is O(n) in terms of time;
        So to speak about the space, it is of course O(1) coz we have only num and sum as extra varaibles. 
        it took 4.78ms and that is beacue I delayed while typing the num. so I cannot be accurate about time elapsed.
    
    */
}

void Pt2_Question1C(){
    int num;
    int sum = 0;
    cout << "Enter a number:";
    cin >> num;
    do{
        sum += num;
        num--;
    }while(num > 0);
    cout << "SUM:" << sum;

    /*
        This function is Do while version, as it does not change anything in time and space complexity, but it is important to know
        that, we always run one time, so in best case we will have O(1) in terms of time. 
        I cannot be accurate about time elapsed, coz it takes input from keyboard.
    
    */
}

int Pt2_Question2A(int n){
    if(n == 0){
        return 0;
    }
    cout << n << " ";
    return Pt2_Question2A(n-1);
    
    /*
        This function is O(n) in both terms, space and time. Why O(n) in space? coz we do the calling for n times and in each time it does 
        the work of all function statements. 
        Why O(n) in terms of spacE? coz we know that recursion uses stacks, so when we call it, there will be activiation recall created 
        for each call. so if n is 50, we will have 50 stack frames in memory and that will take extra space. so it is O(n);
        it took 76ms for 20
    
    */

}

int Pt2_Question2B(int n){
    if (n == 0){
        return 0;
    }
    return Pt2_Question2B(n-1) + n;

    /*
        This function also O(n) in terms of time and space. coz it does n unit of work and takes n stack from in memory.
        it took 86ms for 15;
    
    */   
}

//Question 3:
int Q3factotial(int n){
    if(n == 0){
        return 1;
    }
    return Q3factotial(n-1) * n;

    /*
        This function is a little bit different. This can be the slowest function in entire algorithms. because it is n^n 
        HOW? if we see, we multiply each term by that term number. for example, 5x4x3x2x1, so it will go to n^n; 
        it is O(n) in terms of space as it uses n stack frames.
    
    
    */
}

//Question 4:
int Fibonocci(int n){
    if(n == 0) return 1;
    if(n == 1) return 1;
    return Fibonocci(n-1) + Fibonocci(n-2);

    /*
    This function is O(n^2), coz we calculate each fib two times. so it makes the complexity for time as n^2. 
    and it is O(n^2) in terms space too, coz it also gets two stack from for each Fib  
    
    */

}

int main() {
    cout << Fibonocci(5);


    return 0;
}