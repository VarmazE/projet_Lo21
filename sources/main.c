
#include "../headers/Bases_Connaissances.h"
int main()
{

    //----------Parametrage des regle-------------//

    Regle* regle_N1=creer_Regle_Vide();
    regle_N1= Ajout_propostion_regle(regle_N1,"AB");
    regle_N1->conclusion="C";
    Regle* regle_N2=creer_Regle_Vide();
    regle_N2= Ajout_propostion_regle(regle_N2,"C");
    regle_N2->conclusion="D";

    //-----------------Fin------------------------//


    //--Parametrage de la Base de Connaissances--//

    Elem_BC* liste_BC=creer_Base_Connaissances();
    liste_BC= Ajout_en_queue_BC(liste_BC,regle_N1);
    liste_BC= Ajout_en_queue_BC(liste_BC,regle_N2);
    printf("%s",liste_BC->next->regle->premisse);

    //-----------------Fin------------------------//

    return 0;
}
