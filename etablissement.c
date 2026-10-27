#include <stdio.h>
#include "etablissement.h"
#define TAILLE 9000

// Grégoire :
void afficheMenu(void){
    printf("Gestion du centre : \n");

    printf("1. affichager les activités disponible\n");
    printf("2. ajouter un adhérent\n");
    printf("3. afficher un adhérent\n");
    printf("4. afficher la liste des adhérents\n");
    printf("5. créditer un adhérent\n");
    printf("6. modifier un statut\n");
    printf("7. inscription à une acitivité\n");
    printf("8. fréquentation des activités\n");
    printf("9. quitter\n");
}

//Grégoire:
void gestionEtablissement(void){
    int tabA[TAILLE], tabC[TAILLE];
    int choix;
    int nbAdherent;

    nbAdherent = chargement(tabA, tabC, TAILLE);
    if(nbAdherent==-1){
        printf("Modifier la taille du tableaux puis réessayer");
        return ;
    }

    afficheMenu();
    printf("votre choix : ");
    scanf("%d", &choix);
    while (choix != 9){
        if (choix == 1){
            // A COMPLETER
            printf("pas encore codé ...\n");
        }
        else if (choix == 2){
            // A COMPLETER
            printf("pas encore codé ...\n");
        }
        else if (choix == 3){
            // A COMPLETER
            printf("pas encore codé ...\n");
        }
        else if (choix == 4){
            // A COMPLETER
            printf("pas encore codé ...\n");
        }
        else if (choix == 5){
            // A COMPLETER
            printf("pas encore codé ...\n");
        }
        else if (choix == 6){
            // A COMPLETER
            printf("pas encore codé ...\n");
        }
        else if (choix == 7){
            // A COMPLETER
            printf("pas encore codé ...\n");
        }
        else if (choix == 8){
            // A COMPLETER
            printf("pas encore codé ...\n");
        }
        else if (choix == 9){
            // A COMPLETER
            printf("pas encore codé ...\n");
        }
        else{
            printf("ce choix n'existe pas\n");
        }

        afficheMenu();
        printf("votre choix : ");
        scanf("%d", &choix);
    }
    sauvegarde(tabA, tabC, nbAdherent);
    printf("au revoir, à bientôt....\n");
}

// Grégoire :
void ajouteAdherent(void)
{
    FILE *fs;
    int idAdherent, credit;

    fs = fopen("aderent.don", "a");
    if (fs == 0)
        printf("Erreur ouverture fichier");

    printf("numéro Adhérent (xxxx) :");
    scanf("%d", &idAdherent);
    while (idAdherent < 1000 || idAdherent > 9999)
    { // vérifie que l'id est bien un int de 4 chiffes
        printf("Erreur de saisie (forme : xxxx), saississe à nouveau: ");
        scanf("%d", &idAdherent);
    }
    printf("Crédit de carte: ");
    scanf("%d", &credit);
        fprintf(fs, "%d\t%d\n", idAdherent, credit);

    fclose(fs);
}

// Grégoire :
int chargement(int tabA[], int tabC[], int tPhys){
    FILE *fe;
    int adherent, credit;
    int compt = 0;

    fe = fopen("aderent.don", "r");
    if (fe == NULL){
        printf("Erreur d'ouverture du fichier\n");
        return -1;
    }

    fscanf(fe, "%d %d", &adherent, &credit); 
    while (feof(fe) == 0){
        if (compt >= tPhys){
            printf("Tableaux trop petits\n");
            fclose(fe);
            return -1;
        }
        tabA[compt] = adherent;
        tabC[compt] = credit;
        fscanf(fe, "%d %d", &adherent, &credit);
        compt++;
    }

    fclose(fe);
    return compt; // renvoie la taille logique
}

//Grégoire:
int rechPos(int tab[], int tlog, int val, int *trouve){
  int i;

  for (i = 0; i < tlog; i++){
    if (tab[i] == val){
      *trouve = 1;
      return i;
    }
  }
  *trouve = 0;
  return ;
}

//gréoire:
void crediterAdherent(int tabA[], int tabC[], int nbAdherent)
{
  int adherent, credit, pos, trouve;

  printf("N° de matière à modifier :");
  scanf("%d", &adherent);
  printf("Nouveau coefficiant à modifier :");
  scanf("%d", &credit);

  pos = rechPosIns(tabA, nbAdherent, adherent, &trouve);
  if (trouve == 0)
  {
    printf("Adherent non trouvée");
    return;
  }
  printf("ancien credit: %d\n", tabC[pos]);
  tabC[pos] = credit;
}

// Grégoire :
void supprimeAdherent(void)
{
    FILE *fs;
    int idAdherent, idFile;

    fs = fopen("aderent.don", "a");
    if (fs == 0)
        printf("Erreur ouverture fichier");

    printf("numéro adhérent à supprimer(xxxx) :");
    scanf("%d", &idAdherent);
    while (idAdherent < 1000 || idAdherent > 9999)
    { // vérifie que l'id est bien un int de 4 chiffes
        printf("Erreur de saisie (forme : xxxx), saississe à nouveau: ");
        scanf("%d", &idAdherent);
    }
    while (feof(fs) == 0)
    {
        fscanf(fs, "%d", &idFile);
        if (idAdherent == idFile)
        {
            idFile = 0;
            break;
        }
    }

    fclose(fs);
}

void affichLesAdherents(int tabA[], int tabC[], int nbAdherent){
  int i;

  for (i = 0; i < nbAdherent; i++){
    printf("%d  %d\n", tabA[i], tabC[i]);
  }
}

//Grégoire:
void sauvegarde(int tabA[], int tabC[], int nbAdherent){
  FILE *fs;
  int i;

  fs = fopen("aderent.don", "w");
  if (fs == 0){
    printf("Erreur chargement du fichier pendant la sauvegarde\n");
    return;
  }

  for (i = 0; i < nbAdherent; i++){
    fprintf(fs, "%d\t%d\n", tabA[i], tabC[i]);
  }

  fclose(fs);
}

