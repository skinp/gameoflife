# INF3105 - Travail Pratique #1 
# Auteur: Patrick Pelletier (PELP29088609)
# 			<pp.pelletier@gmail.com>
#
# Makefile simple pour le "Game of life"

CC = g++
CFLAGS = -g -W -Wall
SRCDIR = src
BINDIR = bin

all: gameoflife

gameoflife: $(SRCDIR)/gameoflife.o $(SRCDIR)/Grille.o $(SRCDIR)/Jeu.o $(SRCDIR)/PortableSleep.o
	$(CC) $(CFLAGS) -o $(BINDIR)/gameoflife $(SRCDIR)/gameoflife.o $(SRCDIR)/Grille.o $(SRCDIR)/Jeu.o $(SRCDIR)/PortableSleep.o

$(SRCDIR)/gameoflife.o: $(SRCDIR)/gameoflife.cpp $(SRCDIR)/Grille.hpp $(SRCDIR)/Jeu.hpp

$(SRCDIR)/Grille.o: $(SRCDIR)/Grille.cpp

$(SRCDIR)/PortableSleep.o: $(SRCDIR)/PortableSleep.cpp

$(SRCDIR)/Jeu.o: $(SRCDIR)/Jeu.cpp $(SRCDIR)/Grille.hpp $(SRCDIR)/PortableSleep.hpp

clean:
	rm $(BINDIR)/gameoflife $(SRCDIR)/*.o
