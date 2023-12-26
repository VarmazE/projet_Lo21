#ifndef PROJET_LO21_REGLES_H
#define PROJET_LO21_REGLES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#endif //PROJET_LO21_REGLES_H


/*
 * Définition d'une Règle:
*/

typedef struct Regle
{
    char* premisse;  //sachant que la dernière element rêgle contient la conclusion
    char* conclusion;
    struct Regle* next; // Pointeur vers la règle suivante dans la liste
}Regle;



/**
 * Crée une nouvelle règle vide.
 *
 * @return Un pointeur vers une nouvelle règle avec prémisse et conclusion initialisées à des chaînes vides.
 */
Regle* creer_Regle_Vide();

//------------------------------------------//

/**
 * Ajoute une proposition à la prémisse d'une règle.
 *
 * @param regle La règle à laquelle ajouter la proposition.
 * @param proposition La proposition à ajouter à la prémisse.
 * @return Un pointeur vers une nouvelle règle avec la prémisse mise à jour.
 */
Regle* Ajout_propostion_regle(Regle* regle,char* proposition);

//------------------------------------------//

/**
 * Crée une nouvelle règle avec une conclusion spécifiée.
 *
 * @param regle La règle à laquelle ajouter la conclusion.
 * @param proposition La proposition à ajouter comme conclusion.
 * @return Un pointeur vers une nouvelle règle avec la conclusion spécifiée, ou la règle d'origine si aucune prémisse n'est détectée.
 */
Regle* Creer_Conclusion_Regle(Regle* regle,char* proposition);

//------------------------------------------//

/**
 * Vérifie l'appartenance d'une proposition à la prémisse.
 *
 * @param Premisse La prémisse à vérifier.
 * @param proposition La proposition à rechercher dans la prémisse.
 * @return true si la proposition appartient à la prémisse, sinon false.
 */
bool Appartenance_premisse(Regle* regle, char* proposition);

//------------------------------------------//

/**
 * Vérifie si la prémisse est vide.
 *
 * @param Premisse La prémisse à vérifier.
 * @return true si la prémisse est vide, sinon false.
 */
bool vide_Premisse(char* Premisse);

//------------------------------------------//

/**
 * Retourne la première prémisse d'une règle.
 *
 * @param regle La règle d'origine.
 * @return Une nouvelle chaîne contenant la première prémisse de la règle.
 */
char* tete_Premisse(Regle* regle);

//------------------------------------------//

/**
 * Retourne le reste d'une règle, excluant la dernière prémisse.
 *
 * @param regle La règle d'origine.
 * @return Une nouvelle règle représentant le reste de la règle d'origine sans la dernière prémisse.
 */
Regle* Reste(Regle* regle);

//------------------------------------------//

/**
 * Affiche les prémisse successives d'une règle.
 *
 * @param regle La règle à afficher.
 */
void afficher_Liste_Regle(Regle* regle);

//------------------------------------------//

/**
 * Vérifie si une règle est vide.
 *
 * @param regle La règle à vérifier.
 * @return true si la règle est vide, sinon false.
 */
bool Regle_Vide(Regle* regle);

//------------------------------------------//

/**
 * Supprime une proposition de la prémisse d'une règle.
 *
 * @param regle La règle d'origine.
 * @param proposition La proposition à supprimer de la prémisse.
 * @return Une nouvelle règle résultante après la suppression de la proposition.
 */
Regle* Supprmier_proposition(Regle* regle, char* proposition);

//------------------------------------------//

/**
 * Retourne la longueur de la prémisse d'une règle.
 *
 * @param regle La règle d'origine.
 * @return La longueur de la prémisse de la règle.
 */
int longueur_Premisse(Regle* regle);
