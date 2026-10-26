#include<iostream>
#include "transactions.hpp"


std::string Transaction::getDate() const{
    return date;
}

std::string Transaction::getCatagory() const{
    return catagory;
}

std::string Transaction::getNote() const{
    return note;
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