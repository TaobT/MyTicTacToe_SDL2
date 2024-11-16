#include "GameApp.h"

int main(int argc, char* argv[]) {
	GameApp gameApp;
	gameApp.Initialize("Tic Tac Toe", 800, 600);
	gameApp.Run();
	gameApp.Clean();
	return 0;
}