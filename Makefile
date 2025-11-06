
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

PREF_SRC = 	./src/
PREF_OBJ =  ./obj/
PREF_BIN =  ./bin/

SRC = $(wildcard $(PREF_SRC)*.c)
OBJ = $(patsubst $(PREF_SRC)%.c, $(PREF_OBJ)%.o, ${SRC})
TARGET = $(PREF_BIN)demo

all : ${TARGET}

$(TARGET) : $(OBJ)
	@@$(CC) $(OBJ) -o $(TARGET)

$(PREF_OBJ)%.o : $(PREF_SRC)%.c
	@@$(CC) $(CFLAGS) -c $< -o $@


clean:
	@rm $(TARGET) $(PREF_OBJ)*.o

rebuild: clean all