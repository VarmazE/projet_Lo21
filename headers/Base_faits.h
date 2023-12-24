

#ifndef PROJET_LO21_BASE_FAITS_H
#define PROJET_LO21_BASE_FAITS_H

#include "../headers/Bases_Connaissances.h"

#endif //PROJET_LO21_BASE_FAITS_H


typedef struct Base_faits
{
    char* proposition;  //sachant que la dernière element rêgle contient la conclusion
    struct Base_faits *next;
}Elem_BF;

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
 * Crée un nouvel élément de base de faits avec une proposition vide.
 *
 * @return Un pointeur vers un nouvel élément de base de faits avec une proposition vide.
 */
Elem_BF* Creer_BF_Vide();







