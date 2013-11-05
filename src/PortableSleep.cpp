#include "PortableSleep.hpp"

/*
 * Auteur: Eric Wenaas
 * Date:   20 janvier 2008
 */

#ifdef WIN_32

#include <windows.h>
void sleepMilis(int miliseconds)
{
    Sleep(static_cast<DWORD>(miliseconds));
}

#else

#include <unistd.h>
void sleepMilis(int miliseconds)
{
    usleep(1000 * miliseconds);
}

#endif
