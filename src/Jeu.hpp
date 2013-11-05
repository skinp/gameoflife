/* INF3105 - Travail Pratique #1
 * Representation en C++ du "GAME OF LIFE"
 *
 * Universite du Quebec a Montreal
 *
 * Auteur: Patrick Pelletier (PELP29088609)
 *          <pp.pelletier@gmail.com>
 *
 * Fichier d'interface de la classe de jeu.
 */

#ifndef JEU_HPP
#define JEU_HPP

#include "Grille.hpp"

/* Implante les services pour le "Game of life"
 *
 * Tout le deroulement du Jeu se passe dans cette class.
 * Pour initialiser un Jeu, il faut simplement instancier un objet
 * de cette classe et initialiser le Jeu en appelant la fonction jouer().
 */
class Jeu
{

public:

    /* Construit un jeu de "Game of life".
     *
     * Parametres:  grille: la grille initiale du Jeu
     *              nbGenerations: nombre de generations
     *              attente: temps d'attente entre les generations
     */
    Jeu(Grille *grille, int nbGenerations, int attente);

    /* Joue une partie de "Game of life".
     *
     * On affiche la grille, attend un delai et met la grille a jour.
     * On recommence autant de fois que le nbGenerations.
     */
    void jouer();


private:

    Grille grille;      // la grille du jeu
    int nbGenerations;  // le nombre de generation du jeu
    int attente;        // le temps d'attente entre chaque generation

    /* Calcule et renvoit une grille mis-a-jour de la prochaine generation
     * du jeu.
     *
     * Parcours la grille du jeu et met a jour chaque cellule de celle-ci
     * en respectant les regles du "Game of life".
     * On doit creer une grille temporaire pour sauvegarder les cellules
     * mis a jour de la prochaine generation.
     *
     * Retourne: la grille mis a jour de la prochaine generation.
     */
    Grille majGrille();

    /* Calcul et renvoit le nombre de voisin d'une cellule de la grille.
     *
     * Dependemment l'endroit ou on se trouve dans la grille, on additionne
     * la valeur des cellules qui entoure celle dont on veut connaitre le
     * nombre de voisin.
     * On doit s'assurer de l'endroit ou on est dans la grille pour ne pas
     * essayer d'acceder un espace memoire qui n'est pas reserve a la
     * grille. Par exemple, les coins sont problematique. On doit seulement
     * calculer les 3 cases adjacentes au coin qui font reelement partie
     * de la grille.
     *
     * Parametres:  lig: la ligne de la cellule
     *              col: la colonne de la cellule
     * Retourne: le nombre de cellule vivante adjacente
     */
    int getNbVoisins(int lig, int col) const;
};

#endif
