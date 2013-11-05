/* INF3105 - Travail Pratique #1
 * Representation en C++ du "GAME OF LIFE"
 *
 * Universite du Quebec a Montreal
 *
 * Auteur: Patrick Pelletier (PELP29088609)
 *          <pp.pelletier@gmail.com>
 *
 * Fichier contenant la fonction main (le point d'entree du programme)
 * ainsi que les fonctionnalites pour traiter les arguments du programmes et le
 * fichier d'entree des donnees du jeu.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "Jeu.hpp"
#include "Grille.hpp"

using namespace std;

void usage(char *argv0);
bool ouvrirFichier (ifstream & f, char *nom);

/* Fonction Principale du programme
 *
 * Valide les arguments, ouvre et lit le fichier et initialise le jeu.
 *
 * Parametres:  argc: le nombre d'arguments de la ligne de commande
 *              argv: le tableau des chaines correspondant au arguments
 */
int main (int argc, char *argv[])
{
    // declaration des variables necessaire
    int nbGenerations, attente;
    ifstream ficDepart;

    // instanciation d'une grille pour la lecture dans le fichier
    Grille *grille = new Grille();

    // verification et affectation des arguments
    if (argc != 4)
    {
        usage(argv[0]);
    }
    nbGenerations = atoi(argv[2]);
    attente = atoi(argv[3]);

    // ouverture et lecture du fichier + affectation de la grille initiale
    ouvrirFichier (ficDepart, argv[1]);
    while (!ficDepart.eof())
    {
        int lig, col;

        // On ne fait aucune verification sur les donnees dans le fichier.
        // On suppose que les donnees on le bon format.
        ficDepart >> lig >> col;
        grille->setCell(1, lig, col);
    }
	ficDepart.close();

    // instanciation et deroulement du jeu
    Jeu *jeu = new Jeu(grille, nbGenerations, attente);
    jeu->jouer();

    return 0;
}

/* Affiche un message d'erreur et quitte le programme.
 *
 * La fonction est appelee lorsque l'utilisateur n'entre pas le bon nombre de
 * parametre a l'appel en ligne de commande.
 *
 * Parametres:  argv0: le nom du programme
 */
void usage (char *argv0)
{
    cerr << "Usage: " << argv0 << " <nomFichierPatern> <nbOscillations> <nbMilisecondes>\n";
    exit(1);
}

/* Ouvre un fichier en lecture.
 *
 * Affiche un message d'erreur et quitte le programme si le fichier n'est pas
 * valide.
 *
 * Parametres:  f: flux de fichier en lecture
 *              nom: le nom du fichier a ouvrir
 * Retourne: true si l'ouverture s'est effectuee, false sinon
 */
bool ouvrirFichier (ifstream & f, char *nom)
{
    bool ouvert;
    f.open (nom, ios::in);
    ouvert = f;
    if (!f)
    {
        cerr << "Impossible d'ouvrir le fichier " << nom << endl;
        exit(1);
    }
    return ouvert;
}
