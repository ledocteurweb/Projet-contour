#ifndef CONTOUR_H
#define CONTOUR_H
#include "../../S04/TACHE2/geometrie2d.h"
#include "../../S04/TACHE1/image.h"
#include <stdio.h>
#include "sequence.h"

typedef enum {Nord, Est, Sud, Ouest} Orientation;

// fonction qui recupere les premier pixel noir qui a un pixel blanc au dessus 

Point trouver_pixel_depart(Image I);

void memoriser_position(Point P, Liste_Point *L);

void avancer(Point *P, Orientation o);

Pixel valeur_pixel_gauche(Image I, Point P, Orientation o);

Pixel valeur_pixel_droite(Image I, Point P, Orientation o);

void tourner_90_degres(Orientation *o);

void tourner_270_degre(Orientation *o);

void nouvelle_orientation(Image I,Point P, Orientation *o);

void calcul_contour(Image I, Liste_Point *L);

void ecrire_stroke_eps(Image I,Liste_Point L);

void ecrire_fill_eps(Image I,Liste_Point L);

#endif