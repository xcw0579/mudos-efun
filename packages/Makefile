
SRC=contrib.c sockets.c mongo.c develop.c math.c 
OBJ=contrib.$(O) sockets.$(O) mongo.$(O) develop.$(O) math.$(O) 

.c.$(O):
	$(CC) $(CFLAGS) -I.. -c $*.c

all: $(OBJ)
	ar rcu packages.$(A) $(OBJ)
	$(RANLIB) packages.$(A)

clean:
	rm -f *.$(O)
	rm -f packages.$(A)
