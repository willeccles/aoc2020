BDIR = bin
SDIR = .

SRC = $(wildcard $(SDIR)/*.c)
OBJ = $(patsubst $(SDIR)/%.c,$(BDIR)/%.o,$(SRC))

CFLAGS += -O3 -std=c11 -Wall -W -pedantic -Werror

all: $(OBJ)

$(BDIR)/%.o: $(SDIR)/%.c | $(BDIR)
	$(CC) $(CFLAGS) -o $@ $?

$(BDIR):
	mkdir $(BDIR)

clean:
	$(RM) -r $(BDIR)
