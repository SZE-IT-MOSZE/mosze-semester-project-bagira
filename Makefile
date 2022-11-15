OBJS := main.o Game.o Page.o Option.o
COMP := g++ -Wall -std=c++17
IDIR := include/

snowattack: $(OBJS)
	$(COMP) -o snowattack $(OBJS)

main.o: main.cpp $(IDIR)Game.h
	$(COMP) -c main.cpp

Game.o: $(IDIR)Game.cpp $(IDIR)Game.h $(IDIR)Json.h $(IDIR)Page.h $(IDIR)Option.h
	$(COMP) -c $(IDIR)Game.cpp

Page.o: $(IDIR)Page.cpp $(IDIR)Page.h $(IDIR)Option.h
	$(COMP) -c $(IDIR)Page.cpp

Option.o: $(IDIR)Option.cpp $(IDIR)Option.h 
	$(COMP) -c $(IDIR)Option.cpp

clean:
	rm -rf *.o snowattack