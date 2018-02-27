cipher: cipher.o PlayFair.o RowTransposition.o Ceasar.o RailFence.o Vigenere.o 
	g++ $^ -o cipher
cipher.o: cipher.cpp
	g++ -c cipher.cpp
PlayFair.o: PlayFair.cpp PlayFair.h
	g++ -c PlayFair.cpp
RowTransposition.o: RowTransposition.cpp RowTransposition.h
	g++ -c RowTransposition.cpp
Ceasar.o: Ceasar.cpp Ceasar.h
	g++ -c Ceasar.cpp
RailFence.o: RailFence.cpp
	g++ -c RailFence.cpp RailFence.h
Vigenere.o : Vigenere.cpp Vigenere.h
	g++ -c Vigenere.cpp
clean:
	rm *.o cipher
