#include "C_Tarjeta.h"

Tarjeta::Tarjeta( int numero):m_numero{numero} {}
void Tarjeta::setNro(int num) {m_numero = num;}
int Tarjeta::getNumero() {return m_numero;}