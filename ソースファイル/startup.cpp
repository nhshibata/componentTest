/* コンポーネント指向の試し


*/

//
#include "game.h"
#include <stdio.h>
#include <windows.h>

//
int main()
{
	bool b = false;
	b = CGame::Start();
//	CGame* game = new CGame;
	if (b)
	{
		int n;
		n = 10;
	}
	else
	{
		int j;
		j = 10;
	}
	GAME->Init();
	while (!GetAsyncKeyState(VK_ESCAPE))
	{
		GAME->Update();
		getchar();
	}

	//
	CGame::End();
//	delete game;

	rewind(stdin);
	getchar();
	return 0;
}
