

#include "../headers/Base_faits.h"
int main()
{

    //----------Paramétrage des regle-------------//

    Regle* regle_N1=creer_Regle_Vide();
    regle_N1= Ajout_propostion_regle(regle_N1,"AB");
    regle_N1->conclusion="C";
    Regle* regle_N2=creer_Regle_Vide();
    regle_N2= Ajout_propostion_regle(regle_N2,"C");
    regle_N2->conclusion="D";

    Regle* regle_N3 = creer_Regle_Vide();
    regle_N3= Ajout_propostion_regle(regle_N3,"E");
    regle_N3->conclusion="F";

    //-----------------Fin------------------------//


    //--Paramétrage de la Base de Connaissances--//

    Elem_BC* liste_BC=creer_Base_Connaissances();
    liste_BC= Ajout_en_queue_BC(liste_BC,regle_N1);
    liste_BC= Ajout_en_queue_BC(liste_BC,regle_N2);
    liste_BC= Ajout_en_queue_BC(liste_BC,regle_N3);

    //-----------------Fin------------------------//


    //-------Paramétrage de la Base de Fait-------//

    Elem_BF* liste_BF = Creer_BF_Vide();
    liste_BF = Ajout_en_queue_BF(liste_BF, "A");
    liste_BF = Ajout_en_queue_BF(liste_BF, "B");
    liste_BF = Ajout_en_queue_BF(liste_BF, "C");
    printf("%s",liste_BF->next->next->proposition);
    //-----------------Fin------------------------//


    return 0;
}
