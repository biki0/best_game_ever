all:
	g++ -IInclude -Llib -o main src/*.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_mixer -lSDL2_image 

