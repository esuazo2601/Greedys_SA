# Nombre del ejecutable para Greedy
GREEDY_EXECUTABLE = Greedy

# Nombre del ejecutable para Greedy Probabilista
GREEDY_PROBABILISTA_EXECUTABLE = greedy-probabilista

# Lista de archivos fuente para Greedy
GREEDY_SOURCE = Greedy.cpp

# Lista de archivos fuente para Greedy Probabilista
GREEDY_PROBABILISTA_SOURCE = greedy-probabilista.cpp

# Comando de compilación
CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: $(GREEDY_EXECUTABLE) $(GREEDY_PROBABILISTA_EXECUTABLE)

$(GREEDY_EXECUTABLE): $(GREEDY_SOURCE)
	$(CXX) $(CXXFLAGS) -o $@ $(GREEDY_SOURCE)

$(GREEDY_PROBABILISTA_EXECUTABLE): $(GREEDY_PROBABILISTA_SOURCE)
	$(CXX) $(CXXFLAGS) -o $@ $(GREEDY_PROBABILISTA_SOURCE)

clean:
	rm -f $(GREEDY_EXECUTABLE) $(GREEDY_PROBABILISTA_EXECUTABLE)
