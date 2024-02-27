all:
	g++ -I src/inc -L src/lib -o main main.cpp -F /Library/Frameworks -framework SDL2 -framework SDL2_image