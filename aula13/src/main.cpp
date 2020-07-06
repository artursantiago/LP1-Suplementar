#include "../include/Account.hpp"

#include <iostream>

int main(int argc, char const *argv[])
{
  Account account("Samuel Gomes", 4444555566667777, 10000);
  Account account2("Artur Melo", 0000111122223333, 5000);

  std::cout << "Artur is withdrawing money. His previous balance was " << account2.balance << std::endl;
  account2.withdraw(1250);
  std::cout << "His new balance is " << account2.balance << std::endl;
  
  std::cout << "\nArtur is depositing money. His previous balance was " << account2.balance << std::endl;
  account2.deposit(2550);
  std::cout << "His new balance is " << account2.balance << std::endl;

  std::cout << "\nSamuel is transfering money to Artur." << std::endl 
            << "Samuel's previous balance was " << account.balance << std::endl
            << "Artur's previous balance was " << account2.balance << std::endl;
  account.transfer(10000, account2);
  std::cout << "Samuel's new balance is " << account.balance << std::endl;
  std::cout << "Artur's new balance is " << account2.balance << std::endl;

  return 0;
}
