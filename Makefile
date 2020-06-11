CC = /usr/bin/g++
SRC = sw*.cpp
OBJ = $(SRC:.cpp=.o) 
CFLAGS = -std=c++11 -g
LDFLAGS = -lcurl -ljson-c -lcurses
EXE=stickweather

all: $(SRC) $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $^

clean:
	rm $(OBJ) $(EXE)
  
