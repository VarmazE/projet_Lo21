

#include "../headers/menu.h"


int main()
{

    Elem_BC* liste_BC=creer_Base_Connaissances();
    Elem_BF* liste_BF=Creer_BF_Vide();

    int choix;

    do {
        afficherMenu();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                // Appel de la fonction pour créer une règle manuellement
                liste_BC=creerBCManuellement();
                break;

            case 2:
                // Appel de la fonction pour créer une liste de faits manuellement
                liste_BF= creerBFManuellement();
                break;

            case 3:
                printf("Au revoir! Fin du programme.\n");
                break;

            default:
                printf("Option invalide. Veuillez choisir une option valide.\n");
        }

    } while (choix != 3);


    Menu(liste_BF,liste_BC);

    return 0;
}
