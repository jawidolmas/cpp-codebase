#pragma once
#include <iostream>
#include<vector>
#include "transactions.hpp"

class Tracker{
  private:
    std::vector<Transaction> records;
  public:
    void add(const Transaction& transaction);
    void printAll() const;
    double totalBalance() const;
    size_t count() const;
};



