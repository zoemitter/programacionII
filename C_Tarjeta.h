#ifndef UCC_2023_TRABAJO_FINAL_TARJETA_H
#define UCC_2023_TRABAJO_FINAL_TARJETA_H
#include "string"
class Tarjeta  {
private:
  int m_numero;
public:
  Tarjeta(int numero);
  void setNro(int n);
 int getNumero();
};

#endif // UCC_2023_TRABAJO_FINAL_TARJETA_H