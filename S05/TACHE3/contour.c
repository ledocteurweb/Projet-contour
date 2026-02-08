#include "contour.h"
#include "sequence.h"

Point trouver_pixel_depart(Image I){
    Point P;
    UINT hauteur, largeur;
    hauteur = hauteur_image(I);
    largeur = largeur_image(I);

    for (UINT y = 1 ; y <= largeur; y++)
    {
        for (UINT x = 1; x <= hauteur; x++)
        {
            if (get_pixel_image(I,x,y)==1 && get_pixel_image(I,x,y-1)==0)
            {
                P=set_point(x,y); 
                return P;           
            }
            
        }
    }
}


void memoriser_position(Point P, Liste_Point *L){
    *L=ajouter_element_liste_Point(*L,P);
}


void avancer(Point *P, Orientation o){
    switch (o)
    {
    case Est:
        P->x=P->x+1;
        break;
    case Ouest:
        P->x=P->x-1;
        break;
    case Nord:
        P->y=P->y-1;
        break;
    case Sud:
        P->y=P->y+1;
        break;
    }
}

Pixel valeur_pixel_gauche(Image I, Point P, Orientation o){
    switch (o)
    {
    case Nord:
        return get_pixel_image(I, P.x,P.y);
        break;
    case Sud:
        return get_pixel_image(I, P.x+1,P.y+1);
        break;
    case Est:
        return get_pixel_image(I, P.x+1,P.y);
        break;
    case Ouest:
        return get_pixel_image(I, P.x,P.y+1);
        break;
    default:
        break;
    }
}

Pixel valeur_pixel_droite(Image I, Point P, Orientation o){
    switch (o)
    {
    case Nord:
        return get_pixel_image(I, P.x+1,P.y);
    case Sud:
        return get_pixel_image(I, P.x,P.y+1);
    case Est:
        return get_pixel_image(I, P.x+1,P.y+1);
    case Ouest:
        return get_pixel_image(I, P.x,P.y);
    }
}

void tourner_90_degres(Orientation *o){
    switch (*o)
    {
    case Nord:
        *o=Ouest;
        break;
    case Sud:
        *o=Est;
        break;
    case Est:
        *o=Nord;
        break;
    case Ouest:
        *o=Sud;
        break;
    }
}

void tourner_270_degre(Orientation *o){
    switch (*o)
    {
    case Nord:
        *o=Est;
        break;
    case Sud:
        *o=Ouest;
        break;
    case Est:
        *o=Sud;
        break;
    case Ouest:
        *o=Nord;
        break;
    }
}

void nouvelle_orientation(Image I, Point P, Orientation *o){
    Pixel PD,PG;
    PD=valeur_pixel_droite(I,P,*o);
    PG=valeur_pixel_gauche(I,P,*o);
    if (PG==1)
    {
        tourner_90_degres(o);
    }
    else if (PD==0)
    {
        tourner_270_degre(o);
    }
}

void calcul_contour(Image I,Liste_Point *L){
    Point depart,pos;
    Orientation o;
    double x0,y0;
    int boucle = 0;
    depart=trouver_pixel_depart(I);
    x0=depart.x-1;
    y0=depart.y-1;
    pos=set_point(depart.x-1,depart.y-1);
    o=Est;
    while(boucle==0){
        memoriser_position(pos,L);
        avancer(&pos,o);
        nouvelle_orientation(I,pos,&o);
        if ((pos.x==x0 && pos.y==y0) && o==Est )
        {
            boucle=1;
        }
    }
    memoriser_position(pos,L);
    printf("notre contour compte %d segments\n", (L->taille-1) );
}