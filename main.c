
#include "regles.h"

int main()
{

    Regle* regle_N1=creer_Regle_Vide();
    regle_N1= Ajout_propostion_regle(regle_N1,"GCF");
    printf("la cececee evren");

    
    printf("%s",regle_N1->conclusion);

    return 0;
}
