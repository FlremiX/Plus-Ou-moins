#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int niveau, challengMod = 0, tours, continuerPartie = 0, MAX, MIN, compteurCoups = 0, cache1 = 0, nombreMystere = 0, nombreEntre = 0;

int main ( int argc, char** argv )
{
    printf("! CE PROGRAMME A ÉTÉ RÉALISÉ SOUS LINUX !\nBienvenue a ''Plus au Moins'', veuillez sélectionner le niveu de difficultée :\n");
    do{
    if (continuerPartie == 1){ system("clear"); }//Netoyer l'écran si le joueur recommence le jeu
    do{
    // choix du niveau
    cache1 = 0;
    challengMod = 0;
    niveau = 0;
    printf("Niveau 1 : le nombre mysètre se situe entre 1 et 100 (Choix 1)\nNiveau 2 : le nombre se situe entre 1 et 1000 (Choix 2)\nNiveau 3 : le nombre se situe entre 1 et 10.000 (Choix 3)\nMode Chalenge : Pour plus d'informations, tapez 4\nTapez le numéro de votre choix : ");
    scanf("%d", &niveau);
    printf("\nNiveau choisi : %d\n", niveau);
    system("sleep 2");
    system("clear");

    // Génération des nombres aléatoire :
    if (niveau == 1){ MAX = 100, MIN = 1; cache1 = 0; challengMod = 2;} //Si le niveau choisi est le niveau 1
    else if (niveau == 2){ MAX = 1000, MIN = 1; cache1 = 0; challengMod = 2;} //Si le niveau choisi est le niveau 2
    else if (niveau == 3){ MAX = 10000, MIN = 1; cache1 = 0; challengMod = 2;} //Si le niveau choisi est le niveau 3
    else if (niveau == 4){ printf("Le mode ''Chalenge'' est un mode où l'utilisateur doit trouver le nombre (situé entre 1 et 10.000) en un nombre de tour défini par ce dernier.\nTapez 1 si vous voulez jouer en mode ''Chalenge'', sinon, tapez 0 :"); scanf("%d", &challengMod); }
    //Explications concernant le mode chalenge
    else { printf("Nombre rentré invalide... Rentrer à nouveau le choix du niveau :\n"); cache1 = 1; }
    if (challengMod == 1){ MAX = 10000, MIN = 1; printf("\nEn combien de tours le nombre doit-il être trouvé ?\nEntrez le nombre de tours : "); scanf("%d", &tours); compteurCoups =tours; printf("\nLe nombre doit-être trouvé en %d tours\nGood Luck !\n", tours); }
    else if (challengMod == 0){ printf("Vous êtes renvoyer au choix des niveaux...\n"); cache1 = 1; system("sleep 2"); system("clear"); }
    else if (challengMod != 0 && challengMod != 1 && challengMod != 2) { printf("Choix incorrecte, Vous êtes renvoyer aux choix des niveaux...\n"); cache1 = 1; system("clear"); }
    }while (cache1 == 1);
    nombreMystere = 0;
    nombreEntre = 0;
    srand(time(NULL));
    nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
    system("clear");

    do
    {
        printf("Quel est le nombre ? ");
        scanf("%d", &nombreEntre);
        if (nombreMystere > nombreEntre)
            {
            printf("C'est plus !\n");
            if (challengMod == 2){ compteurCoups++; }
            if (challengMod == 1){ compteurCoups--; printf("Il vous reste %d tours restant !\n", compteurCoups);}
            }
         else if (nombreMystere < nombreEntre)
            {
            printf("C'est moins !\n");
            if (challengMod == 2 ){ compteurCoups++; }
            if (challengMod == 1){ compteurCoups--; printf("Il vous reste %d tours restant !\n", compteurCoups);}
            }
        else
           if (challengMod == 2){ printf ("Bravo, vous avez trouve le nombre mystere en %d coups !!!\n", compteurCoups); }
           else if (challengMod == 1){ printf("Bravo, vous avez gagné ! Vous avez trouvez le nombre malgré la limite de tours !\nVous avez utilisé %d sur %d de vos tours !\n", compteurCoups, tours);}
    } while (nombreEntre != nombreMystere || compteurCoups == 0);
    if (challengMod == 1 && compteurCoups == 0){ printf("\nPerdu... Le nombre était %d\n", nombreMystere);}
    printf("Voulez-vous recommencer le jeu ? [Oui = 1, Non = 0]\n");
    scanf("%d", &continuerPartie);
    } while (continuerPartie != 0);
    sytem("exit");
    return 0;
}
