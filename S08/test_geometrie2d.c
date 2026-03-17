#include "geometrie2d.h"
#include <stdio.h>
int main()
{
    // creons 2 points A et B
    Point A, B, P;

    printf("Vous aller entrer les coordonnées de 3 points P, A et B\nNous calculerons la distance entre le point P et le segment [A,B]");
    printf("\n\nVeuillez entrer les coordonnee sous la forme abscisse ordonnée ");
   
    printf("\n\ncoordonnees de P ");
    scanf("%lf %lf",&P.x,&P.y);
    
    printf("\n\ncoordonnees de A ");
    scanf("%lf %lf",&A.x,&A.y);
        
    printf("\n\ncoordonnees de B ");
    scanf("%lf %lf",&B.x,&B.y);

    printf("La distance entre le point P et le segment [A,B] est %lf \n",distance_point_segent(P,A,B));

    return 0;
}