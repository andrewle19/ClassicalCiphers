output: cipher.o PlayFair.o RowTransposition.o Ceasar.o
	g++ $^ -o cipher
cipher.o: cipher.cpp
	g++ -c cipher.cpp
PlayFair.o: PlayFair.cpp PlayFair.h
	g++ -c PlayFair.cpp
RowTranspostion.o: RowTranspostion.cpp RowTranspostion.h
	g++ -c RowTranspostion.cpp
Ceasar.o: Ceasar.cpp Ceasar.h
	g++ -c Ceasar.cpp
clean:
	rm *.o output
