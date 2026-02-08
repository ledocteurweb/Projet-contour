#include <stdio.h>
#include "image.h"

int main(int argc, char *argv[])
{
    Image I, I1;
    //lis le fichier image fourni 
    I=lire_fichier_image(argv[1]);
    // ecriture de l'image fourni dans la console 
    ecrire_image(I);
    printf("\n");
    // donne le negatif de l'image fourni
    I1=negatif_image(I);
    //ecris le negatif de l'image fourni dans la console
    ecrire_image(I1);
    return 0;
}