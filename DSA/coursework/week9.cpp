#include<iostream>
#include<queue>
#include<string>
using namespace std;

// Question 1
void Question1(){
    // Menu
    int choice;
    std::queue<int> q1;
    do{
    cout << "\nWhat Operation Do You Want to Perform? Select Option Number. Enter 0 to Exit.\n";
    cout << "1.Enqueue\n";
    cout << "2.Dequeue\n";
    cout << "3.isEmpty\n";
    cout << "4.isFull\n";
    cout << "5.Count\n";
    cout << "6.Display\n";
    cout << "7.Clear Screen\n";
    if (!(cin >> choice)) {
        cout << "Invalid input. Exiting.\n";
        return;
    }
    // Menu Functions
    switch(choice){
        case 1: {
            int data;
            cout << "Enter the number you want to enqueue: ";
            cin >> data;
            q1.push(data);
            break;
        }
        case 2: {
            if (q1.empty()) {
                cout << "Cannot dequeue: Queue is empty\n";
                break;
            }
            q1.pop();
            cout << "First element " << q1.front() << " deleted\n";
            break;
        }
        case 3: {
            cout << "Checking if queue is empty...";
            if(q1.empty()){
                cout << "  Queue is Empty\n";
                break;
            }else{
                cout << "  Queue is not Empty\n";
                break;
            }
        }
        case 4: {
            cout << "Checking if queue is full...";
            cout << "  Queue is not Full\n";
            break;
        }
        case 5: {
            cout << "Fetching the size of queue...";
            cout << "  Size:  " << q1.size() << endl;
            break;
        }
        case 6: {
            queue<int> copy = q1;
            if (copy.empty()) {
                cout << "Queue is Empty\n";
                break;
            }
            while(!copy.empty()){
                cout << copy.front() << " ";
                copy.pop();
            }
            cout << endl;
            break;
        }
        case 7:
            cout << string(40, '\n');
            break;
        case 0:
            break;
        default:
            cout << "Invalid option\n";
            break;
    }
    } while(choice != 0);


}


// Question 2
void Question2() {
    queue<string> earth, mars;

    earth.push("E1"); earth.push("E2");
    mars.push("M1");  mars.push("M2");

    auto show = [&]() {
        cout << "  EARTH: size=" << earth.size()
             << " front=" << (earth.empty() ? "EMPTY" : earth.front())
             << " back="  << (earth.empty() ? "EMPTY" : earth.back()) << "\n";
        cout << "  MARS : size=" << mars.size()
             << " front=" << (mars.empty() ? "EMPTY" : mars.front())
             << " back="  << (mars.empty() ? "EMPTY" : mars.back()) << "\n\n";
    };
    auto serve = [&](queue<string>& q, const string& name) {
        if (!q.empty()) {
            cout << "  Delivered " << q.front() << " from " << name << " Gate.\n";
            q.pop();
        } else {
            cout << "  Delivery failed: " << name << " Gate is empty.\n";
        }
    };

    cout << "Step 1: SERVE EARTH\n";      serve(earth, "EARTH");                 show();
    cout << "Step 2: ARRIVE MARS M3\n";   mars.push("M3");                       show();
    cout << "Step 3: ARRIVE EARTH E3\n";  earth.push("E3");                      show();
    cout << "Step 4: TELEPORT\n";         earth.swap(mars);                      show();
    cout << "Step 5: SERVE EARTH\n";      serve(earth, "EARTH");                 show();
    cout << "Step 6: SERVE MARS\n";       serve(mars, "MARS");                   show();
    cout << "Step 7: SERVE EARTH\n";      serve(earth, "EARTH");                 show();
    cout << "Step 8: ARRIVE MARS M4\n";   mars.push("M4");                       show();
    cout << "Step 9: SERVE MARS\n";       serve(mars, "MARS");                   show();
    cout << "Step 10: SERVE EARTH\n";     serve(earth, "EARTH");                 show();
    cout << "Step 11: SERVE EARTH\n";     serve(earth, "EARTH");                 show();
    cout << "Step 12: SERVE MARS\n";      serve(mars, "MARS");                   show();
    cout << "Step 13: SERVE MARS\n";      serve(mars, "MARS");                   show();
}


int main()
{   
    cout << "Question 1 starting: \n";
    Question1();
    cout << "Question 2 starting: \n";
    Question2();
    return 0;
}