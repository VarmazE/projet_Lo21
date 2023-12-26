//
// Created by varma on 24/12/2023.
//

#include "../headers/Moteur_inference.h"

Elem_BF* Moteur_inference_I(Elem_BF* liste_BF, Elem_BC* liste_BC)
{
    Elem_BC* actuel_BC = liste_BC;

    while (actuel_BC != NULL)
    {
        int longueur_regle = longueur_Premisse(actuel_BC->regle);
        int compteur = 0;

        Elem_BF* actuel_BF = liste_BF;

        while (actuel_BF != NULL)
        {
            if (Appartenance_premisse(actuel_BC->regle, actuel_BF->proposition))
            {
                compteur++;
            }
            actuel_BF = actuel_BF->next;
        }

        if (compteur == longueur_regle)
        {
            liste_BF = Ajout_en_queue_BF(liste_BF, actuel_BC->regle->conclusion);
        }

        // Réinitialiser le compteur avant la prochaine itération
        compteur = 0;

        actuel_BC = actuel_BC->next;
    }

    return liste_BF;
}

//------------------------------------------//


Elem_BF* Moteur_inference_P(Elem_BF* liste_BF,Elem_BC* liste_BC)
{
    bool comparaison = false;
    while (comparaison == false)
    {
        Elem_BF* temp = copierListe_BF(liste_BF);
        liste_BF = Moteur_inference_I(liste_BF,liste_BC);
        comparaison = Comparaison_BF(temp,liste_BF);
    }
    return liste_BF;
}

//------------------------------------------//
