#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Administrateur()
{
    char login[10],choix, pwd[10];
    int shut = 0;
    do
    {

        system("cls");system("color a4");
        puts("\n\n\n\n\n\t\t\t\t******************************************");
        puts("\t\t\t\t*       VEUILLEZ VOUS CONNECTER SVP      *");
        puts("\t\t\t\t******************************************\n");
        printf("\t\t\t\tLOGIN ---> ");scanf("%s",login);
        printf("\t\t\t\tMOT_DE_PASS ---> ");scanf("%s",pwd);

        if(strcmp(login,"Admin")!=0 || strcmp(pwd,"admin")!=0)
        {
            system("color 4a");
             printf("\n\n\t\t\tAttention:: Le login ou le Mot de pass est Incorrect \n");
             printf("\t\t\tIls vous reste %d tentative ",3-shut);
            system("pause >nul");
        }

        shut++;
        if(shut == 4)
        {
            system("cls");system("color 4f");
            puts("\n\n\n\t\t\t****************************************");
            printf("\t\t\t*  Veuillez Contacter l'Administrateur *\n");
            printf("\t\t\t*  TEL: +224 622-48-90-83              *\n");
            printf("\t\t\t*  E-mail: souleymanebah752@gmail.com  *\n");
            puts("\t\t\t****************************************");
            system("pause >nul");
            exit(-1);
        }
    }while(strcmp(login,"Admin")!=0 || strcmp(pwd,"admin")!=0);
    system("cls");
    puts("\n\n\t\t****************************************");
    puts("\t\t****** BIENVENUE CHEZ LE PROJET 16 *****");
    puts("\t\t****************************************");

    do
    {a:
        system("cls");menu();
        printf("\t\t\tVOTRE CHOIX ---> ");scanf("%d",&choix);
    }while(choix < 1 || choix > 3);

    switch(choix)
    {
    case 1: /// GESTION DES ARTICLES
        system("cls");
        f_Articles();
        system("cls");
        goto a;
    case 2: /// GESTION DES VENTES
        system("cls");
        f_Ventes();
        system("cls");
        goto a;
    case 3: /// QUITTER LE PROGRAMME
        break;
    default:
        break;
    }
}
