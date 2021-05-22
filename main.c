#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get.h"
#include "Clientes.h"
#include "Juegos.h"
#include "Alquileres.h"
#include "Categorias.h"
#include "DataWareHouse.h"
#include "Localidad.h"
#include "Informes.h"





#define TAMJUE 5 //juegos
#define TAMCAT 10 //categorias
#define TAMCLI 100 //clientes
#define TAMALQUI 100 //alquileres
#define TAMLOC 5 //localidades





int main()
{
   eJuego juegos[TAMJUE]={
       {100,"Puzzle",2000.00,500},
       {101,"TinkiWinki",1000.00,501},
       {102,"TEG",5000.00,502},
       {103,"Ajedrez",1500.00,503},
       {104,"HokusPokus",3000.00,504},

   };


   eCategoria categorias[TAMCAT]={
       {500,"Mesa"},
       {501,"Azar"},
       {502,"Estrategia"},
       {503,"Salon"},
       {504,"Magia"},

   };


   eLocalidad localidades[TAMLOC]={
       {600,"Chilvilcoy"},
       {601,"Lujan"},
       {602,"Mercedes"},
       {603,"Baradero"},
       {604,"Pilar"},

   };

   eCliente clientes[TAMCLI];
   eAlquiler alquileres[TAMALQUI];


   char salida='n';
   int nextIdCliente=2000;
   int nextIdAlquiler=8000;


   inicializarClientes(clientes,TAMCLI);
   inicializarAlquileres(alquileres,TAMALQUI);
   hardcodearClientes(clientes,TAMCLI,10,&nextIdCliente); //10 porque quiero 10 clientes.
   hardcodearAlquileres(alquileres,TAMALQUI,10,&nextIdAlquiler);


   do{

        switch(menu())
        {
        case 1:

            if(altaCliente(clientes,TAMCLI,&nextIdCliente))
            {
                printf("Alta exitosa\n");
            }
            else
            {
                printf("Hubo un problema al dar de alta\n");
            }
            break;

        case 2:
            modificarClientes(clientes,TAMCLI,localidades,TAMLOC);
            break;

        case 3:
            if(bajaCliente(clientes,TAMCLI,alquileres,TAMALQUI,localidades,TAMLOC))
            {

                printf("Baja exitosa\n");
            }
            else
            {
                printf("Hubo un problema al dar de baja\n");
            }

            break;
        case 4:
            if(ordenarClientes(clientes,TAMCLI))
            {
               mostrarClientes(clientes,TAMCLI,localidades,TAMLOC);
            }

            break;

        case 5:

           if(altaAlquiler(alquileres,TAMALQUI,clientes,TAMCLI,&nextIdAlquiler,juegos,TAMJUE,categorias,TAMCAT,localidades,TAMLOC))
           {
               printf("Alta alquiler exitosa\n");
           }
           else
           {
               printf("Error al dar de alta alquiler");
           }

            break;

        case 6:

            mostrarAlquileres(clientes,TAMCLI,juegos,TAMJUE,alquileres,TAMALQUI,categorias,TAMCAT);
           break;

        case 7:
            //SALIR
            utn_getCaracter(&salida,"Desea salir?","Error. ",'s','n',10);
            break;

        case 8:
             informar(clientes,TAMCLI,alquileres,TAMALQUI,juegos,TAMJUE,categorias,TAMCAT,localidades,TAMLOC);
           break;
        default:
            printf("Opcion invalida\n");


        }
        printf("\n");
        system("pause");



    }while (salida=='n');




}

int menu()
{
    int opcion;

    system("cls");
    printf("      *** GESTION DE JUEGOS ***\n\n");
    printf("1) Alta cliente.\n");
    printf("2) Modificar cliente.\n");
    printf("3) Baja cliente.\n");
    printf("4) Listar clientes.\n");
    printf("5) Alta alquiler\n");
    printf("6) Listar alquileres.\n");
    printf("8) Informes.\n");

    printf("7) Salir.\n");

    printf("\n");

   utn_getNumero(&opcion,"Ingrese opcion: ","Error. ",1,8,3);

    return opcion;

}



int mostrarAlquileresPorCliente(eCliente clientes[],int tamcli,eAlquiler alquileres[],int tamalqui,eJuego juegos[],int tamjue,eCategoria categorias[],int tamcat,eLocalidad localidades[],int tamloc)
{
    int codigo;
    int flag=0;


    printf( " Alquileres por cliente\n\n");

    mostrarClientes(clientes,tamcli,localidades,tamloc);
    printf("Ingrese codigo cliente: ");
    scanf("%d",&codigo);


   while(buscarCliente(clientes,tamcli,codigo)== -1)
   {
        printf("Codigo invalido. Reingrese: ");
        scanf("%d",&codigo);
   }



    system("cls");

    printf("      Alquileres del cliente seleccionado: \n\n");

    for(int i=0; i<tamalqui ; i++) //recorro array de alquileres
     {
         if(alquileres[i].isEmpty==0 && alquileres[i].codigoCliente== codigo)
         {

             mostrarAlquiler(alquileres[i],juegos,tamjue,clientes,tamcli,categorias,tamcat);


             flag=1;
         }


    }

    if(!flag)
    {
        printf("El cliente del codigo %d no registra alquileres\n",codigo);
    }





}

























