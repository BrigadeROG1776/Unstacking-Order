#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

/** \brief
 *  Ce programme a �t� r�alis� dans le but
 *  de v�rifier un ordre pr�cis (Du haut vers le bas)
 *  de d�pilement des �l�ments d'une pile..
 *
 *  Les fonctions utilis�s dans le main permettent :
 *  --> D'empiler une chaine de caract�re dans une pile.
 *
 *  --> D'empiler une deuxieme chaine de caract�re dans
 *      Une autre pile qui sert de comparaison par rapport
 *      a la pile 1 pendant le d�pilement.
 *
 *  --> D'afficher la pile 1 et le resultat de la comparaison
 *      Entre les deux piles, si la pile 2 correspond au m�me
 *      ordre de d�pilement de la pile 1(affiche oui) ou non.
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
