

#ifndef PROJET_LO21_BASE_FAITS_H
#define PROJET_LO21_BASE_FAITS_H

#include "../headers/Bases_Connaissances.h"

#endif //PROJET_LO21_BASE_FAITS_H


typedef struct Base_faits
{
    char* proposition;  //sachant que la dernière element rêgle contient la conclusion
    struct Base_faits *next;
}Elem_BF;


/**
 * Crée un nouvel élément de base de faits avec une proposition vide.
 *
 * @return Un pointeur vers un nouvel élément de base de faits avec une proposition vide.
 */
Elem_BF* Creer_BF_Vide();

//------------------------------------------//

/**
 * Ajoute une proposition à la fin de la liste des faits de la base de faits.
 *
 * @param liste La liste des faits de la base de faits.
 * @param proposition La proposition à ajouter.
 * @return Un pointeur vers la liste des faits mise à jour.
 */
Elem_BF* Ajout_en_queue_BF(Elem_BF* liste, char* proposition);

//------------------------------------------//

/**
 * Affiche les propositions de la liste des faits de la base de faits.
 *
 * @param liste_BF La liste des faits de la base de faits.
 */
void afficherListe_BF(Elem_BF* liste_BF);

//------------------------------------------//

/**
 * Compare deux listes de faits pour déterminer si elles sont équivalentes.
 *
 * @param liste_BF1 La première liste des faits.
 * @param liste_BF2 La deuxième liste des faits.
 * @return true si les deux listes sont équivalentes, sinon false.
 */
bool Comparaison_BF(Elem_BF* liste_BF1, Elem_BF* liste_BF2);

//------------------------------------------//

/**
 * Retourne la longueur d'une liste de faits.
 *
 * @param liste_BF La liste des faits.
 * @return La longueur de la liste des faits.
 */
int longueur_BF(Elem_BF* liste_BF);

//------------------------------------------//

/**
 * Retourne le reste d'une liste de faits, excluant le dernier élément.
 *
 * @param listeBF La liste de faits d'origine.
 * @return Une nouvelle liste de faits représentant le reste de la liste d'origine sans le dernier élément.
 */
Elem_BF* Reste_BF(Elem_BF* listeBF);

//------------------------------------------//

/**
 * Vérifie si une proposition appartient à une liste de faits.
 *
 * @param listeBF La liste de faits à vérifier.
 * @param proposition La proposition à rechercher.
 * @return true si la proposition appartient à la liste de faits, sinon false.
 */
bool Appartenance_BF(Elem_BF* listeBF, char* proposition);

//------------------------------------------//

/**
 * Copie une liste de faits.
 *
 * @param liste La liste de faits à copier.
 * @return Une nouvelle liste de faits identique à la liste d'origine.
 */
Elem_BF* copierListe_BF(Elem_BF* liste);