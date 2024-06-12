#ifndef UCC_2023_TRABAJO_FINAL_TRANSACCION_H
#define UCC_2023_TRABAJO_FINAL_TRANSACCION_H

class transaccion {
private:
  int m_nro_transaccion;
  int m_cantidad;
  char m_tipo;
  int m_dia;
  int m_mes;
  int m_anio;
  int m_nro_cliente;
public:
transaccion(int nro_transaccion, int cantidad, char tipo, int dia, int mes, int anio, int nro_cliente);
int getNroTransaccion();
void setNroTransaccion(int NroTransaccion);
int getCantidad();
void setCantidad(int Cantidad);
char getTipo();
void setTipo(char Tipo);
int getDia();
void setDia(int Dia);
int getMes();
void setMes(int Mes);
int getAnio();
void setAnio(int Anio);
int getNroCliente();
void setNroCliente(int NroCliente);
void imprimirTransaccion();

};

#endif // UCC_2023_TRABAJO_FINAL_TRANSACCION_H
