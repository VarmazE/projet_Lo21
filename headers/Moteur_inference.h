//
// Created by varma on 24/12/2023.
//

#ifndef PROJET_LO21_MOTEUR_INFERENCE_H
#define PROJET_LO21_MOTEUR_INFERENCE_H
#include "../headers/Base_faits.h"
#endif //PROJET_LO21_MOTEUR_INFERENCE_H

/**
 * Applique le moteur d'inférence itératif sur la base de faits en fonction de la base de connaissances.
 *
 * @param liste_BF La liste des faits de la base de faits.
 * @param liste_BC La liste des règles de la base de connaissances.
 * @return La liste des faits mise à jour après l'application du moteur d'inférence itératif.
 */
Elem_BF* Moteur_inference_I(Elem_BF* liste_BF, Elem_BC* liste_BC);

//------------------------------------------//

/**
 * Applique le moteur d'inférence persistant sur la base de faits en fonction de la base de connaissances.
 *
 * @param liste_BF La liste des faits de la base de faits.
 * @param liste_BC La liste des règles de la base de connaissances.
 * @return La liste des faits mise à jour après l'application du moteur d'inférence persistant.
 */
Elem_BF* Moteur_inference_P(Elem_BF* liste_BF, Elem_BC* liste_BC);
