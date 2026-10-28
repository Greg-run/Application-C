/**
    \file etablissement.h
    \author Grégoire Farfelan
    \date 14/10/2026
    \brief application qui gère le complexe
 */

/**
   \brief Fonction qui affiche le menu 
*/
void afficheMenu(void);

/**
   \brief Fonction globale du programme
*/
void gestionEtablissement(void);


/**
   \brief Fonction qui charge les données du fichier adherent.don dans un
       tableau d'adherent et un tableau de credit
   \param[out] tabA : tableau des adhérents
   \param[out] tabC : tableau des crédits
   \param[in] tPhys : taille physique des deux tableaux
   \return la taille logique des tableaux si le chargement a bien pu se faire
        ou -1 sinon ( tableaux trop petits ou problème d'ouverture du fichier)
*/
int chargement(int tabA[], int tabC[], int tPhys);

/**
   \brief Fonction qui affiche le contenu des tableaux d'adherents et de crédits
   \param[in] tabA : tableau des adherents
   \param[in] tabCoeff : tableau des crédits
   \param[in] nbAdherent : nombre d'adhrents contenues dans tabA
*/
void affichLesAdherents(int tabA[], int tabC[], int nbAdherent);


/**
   \brief Fonction qui cherche dans un tableau d'entiers
        une valeur. Cette fonction permet de savoir si la valeur est contenue
	ou pas dans le tableau; et indique aussi sa position (si elle y est)
   \param[in] tab : tableau dans lequel cherché
   \param[in] tlog : taille logique du tableau
   \param[in] val : valeur cherchée
   \param[out] trouve : adresse de la variable dans laquelle va être mis 1 si la
        valeur a été trouvée, ou 0 sinon
   \return la position de la valeur si trouvée
*/
int rechPos(int tab[], int tlog, int val, int* trouve);


/**
   \brief Fonction qui cherche à modifier le crédit associé à un adhérent
   \param[in] tabA : tableau des matières
   \param[in] tabC : tableau des coefficients
   \param[in] nbAdherent : nombre d'adherents contenues dans tabA
	
*/
void crediterAdherent(int tabA[], int tabC[], int nbAdherent);

/**
   \brief Fonction qui sauvegarde des tableaux tabA et tabC dans le fichier
       adherent.don
   \param[in] tabMat : tableau des adherents
   \param[in] tabCoeff : tableau des crédits
   \param[in] nbMap : taille logique des deux tableaux
*/
void sauvegarde(int tabA[], int tabC[], int nbAdherent);




/** 
    \brief Fonction qui ajoute un adhérent
*/
void ajouteAdherent(void);


/** 
    \brief Fonction qui supprime un adhérent
*/
void supprimeAdherent(void);


