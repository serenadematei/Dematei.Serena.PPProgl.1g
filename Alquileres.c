#include <stdio.h>
#include <stdlib.h>
#include "Alquileres.h"
#include "get.h"
#include "Clientes.h"
#include "Categorias.h"
#include "Juegos.h"





void inicializarAlquileres(eAlquiler alquileres[],int tamalqui)
{
    for(int i=0; i<tamalqui; i++)
    {
        alquileres[i].isEmpty=1; //1 vacio, 0 llenos
    }
}



int altaAlquiler(eAlquiler alquileres[],int tamalqui,eCliente clientes[],int tamcli,int*pIdAlquiler,eJuego juegos[],int tamjue,eCategoria categorias[],int tamcat,eLocalidad localidades[],int tamloc)
{
    int todoOk=0;
    int indice;
    eAlquiler nuevoAlquiler; //variable auxiliar para guardar datos
    int codigoCliente;
    int idJuego;

    if(alquileres!=NULL && tamalqui>0 && pIdAlquiler !=NULL && clientes!=NULL && tamcli>0)
    {

        system("cls");
        printf("     Alta Alquiler\n");
        printf("Id alquiler: %d\n", *pIdAlquiler);


        indice=buscarLibreAlquiler(alquileres,tamalqui);


        if(indice==-1)
        {
            printf("No hay lugar para mas alquileres\n");
        }
        else
        {
            nuevoAlquiler.codigo =*pIdAlquiler;



            mostrarClientes(clientes,tamcli,localidades,tamloc);
            printf("Ingrese codigo del cliente: ");
            scanf("%d",&codigoCliente);

            while(buscarCliente(clientes,tamcli,codigoCliente)==-1)  //valido si el legajo ese existe
            {
                printf("No es un cliente valido. Reingrese codigo: ");
                scanf("%d",&codigoCliente);  //hasta q no ingrese un legajo que existe, lo mantengo en el while
            }
            nuevoAlquiler.codigoCliente= codigoCliente;




            mostrarJuegos(juegos,tamjue,categorias,tamcat);
            printf("Ingrese id de juego: ");
            scanf("%d",&idJuego);

            while(buscarJuego(juegos,tamjue,idJuego)==-1)  //valido si el id juego ese existe
            {
                printf("No es un juego valido. Reingrese id  juego: ");
                scanf("%d",&idJuego);
            }
            nuevoAlquiler.codigoJuego=idJuego;

            printf("Ingrese fecha (dd/mm/aaaa):  ");
            scanf("%d/%d/%d",&nuevoAlquiler.fechaIngreso.dia,&nuevoAlquiler.fechaIngreso.mes, &nuevoAlquiler.fechaIngreso.anio);




            nuevoAlquiler.isEmpty=0;
            alquileres[indice]=nuevoAlquiler;





        }


        (*pIdAlquiler)++;



        todoOk=1;

    }

    return todoOk;
}




int buscarLibreAlquiler(eAlquiler alquileres[],int tamalqui)
{
    int indice= -1;

    if(alquileres !=NULL && tamalqui>0)
    {
        for(int i=0; i<tamalqui; i++)
        {
            if(alquileres[i].isEmpty==1)
            {
                indice=i;
                break;
            }
        }

    }

    return indice;
}

int mostrarAlquileres(eCliente clientes[], int tamcli, eJuego juegos[], int tamjue, eAlquiler alquileres[], int tamalqui,eCategoria categorias[],int tamcat)
{
   int flag= 1;
   int todoOk=0;

  if(alquileres!=NULL && tamalqui>0)
  {
    system("cls");
     printf("                                      LISTA DE ALQUILERES\n\n");
     printf("ID Alquiler            Juego      Categoria     Importe        Cliente             ID cliente       Fecha\n");
     printf("---------------------------------------------------------------------------------------------------------------\n");

     for(int i=0; i<tamalqui ; i++)
     {

         if(alquileres[i].isEmpty==0)
         {
             mostrarAlquiler(alquileres[i],juegos,tamjue,clientes,tamcli,categorias,tamcat);
             flag=0;
         }

     }


         if(flag)
         {
             fflush(stdin);
             printf("No hay alquileres en la lista  \n");

         }

     todoOk=1;
  }

  return todoOk;
}









void mostrarAlquiler(eAlquiler unAlquiler,eJuego juegos[],int tamjue,eCliente clientes[],int tamcli,eCategoria categorias[],int tamcat)
{
     char descripcionJuego[51];
     char apellidoCliente[51];
     char categoria[51];
     char localidad[51];
     float importe;


    if(cargarDescripcionJuego (juegos,tamjue,descripcionJuego,unAlquiler.codigoJuego)&&
        cargarApellidoCliente(clientes,tamcli,apellidoCliente,unAlquiler.codigoCliente)&&
       cargarImporteJuego(juegos,tamjue,&importe,unAlquiler.codigoJuego) &&
       cargarCategoriaJuego(categorias,tamcat,juegos,tamjue,categoria,unAlquiler.codigoJuego))
       {
           printf("%5d            %10s   %10s      %.2f      %10s    %10s  %4d        %02d/%02d/%4d \n",
               unAlquiler.codigo,
               descripcionJuego,
               categoria,
               importe,
               apellidoCliente,
               localidad,
               unAlquiler.codigoCliente,
               unAlquiler.fechaIngreso.dia,
               unAlquiler.fechaIngreso.mes,
               unAlquiler.fechaIngreso.anio);
       }
       else
    {
        printf("Hubo un problema al cargar alquiler\n");
    }




}




int bajaCliente(eCliente clientes[], int tamcli,eAlquiler alquileres[], int tamalqui,eLocalidad localidades[],int tamloc)
{
    int todoOk=0;
    int indice;
    int codigoIngresado;
    char confirma;

    system("cls");

    if(clientes!=NULL && tamcli>0)
    {
        mostrarClientes(clientes,tamcli,localidades,tamloc);
        printf("Ingrese codigo del cliente: ");
        scanf("%d",&codigoIngresado);


        indice=buscarCliente(clientes,tamcli,codigoIngresado);

        if(indice==-1)
        {
            printf("No existe cliente con el codigo %d\n",codigoIngresado);
        }
        else
        {
            system("cls");
            mostrarCliente(clientes[indice],localidades,tamloc);
            utn_getCaracter(&confirma,"Confirma la baja? s/n:","Respuesta invalida.",'s','n',3);

        }


        if(confirma=='s')
        {

            clientes[indice].isEmpty=1;
            bajaAlquiler(alquileres,tamalqui,clientes[indice].codigo);


            todoOk=1;
        }
        else
        {
            printf("Baja cancelada por el usuario\n");
        }


    }


 return todoOk;

}

int bajaAlquiler(eAlquiler alquileres[], int tamalqui, int codigo)
{
    int todoOk=0;
    //int cant=0;
    if(alquileres!=NULL && tamalqui>0)
    {
        for(int i=0; i<tamalqui; i++)
        {
            if(!alquileres[i].isEmpty && alquileres[i].codigoCliente==codigo)
            {
                alquileres[i].isEmpty=1;
                //cant++;
                todoOk=1;
            }
        }
    }


    //return cant;
    return todoOk;
}


