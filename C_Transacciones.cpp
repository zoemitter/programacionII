#include "iostream"
#include "C_Transacciones.h"
#include "cassert"
#include <stdexcept>
transaccion::transaccion(int nro_transaccion, int cantidad, char tipo,int dia,int mes,
							 int anio, int nro_cliente): m_nro_transaccion{nro_transaccion}, m_cantidad{cantidad},
							 m_tipo{tipo},m_dia{dia},m_mes{mes},m_anio{anio}, m_nro_cliente{nro_cliente} {


  if(nro_transaccion<=0){throw std::invalid_argument("El numero de transaccion debe ser mayor a 0!");}
  if(cantidad<=0){throw std::invalid_argument("Se tiene que mover plata!");}
  if(tipo != 'E' && tipo != 'e' && tipo != 'D' && tipo != 'd'){throw std::invalid_argument("Solo puede ser Extraccion o Deposito!");}

  if(dia<=0 || dia>31){throw std::invalid_argument("Inserte un dia valido!");}
  if(mes<=0 || mes>12){throw std::invalid_argument("Inserte un dia valido!");}
  if(anio<0){throw std::invalid_argument("El anio debe ser despues de cristo!");}
}
int transaccion::getNroTransaccion() { return m_nro_transaccion; }
void transaccion::setNroTransaccion(int NroTransaccion) {
  m_nro_transaccion = NroTransaccion;
}
int transaccion::getCantidad()  { return m_cantidad; }
void transaccion::setCantidad(int Cantidad) { m_cantidad = Cantidad; }
char transaccion::getTipo(){ return m_tipo; }
void transaccion::setTipo(char Tipo) { m_tipo = Tipo; }
int transaccion::getDia()  { return m_dia; }
void transaccion::setDia(int Dia) { m_dia = Dia; }
int transaccion::getMes()  { return m_mes; }
void transaccion::setMes(int Mes) { m_mes = Mes; }
int transaccion::getAnio() { return m_anio; }
void transaccion::setAnio(int Anio) { m_anio = Anio; }
int transaccion::getNroCliente()  { return m_nro_cliente; }
void transaccion::setNroCliente(int NroCliente) {
  m_nro_cliente = NroCliente;
}

void transaccion::imprimirTransaccion() {
  std::cout << "Numero de transaccion: " << getNroTransaccion();
  std::cout << " cantidad " << getCantidad();
  std::cout << " tipo " << getTipo();
  std::cout << " dia " << getDia();
  std::cout << " mes " << getMes();
  std::cout << " anio " << getAnio();
  std::cout << " numero de cliente " << getNroCliente()<<std::endl;
}

