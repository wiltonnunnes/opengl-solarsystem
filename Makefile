main: main -lglut -lGL -lGLU -lm
	g++ -o main main.cpp -lglut -lGL -lGLU -lm

clean: main
	rm main