#include "../include/Account.hpp"

Account::Account()
  : account_holder(""),
    account_number(0),
    balance(0)
{
}

Account::Account(std::string account_holder, double account_number, double balance)
  : account_holder(account_holder),
    account_number(account_number),
    balance(balance)
{
}

Account::~Account()
{
}

void Account::withdraw(double amount) {
  this->balance -= amount;
}

void Account::deposit(double amount) {
  this->balance += amount;
}

void Account::transfer(double amount, Account& account) {
  this->balance -= amount;
  account.deposit(amount);
}