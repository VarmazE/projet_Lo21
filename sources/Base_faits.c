#include "../headers/Base_faits.h"

Elem_BF* Ajout_en_queue_BF(Elem_BF* liste, char* proposition)
{
    Elem_BF* newel_p = Creer_BF_Vide();
    newel_p->proposition=concatener(newel_p->proposition,proposition);
    newel_p->next = NULL;

    if (strcmp(liste->proposition,"") == 0)
    {
        return newel_p;
    }
    else
    {
        Elem_BF* temp = liste;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newel_p;
        return liste;
    }
}

//------------------------------------------//

Elem_BF* Creer_BF_Vide()
{
    Elem_BF* newel_p = malloc(sizeof(Elem_BF));
    newel_p->proposition = "";
    newel_p->next = NULL;
    return newel_p;
}