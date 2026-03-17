#include "geometrie2d.h"
#include<stdio.h>
#include <math.h>

// operation sur les points 

Point set_point(double x, double y){
    Point P={x,y};
    return P;
}

Point add_point(Point P1, Point P2){
    return set_point(P1.x+P2.x, P1.y+P2.y);
}

Point mult_point(Point A, double a){
    return set_point(A.x*a,A.y*a);
}

double distance(Point A, Point B){
    return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
}

// operations sur les vecteurs 
 
Vecteur vect_bipoint(Point A, Point B){
    Vecteur V ={B.x-A.x, B.y-A.y};
    return V;
}
Vecteur add_vecteur(Vecteur V1, Vecteur V2){
    Vecteur V ={V1.x+V2.x, V1.y+V2.y};
    return V;
}

Vecteur mult_vect(Vecteur V, double a){
    Vecteur V1 ={V.x*a, V.y*a};
    return V1;
}

double scalaire( Vecteur V1 , Vecteur V2 ){
    return V1.x*V2.x + V1.y*V2.y;
}

double norme( Vecteur V){
    return sqrt(V.x*V.x + V.y*V.y);
}

double distance_point_segent(Point P, Point A, Point B){
    Vecteur vectab=vect_bipoint(A,B);
    if (scalaire(vectab,vectab)==0)
        return distance(A,P);
    else
    {
        double lambda;
        Vecteur vectap=vect_bipoint(A,P);
        lambda=scalaire(vectap,vectab)/scalaire(vectab,vectab);
        if (lambda < 0)
            return distance(A,P);
        else if (lambda>1)
            return distance(B,P);
        else
        {
            Point Q;
            Q=add_point(A,mult_point(add_point(B,mult_point(A,-1)),lambda));
            return distance(P,Q);
        }
    }  
}