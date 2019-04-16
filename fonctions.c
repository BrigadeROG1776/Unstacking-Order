#include <stdio.h>
#include <string.h>
#include "fonctions.h"
#define N_MAX 100

Pile init()
{
    Pile p;
    p.sommet=0;
    p.taille_max=N_MAX;
    return p;
}

/*--------------------------------------------*/

void empiler(Pile *pile, char* mot)
{
    if(pile->sommet==pile->taille_max)
    {
        printf("La pile est pleine\n");
        return;
    }

    strcpy(pile[pile->sommet].mot, mot);
    pile->sommet++;

}

/*--------------------------------------------*/

char* depiler(Pile* pile)
{
    if(pile->sommet==0)
    {
        printf("Rien a depiler, La pile est vide\n");
        return 0;
    }

    pile->sommet--;
    return pile[pile->sommet].mot;
}

/*--------------------------------------------*/

void affichage(Pile* pile)
{
    int i;

    if(pile->sommet==0)
    {
        printf("La pile est vide\n");
        return;
    }

    for (i = pile->sommet-1; i >= 0; i--)
    {
        printf("[%s]\n", pile[i].mot);
    }

}
/*--------------------------------------------*/

void vider_pile(Pile* pile)
{
    while(pile->sommet!=0)
        depiler(pile);
}

/*--------------------------------------------*/

void ret_phr(Pile* p)
{
    vider_pile(p);
    char phrase[100];
    printf("Entrez la phrase originale :\n" );
    gets(phrase);

    sauvegarde(p, phrase);
}

/*--------------------------------------------*/

void sauvegarde(Pile* p, char* phrase)
{
    char mot[20];
    int cmp=0, i=0;
    do
    {
        mot[cmp]=phrase[i];

        if(phrase[i]==' ' || phrase[i]=='\0')
        {
            mot[cmp]='\0';
            empiler(p, mot);
            cmp=-1;
        }
        i++;
        cmp++;

    }
    while(i<=strlen(phrase));
}

/*--------------------------------------------*/

void ver_phr(Pile* p)
{
    if(p->sommet==0)
    {
        printf("Pile vide, Entrer la phrase Originale\n");
        return;
    }

    char phrase[100];

    printf("Entrez la phrase a verifier :\n");
    gets(phrase);

    verfier(p,phrase);
}

/*--------------------------------------------*/

void verfier(Pile* p,char* phraseVerif)
{
    int i=0, j=0;
    char mot[20];

    while(phraseVerif[i]!=' ')
    {
        mot[j]=phraseVerif[i];
        i++;
        j++;
    }
    if(phraseVerif[i]==' ')
        mot[i]='\0';

    if(strcmp(mot, p[p->sommet-1].mot)==0)
        verification1(p,phraseVerif);
    else
        verification2(p, phraseVerif);

}

/*--------------------------------------------*/

//Algo de verification d'ordre normal
void verification1(Pile* p, char* phrase)
{
    int i=0,j=0, cmp=p->sommet;
    char mot[20];

    do
    {
        mot[j]=phrase[i];

        if(phrase[i]==' ' || phrase[i]=='\0')
        {
            mot[j]='\0';

            if(strcmp(mot, p[cmp-1].mot)!=0)
            {
                printf("non\n");
                return;
            }

            j=-1;
            cmp--;

        }

        i++;
        j++;

    }
    while(i<=strlen(phrase));

    printf("oui\n");
}

/*--------------------------------------------*/

//Algo de verification cas particulier
void verification2(Pile* p,char* phrase)
{
    Pile phrase_v=init();

    sauvegarde(&phrase_v, phrase);

    comparaison(p, &phrase_v);
}

/*--------------------------------------------*/

void comparaison(Pile* p, Pile* phrase_v)
{
    int i=p->sommet-1, j=0, k,nbr_mots=0;
    int tabS[10];
    short ind=0;

    do
    {

        if(strcmp(p[i].mot,phrase_v[j].mot)!=0)
        {
            tabS[ind]=i;
            ind++;

            if(ind==p->sommet)
            {
                printf("non\n");
                return;
            }
        }
        else
        {

            if(strcmp(p[i].mot,phrase_v[j].mot)==0 && i==0)
            {
                for(k=0; k<ind; k++)
                {
                    i=tabS[k];

                    j++;
                    if(strcmp(p[i].mot, phrase_v[j].mot)!=0 && j!=phrase_v->sommet)
                    {
                        printf("non\n");
                        return;
                    }

                    i--;
                }

                printf("oui\n");
                return;
            }

            j++;
            nbr_mots++;
        }

        i--;
    }
    while(nbr_mots<=p->sommet);

}

/*--------------------------------------------*/

void menuFrench()
{
    printf("///////////MENU/////////////////////\n");
    printf("1-Entrez la phrase originale       /\n");
    printf("2-Entrez la phrase a verifier      /\n");
    printf("3-Afficher la pile                 /\n");
    printf("4-Quitter                          /\n");
    printf("///////////MENU/////////////////////\n");
}
/*--------------------------------------------*/
void menuEnglish()
{
    printf("///////////MENU/////////////////////\n");
    printf("1-Input the original phrase      /\n");
    printf("2-Input the phrase to check      /\n");
    printf("3-Display the stack                /\n");
    printf("4-Quit                           /\n");
    printf("///////////MENU/////////////////////\n");
}
/*--------------------------------------------*/
