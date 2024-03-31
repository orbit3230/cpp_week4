FLAGS = -Werror

main.exe : main.o input_process.o database.o database.h
	g++ -o main.exe main.o input_process.o database.o

main.o : main.cpp
	g++ ${FLAGS} -c main.cpp

input_process.o : input_process.cpp
	g++ ${FLAGS} -c input_process.cpp

database.o : database.cpp database.h
	g++ ${FLAGS} -c database.cpp

clean :
	rm *.o
	rm main