

#include "../headers/Moteur_inference.h"
int main()
{

    //----------Paramétrage des regle-------------//

    Regle* regle_N1=creer_Regle_Vide();
    regle_N1 = Ajout_propostion_regle(regle_N1,"A");
    regle_N1=Ajout_propostion_regle(regle_N1,"B");
    regle_N1= Creer_Conclusion_Regle(regle_N1,"C");
    afficherListe(regle_N1);

    Regle* regle_N2 = creer_Regle_Vide();
    regle_N2 = Ajout_propostion_regle(regle_N2,"C");
    regle_N2 = Ajout_propostion_regle(regle_N2,"E");
    regle_N2 = Creer_Conclusion_Regle(regle_N2,"D");
    afficherListe(regle_N2);

    Regle* regle_N3 = creer_Regle_Vide();
    regle_N3 = Ajout_propostion_regle(regle_N3,"D");
    regle_N3 = Ajout_propostion_regle(regle_N3,"F");
    regle_N3= Creer_Conclusion_Regle(regle_N3,"G");
    afficherListe(regle_N3);



    //-----------------Fin------------------------//


    //----------Paramétrage de la base de connaissances-------------//

    Elem_BC* liste_BC=creer_Base_Connaissances();
    liste_BC= Ajout_en_queue_BC(liste_BC,regle_N1);
    liste_BC= Ajout_en_queue_BC(liste_BC,regle_N2);
    liste_BC= Ajout_en_queue_BC(liste_BC,regle_N3);


    //-----------------Fin------------------------//

    //----------Paramétrage de la base de fait -------------//

    Elem_BF* liste_BF=Creer_BF_Vide();
    liste_BF= Ajout_en_queue_BF(liste_BF,"A");
    liste_BF= Ajout_en_queue_BF(liste_BF,"B");
    liste_BF= Ajout_en_queue_BF(liste_BF,"F");
    liste_BF= Ajout_en_queue_BF(liste_BF,"D");
    //-----------------Fin------------------------//

    printf("Base de faits avant : ");
    afficherListe_BF(liste_BF);
    liste_BF = Moteur_inference(liste_BF,liste_BC);
    printf("Base de faits apres : ");
    afficherListe_BF(liste_BF);
    return 0;
}
