BINNAME=PrettyPoem
CC=g++
SRCDIR=src
SETDIR=settings
FLAGS=-O0
COLORS=White,Black\\nWhite,Red\\nWhite,Magenta\\nBlack,Salmon\\nBlack,SpringGreen\\nSalmon,Black\\nLavender,Black\\nBlack,CornflowerBlue\\nCornflowerBlue,Black\\nBlack,White\\nCadetBlue,White\\nSepia,White\\nRedViolet,White\\nApricot,Black
COLORFILENAME=settings/colors
FONTSFILENAME=settings/fonts

make: $(SRCDIR)/main.o $(SRCDIR)/Poemifier.o 
	$(CC) $(SRCDIR)/main.o $(SRCDIR)/Poemifier.o $(FLAGS) -o $(BINNAME)
	
ifeq (,$(wildcard $(SETDIR)))
	mkdir $(SETDIR)
	touch $(FONTSFILENAME)
endif
	
	@printf $(COLORS) > $(COLORFILENAME)
	
	rm $(SRCDIR)/main.o $(SRCDIR)/Poemifier.o 
	
Poemifier.o: $(SRCDIR)/Poemifier.cpp 
	$(CC) $(SRCDIR)/Poemifier.cpp $(FLAGS)
	
main.o: $(SRCDIR)/main.cpp
	$(CC) $(SRCDIR)/main.cpp $(FLAGS)	

clean:
	rm $(BINNAME) $(SRCDIR)/main.o $(SRCDIR)/Poemifier.o $(SETDIR)/*
