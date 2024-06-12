#ifndef UCC_2023_TRABAJO_FINAL_BANCO_H
#define UCC_2023_TRABAJO_FINAL_BANCO_H
#include "C_Cliente.h"
#include "C_Transacciones.h"
#include "vector"
#include <fstream>
#include "C_Tarjeta.h"
class Banco {
private:
    std::vector<cliente> clientesList;
    std::vector<transaccion> transaccionesList;
    std::fstream clientesFile;
    std::fstream transaccionesFile;

public:
    Banco();
    void AddCliente(std::string nombre, std::string apellido, std::string tipo, int anio,char estado);
    void GenerarExtraccion(int cantidad,int nro_cliente);
    void GenerarDeposito(int cantidad, int nro_cliente);
    void darBaja(int nro_cliente);
    void darAlta(int nro_cliente);
    void GetAllClientes();
    cliente getCliente(int nro_cliente);
    void getTransaccionPorCliente(int nro_cliente);
    void getTransaccionPorTiempo(std::string periodo);
    void escribirTransacciones();
    void escribirClientes();
    void generarTransac(int nro_transaccion, int cantidad, char tipo,int dia,int mes,
                        int anio, int nro_cliente);
    void generarTarjeta(int nro_cliente);
    std::vector<cliente> getClientesList();

};

#endif // UCC_2023_TRABAJO_FINAL_BANCO_H