

#include "../headers/Base_faits.h"
int main()
{

    //----------Paramétrage des regle-------------//

    Regle* regle_N1=creer_Regle_Vide();

    regle_N1 = Ajout_propostion_regle(regle_N1,"A");
    regle_N1 = Ajout_propostion_regle(regle_N1,"B");
    regle_N1 = Ajout_propostion_regle(regle_N1,"C");
    regle_N1 = Ajout_propostion_regle(regle_N1,"D");
    regle_N1 = Ajout_propostion_regle(regle_N1,"F");
    if (Appartenance_premisse(regle_N1,"F"))
    {
        printf("evrim il est trop beau");
    }
















    //-----------------Fin------------------------//


    return 0;
}
