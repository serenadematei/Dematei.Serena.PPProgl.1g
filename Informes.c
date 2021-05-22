#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Informes.h"
#include "Clientes.h"
#include "Localidad.h"
#include "get.h"



int informar(eCliente clientes[],int tamcli,eAlquiler alquileres[],int tamalqui,eJuego juegos[],int tamjue,eCategoria categorias[],int tamcat,eLocalidad localidades[],int tamloc)
{
    int todoOk=0;
    int opcion;

    if(clientes!=NULL && tamcli>0 && alquileres!=NULL &&tamalqui>0 && juegos!=NULL &&tamjue >0 && categorias!=NULL && tamcat>0)
    {
        do
        {
            opcion=menuInformes();
            switch(opcion)
            {
            case 1:



                mostrarAlquileresPorCliente(clientes,tamcli,alquileres,tamalqui,juegos,tamjue,categorias,tamcat,localidades,tamloc);

                printf("\n\n");
                system("pause");
                break;
            case 2:

                totalGastoAlquiler (clientes,tamcli, alquileres,tamalqui,juegos,tamjue,categorias,tamcat,localidades,tamloc);

                printf("\n\n");
                system("pause");
                break;
            case 3:
                clientesPorLocalidad(clientes,tamcli,localidades,tamloc);

                system("pause");
                break;
            case 4:
                juegoPreferidoDeUnaLocalidad(clientes,tamcli,localidades,tamloc,juegos, tamjue,alquileres,tamalqui);

                printf("\n\n");
                system("pause");
                break;
            case 5:
                localidadQueMasJugoUnJuego(clientes,tamcli,localidades,tamloc, juegos,tamjue,alquileres, tamalqui,categorias,tamcat);

                system("pause");
                break;
            case 6:
                juegosMasAlquiladosPorHombres(clientes,tamcli,localidades, tamloc, juegos, tamjue, alquileres,tamalqui);

                printf("\n\n");
                system("pause");
                break;
            case 7:

                printf("\n\n");
                system("pause");
                break;
            case 8:

                system("pause");
                break;
            case 9:

                printf("\n\n");
                system("pause");
                break;
            case 10:

                printf("\n\n");
                system("pause");
                break;
            case 11:
                //volver a menu principal

                break;

            }

            printf("\n\n");

        }while(opcion!=11);

        todoOk=1;
    }

    return todoOk;

}




int menuInformes()
{
    int opcion;

    system("cls");
    printf("   ***MENU INFORMES***\n\n");
    printf("1. Mostrar alquileres por cliente\n");
    printf("2.Gastos totales del cliente en alquileres\n");
    printf("3.Cantidad de clientes por localidad\n");
    printf("4.Juego preferido de una localidad\n");
    printf("5.Localidad que mas jugo un juego\n");
    printf("6. Juegos mas alquilados por hombres\n");
    printf("7.\n");
    printf("8.\n");
    printf("9.\n");
    printf("10.\n");
    printf("11.Volver al menu principal\n");
    printf("___________________________________________\n");
    utn_getNumero(&opcion,"Ingrese opcion: ","Opcion no valida.",1,11,3);

    return opcion;
}




int localidadQueMasJugoUnJuego(eCliente clientes[], int tamcli, eLocalidad localidades[], int tamloc, eJuego juegos[], int tamjue, eAlquiler alquileres[], int tamalqui,eCategoria categorias[],int tamcat)
{
    int todoOk=0;
    int idJuego;
    int mayor;
    int contador[5]={0};

    if(clientes!=NULL && localidades!=NULL && tamloc>0 && tamcli>0 && juegos!=NULL && tamjue>0 && alquileres!=NULL && tamalqui>0 && categorias!=NULL && tamcat>0)
    {
        mostrarJuegos(juegos,tamjue,categorias,tamcat);
        utn_getNumero(&idJuego,"Ingrese ID: ","ERROR. ",100,104,3);
        while(buscarJuego(juegos,tamjue,idJuego)==-1)
        {
            utn_getNumero(&idJuego,"Ingrese un ID valido: ","ERROR. ",100,104,3);
        }

        for(int i=0; i<tamjue; i++)
        {
            if(juegos[i].codigo==idJuego)
            {
                for(int j=0; j<tamalqui; j++)
                {
                    if(alquileres[j].codigoJuego==juegos[i].codigo && !alquileres[j].isEmpty)
                    {
                        for(int k=0; k<tamcli; k++)
                        {
                            if(alquileres[j].codigoCliente==clientes[k].codigo && !clientes[k].isEmpty)
                            {
                                switch(clientes[k].idLocalidad)
                                {
                                case 600:
                                    contador[0]++;
                                    break;
                                case 601:
                                    contador[1]++;
                                    break;
                                case 602:
                                    contador[2]++;
                                    break;
                                case 603:
                                    contador[3]++;
                                    break;
                                case 604:
                                    contador[4]++;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }

        mayor=contador[0];
        for(int i=1; i<tamjue; i++)
        {
            if(contador[i]>mayor)
            {
                mayor=contador[i];
            }
        }

        printf("Las localidades que mas jugaron a ese juego fueron:\n");
        for(int i=0; i<tamloc; i++)
        {
            if(contador[i]==mayor)
            {
                printf(" %s ", localidades[i].descripcion);
            }
        }
        printf("\n\n");

        todoOk=1;
    }

  return todoOk;
}



int  juegoPreferidoDeUnaLocalidad(eCliente clientes[], int tamcli, eLocalidad localidades[], int tamloc, eJuego juegos[], int tamjue, eAlquiler alquileres[], int tamalqui)
{

    int todoOk=0;
    int contador[5]={0};
    int idLocalidad;
    int mayor;

    system("cls");

    if(clientes!=NULL && localidades!=NULL && tamloc>0 && tamcli>0 && juegos!=NULL && tamjue>0 && alquileres!=NULL && tamalqui>0)
    {
        mostrarLocalidades(localidades,tamloc);
        utn_getNumero(&idLocalidad,"Ingrese ID de la localidad: ","ERROR. ",600,604,3);
        while(buscarLocalidad(localidades,tamloc,idLocalidad)==-1)
        {
            utn_getNumero(&idLocalidad,"Ingrese un ID valido: ","ERROR. ",600,604,3);
        }

        for(int i=0; i<tamcli; i++)  //recorro array clientes
        {
            if(clientes[i].idLocalidad==idLocalidad && !clientes[i].isEmpty)
            {
                for(int j=0; j<tamalqui; j++)  //recorro alquileres
                {
                    if(alquileres[j].codigoCliente==clientes[i].codigo && !alquileres[j].isEmpty)
                    {
                        switch(alquileres[j].codigoJuego)
                        {
                        case 100:
                            contador[0]++;
                            break;
                        case 101:
                            contador[1]++;
                            break;
                        case 102:
                            contador[2]++;
                            break;
                        case 103:
                            contador[3]++;
                            break;
                        case 104:
                            contador[4]++;
                            break;
                        }
                    }
                }
            }



        }

        mayor=contador[0];
        for(int i=1; i<tamjue; i++)
        {
            if(contador[i]>mayor)
            {
                mayor=contador[i];
            }
        }

        printf("Juego favorito de la localidad:\n");
        for(int i=0; i<tamjue; i++)
        {
            if(contador[i]==mayor)
            {
                printf(" %s ", juegos[i].descripcion);
            }
        }
        printf("\n\n");



        todoOk=1;
    }


  return todoOk;
}


int clientesPorLocalidad(eCliente clientes[], int tamcli, eLocalidad localidades[],int tamloc)
{
    int todoOk=0;
    int auxId;
    int contador=0;
    char descripcion[51];
    system("cls");

    if(clientes!=NULL && localidades!=NULL && tamloc>0 && tamcli>0)
    {
        printf("   INFORME CLIENTES POR LOCALIDAD\n");
        mostrarLocalidades(localidades, tamloc);
        if(clientes!=NULL && tamcli>0 && localidades!=NULL && tamloc>0 && !utn_getNumero(&auxId, "Ingrese el ID de la localidad: ","ERROR. ", 600,604,10))
        {
            printf("\n\n");
            cargarDescripcionLocalidad(auxId,localidades,tamloc,descripcion);
            for(int i=0; i<tamcli; i++)
            {
                if(clientes[i].idLocalidad==auxId && !clientes[i].isEmpty)
                {
                    mostrarCliente(clientes[i],localidades,tamloc);
                    contador++;
                }
            }
            if(!contador)
            {
                printf("No hay clientes en la localidad %s.\n",descripcion);
            }
            else
            {
                printf("Hay %d clientes en la localidad %s.\n",contador,descripcion);
            }

            printf("\n\n");

        }


        todoOk=1;
    }

    return todoOk;
}


int totalGastoAlquiler (eCliente clientes[],int tamcli,eAlquiler alquileres[],int tamalqui,eJuego juegos[],int tamjue,eCategoria categorias[],int tamcat,eLocalidad localidades[],int tamloc)
{
    int todoOk=0;
    int codigo;
    int flag=0;
    float totalPrecioAlquileres=0;
    int codigoJuego;

    if(clientes!=NULL && localidades!=NULL && tamloc>0 && tamcli>0 && alquileres!=NULL && tamalqui>0 && juegos!=NULL && tamjue>0 && categorias!=NULL &&tamcat>0)
    {
        printf( " Gastos totales del cliente en alquileres\n\n");

        mostrarClientes(clientes,tamcli,localidades,tamloc);
        printf("Ingrese codigo: ");
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
                // flagGastos=1;

                codigoJuego = alquileres[i].codigoJuego;

                for(int j=0; j<tamjue ; j++)
                {


                    if(juegos[j].codigo==codigoJuego)
                    {

                        totalPrecioAlquileres=totalPrecioAlquileres+juegos[j].importe;
                        flag=1;
                    }
                }

            }


        }

        if(flag)
        {
            printf("\n El total gastado en alquileres por este cliente es de: $%.2f",totalPrecioAlquileres);
        }


        if(!flag )
        {
            printf("El cliente del codigo %d no registra alquileres\n",codigo);
        }

        todoOk=1;
    }


  return todoOk;
}

int juegosMasAlquiladosPorHombres(eCliente clientes[], int tamcli, eLocalidad localidades[], int tamloc, eJuego juegos[], int tamjue, eAlquiler alquileres[], int tamalqui)
{
    int todoOk=0;
    int contador[5]={0};
    int mayor;

    system("cls");


 if(clientes!=NULL && localidades!=NULL && juegos!=NULL && alquileres!=NULL && tamloc>0 && tamcli>0 && tamjue>0 && tamalqui>0)
 {
      for(int i=0; i<tamcli; i++)
    {
        if(!clientes[i].isEmpty && clientes[i].sexo=='m')
        {
            for(int j=0; j<tamalqui; j++)  //recorro alquileres
            {
                if(alquileres[j].codigoCliente==clientes[i].codigo && !alquileres[j].isEmpty)
                {

                    switch(alquileres[j].codigoJuego)
                    {
                        case 100:
                        contador[0]++;
                        break;
                    case 101:
                        contador[1]++;
                        break;
                    case 102:
                        contador[2]++;
                        break;
                    case 103:
                        contador[3]++;
                        break;
                    case 104:
                        contador[4]++;
                        break;
                    }

                }
            }
        }
    }
    todoOk=1;
 }


    mayor=contador[0];
    for(int i=1; i<tamjue; i++)
    {
        if(contador[i]>mayor)
        {
            mayor=contador[i];
        }
    }

    printf("Juego favorito de los hombres:\n");
    for(int i=0; i<tamjue; i++)
    {
        if(contador[i]==mayor)
        {
            printf(" %s ", juegos[i].descripcion);
        }
    }
    printf("\n\n");



    return todoOk;

}


