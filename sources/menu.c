//
// Created by evrim on 26/12/2023.
//

#include "../headers/menu.h"



void remplirTableau_R(char *tableau[], int taille)
{

    printf("\n=======================================\n");
    printf("Saisie des propositions\n");
    printf("Et de la conclusion (%d nombres elements au total)\n", taille);
    printf("=======================================\n");

    for (int i = 0; i < taille; ++i) {
        if (i < taille - 1) {
            printf("Proposition %d : ", i + 1);
        } else {
            printf("Conclusion : ");
        }

        // Allocation de mémoire pour chaque chaîne
        tableau[i] = malloc(50 * sizeof(char));

        // Lecture de l'entrée utilisateur
        scanf("%s", tableau[i]);
    }


}

//------------------------------------------//

void remplirTableau_BF(char *tableau[], int taille)
{

    printf("\n=======================================\n");
    printf("Saisie des propositions (Base de faits)\n");
    printf("(%d nombres elements au total)\n", taille);
    printf("=======================================\n");

    for (int i = 0; i < taille; ++i)
    {
        printf("Proposition %d : ", i + 1);
        // Allocation de mémoire pour chaque chaîne
        tableau[i] = malloc(50 * sizeof(char));
        // Lecture de l'entrée utilisateur
        scanf("%s", tableau[i]);
    }
}

//------------------------------------------//

Regle* creerRegleManuellement()
{
    Regle* nouvelleRegle = creer_Regle_Vide();
    int taille = 0;

    printf("\n=======================================\n");
    printf("  Creation d'une nouvelle regle\n");
    printf("=======================================\n");

    printf("Nombre d'elements dans la premisse et la conclusion : ");
    scanf("%d", &taille);

    char *tableau[taille];

    // Appel de la fonction pour remplir le tableau
    remplirTableau_R(tableau, taille);

    for (int i = 0; i < taille - 1; ++i) {
        nouvelleRegle = Ajout_proposition_regle(nouvelleRegle, tableau[i]);
    }

    nouvelleRegle = Creer_Conclusion_Regle(nouvelleRegle, tableau[taille - 1]);

    printf("\n=======================================\n");
    printf("  Nouvelle regle creee avec succes!\n");
    printf("=======================================\n");

    return nouvelleRegle;
}

//------------------------------------------//

Elem_BC* creerBCManuellement()
{
    Elem_BC* nouv_BF = creer_Base_Connaissances();
    int compteur;

    printf("Entrer le nombre de regles que vous voulez : ");
    scanf("%d", &compteur);

    for (int i = 0; i < compteur; ++i)
    {
        Regle* nouvelleRegle = creerRegleManuellement();
        nouv_BF = Ajout_en_queue_BC(nouv_BF, nouvelleRegle);
    }

    return nouv_BF; // Ajout de la valeur de retour
}

//------------------------------------------//

Elem_BF* creerBFManuellement()

{
    Elem_BF* nouvelleListeBF = Creer_BF_Vide();

    int taille = 0;

    printf("\n=======================================\n");
    printf("  Creation d'une nouvelle liste de faits\n");
    printf("=======================================\n");

    printf("Nombre d'elements dans la liste de faits : ");
    scanf("%d", &taille);

    char *tableau[taille];

    // Appel de la fonction pour remplir le tableau
    remplirTableau_BF(tableau, taille);

    for (int i = 0; i < taille; ++i) {
        nouvelleListeBF = Ajout_en_queue_BF(nouvelleListeBF, tableau[i]);
    }

    printf("\n=======================================\n");
    printf("  Nouvelle liste de faits creee avec succes!\n");
    printf("=======================================\n");

    return nouvelleListeBF;
}

//------------------------------------------//

void afficherMenu()
{

    printf("\n================= MENU =================\n");
    printf("1. Creer une nouvelle Base de connaissance\n");
    printf("2. Creer une nouvelle liste de faits manuellement\n");
    printf("3. Acceder au moteur d'inference\n");
    printf("=======================================\n");
    printf("Choisissez une option (1-3) : ");
}

//------------------------------------------//

void afficherSeparateur()
{
    printf("========================================\n");
}

//------------------------------------------//

void Menu(Elem_BF* liste_BF,Elem_BC* liste_BC)
{
    printf("\n");
    printf("\n");
    int choix_menu;

    do
    {
        // Affichage du menu
        afficherSeparateur();
        printf("          Moteur inference\n");
        afficherSeparateur();
        printf("1. Afficher la base de faits\n");
        printf("2. Afficher la base de connaissance\n");
        printf("3. Executer le moteur d'inference\n");
        printf("0. Quitter\n");
        afficherSeparateur();
        printf("Choix : ");
        scanf("%d", &choix_menu);

        // Traitement des options du menu
        switch (choix_menu)
        {
            case 1:
                printf("\nBase de faits : ");
                afficherListe_BF(liste_BF);
                break;

            case 2:
                printf("\nBase de connaissance : ");
                afficherListe_BC(liste_BC);
                break;

            case 3:
                printf("\nBase de faits avant : ");
                afficherListe_BF(liste_BF);
                liste_BF = Moteur_inference_P(liste_BF, liste_BC);
                printf("Base de faits apres : ");
                afficherListe_BF(liste_BF);
                break;

            case 0:
                printf("\nAu revoir !\n");
                break;

            default:
                printf("\nChoix invalide. Veuillez entrer un nombre valide.\n");
        }

    } while (choix_menu != 0);
    printf("\n");
    printf("\n");
}

