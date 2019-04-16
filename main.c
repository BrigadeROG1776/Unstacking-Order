#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

/** \brief
 *  Ce programme a été réalisé dans le but
 *  de vérifier un ordre précis (Du haut vers le bas)
 *  de dépilement des éléments d'une pile..
 *
 *  Les fonctions utilisés dans le main permettent :
 *  --> D'empiler une chaine de caractère dans une pile.
 *
 *  --> D'empiler une deuxieme chaine de caractère dans
 *      Une autre pile qui sert de comparaison par rapport
 *      a la pile 1 pendant le dépilement.
 *
 *  --> D'afficher la pile 1 et le resultat de la comparaison
 *      Entre les deux piles, si la pile 2 correspond au même
 *      ordre de dépilement de la pile 1(affiche oui) ou non.
 *
 *
 * \param
 * \param
 * \return
 *
 */


int main()
{
    Pile p=init();
    int choix;

    do
    {
        menu();
        printf("\tChoix:");
        scanf("%d", &choix);
        fflush(stdin);

        switch(choix)
        {
        case 1:
            ret_phr(&p);
            break;
        case 2:
            ver_phr(&p);
            break;
        case 3:
            affichage(&p);
            break;
        case 4:
            printf("-------------Fin du programme-----------\n");
            break;
        default :
            printf("-------------Touche inconnue-----------\n\n");
            break;
        }
        fflush(stdin);
    }
    while(choix!=4);

    return 0;
}
