
SRC=contrib.c sockets.c mongo.c develop.c math.c 
OBJ=contrib.$(O) sockets.$(O) mongo.$(O) develop.$(O) math.$(O) 

OBJ=$(addprefix $(OBJDIR)/,$(subst .c,.o,$(SRC)))
LIBS=-I../libs 


$(OBJDIR)/%.o: %.c
	gcc -I$(OBJDIR) -I.. $(LIBS)   -o $@ -c $<

all: $(OBJ)
	ar rcu packages.$(A) $(OBJ)
	$(RANLIB) packages.$(A)

clean:
	rm -f *.$(O)
	rm -f packages.$(A)
