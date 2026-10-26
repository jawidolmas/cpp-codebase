#include "tracker.hpp"

void Tracker::add(const Transaction& t){
    records.push_back(t);
}

void Tracker::printAll() const{
    if(records.empty()){
      std::cout << "No records found\n";
      return;
    }
    int n = 1;
    for(const auto& t : records){
        std::cout << n << ". ";
        t.print();
        n++;
    }
}

double Tracker::totalBalance() const{
    double sum = 0.0;
    for(const auto& t : records){
        sum += t.getAmount();
    }
    return sum;
}

size_t Tracker::count() const{
    return records.size();
}