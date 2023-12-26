#include "../headers/regles.h"


Regle* creer_Regle_Vide()
{

    Regle* newel_r= malloc(sizeof (Regle));
    newel_r->premisse="";
    newel_r->conclusion="";
    newel_r->next=NULL;
    return newel_r;
}

//------------------------------------------//

bool Regle_Vide(Regle* regle)
{
    if (strlen(regle->premisse)==0 && strlen(regle->conclusion)==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//------------------------------------------//

bool Appartenance_premisse(Regle* regle, char* proposition)
{

    if (regle->next == NULL)
    {


        if (strcmp(regle->premisse, proposition) == 0)
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

        if (Appartenance_premisse(Reste(regle), proposition) == true)
        {
            return true;
        }
        else
        {
            Regle* temp = regle;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            if (strcmp(temp->premisse, proposition) == 0)
            {
                return true;
            }
            else
            {

                return false; // Correction ici
            }
        }
    }
}

//------------------------------------------//

Regle* Ajout_propostion_regle(Regle* regle,char* proposition)
{
    Regle* newel_r = creer_Regle_Vide();
    newel_r->premisse=proposition;
    newel_r->conclusion=regle->conclusion;

    if (strlen(regle->premisse) == 0)
    {
        return newel_r;
    }
    else
    {
        Regle* temp = regle;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newel_r;
        return regle;
    }


}

//------------------------------------------//

Regle* Creer_Conclusion_Regle(Regle* regle,char* proposition) //changer conclusion
{
    if (strcmp(regle->premisse, "") == 0)
    {
        printf("Impossible de creer une conclusion si aucune premisse n'est detectee");
        return regle;
    }
    else
    {
        Regle* newel_r= malloc(sizeof (Regle*));
        newel_r->premisse=regle->premisse;
        newel_r->next=regle->next;
        newel_r->conclusion= malloc(sizeof (strlen(proposition)+1)); // changer la fonction
        strcpy(newel_r->conclusion,proposition);
        return newel_r;
    }

}

//------------------------------------------//

Regle* Reste(Regle* regle)
{
    Regle* newel_r = creer_Regle_Vide();
    if (regle->next==NULL)
    {
        return newel_r;
    }
    else
    {
        Regle* temp=regle;
        while (temp->next!=NULL)
        {
            newel_r=Ajout_propostion_regle(newel_r,temp->premisse);
            temp=temp->next;
        }
        return newel_r;

    }
}

//------------------------------------------//

void afficherListe(Regle* regle) {
    Regle* courant = regle;
    while (courant != NULL) {
        printf("%s -> ", courant->premisse);
        courant = courant->next;
    }
    printf("NULL\n");
}

//------------------------------------------//

char* concatener(const char* chaine1, const char* chaine2)
{
    // Allouer suffisamment d'espace pour contenir les deux chaînes plus le caractère nul
    char* resultat = malloc(strlen(chaine1) + strlen(chaine2) + 1);

    // Vérifier si l'allocation de mémoire a réussi
    if (resultat == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        exit(EXIT_FAILURE);
    }

    // Copier la première chaîne dans le résultat
    strcpy(resultat, chaine1);

    // Concaténer la deuxième chaîne au résultat
    strcat(resultat, chaine2);

    return resultat;
}

//------------------------------------------//

bool vide_Premisse(char* Premisse)
{
    if (strlen(Premisse)==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//------------------------------------------//

char* tete_Premisse(Regle* regle)
{
    return regle->premisse;
}

//------------------------------------------//

Regle* Supprmier_proposition(Regle* regle,char* proposition)
{
    Regle* newel_r = creer_Regle_Vide();
    if (regle->next==NULL) // tuiliser la fonction appartenir 
    {
        free(regle);
        regle=NULL;
        return regle;
    }
    else
    {
        Regle* temp=regle;
        while (temp != NULL)
        {
            if (strcmp(temp->premisse,proposition) != 0)
            {
                newel_r= Ajout_propostion_regle(newel_r,temp->premisse);
            }
            temp=temp->next;
        }
        return newel_r;
    }
}

//------------------------------------------//

int longueur_Premisse(Regle* regle)
{
    Regle* temp=regle;
    int longuer=0;
    while (temp!=NULL)
    {
        temp=temp->next;
        longuer++;
    }
    return longuer;
}
