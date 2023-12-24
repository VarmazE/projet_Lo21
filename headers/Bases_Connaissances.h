
#ifndef PROJET_LO21_BASES_CONNAISSANCES_H
#define PROJET_LO21_BASES_CONNAISSANCES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../headers/regles.h"

#endif //PROJET_LO21_BASES_CONNAISSANCES_H

/*
 * Définition d'une Base de connaissances:
*/

typedef struct BC
{
    Regle* regle;
    struct BC* next;
}Elem_BC;

//------------------------------------------//

/**
 * Crée un nouvel élément de base de connaissances avec une règle vide.
 *
 * @return Un pointeur vers un nouvel élément de base de connaissances avec une règle vide.
 */
Elem_BC* creer_Base_Connaissances();

//------------------------------------------//

/**
 * Ajoute une règle à la fin de la liste de la base de connaissances.
 *
 * @param liste La liste de la base de connaissances.
 * @param regle La règle à ajouter.
 * @return Un pointeur vers la liste mise à jour.
 */
Elem_BC* Ajout_en_queue_BC(Elem_BC* liste, Regle* regle);

//------------------------------------------//

/**
 * Retourne la première règle de la base de connaissances.
 *
 * @param liste La liste de la base de connaissances.
 * @return Un pointeur vers la première règle de la base de connaissances.
 */
Regle* tete_BC(Elem_BC* liste);


