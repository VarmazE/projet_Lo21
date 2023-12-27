//
// Created by evrim on 26/12/2023.
//

#ifndef PROJET_LO21_MENU_H
#define PROJET_LO21_MENU_H


#include "../headers/Moteur_inference.h"

#endif //PROJET_LO21_MENU_H



/**
 * Affiche un séparateur visuel dans la console.
 */
void afficherSeparateur();

//------------------------------------------//

/**
 * Affiche un menu interactif pour interagir avec le moteur d'inférence.
 *
 * @param liste_BF La liste des faits de la base de faits.
 * @param liste_BC La liste des règles de la base de connaissances.
 */
void Menu(Elem_BF* liste_BF, Elem_BC* liste_BC);

//------------------------------------------//

/**
 * Crée manuellement une nouvelle règle en demandant à l'utilisateur de spécifier la premisse et la conclusion.
 *
 * @return Un pointeur vers la nouvelle règle créée.
 */
Regle* creerRegleManuellement();

//------------------------------------------//

/**
 * Demande à l'utilisateur de saisir les propositions et la conclusion pour une nouvelle règle.
 *
 * @param tableau Un tableau de chaînes pour stocker les propositions et la conclusion.
 * @param taille La taille totale du tableau.
 */
void remplirTableau_R(char *tableau[], int taille);

//------------------------------------------//

/**
 * Demande à l'utilisateur de saisir les propositions pour une nouvelle base de faits.
 *
 * @param tableau Un tableau de chaînes pour stocker les propositions.
 * @param taille La taille totale du tableau.
 */
void remplirTableau_BF(char *tableau[], int taille);

//------------------------------------------//

/**
 * Crée manuellement une nouvelle base de connaissances en demandant à l'utilisateur de spécifier des règles.
 *
 * @return Un pointeur vers la nouvelle base de connaissances créée.
 */
Elem_BC* creerBCManuellement();

//------------------------------------------//

/**
 * Crée manuellement une nouvelle liste de faits en demandant à l'utilisateur de spécifier les propositions.
 *
 * @return Un pointeur vers la nouvelle liste de faits créée.
 */
Elem_BF* creerBFManuellement();

//------------------------------------------//

/**
 * Affiche un menu interactif pour permettre à l'utilisateur de choisir des options.
 */
void afficherMenu();
