/* INF3105 - Travail Pratique #1
 * Representation en C++ du "GAME OF LIFE"
 *
 * Universite du Quebec a Montreal
 *
 * Auteur: Patrick Pelletier (PELP29088609)
 *          <pp.pelletier@gmail.com>
 *
 * Fichier d'interface de la classe de la grille.
 */

#ifndef GRILLE_HPP
#define GRILLE_HPP

/* Represente une grille de jeu.
 *
 * Implante les services principaux pour un tableau dynamique 2d
 * de booleen.
 * Le tableau est instancier a 80x24 par defaut.
 */
class Grille
{

public:

	/* Construit une grille de jeu de 80x24 dynamiquement. */
    Grille();

	/* Construit dynamiquement une copie d'une grille passee en parametre. */
    Grille(const Grille& g);

	/* Detruit la grille. */
    ~Grille();

	/* Retourne le nombre de lignes de la grille. */
    int getLig() const;

	/* Retourne le nombre de colonnes de la grille. */
    int getCol() const;

	/* Affiche la grille.
	 *
	 * Les cases dont la valeur booleenne est vrai son representees par des '*'.
	 */
    void afficher() const;

	/* Retourne la valeur booleenne d'une case.
	 *
	 * Parametres:	lig: la ligne de la case
	 *				col: la colonne de la case
	 * Retourne: la valeur booleenne de la case
	 */
    bool getCell(int lig, int col) const;

	/* Affecte une nouvelle valeur a une case.
	 *
	 * Parametres:	valeur: la nouvelle valeur booleenne
	 *				lig: la ligne de la case
	 *				col: la colonne de la case
	 */
    void setCell(bool valeur, int lig, int col);
    
	/* Redefinit l'operateur = pour une grille.
	 *
	 * Supprime l'ancienne grille, en creer une nouvelle dynamiquement
	 * et copie le contenu de celle a egaliser dans la nouvelle creer.
	 *
	 * Parametres:	g: la grille a egaliser
	 * Retourne: la nouvelle grille egale a celle passee en parametre
	 */
	Grille& operator=(const Grille& g);

private:

    bool **tableau2d; 	// tableau de la grille de jeu
    int lig;			// nombre de lignes de la grille
    int col;			// nombre de colonnes de la grille

};

#endif

