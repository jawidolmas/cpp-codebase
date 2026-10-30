#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<string>


class Test{
    private:
        std::string name;
        std::vector<int> marks;
        std::list<double> gpa;
    public: 
        Test() = default;
        Test(std::string name, std::vector<int> marks, std::list<double> gpa) : name(std::move (name)), marks(std::move(marks)), gpa(std::move(gpa)) { }
        void create();
        void print() const;
        bool isEmptpy() const;
};

void Test::create(){
        std::cout << "Name: ";
        std::cin >> name;
        for(int i = 0; i<3; i++){
            std::cout << "Marks(DSA, Digital Design, OOP): ";
            int temp; 
            std::cin >> temp;
            marks.push_back(temp); 
        }
        std::cout << "GPA: ";
        double temp;
        std::cin >> temp;
        gpa.push_back(temp);
} 
bool Test::isEmptpy() const{
    if (name.empty() && marks.empty() && gpa.empty()){
        return true;
    }
    return false;
}

void Test::print() const {
    if (isEmptpy()) {
        std::cout << "No records found.\n"; 
        return; 
    }
    std::cout << "Name: " << name << " | ";
    std::cout << "Marks: ";
    for (const auto& mark : marks) {
        std::cout << mark << " ";
    }
    std::cout << "| ";
    std::cout << "GPAs: ";
    for (const auto& single_gpa : gpa) {
        std::cout << single_gpa << " ";
    }
    std::cout << "\n";
}


int main()
{       
    Test t1;
    Test t2("Jawid", {10, 20, 30}, {3.55});
    t2.print();
    t1.create();
    t1.print();
    

    return 0;
}