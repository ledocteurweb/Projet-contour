#############################################################################
# Fichier Makefile 
# UE MAP401 - DLST - UGA - 2024/2025
#############################################################################

#############################################################################
# definition des variables locales
#############################################################################

# compilateur C
CC = clang

# chemins d'acces aux interfaces (.h)
INCDIR = . ../../S04/TACHE1 ../../S04/TACHE2

# chemins d'acces aux binaires
LIBDIR = .

# options pour l'edition des liens
LDOPTS = -L$(LIBDIR) -lm

# options pour la recherche des fichiers .h
INCLUDEOPTS = $(foreach dir,$(INCDIR),-I$(dir))

# options de compilation
COMPILOPTS = -g -Wall $(INCLUDEOPTS)

# liste des executables
EXECUTABLES = test_contour


#############################################################################
# definition des regles
#############################################################################

########################################################
# regle par defaut
all : $(EXECUTABLES)

########################################################
# regle generique de compilation
%.o : %.c %.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module "$*
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<


########################################################
# regles explicites de compilation des modules

sequence.o : sequence.c sequence.h ../../S04/TACHE2/geometrie2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module sequence"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

contour.o : contour.c contour.h sequence.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module contour"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_contour.o : test_contour.c contour.h sequence.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_contour"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<


image.o : ../../S04/TACHE1/image.c ../../S04/TACHE1/image.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module image"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $< -o $@

geometrie2d.o : ../../S04/TACHE2/geometrie2d.c ../../S04/TACHE2/geometrie2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module geometrie2d"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $< -o $@


########################################################
# regle de creation de l'executable
test_contour : test_contour.o contour.o image.o geometrie2d.o sequence.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@


########################################################
# nettoyage
clean:
	rm -f $(EXECUTABLES) *.o

.PHONY: all clean

