IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=../out
LDIR =../lib

LIBS=-lm

_DEPS = module.h event_manager.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = init.o module.o event_manager.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/evt: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
