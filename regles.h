#ifndef PROJET_LO21_REGLES_H
#define PROJET_LO21_REGLES_H

#endif //PROJET_LO21_REGLES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/*
 * Définition d'une Règle:
*/

typedef struct Regle
{
    char* premisse;  //sachant que la dernière element rêgle contient la conclusion
    char* conclusion;
    struct Regle* next; // Pointeur vers la règle suivante dans la liste
}Regle;

typedef Regle* liste_BC; //liste_Base_de_Connaissancesdevient un pointeur vers un element

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
bool Appartence_premisse(char* Premisse,char proposition);

//------------------------------------------//

/**
 * Supprime la première occurrence d'une proposition dans la prémisse.
 *
 * @param Premisse La prémisse à modifier.
 * @param proposition La proposition à supprimer de la prémisse.
 * @return Une nouvelle prémisse avec la première occurrence de la proposition supprimée.
 */
char* Supprimer_Premisse(char* Premisse, char proposition);

//------------------------------------------//

/**
 * Vérifie si la prémisse est vide.
 *
 * @param Premisse La prémisse à vérifier.
 * @return true si la prémisse est vide, sinon false.
 */
bool vide_Premisse(char* Premisse);

//------------------------------------------//

char* tete_Premisse(const char* Premisse);



//------------------------------------------//
//--------------Utilitaire---------------------//

/**
 * Retourne une nouvelle chaîne sans son dernier caractère.
 *
 * @param chaine La chaîne d'origine.
 * @return Une nouvelle chaîne sans le dernier caractère de la chaîne d'origine.
 */
char* Reste(char* chaine);

//------------------------------------------//

/**
 * Concatène deux chaînes de caractères.
 *
 * @param chaine1 La première chaîne.
 * @param chaine2 La deuxième chaîne.
 * @return Une nouvelle chaîne résultante de la concaténation de chaine1 et chaine2.
 */
char* concatener(const char* chaine1, const char* chaine2);
