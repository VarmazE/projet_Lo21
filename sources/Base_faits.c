#include "../headers/Base_faits.h"

Elem_BF* Creer_BF_Vide()
{
    Elem_BF* newel_p = malloc(sizeof(Elem_BF));
    newel_p->proposition = "";
    newel_p->next = NULL;
    return newel_p;
}

//------------------------------------------//

Elem_BF* Ajout_en_queue_BF(Elem_BF* liste, char* proposition)
{
    if (Appartenance_BF(liste,proposition)==false)
    {
        Elem_BF* newel_p = Creer_BF_Vide();
        newel_p->proposition=proposition;
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
    else
    {
        return liste;
    }
}

//------------------------------------------//

void afficherListe_BF(Elem_BF* liste_BF) {
    Elem_BF* courant = liste_BF;

    printf("\n");

    printf("\n=======================================\n");
    printf("  Affichage de la liste de faits\n");
    printf("=======================================\n");

    while (courant != NULL) {
        printf("%s -> ", courant->proposition);
        courant = courant->next;
    }

    printf("NULL\n");

    printf("=======================================\n");
    printf("  Fin de la liste de faits\n");
    printf("=======================================\n");
    printf("\n");
    printf("\n");
}


//------------------------------------------//

int longueur_BF(Elem_BF* liste_BF)
{
    Elem_BF* temp=liste_BF;
    int longuer=0;
    while (temp!=NULL)
    {
        temp=temp->next;
        longuer++;
    }
    return longuer;
}
//------------------------------------------//

Elem_BF* Reste_BF(Elem_BF* listeBF)
{
    Elem_BF* newel_BF = Creer_BF_Vide();
    if (listeBF->next==NULL)
    {

        return newel_BF;
    }
    else
    {
        Elem_BF* temp = listeBF;
        while (temp->next!=NULL)
        {
            newel_BF=Ajout_en_queue_BF(newel_BF,temp->proposition);

            temp=temp->next;
        }
        return newel_BF;
    }
}

//------------------------------------------//

bool Appartenance_BF(Elem_BF* listeBF, char* proposition)
{
    if (listeBF->next == NULL)
    {

        if (strcmp(listeBF->proposition, proposition) == 0)
        {

            return true;
        }
        else
        {

            return false;
        }
    }

    else
    {

        if (Appartenance_BF(Reste_BF(listeBF), proposition) == true)
        {
            return true;
        }
        else
        {
            Elem_BF* temp = listeBF;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            if (strcmp(temp->proposition, proposition) == 0)
            {

                return true;
            }
            else
            {

                return false;
            }
        }
    }
}

//------------------------------------------//

bool Comparaison_BF(Elem_BF* liste_BF1,Elem_BF* liste_BF2)
{
    if (longueur_BF(liste_BF1) != longueur_BF(liste_BF2))
    {
        return false;
    }
    else
    {
        Elem_BF* temp1=liste_BF1;
        Elem_BF* temp2=liste_BF2;
        while (temp1 != NULL)
        {
            if (strcmp(temp1->proposition,temp2->proposition) != 0)
            {
                return false;
            }
            else
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
    }
    return true;
}

//------------------------------------------//

Elem_BF* copierListe_BF(Elem_BF* liste)
{
    Elem_BF* newel_BF = Creer_BF_Vide();
    Elem_BF* temp = liste;
    while (temp != NULL)
    {
        newel_BF = Ajout_en_queue_BF(newel_BF,temp->proposition);
        temp=temp->next;
    }
    return newel_BF;
}