/* INF3105 - Travail Pratique #1
 * Representation en C++ du "GAME OF LIFE"
 *
 * Universite du Quebec a Montreal
 *
 * Auteur: Patrick Pelletier (PELP29088609)
 *          <pp.pelletier@gmail.com>
 *
 * Fichier d'implantation de la classe Jeu.
 */

#include <iostream>
#include "Jeu.hpp"
#include "PortableSleep.hpp"

using namespace std;

// Creation du jeu.
Jeu :: Jeu(Grille *grille, int nbGenerations, int attente)
{
    this->grille = *grille;
    this->nbGenerations = nbGenerations;
    this->attente = attente;
}

// Jouer au jeu.
void Jeu :: jouer()
{
    // boucle principale du jeu
    for (int i = 1; i <= this->nbGenerations; ++i)
    {
        cout << "Generation " << i;
        this->grille.afficher();
        sleepMilis(this->attente);
        this->grille = majGrille();
    }
}

// Mis-a-jour de la grille.
Grille Jeu :: majGrille()
{
    Grille *grilleTmp = new Grille();

    // Parcours de la grille
    for (int i = 0; i < this->grille.getLig(); ++i)
    {
        for (int j = 0; j < this->grille.getCol(); ++j)
        {
            // La cellule est morte et a 3 voisins, elle nait.
            if ((this->grille.getCell(i, j) == 0) && (getNbVoisins(i, j) == 3))
            {
                grilleTmp->setCell(1, i, j);
            }

            // La cellule est vivante et a 2 ou 3 voisins, elle survit.
            else if ((this->grille.getCell(i, j) == 1) &&
                     ((getNbVoisins(i, j) == 2) || (getNbVoisins(i, j) == 3)))
            {
                grilleTmp->setCell(1, i, j);
            }

            // Autre cas, elle reste morte ou meurt.
            else
            {
                grilleTmp->setCell(0, i, j);
            }
        }
    }
    return *grilleTmp;
}

// Calcul du nombre de voisin d'une cellule.
int Jeu :: getNbVoisins(int lig, int col) const
{
    int reponse = 0;

    // Cellule dans le coin supérieur gauche
    if ((lig == 0) && (col == 0))
    {
        reponse += grille.getCell(lig, col+1);
        reponse += grille.getCell(lig+1, col);
        reponse += grille.getCell(lig+1, col+1);
    }

    // Cellule dans le coin supérieur droit
    else if ((lig == 0) && (col == this->grille.getCol()-1))
    {
        reponse += grille.getCell(lig, col-1);
        reponse += grille.getCell(lig+1, col-1);
        reponse += grille.getCell(lig+1, col);
    }

    // Cellule dans le coin inferieur gauche
    else if ((lig == this->grille.getLig()-1) && (col == 0))
    {
        reponse += grille.getCell(lig-1, col);
        reponse += grille.getCell(lig-1, col+1);
        reponse += grille.getCell(lig, col+1);
    }

    // Cellule dans le coin inferieur droit
    else if ((lig == this->grille.getLig()-1) &&
             (col == this->grille.getCol()-1))
    {
        reponse += grille.getCell(lig-1, col-1);
        reponse += grille.getCell(lig-1, col);
        reponse += grille.getCell(lig, col-1);
    }

    // Cellule sur la ligne superieure (mais pas dans un coin)
    else if ((lig == 0) && (col != 0) && (col != this->grille.getCol()-1))
    {
        reponse += grille.getCell(lig, col-1);
        reponse += grille.getCell(lig, col+1);
        reponse += grille.getCell(lig+1, col-1);
        reponse += grille.getCell(lig+1, col);
        reponse += grille.getCell(lig+1, col+1);
    }

    // Cellule sur la colonne gauche (mais pas dans un coin)
    else if ((lig != 0) && (lig != this->grille.getLig()-1) && (col == 0))
    {
        reponse += grille.getCell(lig-1, col);
        reponse += grille.getCell(lig-1, col+1);
        reponse += grille.getCell(lig, col+1);
        reponse += grille.getCell(lig+1, col);
        reponse += grille.getCell(lig+1, col+1);
    }

    // Cellule sur la colonne droite (mais pas dans un coin)
    else if ((lig != 0) && (lig != this->grille.getLig()-1) &&
             (col == this->grille.getCol()-1))
    {
        reponse += grille.getCell(lig-1, col-1);
        reponse += grille.getCell(lig-1, col);
        reponse += grille.getCell(lig, col-1);
        reponse += grille.getCell(lig+1, col-1);
        reponse += grille.getCell(lig+1, col);
    }

    // Cellule sur la ligne inferieure (mais pas dans un coin)
    else if ((lig == this->grille.getLig()-1) && (col != 0) &&
             (col != this->grille.getCol()-1))
    {
        reponse += grille.getCell(lig-1, col-1);
        reponse += grille.getCell(lig-1, col);
        reponse += grille.getCell(lig-1, col+1);
        reponse += grille.getCell(lig, col-1);
        reponse += grille.getCell(lig, col+1);
    }

    // Cellule dans une des cases du milieu de la grille
    else
    {
        reponse += grille.getCell(lig-1, col-1);
        reponse += grille.getCell(lig-1, col);
        reponse += grille.getCell(lig-1, col+1);
        reponse += grille.getCell(lig, col-1);
        reponse += grille.getCell(lig, col+1);
        reponse += grille.getCell(lig+1, col-1);
        reponse += grille.getCell(lig+1, col);
        reponse += grille.getCell(lig+1, col+1);
    }
    return reponse;
}
