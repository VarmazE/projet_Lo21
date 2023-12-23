#include "../headers/Bases_Connaissances.h"

//------------------------------------------//

Elem_BC* creer_Base_Connaissances()
{
    Elem_BC* newel= malloc(sizeof (Elem_BC*));
    newel->regle=creer_Regle_Vide();
    newel->next=NULL;
    return newel;
}

//------------------------------------------//

Elem_BC* Ajout_en_queue_BC(Elem_BC* liste, Regle* regle)
{
    Elem_BC* newel = malloc(sizeof(Elem_BC));
    newel->regle = regle;
    newel->next = NULL;

    if (liste == NULL)
    {
        return newel;
    }
    else
    {
        Elem_BC* temp= liste;
        while (temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=newel;
        return temp;
    }
}