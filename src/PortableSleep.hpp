#ifndef PORTABLE_SLEEP_HPP_
#define PORTABLE_SLEEP_HPP_


/* PortableSleep.hpp
 *
 * fichier qui d�finit une fonction de pause pouvant �tre utilis�e sur Windows XP
 * et Linux Ubuntu.  La fonction n'a pas �t� test�e sur d'autres plate-formes.
 *
 * La fonction est incompl�te puisqu'elle ne retourne pas le temps r�ellement attendu
 * en cas d'interruption mais elle r�pond � un besoin sp�cifique. 
 *
 * Auteur: Eric Wenaas (ewenaas@videotron.ca)
 * Date:   20 janvier 2008
 */
 
void sleepMilis(int miliseconds);

#endif 
