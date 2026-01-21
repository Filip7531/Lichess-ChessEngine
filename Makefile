CXX = g++
CXXFLAGS = -std=c++17 -Wall
DEPS = DataTypes.h Utils.h Evaluation.h Hash.h Moves.h BoardUtils.h Bot.h
OBJ = main.o Utils.o Evaluation.o Hash.o Moves.o BoardUtils.o Bot.o

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

ChessEngine: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

clean:
	rm -f *.o ChessEngine
