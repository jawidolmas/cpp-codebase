#pragma once
#include<iostream>
#include<string>

class Transaction{
  private:
    std::string date;
    std::string catagory;
    std::string note;
    double amount;

  public:
    Transaction( const std::string& date, 
                 const std::string& catagory,
                 const std::string& note, 
                 double amount) : date(date), 
                                 catagory(catagory),
                                 note(note),
                                 amount(amount) 
      {}
      std::string getDate() const;
      std::string getCatagory() const;
      std::string getNote() const;
      double getAmount() const;
      bool isIncome() const;
      void print() const; 
};