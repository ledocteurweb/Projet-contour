#include "geometrie2d.h"
#include <stdio.h>
int main()
{

    // creons 2 points A et B
    Point A, B, C, D;
    A=set_point(4,5);
    B=set_point(2,3);

    // point C=A+B
    C=add_point(A,B);
    
    // point D = 3*C
    D=mult_point(C,3);

    // distance entre A et B puis entre C et D
    printf("la distance entre le point A et le point B est de %f et celle entre le point C et le point D est de %f \n",distance(A,B),distance(C,D));
    
    // creation des vecteurs AB et CD 
    Vecteur V, V1, AB ,CD;
    AB=vect_bipoint(A,B);

    CD=vect_bipoint(C,D);

    // addiction de vecteur 
    V=add_vecteur(AB,CD);

    // creation du vecteur V1=2*V
    V1=mult_vect(V,2);

    // produit scalaire 
    printf("le produit scalaire entre AB et CD est de %f\n", scalaire(AB ,CD));

    // norme

    printf("La norme du vecteur AB est de %f \n", norme(V1));

    return 0;
}