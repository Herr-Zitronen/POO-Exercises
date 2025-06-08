CC = g++
CFLAGS = -Wall -g
SRC = src/main.cpp src/Cliente.cpp src/Libro.cpp src/LibroFisico.cpp src/LibroElectronico.cpp src/Biblioteca.cpp src/Interfaz.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = biblioteca-app

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

#%.o: %.cpp
#$(CC) $(CFLAGS) -c $< -o $@

run : $(TARGET)
	./$(TARGET)

# Usa CMD por defecto:
clean:
	del /f /q $(TARGET).exe