#ifndef ARTICLES_H_INCLUDED
#define ARTICLES_H_INCLUDED
#include <string.h>
#define N 200

/*********************************** CRERATION DA LA STRUCTURE ARTICLE ************************************************/

typedef struct
{
    int codeA;
    int jourP;
    int moisP;
    int anneeP;
    char NomA[30];
    int prixAchat;
    int QtStock;
}article;

article a;
FILE * fichier;

/********************************************************************************************************************/

/********************************************** Cr�ation des prototypes ********************************************/

void ajoutA(); /// ajout des articles
void modifierA();
void supprimerA();
void affA_alph();
void affA_Qt();
void calAffA_QtSup(); /// Calcul et affichage de la liste des articles ayant une quantit� en stock sup�rieur � 20;
void affA_p();

/*****************************************************************************************************************/

/****************************************** CREEATION DES FONCTIONS/PROCEDURE *************************************************************/

void ajoutA()/// Ajoute d'un article
{
    /**
        Cette fonction permet de cr�er des articles dans le fichier article.txt
    */

    int codeR, tr=0;
    fichier = fopen("article.txt","at+");
    if(fichier==NULL)
    {
        printf("LE FICHIER ARTICLE N'EXISTE PAS \n");
        exit(1);
    }

    printf("\n\t\tDonner le code : ");scanf("%d",&codeR);
    while(!feof(fichier))
    {
        /**
            Permet de v�rifier si le code existe d�dj� dans le fichier article.txt
            s'il existe la variable tr retourne 1 si le codeR=a.codeA codeR(Code entrer) a.odeA(Code Article);
        */
        fscanf(fichier,"%d\n%s\n%d %d %d\n%d\n%d\n\n",&a.codeA,a.NomA,&a.jourP,&a.moisP,&a.anneeP,&a.prixAchat,&a.QtStock);
        if(codeR==a.codeA) /// V�rification du code
        {
            tr =1;
            break;
        }
    }

    if(tr==1)
    {
        printf("Ce code d'article existe deja dans le programme \n");
    }
    else
    {
        printf("\n\t\t\tENTREZ LES INFORMATIONS DU PRODUIT \n");
        printf("\t\t\tNOM :");scanf("%s",a.NomA);
        puts("\t\t\tDATE DE PREMPTION ");

        printf("\t\t\tJour --> ");scanf("%d",&a.jourP);
        while(a.jourP<1 || a.jourP>31) /// Nous avons pris l'interval de jours 27-31 pour l'Admi vus qu'on ne peut pas enregistre un produit perim�
        {
            printf("\t\t\tJour non valide --> ");scanf("%d",&a.jourP);
        }

        printf("\t\t\tMois --> ");scanf("%d",&a.moisP);
        while(a.moisP<6 || a.moisP>12) /// On ne pourra enregistre un produit qui est d�j� expir�
        {
            printf("\t\t\tmois non valide --> ");
            scanf("%d",&a.moisP);
        }
        printf("\t\t\tannee --> ");scanf("%d",&a.anneeP);
        while(a.anneeP<2022 || a.anneeP>2035) /// date de peremption dans l'intervale 2022-2035
        {
            printf("\t\t\tannee non valide --> ");
            scanf("%d",&a.anneeP);
        }

        printf("\t\t\tPRIX D'ACHAT:");scanf("%d",&a.prixAchat);
        printf("\t\t\tQUANTITE EN STOCK :");scanf("%d",&a.QtStock);
        fprintf(fichier,"%d\n%s\n%d %d %d\n%d\n%d\n\n",codeR,a.NomA,a.jourP,a.moisP,a.anneeP,a.prixAchat,a.QtStock);

        puts("Felicitation Enregistrement avec succes ");
    }

    fclose(fichier);

}

void modifierA() /// Modification d'un article
{
    /**
    La modification d'un article est possible que lorsque le code dans le fichier existe et nous cr�eons un fichier temp pour la modification d'un article
    */
    int codeR, tr=0;
    FILE * temp;
    fichier=fopen("article.txt","rt");

    if(fichier==NULL)
    {
        printf("Impossible d'ouvrir le fichier article ");
        exit(1);
    }

    temp = fopen("temp.txt","wt");
    if(temp==NULL)
    {
        printf("Impossible d'ouvrir le fichier temp ");
    }

    printf("\n\t\tDonnez le code d'article a modifier ");scanf("%d",&codeR);

    while(!feof(fichier))
    {
        fscanf(fichier,"%d\n%s\n%d %d %d\n%d\n%d\n\n",&a.codeA,a.NomA,&a.jourP,&a.moisP,&a.anneeP,&a.prixAchat,&a.QtStock);
        if(codeR==a.codeA)
        {
            tr=1;
            printf("\n\t\t\tNOM : ");scanf("%s",a.NomA);
             puts("\t\t\tDATE DE PREMPTION :");
            printf("\t\t\tJour --> ");scanf("%d",&a.jourP);
            while(a.jourP<27 || a.jourP>31) /// Nous avons pris l'interval de jours 27-31 pour l'Admi vus qu'on ne peut pas enregistre un produit perim�
            {
                printf("\t\t\tJour non valide ");
                scanf("%d",&a.jourP);
            }
            printf("\t\t\tMois --> ");scanf("%d",&a.moisP);
            while(a.moisP<6 || a.moisP>12)
            {
                printf("\t\t\tmois non valide ");
                scanf("%d",&a.moisP);
            }
            printf("\t\t\tannee --> ");scanf("%d",&a.anneeP);
            while(a.anneeP<2022 || a.anneeP>2035) /// date de peremption dans l'intervale 2022-2035
            {
                printf("\t\t\tannee non valide");
                scanf("%d",&a.anneeP);
            }
                printf("\t\t\tPRIX D'ACHAT:");scanf("%d",&a.prixAchat);
                printf("\t\t\tQUANTITE EN STOCK :");scanf("%d",&a.QtStock);
        }
    fprintf(temp,"%d\n%s\n%d %d %d\n%d\n%d\n\n",codeR,a.NomA,a.jourP,a.moisP,a.anneeP,a.prixAchat,a.QtStock);
    }
    fclose(fichier); fclose(temp);
    remove("article.txt");
    rename("temp.txt","article.txt");

    if(tr==0)
    {
        printf("Le Code %d n'existe pas \n",a.codeA);
    }
    else
    {
        printf("Modification avec succes \n");
    }
}

void supprimerA() /// Suppression d'un article
{
    int codeR, tr=0;
    FILE * temp;
    fichier=fopen("article.txt","rt");

    if(fichier==NULL)
    {
        printf("Impossible d'ouvrir le fichier ");
        exit(1);
    }
    temp = fopen("temp.txt","wt");
    if(temp==NULL)
    {
        printf("impossible d'ouvrir le fichier temp ");
    }
    printf("\n\t\tDonnez le code d'article a supprimer ");scanf("%d",&codeR);
    while(!feof(fichier))
    {
        fscanf(fichier,"%d\n%s\n%d %d %d\n%d\n%d\n\n",&a.codeA,a.NomA,&a.jourP,&a.moisP,&a.anneeP,&a.prixAchat,&a.QtStock);

        if(a.codeA!=codeR){
         fprintf(temp,"%d\n%s\n%d %d %d\n%d\n%d\n\n",a.codeA,a.NomA,a.jourP,a.moisP,a.anneeP,a.prixAchat,a.QtStock);
        }
        else
            tr=1;
    }

    fclose(fichier); fclose(temp);
    remove("article.txt");
    rename("temp.txt","article.txt");

    if(tr==0)
    {
        printf("Le Code n'existe pas \n");
    }
    else
    {
        printf("Suppression avec succes \n");
    }
}

void affA_alph() /// Afficher la liste des articles par ordre alphabetique
{
    article tab[N]; /// Ici nous attribions la structure (variable article) � un tableau
    article temps;
    int i=0;
    int nbre = 0;

    fichier =fopen("article.txt","rt");

    if(fichier==NULL)
    {
        printf("Impossible d'ouvrir le fichier article ");
    }

    while(!feof(fichier))
    {
        fscanf(fichier,"%d\n%s\n%d %d %d\n%d\n%d\n\n",&tab[i].codeA,tab[i].NomA,&tab[i].jourP,&tab[i].moisP,&tab[i].anneeP,&tab[i].prixAchat,&tab[i].QtStock);
        i++;
    }

    fclose(fichier);

    /// Cette fonction permet de comparer chaque nom Article et de les classer par ordre alphab�tique
    for(int n=0;n<i-1;n++)
    {
        nbre++;
        for(int k = n+1;k<i;k++)
        {
            if(strcmp(tab[k].NomA,tab[n].NomA)==-1)
            {
                temps=tab[n];
                tab[n]=tab[k];
                tab[k]=temps;
            }
        }
    }

    printf("\t\t\tLA LISTE DES ARTICLES PAR ODRE ALPHABETIQUE \n");
    puts("\t\t\t-------------------------------------------------------------------------");
    printf("\t\t\t|CODE_A|  NOM_A| |  DATE_PEREMPTION|  |PRIX_ACHAT| |QUANTITE_STOCK|\n");
    puts("\t\t\t-------------------------------------------------------------------------");


    for(int j=0;j<=nbre;j++)
    {
        printf("\t\t\t| %d      %s\t       %d/%d/%d         %dGNF      %d\n",tab[j].codeA,tab[j].NomA,tab[j].jourP,tab[j].moisP,tab[j].anneeP,tab[j].prixAchat,tab[j].QtStock);
    }


}

void affA_Qt() /// Affichage de la liste des articles par ordre croissant de quantite en stock
{
    article tab[N]; /// Ici nous attribions la structure (variable article) � un tableau et la valeur de N est d�finie comme une constante
    article temps;
    int i=0;
    int nbre = 0;

    fichier =fopen("article.txt","rt");

    if(fichier==NULL)
    {
        printf("Impossible d'ouvrir le fichier ");
    }

    while(!feof(fichier))
    {
        fscanf(fichier,"%d\n%s\n%d %d %d\n%d\n%d\n\n",&tab[i].codeA,tab[i].NomA,&tab[i].jourP,&tab[i].moisP,&tab[i].anneeP,&tab[i].prixAchat,&tab[i].QtStock);
        i++;
    }
    fclose(fichier);

    for(int n=0;n<i-1;n++)
    {
        nbre++;
        for(int k = n+1;k<i;k++)
        {
            if(tab[k].QtStock<tab[n].QtStock)
            {
                temps=tab[n];
                tab[n]=tab[k];
                tab[k]=temps;
            }
        }
    }
    printf("\t\t\tLA LISTE DES ARTICLES PAR ODRE CROISSANT DE QUANTITE EN STOCK \n");
    puts("\t\t\t-------------------------------------------------------------------------");
    printf("\t\t\t|CODE_A|  NOM_A| |  DATE_PEREMPTION|  |PRIX_ACHAT| |QUANTITE_STOCK|\n");
    puts("\t\t\t-------------------------------------------------------------------------");

    for(int j=0;j<=nbre;j++)
    {
        printf("\t\t\t| %d      %s\t       %d/%d/%d         %dGNF      %d\n",tab[j].codeA,tab[j].NomA,tab[j].jourP,tab[j].moisP,tab[j].anneeP,tab[j].prixAchat,tab[j].QtStock);
    }

}

void calAffA_QtSup() /// Calcul et affichage de la liste des articles ayant une quantite en stock superieur � 20
{
    fichier =fopen("article.txt","rt");

    if(fichier==NULL)
    {
        printf("Impossible d'ouvrir le fichier ");
    }

    printf("\n\t\t\tLA LISTE DES ARTICLES AYANT UNE QUANTITE EN STOCK > 20 \n");
    puts("\t\t\t|-----------------------------------------------------------------------|");
    printf("\t\t\t|CODE_A|  NOM_A| |  DATE_PEREMPTION|  |PRIX_ACHAT| |QUANTITE_STOCK|\n");
    puts("\t\t\t|----------------------------------------------------------------------|");
    while(!feof(fichier))
    {
        fscanf(fichier,"%d\n%s\n%d %d %d\n%d\n%d\n\n",&a.codeA,a.NomA,&a.jourP,&a.moisP,&a.anneeP,&a.prixAchat,&a.QtStock);

        if(a.QtStock>20)
        {
            printf("\t\t\t| %d\t%s\t\t%d/%d/%d\t%dGNF\t%d\n",a.codeA,a.NomA,a.jourP,a.moisP,a.anneeP,a.prixAchat,a.QtStock);
            puts("\t\t\t|----------------------------------------------------------------------|");
        }
    }
    fclose(fichier);
}

void affA_p() /// Affichage de la liste des articles qui doivent permier dans 2 mois
{
    fichier =fopen("article.txt","rt");

     if(fichier==NULL)
    {
        printf("Impossible d'ouvrir le fichier arcticle ");
    }

    printf("\t\t\tLA LISTE DES ARTICLES QUI DOIVENT PERIMER DANS 2 MOIS \n");
    puts("\t\t\t---------------------------------------------------------------------");
    printf("\t\t\tCODE_A\tNOM_A\t\tDATE_PEREMPTION\tPRIX_ACHAT\tQUANTITE_STOCK \n");
    puts("\t\t\t----------------------------------------------------------------------");

    while(!feof(fichier))
    {
        fscanf(fichier,"%d\n%s\n%d %d %d\n%d\n%d\n\n",&a.codeA,a.NomA,&a.jourP,&a.moisP,&a.anneeP,&a.prixAchat,&a.QtStock);

        if((a.moisP>=6 && a.moisP<=8) && a.anneeP==2022)
        {
            printf("\t\t\t| %d\t%s\t\t%d/%d/%d\t%dGNF\t%d\n",a.codeA,a.NomA,a.jourP,a.moisP,a.anneeP,a.prixAchat,a.QtStock);
            puts("\t\t\t|----------------------------------------------------------------------|");
        }
    }

    fclose(fichier);
}

#endif // ARTICLES_H_INCLUDED
