#ifndef _GEOMETRIE2D_H_
#define _GEOMETRIE2D_H_

typedef struct Vecteur_ {
    double x,y;
}Vecteur;

typedef struct Point_ {
    double x,y;
}Point;


// operation sur les points 

Point set_point(double x, double y);

Point add_point(Point P1, Point P2);

Point mult_point(Point A, double a);

double distance(Point A, Point B);

// operations sur les vecteurs 
 
Vecteur vect_bipoint(Point A, Point B);

Vecteur add_vecteur(Vecteur V1, Vecteur V2);

Vecteur mult_vect(Vecteur V, double a);

double scalaire( Vecteur V1 , Vecteur V2 );

double norme( Vecteur V);



#endif