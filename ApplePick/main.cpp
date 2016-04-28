#include "apple.h"


int main() {
	fstream inFile;
	inFile.open("saved.txt", ios::in);
	char savedName[50];
	int savedScore = 0;
	inFile >> savedName >> savedScore;
	inFile.close();

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
	man GTQ(100, 470, &iman, &imanx, &bg);

	//put saved highscore
	frMain.setHighScore(savedScore);

	//lists of blocks
	blockList list1(320, true, 3, &tree0, &tree1, &treex, &iblock, &iblockx, &bg);
	blockList list2(175, false, 3, &tree0, &tree1, &treex, &iblock, &iblockx, &bg);
	blockList list3(30, true, 3, &tree0, &tree1, &treex, &iblock, &iblockx, &bg);

	//flags
	bool isExiting = false;
	bool isPlaying = false;
	bool gameOver = false;
	clock_t kbDelay = clock();
	clock_t gameTime = 0;
	clock_t animDelay = clock();

	MOUSEMSG mouseMsg = GetMouseMsg();

	//main loop
	while (!isExiting) {
		//Sleep(1);	//prevent high CPU useage
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
						GTQ.isOnGround = true;
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
					//deal with fucking wstr
					size_t len = strlen(savedName) + 1;
					size_t converted = 0;
					wchar_t *WStr;
					WStr = (wchar_t*)malloc(len * sizeof(wchar_t));
					mbstowcs_s(&converted, WStr, len, savedName, _TRUNCATE);
					wchar_t cont[100];
					swprintf_s(cont, L"%s\t%d", WStr, savedScore);
					MessageBox(NULL, cont, TEXT("High Score"), MB_ICONINFORMATION | MB_OK);
					delete WStr;
				}
				else {
					//jump
					if (isPlaying && GTQ.isOnGround) GTQ.isJumping = true;
				}
			}

		}

		//game over?
		if (gameOver) {
			//update highscore
			if (frMain.getHighScore() < frMain.getScore()) {
				frMain.setHighScore(frMain.getScore());
				//write to file
				ofstream oFile;
				oFile.open("saved.txt");
				//switch wchar to char
				size_t len = wcslen(usrName) + 1;
				size_t converted = 0;
				char *CStr;
				CStr = (char*)malloc(len * sizeof(char));
				wcstombs_s(&converted, CStr, len, usrName, _TRUNCATE);

				oFile << CStr << '\n' << frMain.getHighScore() << '\n';
				oFile.close();
				strcpy_s(savedName, CStr);
				savedScore = frMain.getHighScore();
				delete CStr;
			}
			//reset game
			list1.clear();
			list2.clear();
			list3.clear();
			repaintBlock(0, 30, 800, 530, &bg);
			XD.reset(735, 430);
			GTQ.reset(100, 470);
			frMain.setScore(0);
			frMain.setTime(60);
			isPlaying = false;
			gameOver = false;
		}
		else {
			if (isPlaying) {
				//in game
				//check keyboard
				if (_kbhit()) {
					//dont loop too fast
					if (clock() - kbDelay > 6) {
						kbDelay = clock();	//refresh time
						if ((GetAsyncKeyState(VK_LEFT) & 0x8000) && GTQ.getX() >= 0) {
							BeginBatchDraw();
							GTQ.hide();
							list1.show();
							list2.show();
							list3.show();
							XD.show();
							GTQ.moveL();
							//checkOnGround(&GTQ, &list1, &list2, &list3);
							EndBatchDraw();
						}
						else if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) && GTQ.getX() + GTQ.getW() <= 800) {
							BeginBatchDraw();
							GTQ.hide();
							list1.show();
							list2.show();
							list3.show();
							XD.show();
							GTQ.moveR();
							//checkOnGround(&GTQ, &list1, &list2, &list3);
							EndBatchDraw();
						}
						else if (GetAsyncKeyState(VK_UP) & 0x8000) {
							if (GTQ.isOnGround) GTQ.isJumping = true;
						}
						else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
							if (GTQ.getY() < 470) GTQ.isOnGround = false;
						}
						else if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
							if (getApple(&GTQ, &list1, &list2, &list3)) {
								//got an apple
								if (XD.ifCaught(&GTQ)) {
									gameOver = true;
									MessageBox(NULL, TEXT("Game Over\nYou were caught!"), TEXT("Game Over"), MB_ICONINFORMATION | MB_OK);
								}
								else frMain.setScore(frMain.getScore() + 1);	//get score
							}
						}
					}
				}
				//refresh time
				if (clock() - gameTime >= 1000) {
					gameTime = clock();
					frMain.setTime(frMain.getTime() - 1);
					if (frMain.getTime() == 0) {
						gameOver = true;
						MessageBox(NULL, TEXT("Game Over\nTime up!"), TEXT("Game Over"), MB_ICONINFORMATION | MB_OK);
					}
				}
				//anims
				if ((clock() - animDelay) >= 30) {
					BeginBatchDraw();
					animDelay = clock();
					//release trees
					if (list1.tail->item.getX() >= 0) list1.addNode(rand() % 2, 70 + rand() % 100);
					if (list3.tail->item.getX() >= 0) list3.addNode(rand() % 2, 70 + rand() % 100);
					if (list2.tail->item.getX() <= 800 - list2.tail->item.getW()) list2.addNode(rand() % 2, 70 + rand() % 100);

					//hide objects
					list1.hide();
					list2.hide();
					list3.hide();
					GTQ.hide();
					XD.hide();
					//move trees
					list1.move();
					list2.move();
					list3.move();
					if (GTQ.isOnGround && GTQ.getY() < 470) {
						//man is on moving block
						if (GTQ.getY() == 215) GTQ.moveL();	//2nd row
						else GTQ.moveR();	//1st and 3rd row
						//if out of bound, die
						if (GTQ.getX() < 0 || GTQ.getX() > 800 - GTQ.getW()) {
							gameOver = true;
							MessageBox(NULL, TEXT("Game Over\nYou moved out of field!"), TEXT("Game Over"), MB_ICONINFORMATION | MB_OK);
						}
					}



					//check if man is still on blocks
					if (checkOnGround(&GTQ, &list1, &list2, &list3) == NULL && GTQ.getY() < 470)
						GTQ.isOnGround = false;

					//move bear
					XD.move(70, 430);


					//man jump up
					if (GTQ.isJumping) {
						GTQ.isOnGround = false;
						GTQ.jump();
						//check range
						if (GTQ.getPxJumped() >= 180 || GTQ.getY() <= 10) GTQ.isJumping = false;
						//man's top near whose bottom
						checkBlockBottom(&GTQ, &list1);
						checkBlockBottom(&GTQ, &list2);
						checkBlockBottom(&GTQ, &list3);

					}
					else if (GTQ.isOnGround == false) {
						//man falling
						GTQ.fall();
						//if dropped more than 240px, die
						if (GTQ.getPxFallen() > 240) {
							gameOver = true;
							MessageBox(NULL, TEXT("Game Over\nYou have fallen for more than one level!"), TEXT("Game Over"), MB_ICONINFORMATION | MB_OK);
						}
						//check base ground
						if (GTQ.getY() >= 470) {
							GTQ.setY(470);
							GTQ.isOnGround = true;
						}
						//man's bott near whose top
						checkBlockTop(&GTQ, &list1);
						checkBlockTop(&GTQ, &list2);
						checkBlockTop(&GTQ, &list3);

					}

					//repaint man
					GTQ.show();



					//del trees
					if (list1.head->next->item.getX() > 800) list1.delNode();
					if (list2.head->next->item.getX() + list2.head->next->item.getW() < 0) list2.delNode();
					if (list3.head->next->item.getX() > 800) list3.delNode();
					EndBatchDraw();
				}



			}
		}

	}



	//pressed exit

	//_getch();
	return 0;
}