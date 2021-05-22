#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataWareHouse.h"

//JUEGOS

static char nombres[10][20]={
    "Donato",
    "German",
    "Gunda",
    "Carmen",
    "Daniela",
    "Maria",
    "Alex",
    "Damian",
    "Gaston",
    "Santiago"

};

static char apellidos[10][20]={
    "Gomez",
    "Lopez",
    "Perez",
    "Diaz",
    "Fraiese",
    "Parodi",
    "Ferraro",
    "Bongiovani",
    "Taborda",
    "Contardi"

};


static int telefonos[10]={15560203,15432532,15121358,15204671,15463338,15453347,15301213,15463318,15782029,15423340};

static char sexos[10]={'m','m','f','f','f','f','m','m','m','m'};

static int edades[10]={56,53,58,71,38,47,30,46,29,40};

static float sueldos[10]={10000,12000,11000,12000,13700,11800,10300,13100,14700,12400};

static eFecha fechas[10]={
    {2,3,2001},
    {21,5,2018},
    {10,8,2004},
    {12,8,2017},
    {23,1,2015},
    {13,10,2021},
    {6,7,2011},
    {16,12,2017},
    {8,4,2002},
    {29,2,2020}
};





static int legEmpleados[20]={20000,20000,20001,20002,20005,20003,20001,20007,20005,20006,20004,20009,20007,20005,20000,20001,20002,20005,20007,20003};

static int idComidasA[20]={1000,1004,1002,1000,1000,1000,1003,1004,1003,1000,1001,1002,1001,1003,1004,1001,1001,1003,1002,1004};

static eFecha fechas2[20]={
    {2,3,2021},
    {21,5,2021},
    {10,4,2021},
    {2,3,2021},
    {21,11,2021},
    {10,8,2021},
    {2,3,2021},
    {21,5,2021},
    {10,8,2021},
    {7,3,2021},
    {21,5,2021},
    {10,12,2021},
    {12,5,2021},
    {23,1,2021},
    {12,3,2021},
    {21,5,2021},
    {10,12,2021},
    {22,2,2021},
    {23,1,2021},
    {26,3,2021}
};

static char marcasAutos[10][20]={
    "Fiat",
    "Renault",
    "BMW",
    "Ferrari",
    "Ford",
    "Audi",
    "Seat",
    "Hiundai",
    "Chevrolet",
    "Peugeot"

};


static char marcasCelulares[10][20]= {
    "Samsung",
    "Motorola",
    "Apple",
    "Sony",
    "BGH",
    "LG",
    "Huawei",
    "Xiaomi"

};

static char marcasCervezas[10][20]= {
    "Heineken",
    "Budweiser",
    "Patagonia",
    "Brahma",
    "Quilmes",
    "Andes",
    "Guinness",
    "Corona",
    "Sol",
    "Amstel",
    "Iguana"

};

static char marcasElectrodomesticos[10][20]={
    "Samsung",
    "BGH",
    "Philips",
    "Coventry",
    "Balay",
    "Fujitsu",
    " Siemens",
    "Fagor",
    "Candy",
    "Orbis"
};





static char marcasBicicletas[10][20]={
  "Venzo",
  "Philco",
  "Specialized",
  "Factor",
  "Trek",
  "Cervelo",
  "Giant",
  "Canyon",
  "Ghost",
  "Pinarello"

};

static char ciudades[10][20]={
    "Mercedes",
    "Lujan",
    "Moreno",
    "Moron",
    "Suipacha",
    "Chivilcoy",
    "La plata",
    "San isidro",
    "Pilar",
    "Merlo"


};

static char marcasRopa[10][20]={
    "Prada",
    "Kevingston",
    "Tommy Hilfiger",
    "Vans",
    "Bearcliff",
    "Element",
    "Nike",
    "Columbia",
    "Zara",
    "Gucci"

};








static char emails[10][100]={
    "sofiaaguirre2020@gmail.com",
    "carlaconte@hotmail.com",
    "cesarsanmartin@outlook.com",
    "facundo_bocajrs@gmail.com",
    "estebanbenitez32@hotmail.com",
    "nelbarosamartinez@hotmail.com",
    "sandragonzales@gmail.com",
    "juancruzdematei@outlook.com",
    "sergiomatei@gmail.com",
    "silvinalarrondo46@outlook.com"


};

char static libros[10][20]={
   "El principito",
   "Cien años de soledad",
   "Rayuela",
   "Cronica de una muerte anunciada",
   "El lobo estepario",
   "Demian",
   "Ojos de perro azul",
   "Bestiario",
   "La metamorfosis",
   "Cumbres borrascosas"
};



char static animales[10][20]={
   "Perro",
   "Gato",
   "Vaca",
   "Caballo",
   "Gallina",
   "Oveja",
   "Cabra",
   "Conejo",
   "Cerdo",
   "Burro"
};


char static paises[10][20]={
   "Argentina",
   "Colombia",
   "Venezuela",
   "Brasil",
   "Chile",
   "Peru",
   "Paraguay",
   "Uruguay",
   "Ecuador",
   "Mexico"
};

char static productosLimpieza[10][20]={
   "Lavandina",
   "Detergente",
   "Quitasarro",
   "Jabon blanco",
   "Jabon polvo",
   "Aromatizante",
   "Cera",
   "Desinfectante",
   "Quitamanchas",
   "Lustramueble"
};

char static peliculas[10][20]={
   "El bar",
   "Dolor y gloria",
   "El orfanato",
   "Rapido y furioso",
   "Scarface",
   "El padrino",
   "Perfectos desconocidos",
   "La huerfana",
   "Parasite",
   "Diario de una pasion"
};

static int codigoJuego[10]={100,102,103,101,103,101,104,104,103,103};
static int idCategorias[10]={500,500,502,501,503,501,504,500,501,503};
static int idLocalidades[10]={600,604,601,603,602,604,600,600,602,603};



static int codigoClientes[10]={2000,2000,2001,2002,2005,2003,2001,2007,2005,2006,2004,2009,2007,2005,2000,2001,2002,2005,2007,2003};

int hardcodearClientes (eCliente clientes[], int tamcli, int cant, int* pIdCliente)
{
    int retorno=0;
    if(clientes!=NULL && tamcli>0 && cant>=0 && cant<=tamcli && pIdCliente!=NULL)
    {
        for(int i=0; i<cant; i++)
        {
            clientes[i].codigo=*pIdCliente;
            (*pIdCliente)++;
            strcpy(clientes[i].nombre, nombres[i]);
            strcpy(clientes[i].apellido,apellidos[i]);
            clientes[i].sexo=sexos[i];
            clientes[i].telefono=telefonos[i];
            clientes[i].idLocalidad= idLocalidades[i];
            clientes[i].isEmpty=0;

         }

         retorno=1;
    }

    return retorno;
}




int hardcodearAlquileres(eAlquiler alquileres[], int tamalqui, int cant, int* pIdAlquiler)
{
    int retorno=0;
    if(alquileres!=NULL && tamalqui>0 && cant>=0 && cant<=tamalqui && pIdAlquiler!=NULL)
    {
        for(int i=0; i<cant; i++)
        {
            alquileres[i].codigo=*pIdAlquiler;
            (*pIdAlquiler)++;

            alquileres[i].codigoCliente=codigoClientes[i];
            alquileres[i].codigoJuego=codigoJuego[i];
            alquileres[i].fechaIngreso=fechas2[i];
            alquileres[i].isEmpty=0;

           retorno=1;
        }
    }
    return retorno;
}




