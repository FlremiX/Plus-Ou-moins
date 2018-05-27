#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int niveau, challengMod = 0, tours, continuerPartie = 0, MAX, MIN, compteurCoups = 0, cache1 = 0, nombreMystere = 0, nombreEntre = 0;

int main ( int argc, char** argv )
{
    printf("! CE PROGRAMME A ETE REALISE SOUS LINUX, VOUS EXECUTER ACTUELLEMENT LA VERSION ADAPTE POUR WINDOWS !\nBienvenue a ''Plus au Moins'', veuillez selectionner le niveu de difficultee :\n");
    do{
    if (continuerPartie == 1){ system("cls"); }//Netoyer l'ecran si le joueur recommence le jeu
    do{
    // choix du niveau
    system("title :: PlusOuMoins - Choix du niveau ::");
    cache1 = 0;
    challengMod = 0;
    niveau = 0;
    printf("Niveau 1 : le nombre mystere se situe entre 1 et 100 (Choix 1)\nNiveau 2 : le nombre se situe entre 1 et 1000 (Choix 2)\nNiveau 3 : le nombre se situe entre 1 et 10.000 (Choix 3)\nMode Chalenge : Pour plus d'informations, tapez 4\nTapez le numero de votre choix : ");
    scanf("%d", &niveau);
    printf("\nNiveau choisi : %d\n", niveau);
    system("timeout 1");
    system("cls");

    // Génération des nombres aléatoire :
    if (niveau == 1){ MAX = 100, MIN = 1; cache1 = 0; challengMod = 2;} //Si le niveau choisi est le niveau 1
    else if (niveau == 2){ MAX = 1000, MIN = 1; cache1 = 0; challengMod = 2;} //Si le niveau choisi est le niveau 2
    else if (niveau == 3){ MAX = 10000, MIN = 1; cache1 = 0; challengMod = 2;} //Si le niveau choisi est le niveau 3
    else if (niveau == 4){ printf("Le mode ''Chalenge'' est un mode ou l'utilisateur doit trouver le nombre (situe entre 1 et 10.000) en un nombre de tour defini par ce dernier.\nTapez 1 si vous voulez jouer en mode ''Chalenge'', sinon, tapez 0 :"); scanf("%d", &challengMod); }
    //Explications concernant le mode chalenge
    else { printf("Nombre rentre invalide... Rentrer a nouveau le choix du niveau :\n"); cache1 = 1; }
    if (challengMod == 1){ MAX = 10000, MIN = 1; printf("\nEn combien de tours le nombre doit-il etre trouve ?\nEntrez le nombre de tours : "); scanf("%d", &tours); compteurCoups =tours; printf("\nLe nombre doit-etre trouve en %d tours\nGood Luck !\n", tours); }
    else if (challengMod == 0){ printf("Vous etes renvoyer au choix des niveaux...\n"); cache1 = 1; system("timeout 1"); system("cls"); }
    else if (challengMod != 0 && challengMod != 1 && challengMod != 2) { printf("Choix incorrecte, Vous etes renvoyer aux choix des niveaux...\n"); cache1 = 1; system("cls"); }
    }while (cache1 == 1);
    nombreMystere = 0;
    nombreEntre = 0;
    srand(time(NULL));
    nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
    system("cls");

    do
    {
        if (challengMod == 1){ system("title ChallengeMod [ON] :: Trouver le nombre mystere !! ::"); }
        else { system("title ChallengeMod [OFF] :: Trouver le nombre mystere !! ::"); }
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
           if (challengMod == 2){ system("title ChallengeMod [OFF] :: Victoire ! ::"); printf ("Bravo, vous avez trouve le nombre mystere en %d coups !!!\n", compteurCoups); }
           else if (challengMod == 1){ system("title ChallengeMod [ON] :: Victoire ! ::"); printf("Bravo, vous avez gagne ! Vous avez trouvez le nombre malgre la limite de tours !\nVous avez utilise %d sur %d de vos tours !\n", compteurCoups, tours);}
    } while (nombreEntre != nombreMystere || compteurCoups == 0);
    if (challengMod == 1 && compteurCoups == 0){ system("title ChallengeMod [OFF] :: Game Over... ::"); printf("\nPerdu... Le nombre etait %d\n", nombreMystere);}
    printf("Voulez-vous recommencer le jeu ? [Oui = 1, Non = 0] ");
    scanf("%d", &continuerPartie);
    printf("\n");
    } while (continuerPartie != 0);
    system("exit");
    system("timeout 1");
    return 0;
}
