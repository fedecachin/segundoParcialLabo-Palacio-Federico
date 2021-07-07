#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse.h"
#include "pais.h"
#include "LinkedList.h"

int cargarArchivoTxt(char* archivo, LinkedList* lista)
{
    int todoOk = 0;
    char auxCadena[5][50];
    ePais* auxPais = NULL;
    int bandera = 0;
    if(archivo != NULL && lista != NULL)
    {
        FILE* f = fopen(archivo, "r");

        if(f != NULL)
        {
            while(!feof(f))
            {
                if(fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxCadena[0],auxCadena[1],auxCadena[2],auxCadena[3],auxCadena[4])==5)
                {
                    if(bandera)
                    {
                        auxPais = nuevoPaisParamStr(auxCadena[0],auxCadena[1],auxCadena[2],auxCadena[3],auxCadena[4]);
                        if(auxPais != NULL)
                        {
                            ll_add(lista, auxPais);
                        }

                    }
                    bandera = 1;

                }
            }
            todoOk = 1;
        }
    }
    return todoOk;
}
