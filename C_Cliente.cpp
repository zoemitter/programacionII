#include "cassert"
#include "C_Cliente.h"
#include <iostream>
#include <stdexcept>
#include "C_Tarjeta.h"
cliente::cliente(int cliente, std::string nombre, std::string apellido,
                   std::string tipo,int anio, char estado):
				   m_nro_cliente{cliente},m_nombre{nombre}, m_apellido{apellido},m_tipo{tipo},
				   m_anio{anio},m_estado{estado},m_tarjeta(0){

  if (cliente<=0){throw std::invalid_argument("Numero de cliente debe ser mayor a 0!");}
  if(nombre.empty()){throw std::invalid_argument("El nombre no puede ser nulo!");}
  if(apellido.empty()){throw std::invalid_argument("El apellido no puede ser nulo!");}
  if(tipo != "plata" && tipo != "oro" && tipo != "black"){throw std::invalid_argument("La cuenta debe ser 'plata', 'oro' o 'black'!");
  }
  if(anio<=0){throw std::invalid_argument("No puede ser antes de cristo!");}
  if(estado != 'b' && estado != 'a'){throw std::invalid_argument("El estado debe ser 'b' o 'a'!");}
}
int cliente::getNroCliente()  { return m_nro_cliente; }
void cliente::setNroCliente(int NroCliente) { m_nro_cliente = NroCliente; }
std::string cliente::getNombre() { return m_nombre; }
void cliente::setNombre( std::string Nombre) { m_nombre = Nombre; }
std::string cliente::getApellido() { return m_apellido; }
void cliente::setApellido (std::string Apellido) {
  m_apellido = Apellido;
}
std::string cliente::getTipo()  { return m_tipo; }
void cliente::setTipo( std::string mTipo) { m_tipo = mTipo; }
int cliente::getAnio() { return m_anio; }
void cliente::setAnio(int Anio) { m_anio = Anio; }
char cliente::getEstado() { return m_estado; }
void cliente::setEstado( char Estado) { m_estado = Estado; }
void cliente::imprimirCliente(){
  std::cout << "Numero de cliente: "<<getNroCliente()<<" Nombre: "<< getNombre()<< " Apellido:" << getApellido()<< " Tipo: "<<getTipo()<< " Año: "<< getAnio()<< " Estado: "<<getEstado()<<std::endl;
}
void cliente::setTarjeta(int nro_tarjeta) {m_tarjeta.setNro(nro_tarjeta);}
int cliente::getTarjeta() {return m_tarjeta.getNumero();}
