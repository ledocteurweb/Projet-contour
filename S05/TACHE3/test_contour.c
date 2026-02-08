#include <stdio.h>
#include "contour.h"
#include "sequence.h"

int main(int argc, char *argv[]){
    Image I;
    Contour L;
    L=creer_liste_Point_vide();

    I=lire_fichier_image(argv[1]);

    calcul_contour(I,&L);

    return 0;
}