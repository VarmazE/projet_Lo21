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

                return false;
            }
        }
    }
}

//------------------------------------------//

Regle* Ajout_proposition_regle(Regle* regle,char* proposition)
{
    if (Appartenance_premisse(regle,proposition) == false)
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
    else
    {
        return regle;
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
        regle->conclusion = proposition;
        return regle;
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
            newel_r=Ajout_proposition_regle(newel_r,temp->premisse);
            temp=temp->next;
        }
        return newel_r;

    }
}

//------------------------------------------//

void afficher_Liste_Regle(Regle* regle) {
    Regle* courant = regle;
    while (courant != NULL) {
        printf("%s -> ", courant->premisse);
        courant = courant->next;
    }
    printf("|| %s || \n",regle->conclusion);
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
    if (Appartenance_premisse(regle,proposition))
    {
        Regle* newel_r = creer_Regle_Vide();
        if (regle->next==NULL)
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
                    newel_r= Ajout_proposition_regle(newel_r,temp->premisse);
                }
                temp=temp->next;
            }
            return newel_r;
        }
    }
    else
    {
        return regle;
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