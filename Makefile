CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb

BIN       := bin
SRC       := src
INCLUDE   := inc
RESOURCES := res
OBJ       := obj

LIBRARIES   := lib
EXECUTABLE  := main

SRC_FILES   := $(wildcard $(SRC)/*.cpp)
OBJ_FILES   := $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRC_FILES))

all: $(BIN)/$(EXECUTABLE) copy_resources

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

$(OBJ)/%.o: $(SRC)/%.cpp
	mkdir -p $(OBJ)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -c $< -o $@

copy_resources:
	mkdir -p $(BIN)/$(RESOURCES)
	cp -r $(RESOURCES)/* $(BIN)/$(RESOURCES)

clean:
	-rm -rf $(BIN)/*
	-rm -rf $(OBJ)/*

