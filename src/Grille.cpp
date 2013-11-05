/* INF3105 - Travail Pratique #1
 * Representation en C++ du "GAME OF LIFE"
 *
 * Universite du Quebec a Montreal
 *
 * Auteur: Patrick Pelletier (PELP29088609)
 *          <pp.pelletier@gmail.com>
 *
 * Fichier d'implantation de la classe Grille.
 */

#include <iostream>
#include "Grille.hpp"

// Nombre de lignes et de colonnes de la grille.
// Changer ces valeurs pour une taille de grille differente.
#define NBLIGNES    24
#define NBCOLONNES  80

using namespace std;

// Creation d'une grille. 
Grille :: Grille()
{
    this->lig = NBLIGNES;
    this->col = NBCOLONNES;

	// Creer dynamiquement l'espace pour la grille et initialise les cases a 0.
    this->tableau2d = new bool * [this->lig];
    for (int i = 0; i < this->lig; ++i)
    {
        this->tableau2d[i] = new bool[this->col];
        for (int j = 0; j < this->col; ++j)
        {
            this->tableau2d[i][j] = 0;
        }
    }
}

// Constructeur de copie d'une grille.
Grille :: Grille(const Grille& g)
{
    this->lig = g.getLig();
    this->col = g.getCol();

	// Creer dynamiquement l'espace pour la grille et affecte les valeurs des cases.
    tableau2d = new bool * [this->lig];
    for (int i = 0; i < this->lig; ++i)
    {
        this->tableau2d[i] = new bool[this->col];
        for (int j = 0; j < this->col; ++j)
        {
            this->tableau2d[i][j] = g.getCell(i, j);
        }
    }
}

// Destruction de la grille.
Grille :: ~Grille()
{
	// Supprime l'espace creer dynamiquement de la grille.
    for (int i = 0; i < this->lig; ++i)
    {
        delete[] this->tableau2d[i];
    }
    delete[] this->tableau2d;
}

// Retourne le nombre de lignes de la grille.
int Grille :: getLig() const
{
    return this->lig;
}

// Retourne le nombre de colonnes de la grille.
int Grille :: getCol() const
{
    return this->col;
}

// Affichage de la grille.
void Grille :: afficher() const
{
	// Parcours de la grille
    for (int i = 0; i < this->lig; ++i)
    {
        cout << '\n';
        for (int j = 0; j < this->col; ++j)
        {
			// Affichage d'une case selon sa valeur.
            if (getCell(i,j) == 1)
                cout << '*';
            else
                cout << ' ';
        }
    }
    cout << '\n';
}

// Retourne la valeur d'une case.
bool Grille :: getCell(int lig, int col) const
{
    return this->tableau2d[lig][col];
}

// Affecte une valeur a une case.
void Grille :: setCell(bool valeur, int lig, int col)
{
    this->tableau2d[lig][col] = valeur;
}

// Redefinition de l'operateur =.
Grille& Grille :: operator=(const Grille& g)
{
	// Si la grille est celle-ci, on la retourne.
    if (this == &g)
        return *this;

    this->lig = g.getLig();
    this->col = g.getCol();

	// Supprime l'espace de cette grille.
    for (int i = 0; i < this->lig; ++i)
    {
        delete[] this->tableau2d[i];
    }
    delete[] this->tableau2d;

	// Allocation de l'espace pour la grille.
    tableau2d = new bool * [this->lig];
    for (int i = 0; i < this->lig; ++i)
    {
        this->tableau2d[i] = new bool[this->col];
    }

	// Affectation des valeurs des cellules correspondant a g.
    for (int i = 0; i < this->lig; ++i)
    {
        for (int j = 0; j < this->col; ++j)
        {
            this->tableau2d[i][j] = g.getCell(i, j);
        }
    }

    return *this;
}
