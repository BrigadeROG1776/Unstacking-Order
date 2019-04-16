#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

typedef struct Pile
{
    char mot[20];
    int sommet;
    int taille_max;
} Pile;

Pile init();
void empiler(Pile *pile, char* mot);
char* depiler(Pile* pile);
void affichage(Pile* pile);
void vider_pile(Pile* pile);
void ret_phr(Pile* p);
void ver_phr(Pile* p);
void verfier(Pile* p,char* phraseVerif);
void verification1(Pile* p, char* phrase);
void verification2(Pile* p,char* phrase);
void sauvegarde(Pile* p, char* phrase);
void comparaison(Pile* p, Pile* phrase_v);
void menuFrench();
void menuEnglish();

#endif // FONCTIONS_H_INCLUDED
