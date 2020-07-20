#include "Fila.h"

#include <iostream>

template <class T>
Fila<T>::Fila(int s) : size(s), top(-1)
{
}

template <class T>
void Fila<T>::push(T element){
  if(this->top == (this->size -1)){
    std::cout << "Fila cheia" << std::endl;
  }else{
    this->clientes[++this->top] = element;
  }
}

template <class T>
void Fila<T>::pop(){
  if(this->top == -1){
    std::cout << "Fila vazia" << std::endl;
  }else{
    this->clientes[this->top--];
  }
}

template <class T>
bool Fila<T>::isEmpty(){
  if(this->top == -1){
    return true;
  }else{
    return false;
  }
}

template <class T>
T Fila<T>::back(){
  return this->clientes[this->top];
}