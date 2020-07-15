#if !defined(FILA_H)
#define FILA_H

template <class T>
class Fila
{
private:
  int size;
  int top;
  T *clientes;

public:
  Fila(int s);

  void push(T element);
  void pop();
  bool isEmpty();
  T back();
  
  int getSize() {
    return this->size;
  }
  void setSize(int s) {
    this->size = s;
  }
  int getTop() {
    return this->top;
  }
  void setTop(int t) {
    this->top = t;
  }
  T* getClientes() {
    return this->clientes;
  }
  void setClientes(T *c) {
    this->clientes = c;
  }
};

#endif // FILA_H



