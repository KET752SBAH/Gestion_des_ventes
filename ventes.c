#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ventes.h"
#include "menu.h"
#include "utilisateur.h"

void f_Ventes()
{
    int choix;
    do
    {me:
    system("cls");system("color b");
    puts("\n\t\t************************__MENU GESTION DES VENTES__*********************");
    puts("\t\t*\t1- AJOUTER UNE VENTE                                           *");
    puts("\t\t*\t2- MODIFIER UNE VENTE                                          *");
    puts("\t\t*\t3- SUPPRIMER UNE VENTE                                         *");
    puts("\t\t*\t4- AFFICHER LA LISTE DES VENTES PAR ORDRE ALPHABETIQUE         *");
    puts("\t\t*\t5- CALCUL ET AFFICHAGE DES BENEFICE DE CHAQUE ARTICLE          *");
    puts("\t\t*\t6- CALCUL ET AFFICHAGE LE BENEFICE TOTAL DES ARTICLES          *");
    puts("\t\t*\t0- Precedent !!!                                               *");
    puts("\t\t************************************************************************");
    printf("\t\tVOTRE CHOIX ---> ");scanf("%d",&choix);

    switch(choix)
    {
    case 0:{system("cls");system("color 1");return menu();system("color 3");}
    case 1:{system("cls");system("color 3"); ajoutV()     ;system("pause");system("cls");goto me;system("color 4");break;}
    case 2:{system("cls");system("color 4"); modifierV()  ;system("pause");system("cls");goto me;system("color 5");break;}
    case 3:{system("cls");system("color 5"); supprimerV() ;system("pause");system("cls");goto me;system("color 6");break;}
    case 4:{system("cls");system("color 6"); affV_alpha();       system("pause");system("cls");goto me;system("color 7");break;}
    case 5:{system("cls");system("color 7"); calAffBenefice();   system("pause");system("cls");goto me;system("color 8");break;}
    case 6:{system("cls");system("color A"); calAffBeneficeT();  system("pause");system("cls");goto me;system("color B");break;}
    default:{goto me ;break;}
    }
    }while(choix<0 || choix >7);
    system("pause");
}
