#include "tracker.hpp"

void Tracker::add(const Transaction& transaction){
    records.push_back(transaction);
}

void Tracker::printAll() const{
    if(records.size() == 0){
      std::cout << "No records found\n";
      return;
    }
    for(int i = 1; i<records.size(); i++){
      std::cout << i << " \n";
    }
}

  