#include "C_Banco.h"
#include "C_Cliente.h"
#include "C_Transacciones.h"
#include "C_utils.h"
#include <iostream>
#include "C_Tarjeta.h"

int main() {

  utils::clearScreen();

  Banco b1;
  int opcionMp, opcionM1, opcionM2 = 0;
  while (1){
    std::cout<<"elija una opcion:"<<std::endl;
    std::cout<<"1.Aniadir Cliente"<<"\n"<<"2.Seleccionar Cliente"<<"\n"<<"3.Exit"<<std::endl;
    std::cin>>opcionMp;
    if(opcionMp == 1 ){
      utils::clearScreen();
      std::string nombre, apellido, tipo;
      int anio;
      char estado;
      try{
        std::cout<<"Inserte nombre, apellido, tipo(black, oro, plata)"<<std::endl;
        std::cin>>nombre>>apellido>>tipo;
        b1.AddCliente(nombre,apellido,tipo,2023,'a');
        std::cout<<"Cliente aniadido!"<<std::endl;
        opcionMp =0;}
      catch(std::invalid_argument const& e){std::cerr<<"error: "<<e.what()<<"\n";}
    }
    if (opcionMp == 2) {
      utils::clearScreen();
      while (1){
        for( cliente cliente: b1.getClientesList()){
          std::cout<<cliente.getNroCliente()<<"."<<cliente.getNombre()<<" "<<cliente.getApellido()<<std::endl;
        }
        std::cout<<b1.getClientesList().size()+1<<".Exit"<<std::endl;
        std::cin>>opcionM1;
        for (cliente cliente: b1.getClientesList()) {
          if (opcionM1==cliente.getNroCliente()){
            while (1){
              std::cout<<"1.Generar Tarjeta"<<"\n"<<"2.Ver Tarjeta"<<"\n"<<"3.Extraccion"<<"\n"<<"4.Deposito"<<"\n"<<"5.Dar Alta"<<"\n"<<"6.Dar Baja"<<"\n"<<"7.Exit"<<std::endl;
              std::cin>>opcionM2;
              if (opcionM2==1){
                utils::clearScreen();
                std::cout<<"Tarjeta generada!"<<std::endl;
              b1.generarTarjeta(opcionM1);
                opcionM2=0;
              }
              if (opcionM2==2){
                utils::clearScreen();
                std::cout<<"Tarjeta "<<b1.getCliente(opcionM1).getTarjeta()<<"!"<<std::endl;
                opcionM2=0;
              }
              if (opcionM2 ==3){
                int cant;
                std::cout<<"Inserte cantidad a extraer:"<<std::endl;
                std::cin>>cant;
                b1.GenerarExtraccion(cant,opcionM1);
                utils::clearScreen();
                std::cout<<"Extraccion completada!"<<std::endl;
                opcionM2 = 0;
              }
              if (opcionM2 ==4){
                int cant;
                std::cout<<"Inserte cantidad a depositar:"<<std::endl;
                std::cin>>cant;
                b1.GenerarDeposito(cant,opcionM1);
                utils::clearScreen();
                std::cout<<"Deposito completado!"<<std::endl;
                opcionM2 = 0;
              }
              if(opcionM2 ==5){
               try {
                b1.darAlta(opcionM1);}
               catch(std::invalid_argument const& e){std::cerr<<"error: "<<e.what()<<"\n";}

              }
              if(opcionM2 ==6){
               try {
                b1.darBaja(opcionM1);}
               catch(std::invalid_argument const& e){std::cerr<<"error: "<<e.what()<<"\n";}

              }
              if(opcionM2 ==7){
                utils::clearScreen();
                opcionM2=0;
                break;

              }
            }


          }

        }
        if(opcionM1 == b1.getClientesList().size()+1){
          opcionM1 = 0;
          break;
        }
      }

    }
    if(opcionMp == 3){
      b1.escribirClientes();
      b1.escribirTransacciones();
      opcionMp = 0;
      break;

    }
  }
  return 0;
}