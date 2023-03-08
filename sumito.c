#include<stdio.h>
#define bord 4
#define vide 0
#define rouge 3
#define bleue 2
#define NMAX 11

void deplacement_ligne_rouge(long choix, int tab[][NMAX], int i, int j)
{
int rouge, bleue, bord, vide, var_ech1, var_ech2, sumito[2],R,B;
sumito={R,B}
R=0;
B=0;
switch (choix)
         {
         case E:
                 for(;tab[i][j]==vide || tab[i][j]==bord;j++)
                         {
                         if(tab[i][j]==rouge)
                                 R=R+1;

                         if(tab[i][j]==bleue)
                                 B=B+1;
                         }
                 return sumito;

                 /* Une boule rouge face à une case vide */
                 if(sumito[0]==1 && sumito[1]==0)
                         {
                         var_ech1=*tab[i][j];
                         *tab[i][j]=*tab[i][j+1];
                         *tab[i][j+1]=var_ech1;
                         }

                 /* Deux boules rouges face à une case vide */
                 if(sumito[0]==2 && sumito[1]==0)
                         {
                         var_ech1=*tab[i][j];
                         *tab[i][j]=*tab[i][j+2];
                         *tab[i][j+2]=var_ech1;
                         }

                 /* Trois boules rouges face à une case vide */
                 if(sumito[0]==3 && sumito[1]==0)
                         {
                         var_ech1=*tab[i][j];
                         *tab[i][j]=*tab[i][j+3];
                        *tab[i][j+3]=var_ech1;
                         }

                 /* Deux boules rouges contre une boule bleue */
                 if(sumito[0]==2 && sumito[1]==1)
                         {
                         if(tab[i][j+3]==vide)
                                 {
                                 var_ech1=*tab[i][j+2];
                                 *tab[i][j+2]=*tab[i][j+3];
                                 *tab[i][j+3]=var_ech1;

                                 var_ech2=*tab[i][j];
                                 *tab[i][j]=*tab[i][j+2];
                                 *tab[i][j+2]=var_ech2;
                                 }

                         else if(tab[i][j+3]==bord)
                                 {
                                 tab[i][j+2]=vide;
                                 var_ech=*tab[i][j];
                                 *tab[i][j]=*tab[i][j+2];
                                 *tab[i][j+2]=var_ech;
                                }

                 /* Trois boules rouges contre une boule bleue */
                 if(sumito[0]==3 && sumito[1]==1)
                         {
                         if(tab[i][j+4]==vide)
                                 {
                                 var_ech1=*tab[i][j+3];
                                 *tab[i][j+3]=*tab[i][j+4];
                                 *tab[i][j+4]=var_ech1;

                                 var_ech2=*tab[i][j];
                                 *tab[i][j]=*tab[i][j+3];
                                 *tab[i][j+3]=var_ech2;
                                 }

                         else if(tab[i][j+4]==bord)
                                 {
                                 tab[i][j+3]=vide;
                                 var_ech1=*tab[i][j];
                                 *tab[i][j]=*tab[i][j+3];
                                 *tab[i][j+3]=var_ech1;
                                 }

                 /* Trois boules rouges contre deux boules bleues */
                 if(sumito[0]==3 && sumito[1]==2)
                         {
                         if(tab[i][j+5]==vide)
                                 {
                                 var_ech1=*tab[i][j+3];
                                 *tab[i][j+3]=*tab[i][j+5];
                                 *tab[i][j+5]=var_ech1;

                                 var_ech2=*tab[i][j];
                                 *tab[i][j]=*tab[i][j+3];
                                 *tab[i][j+3]=var_ech2;
                                 }

                         else if(tab[i][j+5]==bord)
                                 {
                                 tab[i][j+3]==vide;
                                 var_ech1=*tab[i][j];
                                 *tab[i][j]=*tab[i][j+3];
                                 *tab[i][j+3]=var_ech1;
                                 }
         break;


         case O:
                 for(;tab[i][j]==vide || tab[i][j]==bord;j--)
                         {
                         if(tab[i][j]==rouge)
                                 R=R+1;

                         if(tab[i][j]==bleue)
                                 B=B+1;
                         }
                 return sumito;

                 /* Une boule rouge face à une case vide */
                 if(sumito[0]==1 && sumito[1]==0)
                         {
                         var_ech1=*tab[i][j];
                         *tab[i][j]=*tab[i][j-1];
                         *tab[i][j-1]=var_ech1;
                         }

                 /* Deux boules rouges face à une case vide */
                 if(sumito[0]==2 && sumito[1]==0)
                         {
                         var_ech1=*tab[i][j];
                         *tab[i][j]=*tab[i][j-2];
                         *tab[i][j-2]=var_ech1;
                         }

                 /* Trois boules rouges face à une case vide */
                 if(sumito[0]==3 && sumito[1]==0)
                         {
                         var_ech1=*tab[i][j];
                         *tab[i][j]=*tab[i][j-3];
                         *tab[i][j-3]=var_ech1;
                         }

                 /* Deux boules rouges contre une boule bleue */
                 if(sumito[0]==2 && sumito[1]==1)
                         {
                         if(tab[i][j-3]==vide)
                                 {
                                 var_ech1=*tab[i][j-2];
                                 *tab[i][j-2]=*tab[i][j-3];
                                 *tab[i][j-3]=var_ech1;

                                 var_ech2=*tab[i][j];
                                 *tab[i][j]=*tab[i][j-2];
                                 *tab[i][j-2]=var_ech2;
                                 }

                         else if(tab[i][j-3]==bord)
                                 {
                                 tab[i][j-2]=vide;
                                 var_ech=*tab[i][j];
                                 *tab[i][j]=*tab[i][j-2];
                                 *tab[i][j-2]=var_ech;
                                 }

                 /* Trois boules rouges contre une boule bleue */
                 if(sumito[0]==3 && sumito[1]==1)
                         {
                         if(tab[i][j-4]==vide)
                                 {
                                 var_ech1=*tab[i][j-3];
                                 *tab[i][j-3]=*tab[i][j-4];
                                 *tab[i][j-4]=var_ech1;

                                 var_ech2=*tab[i][j];
                                 *tab[i][j]=*tab[i][j-3];
                                 *tab[i][j-3]=var_ech2;
                                 }

                         else if(tab[i][j-4]==bord)
                                 {
                                 tab[i][j-3]=vide;
                                 var_ech1=*tab[i][j];
                                 *tab[i][j]=*tab[i][j-3];
                                 *tab[i][j-3]=var_ech1;
                                 }

                 /* Trois boules rouges contre deux boules bleues */
                 if(sumito[0]==3 && sumito[1]==2)
                         {
                         if(tab[i][j-5]==vide)
                                 {
                                 var_ech1=*tab[i][j-3];
                                 *tab[i][j-3]=*tab[i][j-5];
                                 *tab[i][j-5]=var_ech1;

                                 var_ech2=*tab[i][j];
                                 *tab[i][j]=*tab[i][j-3];
                                 *tab[i][j-3]=var_ech2;
                                 }


                         else if(tab[i][j-5]==bord)
                                 {
                                 tab[i][j-3]==vide;
                                 var_ech1=*tab[i][j];
                                 *tab[i][j]=*tab[i][j-3];
                                 *tab[i][j-3]=var_ech1;
                                 }
                 break;


         case SO:
                 for(;tab[i][j]==vide || tab[i][j]==bord;i++)
                         {
                         if(tab[i][j]==rouge)
                                 R=R+1;

                         if(tab[i][j]==bleue)
                                 B=B+1;
                         }
                 return sumito;

                 /* Une boule rouge face à une case vide */
                 if(sumito[0]==1 && sumito[1]==0)
                         {
                         var_ech1=*tab[i][j];
                         *tab[i][j]=*tab[i+1][j];
                         *tab[i+1][j]=var_ech1;
                         }

                 /* Deux boules rouges face à une case vide */
                 if(sumito[0]==2 && sumito[1]==0)
                         {
                         var_ech1=*tab[i][j];
                         *tab[i][j]=*tab[i+2][j];
                         *tab[i+2][j]=var_ech1;
                         }

                 /* Trois boules rouges face à une case vide */
                 if(sumito[0]==3 && sumito[1]==0)
                         {
                         var_ech1=*tab[i][j];
                         *tab[i][j]=*tab[i+3][j];
                         *tab[i+3][j]=var_ech1;
                         }

                 /* Deux boules rouges contre une boule bleue */
                 if(sumito[0]==2 && sumito[1]==1)
                         {
                         if(tab[i+3][j]==vide)
                                 {
                                 var_ech1=*tab[i+2][j];
                                 *tab[i+2][j]=*tab[i+3][j];
                                 *tab[i+3][j]=var_ech1;

                                 var_ech2=*tab[i][j];
                                 *tab[i][j]=*tab[i+2][j];
                                 *tab[i+2][j]=var_ech2;
                                 }

                         else if(tab[i+3][j]==bord)
                                 {
                                 tab[i+2][j]=vide;
                                 var_ech=*tab[i][j];
                                 *tab[i][j]=*tab[i+2][j];
                                 *tab[i+2][j]=var_ech;
                                 }

                 /* Trois boules rouges contre une boule bleue */
                 if(sumito[0]==3 && sumito[1]==1)
                         {
                         if(tab[i+4][j]==vide)
                                 {
                                 var_ech1=*tab[i+3][j];
                                 *tab[i+3][j]=*tab[i+4][j];
                                 *tab[i+4][j]=var_ech1;

                                 var_ech2=*tab[i][j];
                                 *tab[i][j]=*tab[i+3][j];
                                 *tab[i+3][j]=var_ech2;
                                 }

                         else if(tab[i+4][j]==bord)
                                 {
                                 tab[i+3][j]=vide;
                                 var_ech1=*tab[i][j];
                                 *tab[i][j]=*tab[i+3][j];
                                 *tab[i+3][j]=var_ech1;
                                 }

                 /* Trois boules rouges contre deux boules bleues */
                 if(sumito[0]==3 && sumito[1]==2)
                         {
                         if(tab[i+5][j]==vide)
                                 {
                                 var_ech1=*tab[i+3][j];
                                 *tab[i+3][j]=*tab[i+5][j];
                                 *tab[i+5][j]=var_ech1;

                                 var_ech2=*tab[i][j];
                                 *tab[i][j]=*tab[i+3][j];
                                 *tab[i+3][j]=var_ech2;
                                 }

                         else if(tab[i+5][j]==bord)
                                 {
                                 tab[i+3][j]==vide;
                                 var_ech1=*tab[i][j];
                                 *tab[i][j]=*tab[i+3][j];
                                 *tab[i+3][j]=var_ech1;
                                 }
                 break;
