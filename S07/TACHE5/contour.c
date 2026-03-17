#include "contour.h"
#include "sequence.h"

Point trouver_pixel_depart(Image I){
    Point P;
    UINT hauteur, largeur;
    hauteur = hauteur_image(I);
    largeur = largeur_image(I);
    
    for (UINT x = 1; x <= hauteur; x++)
    {
        for (UINT y = 1 ; y <= largeur; y++)
        {
            if (get_pixel_image(I,y,x)==1 && get_pixel_image(I,y,x-1)==0)
            {
                P=set_point(y,x); 
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
void trouver_pixel_candidat(Image I, Image M){
    UINT hauteur, largeur;
    hauteur = hauteur_image(I);
    largeur = largeur_image(I);

    for (UINT x = 1; x <= hauteur; x++)
    {
        for (UINT y = 1 ; y <= largeur; y++)
        {
            if (get_pixel_image(I,y,x)==1 && get_pixel_image(I,y,x-1)==0)
            {
                set_pixel_image(M,y,x,1);          
            }
        }
    }
}
// renvoie 1 s'il existe encore des pixel noirs dans l'image 
int est_pixel_noir(Image I){
    UINT hauteur, largeur;
    hauteur = hauteur_image(I);
    largeur = largeur_image(I);

    for (UINT x = 1; x <= hauteur; x++)
    {
        for (UINT y = 1 ; y <= largeur; y++)
        {
            if(get_pixel_image(I,y,x)==1)
                return 1;
        }
    }
    return 0;
}
void calcul_contour_2(Image I,Liste_Point *L){
    Image M;
    int nombre_de_segments, nombre_de_contours, largeur,hauteur ;
    hauteur = hauteur_image(I);
    largeur = largeur_image(I);
    M=creer_image(largeur,hauteur);
    trouver_pixel_candidat(I,M);
    nombre_de_contours=0;
    while (est_pixel_noir(M)==1)
    {
        Point pos, depart;
        Orientation o;
        double x0,y0;
        int boucle = 0;
        depart=trouver_pixel_depart(M);
        x0=depart.x-1;
        y0=depart.y-1;
        pos=set_point(depart.x-1,depart.y-1);
        o=Est;
        while(boucle==0)
        {
            memoriser_position(pos,L);
            avancer(&pos,o);
            nouvelle_orientation(I,pos,&o);
            if (o==Est)
            {
               set_pixel_image(M,pos.x+1,pos.y+1,0);
            }
            if ((pos.x==x0 && pos.y==y0) && o==Est )
            {
                boucle=1;
            }
        }
        memoriser_position(pos,L);   
        nombre_de_contours++;
    }
    nombre_de_segments=L->taille-nombre_de_contours;
    printf("Il y'a %d contours et un total de %d points soit un total de %d segments\n", nombre_de_contours,L->taille,nombre_de_segments);
    supprimer_image(&M);
}


void ecrire_fill_eps(Image I,Liste_Point *L){

    FILE *f = fopen("fill_test.eps", "w");

    if (f == NULL) {
        perror("Erreur de création du fichier");
        exit(1);
    }

    fprintf(f,"%%!PS-Adobe-3.0 EPSF-3.0\n");
    fprintf(f,"%%%%BoundingBox: 0 %d %d 0\n", -hauteur_image(I), largeur_image(I));
    Image M;
    int nombre_de_segments, nombre_de_contours, largeur,hauteur ;
    hauteur = hauteur_image(I);
    largeur = largeur_image(I);
    M=creer_image(largeur,hauteur);
    trouver_pixel_candidat(I,M);
    nombre_de_contours=0;
    while (est_pixel_noir(M)==1)
    {
        Point pos, depart;
        Orientation o;
        double x0,y0;
        int boucle = 0;
        depart=trouver_pixel_depart(M);
        x0=depart.x-1;
        y0=depart.y-1;
        pos=set_point(depart.x-1,depart.y-1);
        int x = pos.x;
        int y = pos.y;
        fprintf(f,"%d %d moveto ",x,-y);
        o=Est;
        while(boucle==0)
        {
            memoriser_position(pos,L);
            int x = pos.x;
            int y = pos.y;
            fprintf(f,"%d %d lineto ", x,-y);
            avancer(&pos,o);
            nouvelle_orientation(I,pos,&o);
            if (o==Est)
            {
               set_pixel_image(M,pos.x+1,pos.y+1,0);
            }
            if ((pos.x==x0 && pos.y==y0) && o==Est )
            {
                boucle=1;
            }
        }
        memoriser_position(pos,L);   
        nombre_de_contours++;
    }
    fprintf(f,"\n");
    fprintf(f,"0 setlinewidth\nfill\n");
    fprintf(f, "showpage\n");
    fclose(f);
    nombre_de_segments=L->taille-nombre_de_contours;
    printf("Il y'a %d contours et un total de %d segments\n", nombre_de_contours,nombre_de_segments);
    supprimer_image(&M);
}