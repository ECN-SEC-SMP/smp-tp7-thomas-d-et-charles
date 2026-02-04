CXX = g++
CXXFLAGS = -Wall -g -std=c++17
EXEC = tp7_exec
OBJS = main.o tests.o Point.o Forme.o Cercle.o Rectangle.o Carre.o ListeFormes.o

$(EXEC) : $(OBJS)
	$(CXX) -o $@ $^

# Les dépendances entre headers et fichiers sources
main.o : ListeFormes.h Forme.h Point.h
tests.o : ListeFormes.h Forme.h Point.h
Point.o : Point.h
Forme.o : Forme.h Point.h
Cercle.o : Forme.h Point.h
Rectangle.o : Forme.h Point.h
Carre.o : Forme.h Point.h
ListeFormes.o : ListeFormes.h Forme.h Point.h

clean :
	rm -f $(OBJS) $(EXEC)

.PHONY: clean rebuild