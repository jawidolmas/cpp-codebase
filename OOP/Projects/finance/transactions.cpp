#include<iostream>
#include "transactions.hpp"


std::string Transaction::getDate() const{
    return date;
}

void Transaction::getCatagory() const{
  std::cout << catagory << std::endl;
}

void Transaction::getNote() const{
  std::cout << note << std::endl;
}

double Transaction::getAmount() const{
  return amount;
}

bool Transaction::isIncome() const{
  if(amount > 0){
    return true;
  }
  return false;
}

void Transaction::print() const{
  std::cout << date << " | ";
  std::cout << catagory << " | ";
  std::cout << note << " | ";
  if(isIncome()){
    std::cout << "+ " << amount << std::endl;
  }else{
    std::cout << amount << std::endl;
  }
}