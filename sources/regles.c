#include "../headers/regles.h"


Regle* creer_Regle_Vide()
{

    Regle* newel_r= malloc(sizeof (Regle*));
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

bool Appartence_premisse(char* Premisse,char proposition)
{
    if (strlen(Premisse) == 0)
    {
        return false;
    }
    else
    {

        if (Appartence_premisse(Reste(Premisse),proposition))
        {
            return true;
        }
        else
        {

            if (Premisse[strlen(Premisse)-1]==proposition)
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

Regle* Ajout_propostion_regle(Regle* regle,char* proposition)
{
    Regle *newel_r = malloc(sizeof(Regle *));
    newel_r->next = regle->next;
    newel_r->conclusion = regle->conclusion;
    newel_r->premisse=regle->premisse;
    if (Appartence_premisse(regle->premisse,proposition[0])==false) {




        // Allocation de mémoire pour newel_premises
        char *newel_premisse = malloc(sizeof(strlen(regle->premisse) + strlen(proposition) + 1));

        // Copier la prémisse vers newel_premisse
        strcpy(newel_premisse, regle->premisse);

        // Concaténer la proposition à la fin de newel_premisse
        strcat(newel_premisse, proposition);

        //Faire correspondre la mémoire de la règle à la nouvelle prémisse
        newel_r->premisse = malloc(sizeof(strlen(regle->premisse) + strlen(proposition) + 1));

        strcpy(newel_r->premisse, newel_premisse);
        free(newel_premisse);

        return newel_r;
    }
    else
    {
        printf("Impossible la propostion est déjà présent dans la prémisse\n");
        return newel_r;
    }

}

//------------------------------------------//

Regle* Creer_Conclusion_Regle(Regle* regle,char* proposition)
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
        newel_r->conclusion= malloc(sizeof (strlen(proposition)+1));
        strcpy(newel_r->conclusion,proposition);
        return newel_r;
    }

}

//------------------------------------------//

char* Reste(char* chaine)
{
    if (chaine == NULL)
    {
        perror("Allocation de mémoire échouée");
        exit(1);
    }
    else
    {
        char *newel_chaine= malloc(strlen(chaine) );
        strcpy(newel_chaine, chaine);
        newel_chaine[strlen(newel_chaine) - 1] = '\0';

        return newel_chaine;
    }
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

char* Supprimer_Premisse(char* Premssie,char proposition)
{
    if (strlen(Premssie)==1)
    {
        if (Premssie[0] == proposition)
        {
            char* newel_premisse= "";
            return newel_premisse;
        }
        else
        {
            return Premssie;

        }
    }
    else
    {
        if (Premssie[strlen(Premssie)-1] != proposition)
        {
            char queue[1];
            sprintf(queue, "%c", Premssie[strlen(Premssie)-1]);

            return concatener(Supprimer_Premisse(Reste(Premssie),proposition),queue);
        }
        else
        {
            return Reste(Premssie);
        }
    }
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

char* tete_Premisse(const char* Premisse)
{
    if (Premisse == NULL || Premisse[0] == '\0') {
        return NULL;
    }
    char* tete = malloc(2);
    tete[0] = Premisse[0];
    tete[1] = '\0';
    return tete;
}
