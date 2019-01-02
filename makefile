BINNAME=PrettyPoem
CC=g++
SRCDIR=src
SETDIR=settings
FLAGS=-O0
COLORS=White,Black\\nWhite,Red\\nWhite,Magenta\\nBlack,Salmon\\nBlack,SpringGreen\\nSalmon,Black\\nLavender,Black\\nBlack,CornflowerBlue\\nCornflowerBlue,Black\\nBlack,White\\nCadetBlue,White\\nSepia,White\\nRedViolet,White\\nApricot,Black
COLORFILENAME=settings/colors
FONTSFILENAME=settings/fonts

make: $(SRCDIR)/main.o $(SRCDIR)/InputSanitizer.o $(SRCDIR)/Poemifier.o 
	$(CC) $(SRCDIR)/main.o $(SRCDIR)/InputSanitizer.o $(SRCDIR)/Poemifier.o $(FLAGS) -o $(BINNAME)
	
	#check if settings folder exists
ifeq (,$(wildcard $(SETDIR)))
	mkdir $(SETDIR)
endif
	
	touch $(FONTSFILENAME)
	@printf $(COLORS) > $(COLORFILENAME)
	
	rm $(SRCDIR)/main.o $(SRCDIR)/Poemifier.o $(SRCDIR)/InputSanitizer.o
	
InputSanitizer.o: $(SRCDIR)/InputSanitizer.o 
	$(CC) $(SRCDIR)/InputSanitizer.o $(FLAGS)
	
Poemifier.o: $(SRCDIR)/Poemifier.cpp 
	$(CC) $(SRCDIR)/Poemifier.cpp $(FLAGS)

main.o: $(SRCDIR)/main.cpp
	$(CC) $(SRCDIR)/main.cpp $(FLAGS)	

clean:
	rm $(BINNAME) $(SETDIR)/*
