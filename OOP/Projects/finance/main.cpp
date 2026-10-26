  #include<iostream>
  #include "transactions.hpp"
  #include "tracker.hpp"

  int main()
  {
    Tracker t1;
    t1.printAll();
    Transaction t2("2026-10-09", "Salary", "Wage", 1200.00);
    Transaction t3("2015-10-09", "Food", "lunch", -35.00);
    Transaction t4("2034-10-09", "Salary", "Wage", 1200.00);
    Transaction t5("2026-10-08", "Food", "lunch", -35.00);
    t1.add(t2);
    t1.add(t3);
    t1.add(t4);
    t1.add(t5);
    t1.printAll();
    t1.sortDate();
    t1.printAll();
    
    // t1.getDate();
    // t1.getCatagory();
    // t1.getNote();
    // std::cout << t1.getAmount() << std::endl;
    // t1.print();
    // t2.print();
    // std::cout << t1.isIncome() << std::endl;
    // std::cout << t2.isIncome() << std::endl;
    // std::cout << t2.getAmount();

    return 0;
  }