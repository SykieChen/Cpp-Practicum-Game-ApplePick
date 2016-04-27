#include "apple.h"

int main() {
	MessageBox(NULL, TEXT("这是对话框"), TEXT("你好"), MB_ICONINFORMATION | MB_OK);
	srand((unsigned)time(NULL));
	//load resources
	IMAGE bg, ibear, ibearx, iman, imanx, iblock, iblockx, tree0, tree1, treex;
	IMAGE bt_play, bt_pause, bt_stop, bt_exit, bt_hs, btx;
	loadimage(&bg, L"img\\bg.jpg");
	loadimage(&ibear, L"img\\bear.jpg");
	loadimage(&ibearx, L"img\\bearx.jpg");
	loadimage(&iman, L"img\\man.jpg");
	loadimage(&imanx, L"img\\manx.jpg");
	loadimage(&iblock, L"img\\block.jpg");
	loadimage(&iblockx, L"img\\blockx.jpg");
	loadimage(&tree0, L"img\\tree0.jpg");
	loadimage(&tree1, L"img\\tree1.jpg");
	loadimage(&treex, L"img\\treex.jpg");
	loadimage(&bt_play, L"img\\bt_play.bmp");
	loadimage(&bt_pause, L"img\\bt_pause.bmp");
	loadimage(&bt_stop, L"img\\bt_stop.bmp");
	loadimage(&bt_exit, L"img\\bt_exit.bmp");
	loadimage(&bt_hs, L"img\\bt_hs.bmp");
	loadimage(&btx, L"img\\btx.bmp");
	//get name
	wchar_t usrName[20];
	while (!InputBox(usrName, 20, L"Please input your name:", L"Input name") || !wcscmp(usrName, L""));
	//init
	formMain frMain(usrName, 800, 600, &bg, &bt_play, &bt_pause, &bt_stop, &bt_exit, &bt_hs, &btx);
	bear XD(735, 430, &ibear, &ibearx, &bg);
	man GTQ(400, 470, &iman, &imanx, &bg);


	//lists of blocks
	blockList list1(320, true, 1, &tree0, &tree1, &treex, &iblock, &iblockx, &bg);
	blockList list2(175, false, 1, &tree0, &tree1, &treex, &iblock, &iblockx, &bg);
	blockList list3(30, true, 1, &tree0, &tree1, &treex, &iblock, &iblockx, &bg);

	//flags
	bool isExiting = false;
	bool isPlaying = false;
	bool gameOver = false;
	clock_t kbDelay = clock();
	clock_t gameTime = 0;

	MOUSEMSG mouseMsg = GetMouseMsg();

	//main loop
	while (!isExiting) {
		//check mouse
		if (MouseHit()) {
			mouseMsg = GetMouseMsg();
			if (mouseMsg.uMsg == WM_LBUTTONDOWN) {
				//clicked
				if (frMain.btExit.chkRange(mouseMsg.x, mouseMsg.y)) {
					//clicked exit
					isExiting = true;
				}
				else if (frMain.btPlay.chkRange(mouseMsg.x, mouseMsg.y)) {
					//clicked play
					if (!isPlaying) {
						isPlaying = true;
						gameTime = clock();
						frMain.setTime(60);
						frMain.setScore(0);
					}
				}
				else if (frMain.btPause.chkRange(mouseMsg.x, mouseMsg.y)) {
					//clicked pause
					if (isPlaying) pause(&frMain);
				}
				else if (frMain.btStop.chkRange(mouseMsg.x, mouseMsg.y)) {
					//clicked stop
					if (isPlaying) gameOver = true;
				}
				else if (frMain.btHs.chkRange(mouseMsg.x, mouseMsg.y)) {
					//high score
				}
				else {
					//jump
					if (isPlaying) GTQ.isJumping = true;
				}
			}

		}

		//game over?
		/*if (gameOver) {
			//update highscore
			//reset game
			isPlaying = false;
			gameOver = false;
		}
		else {
			if (isPlaying) {
				//in game
				//check keyboard
				if (_kbhit()) {
					//dont loop too fast
					if (clock() - kbDelay > 1) {
						kbDelay = clock();	//refresh time
						if (GetAsyncKeyState(VK_LEFT) & 0x8000)
							GTQ.moveL();
						else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
							GTQ.moveR();
						else if (GetAsyncKeyState(VK_UP) & 0x8000)
							GTQ.isJumping = true;
						else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
							GTQ.isOnGround = false;
						else if (GetAsyncKeyState(VK_SPACE) & 0x8000)
							GTQ.isJumping = true;
					}
				}
				//refresh time
				//if (gameTime == 0) gameTime = clock();	//the first second
				if (clock() - gameTime >= 1000) {
					gameTime = clock();
					frMain.setTime(frMain.getTime() - 1);
					if (frMain.getTime() == 0) {
						gameOver = true;
						
					}
				}



			}
		}
		*/
	}
	

	/*list1.addNode(true, 5);
	list2.addNode(true, 5);
	list3.addNode(true, 5);
	while (list1.tail->item.getX() < 800) {
		list1.move();
		list2.move();
		list3.move();
		Sleep(20);
	}
	list1.delNode();*/


	//pressed exit

	//_getch();
	return 0;
}