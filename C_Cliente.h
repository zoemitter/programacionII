#ifndef UCC_2023_TRABAJO_FINAL_CLIENTE_H
#define UCC_2023_TRABAJO_FINAL_CLIENTE_H
#include "C_Tarjeta.h"
#include "string"
class cliente {

private:
  int m_nro_cliente;
  std::string m_nombre;
  std::string m_apellido;
  std::string m_tipo;
  int m_anio;
  char m_estado;
  int m_tarjeta;
  Tarjeta m_tarjeta;

public:
  cliente(int cliente, std::string nombre, std::string apellido, std::string tipo, int anio,char estado);
int getNroCliente();
void setNroCliente(int NroCliente);
std::string getNombre();
void setNombre(std::string Nombre);
std::string getApellido();
void setApellido(std::string Apellido);
std::string getTipo();
void setTipo(std::string Tipo);
int getAnio();
void setAnio(int Anio);
char getEstado();
void setEstado(char Estado);
void setTarjeta (int nro_tarjeta);
int getTarjeta();
void imprimirCliente();

};

#endif // UCC_2023_TRABAJO_FINAL_CLIENTE_H