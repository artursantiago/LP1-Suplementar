#include <string>

class Account
{
public:
  Account();
  Account(std::string account_holder, double account_number, double balance);
  ~Account();

  double account_number;
  std::string account_holder;
  double balance;

  void withdraw(double amount);
  void deposit(double amount);
  void transfer(double amount, Account& account);
};