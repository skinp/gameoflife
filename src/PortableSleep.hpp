#ifndef PORTABLE_SLEEP_HPP_
#define PORTABLE_SLEEP_HPP_


/* PortableSleep.hpp
 *
 * fichier qui définit une fonction de pause pouvant être utilisée sur Windows XP
 * et Linux Ubuntu.  La fonction n'a pas été testée sur d'autres plate-formes.
 *
 * La fonction est incomplète puisqu'elle ne retourne pas le temps réellement attendu
 * en cas d'interruption mais elle répond à un besoin spécifique. 
 *
 * Auteur: Eric Wenaas (ewenaas@videotron.ca)
 * Date:   20 janvier 2008
 */
 
void sleepMilis(int miliseconds);

#endif 
