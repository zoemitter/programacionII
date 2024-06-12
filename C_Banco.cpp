#include "chrono"
#include <iostream>
#include "iomanip"
#include "C_Banco.h"
#include "C_Tarjeta.h"
#include "C_Cliente.h"
#include "C_Transacciones.h"
Banco::Banco() {
  clientesList = std::vector<cliente>();
  transaccionesList = std::vector<transaccion>();
}

void Banco::AddCliente( std::string nombre, std::string apellido, std::string tipo, int anio, char estado) {

  int nro_cliente = clientesList.size()+1;
  cliente cliente(nro_cliente, nombre, apellido, tipo, anio, estado);
  clientesList.push_back(cliente);
}

void Banco::GenerarExtraccion(int cantidad, int nro_cliente) {
  // Get the current system time
  auto now = std::chrono::system_clock::now();

  // Convert the system time to a time_t object
  std::time_t now_t = std::chrono::system_clock::to_time_t(now);

  // Convert the time_t object to a tm struct
  std::tm *now_tm = std::localtime(&now_t);

  // std::time_t now_t = std::time(nullptr); // get current system time
  // std::tm *now_tm =
  //     std::localtime(&now_t); // convert to struct tm representing local time



  int year = now_tm->tm_year + 1900; // year since 1900
  int month = now_tm->tm_mon + 1;    // month (0-11)
  int day = now_tm->tm_mday;         // day of the month (1-31)


  transaccion transaccion(transaccionesList.size()+1, cantidad, 'E',day, month, year, nro_cliente);
  transaccionesList.push_back(transaccion);
}
void Banco::GenerarDeposito(int cantidad, int nro_cliente){
  // Get the current system time
  auto now = std::chrono::system_clock::now();

  // Convert the system time to a time_t object
  std::time_t now_t = std::chrono::system_clock::to_time_t(now);

  // Convert the time_t object to a tm struct
  std::tm *now_tm = std::localtime(&now_t);

  // std::time_t now_t = std::time(nullptr); // get current system time
  // std::tm *now_tm =
  //     std::localtime(&now_t); // convert to struct tm representing local time



  int year = now_tm->tm_year + 1900; // year since 1900
  int month = now_tm->tm_mon + 1;    // month (0-11)
  int day = now_tm->tm_mday;         // day of the month (1-31)
  transaccion transaccion(transaccionesList.size()+1, cantidad, 'D', day, month, year, nro_cliente);
  transaccionesList.push_back(transaccion);
}

void Banco::darAlta(int nro_cliente) {
  if(getCliente(nro_cliente).getEstado() == 'b'){
    getCliente(nro_cliente).setEstado('a');}
  else{
    throw std::invalid_argument("cliente ya esta dado de alta!");
  }
}
void Banco::darBaja(int nro_cliente) {
  if(getCliente(nro_cliente).getEstado() == 'a'){
    getCliente(nro_cliente).setEstado('b');}
 else{ throw std::invalid_argument("cliente ya esta dado de baja!");}
}

cliente Banco::getCliente(int nro_cliente) {return clientesList[nro_cliente-1];}
void Banco::getTransaccionPorCliente(int nro_cliente) {for (transaccion transaccion : transaccionesList){if (transaccion.getNroCliente() == nro_cliente){
    transaccion.imprimirTransaccion();}}}

void Banco::escribirTransacciones() {
  transaccionesFile.open("C:\\Users\\zoe\\Desktop\\programacionII\\transaccion.txt",std::ios::out); //escribe sobre el archivo
  if(!transaccionesFile.is_open()){
  std::cout<<"no";
  }
  transaccionesFile << "id" << "\t" << "cant" << "\t" << "tipo" << "\t" << "n_T"<< "\t"
                    << "d" << "\t" << "m" << "\t" << "a" << std::endl;
  for (transaccion transaccion : transaccionesList) {


    transaccionesFile << transaccion.getNroCliente() << "\t" << transaccion.getCantidad() << "\t" << transaccion.getTipo() << "\t" << transaccion.getNroTransaccion() << "\t"
               << transaccion.getDia() << "\t" << transaccion.getMes() << "\t" << transaccion.getAnio() << std::endl;




  }
  transaccionesFile.flush();
  transaccionesFile.close();
}
void Banco::escribirClientes() {
  clientesFile.open("C:\\Users\\zoe\\Desktop\\programacionII\\cliente.txt",std::ios::out); //escribe sobre el archivo
  if(!clientesFile.is_open()){
    std::cout<<"no";
  }
  clientesFile << "id" << "\t" << "nombre" << "\t" << "apellido" << "\t" << "tipo"<< "\t"
                    << "a" << "\t" << "estado" << "\t" << std::endl;
  for (cliente cliente : clientesList) {


    clientesFile << cliente.getNroCliente() << "\t" << cliente.getNombre() << "\t" << cliente.getApellido() << "\t" << cliente.getTipo() << "\t"
                      << cliente.getAnio() << "\t" << cliente.getEstado() << "\t" << std::endl;




  }
  clientesFile.flush();
  clientesFile.close();
}
void Banco::GetAllClientes() {
  for(cliente cliente : clientesList){
    cliente.imprimirCliente();
  }
}

  void Banco::getTransaccionPorTiempo(std::string periodo) {

  time_t now = time(nullptr);
  tm* currentTime = localtime(&now);

  int startMonth, startYear;

  if (periodo == "6 meses") {

    std::cout<<"Transacciones en los ultimos 6 meses:\n";
    startMonth = currentTime->tm_mon - 5;
    startYear = currentTime->tm_year + 1900;

    if (startMonth <= 0) {

    startMonth += 12;
    startYear--;
    }
  }
  else if (periodo == "año") {

    std::cout<<"Transacciones en el anio:\n";
    startMonth = 1;
    startYear = currentTime->tm_year + 1900;
  }
  else if (periodo == "total"){
    std::cout<<"Todas las transacciones:\n";
    for( transaccion transaccion: transaccionesList){
    transaccion.imprimirTransaccion();
    }
    return ;
  }
  else {
    // Invalid period option
    std::cout << "Periodo invalido\n";
    return;
  }





    for (transaccion transaccion: transaccionesList) {
      if ((transaccion.getAnio() > startYear || (transaccion.getAnio() == startYear && transaccion.getMes() >= startMonth))) {
      transaccion.imprimirTransaccion();
      }
    }

  }
  void Banco::generarTransac(int nro_transaccion, int cantidad, char tipo,int dia,int mes,
                       int anio, int nro_cliente) {
   //funcion de prueba para ver si funciona transaccion por periodo
    transaccion transaccion(nro_transaccion,cantidad,tipo,dia,mes,anio,nro_cliente);
    transaccionesList.push_back(transaccion);

  }
  void Banco::generarTarjeta(int nro_cliente) {
   if(getCliente(nro_cliente).getTipo() == "black" && getCliente(nro_cliente).getEstado() == 'a'){
      getCliente(nro_cliente).setTarjeta(250000);
   }
   else if(getCliente(nro_cliente).getTipo() == "oro" && getCliente(nro_cliente).getEstado() == 'a') {
      getCliente(nro_cliente).setTarjeta(50000);
   }
  }

  std::vector<cliente> Banco::getClientesList() {return clientesList;}



