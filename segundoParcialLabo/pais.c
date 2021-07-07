#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pais.h"

ePais* nuevoPais()
{
    ePais* nuevoPais = NULL;

    nuevoPais = (ePais*) malloc(sizeof(ePais));

    if(nuevoPais != NULL)
    {
        nuevoPais->id = 0;
        strcpy(nuevoPais->nombre, " ");
        nuevoPais->vac1Dosis = 0;
        nuevoPais->vac2Dosis = 0;
        nuevoPais->sinVacunar = 0;
    }
    return nuevoPais;

}

ePais* nuevoPaisParamStr(char* strId, char* nombre, char* primeraDosisStr, char* segundaDosisStr, char* sinVacunarStr)
{
    ePais* nuevoPais1 = NULL;
    int id;
    int p1;
    int p2;
    int SinV;

    if(strId != NULL && nombre != NULL && primeraDosisStr != NULL && segundaDosisStr != NULL && sinVacunarStr != NULL )
    {
        nuevoPais1 = nuevoPais();

        id = atoi(strId);
        p1 = atoi(primeraDosisStr);
        p2 = atoi(segundaDosisStr);
        SinV = atoi(sinVacunarStr);
        if(nuevoPais1 != NULL)
        {
            nuevoPais1->id = id;
            strcpy(nuevoPais1->nombre, nombre);
            nuevoPais1->vac1Dosis = p1;
            nuevoPais1->vac2Dosis = p2;
            nuevoPais1->sinVacunar = SinV;

        }
    }
    return nuevoPais1;
}

void mostrarPais(ePais* p)
{
    if(p!=NULL)
    {
        printf("%d  %10s       %d    %d   %d\n", p->id, p->nombre, p->vac1Dosis, p->vac2Dosis, p->sinVacunar);
    }

}

void mostrarPaises(LinkedList* list)
{
    int tam;
    if(list!=NULL)
    {
        tam = ll_len(list);
        for(int i = 0; i<tam; i++)
        {
            mostrarPais((ePais*) ll_get(list, i));
        }
        printf("\n\n");
    }
}

ePais* datosRamdon(ePais* pais)
{
    ePais* auxPais = NULL;
    int vac1;
    int vac2;
    int sinV;

    if(pais != NULL)
    {
        auxPais = (ePais*) pais;

        vac1 = rand() % (60 - 1 + 1) +1;
        vac2 = rand() % (40 - 1 + 1) +1;
        sinV = 100 - (vac1 + vac2);

        auxPais->vac1Dosis = vac1;
        auxPais->vac2Dosis = vac2;
        auxPais->sinVacunar = sinV;
    }

    return (void*) auxPais;
}

int filtrarPaisesMejor(void* pElement)
{
    int todoOk = 0;
    ePais* aux = NULL;
    if(pElement != NULL)
    {
        aux = (ePais*) pElement;
        if(aux->vac2Dosis > 30)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int filtrarPaisesPeor(void* pElement)
{
    int todoOk = 0;
    ePais* aux = NULL;
    if(pElement != NULL)
    {
        aux = (ePais*) pElement;
        if(aux->sinVacunar > aux->vac1Dosis)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}
