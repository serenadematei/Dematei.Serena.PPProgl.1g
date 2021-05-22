#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Clientes.h"
#include "get.h"
#include "Localidad.h"


void inicializarClientes(eCliente clientes[], int tamcli)
{
    for(int i=0; i<tamcli; i++)
    {
        clientes[i].isEmpty=1; //1 vacio, 0 llenos
    }
}


int altaCliente(eCliente clientes[],int tamcli,int* pId)
{
    int todoOk=0;
    int indice;
    char auxChar[21];
    eCliente nuevoCliente; //variable auxiliar para guardar datos


    if(clientes !=NULL && tamcli>0 && pId !=NULL)
    {

        system("cls");
        printf("     Alta cliente\n");
        printf("Codigo: %d\n", *pId);


        indice=buscarLibre(clientes,tamcli);


        if(indice==-1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            nuevoCliente.codigo=*pId;

        utn_getNombre(&nuevoCliente.nombre,"Ingrese nombre: ","Error.\n",50,10);
        utn_getNombre(&nuevoCliente.apellido,"Ingrese apellido: ","Error.\n",50,10);
        utn_getCaracter(&nuevoCliente.sexo,"Ingrese sexo: ","Error.\n",'f','m',10);
        utn_getNumero(&nuevoCliente.telefono,"Ingrese telefono (8 digitos): ","Error.\n",10000000,99999999,10);




            nuevoCliente.isEmpty=0;
            clientes[indice]=nuevoCliente;
            (*pId)++;



            todoOk=1;

        }

    }


    return todoOk;

}




int buscarLibre(eCliente clientes[],int tamcli)
{
    int indice= -1;

    if(clientes !=NULL && tamcli>0)
    {
        for(int i=0; i<tamcli; i++)
        {
            if(clientes[i].isEmpty==1)
            {
                indice=i;
                break;
            }
        }

    }

    return indice;
}



int mostrarClientes(eCliente clientes[], int tamcli,eLocalidad localidades[],int tamloc)
{
   int flag= 1;
   int todoOk=0;

  if(clientes!=NULL && tamcli>0)
  {
      system("cls");
     printf("                     LISTA DE CLIENTES\n\n");
     printf("Codigo           Apellido      Nombre        Sexo     Telefono         Localidad\n");

     for(int i=0; i<tamcli ; i++)
     {
         if(!clientes[i].isEmpty)
         {
             mostrarCliente(clientes[i],localidades,tamloc);
             flag=0;
         }

         if(flag)
         {

             fflush(stdin);
             printf("No hay clientes en la lista \n");

         }

     }

     todoOk=1;
  }


}


void mostrarCliente(eCliente unCliente,eLocalidad localidades[],int tamloc)
{
    char descripcion[51];

    if(cargarDescripcionLocalidad(unCliente.idLocalidad,localidades,tamloc,descripcion))
       {
            printf("%6d         %10s   %10s        %c        %d      %10s\n"
           ,unCliente.codigo
           ,unCliente.apellido
           ,unCliente.nombre
           ,unCliente.sexo
           ,unCliente.telefono
           ,descripcion

           );
       }




}



int cargarDescripcionLocalidad(int id,eLocalidad localidades[],int tamloc, char descripcion[])
{
    int todoOk=0;


    if(id>=600 && id<=604 && localidades!=NULL && tamloc>0 && descripcion!=NULL)
    {
        for(int i=0; i<tamloc ; i++)
        {
            if(localidades[i].id==id)
            {
                strcpy(descripcion, localidades[i].descripcion);
                todoOk=1;
                break;
            }
        }
    }
   return todoOk;
}



int buscarCliente(eCliente clientes[],int tamcli,int codigoIngresado)
{
    int indice=-1;

     if(clientes!=NULL && tamcli>0)
     {
          for(int i=0; i<tamcli ; i++)
        {
            if(clientes[i].isEmpty==0 && clientes[i].codigo == codigoIngresado)
            {
                indice=i;
                break;
            }


        }
     }


     return indice;
}


int subMenuModificaciones()
{
    int opcion;

    printf("\n\n\n");
    printf("1-Modificar nombre del cliente\n");
    printf("2-Modificar apellido del cliente\n");
    printf("3-Modificar sexo del cliente\n");
    printf("4-Guardar cambios y salir.\n");
    printf("5-Descartar cambios y salir.\n");

    utn_getNumero(&opcion,"Ingrese una opcion: ","Error.:",1,5,10);

    return opcion;
}



int modificarClientes(eCliente clientes[],int tamcli,eLocalidad localidades[],int tamloc)
{

    eCliente unCliente;
    int todoOk=0;

    int opcion;
    int indice;
    int codigo;
    char continuar='s';
    int flagNombre=1;
    int flagApellido=1;
    int flagSexo=1;



    system("cls");



    mostrarClientes(clientes,tamcli,localidades,tamloc);

    printf("\n\n");
    printf("\nIngrese codigo del cliente a modificar: ");
    scanf("%d",&codigo);


    indice=buscarCliente(clientes,tamcli,codigo);

    if(indice==-1)
    {
        printf("No existe cliente con el codigo %d\n",codigo);
    }
    else
    {



        system("cls");
        printf("Cliente encontrado:\n \n");
        mostrarCliente(clientes[indice],localidades,tamloc);
        printf("\n\n");



        do
        {

            opcion=subMenuModificaciones();

            switch(opcion)
            {
            case 1:
                system("cls");
                flagNombre= utn_getNombre(&unCliente.nombre,"Ingrese nuevo nombre:","Error. ",51,10);
                break;
            case 2:
                system("cls");
                flagApellido= utn_getNombre(&unCliente.apellido,"Ingrese nuevo apellido:","Error. ",51,10);
                break;
            case 3:
                system("cls");
                flagSexo=utn_getCaracter(&unCliente.sexo,"Ingrese nuevo sexo: ","Error. ", 'f','m',10);
                break;
            case 4:
                if(!flagNombre)
                {
                    strcpy(clientes[indice].nombre,unCliente.nombre);
                }
                if(!flagApellido)
                {
                    strcpy(clientes[indice].apellido,unCliente.apellido);
                }
                if(!flagSexo)
                {
                    clientes[indice].sexo=unCliente.sexo;
                }


                printf("\n\nCliente modificado: ");
                mostrarCliente(clientes[indice],localidades,tamloc);
                printf("\n\n");
                printf("\nCambios guardados, volviendo al menu principal...\n\n");

                todoOk=1;
                break;


            case 5:
                printf("\n\n");
                printf("Cambios descartados, volviendo al menu principal...\n\n");
                break;




            }
         todoOk=1;
        }
        while(opcion!=5 && opcion!=4);

    }
    return todoOk;
}


int ordenarClientes(eCliente clientes[],int tamcli)
{
    int todoOk=0;
    eCliente auxCliente;


  if(clientes!=NULL && tamcli>0)
  {
        for(int i=0; i<tamcli-1 && !clientes[i].isEmpty; i++)
        {
            for(int j=i+1; j<tamcli && !clientes[j].isEmpty; j++)
            {
                if(stricmp(clientes[i].apellido,clientes[j].apellido)>0 )//orden alfabetico
                {
                    auxCliente = clientes[i];
                    clientes[i] = clientes[j];
                    clientes[j] = auxCliente;
                }
                if(stricmp(clientes[i].apellido,clientes[j].apellido)==0)
                {
                    if(stricmp(clientes[i].nombre,clientes[j].nombre)>0)
                    {
                        auxCliente=clientes[i];
                        clientes[i] = clientes[j];
                        clientes[j] = auxCliente;

                    }
                }




            }
        }





           todoOk=1;

         }


   return todoOk;
}

int cargarApellidoCliente(eCliente clientes[],int tamcli,char apellidoCliente[],int id)
{
    int todoOk=0;

    if(clientes!=NULL && tamcli>0 && id>=2000 && apellidoCliente!=NULL)
    {
        for(int i=0; i<tamcli; i++)
        {
            if(clientes[i].codigo==id)
            {
                strcpy(apellidoCliente,clientes[i].apellido);
                todoOk=1;
                break;
            }
        }


    }



    return todoOk;
}
