#include "../headers/Bases_Connaissances.h"


Elem_BC* creer_Base_Connaissances()
{
    Elem_BC* newel= malloc(sizeof (Elem_BC));
    newel->regle=creer_Regle_Vide();
    newel->next=NULL;
    return newel;
}

//------------------------------------------//

void afficherListe_BC(Elem_BC* liste_BC) {
    Elem_BC* courant = liste_BC;
    int compteur = 1;
    printf("\n");
    printf("\n");

    printf("\n=======================================\n");
    printf("  Affichage de la Base de Connaissances\n");
    printf("=======================================\n");

    while (courant != NULL) {
        printf("\n--- Regle %d ---\n", compteur);
        afficher_Liste_Regle(courant->regle);
        printf("-----------------\n");

        courant = courant->next;
        compteur++;
    }
    printf("\n");
    printf("\n");
}



//------------------------------------------//

Elem_BC* Ajout_en_queue_BC(Elem_BC* liste, Regle* regle)
{
    Elem_BC* newel = malloc(sizeof(Elem_BC));
    newel->regle = regle;
    newel->next = NULL;

    if (Regle_Vide(liste->regle))
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
        return liste;
    }
}

//------------------------------------------//

Regle* tete_BC(Elem_BC* liste)
{
    return liste->regle;
}