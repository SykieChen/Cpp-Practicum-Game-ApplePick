#include "apple.h"

int main() {
	//load resources
	IMAGE bg, bear, bearx, man, manx, block, blockx, tree0, tree1, treex;
	IMAGE bt_play, bt_pause, bt_stop, bt_exit, bt_hs, btx;
	loadimage(&bg, L"img\\bg.jpg");
	loadimage(&bear, L"img\\bear.jpg");
	loadimage(&bearx, L"img\\bearx.jpg");
	loadimage(&man, L"img\\man.jpg");
	loadimage(&manx, L"img\\manx.jpg");
	loadimage(&block, L"img\\block.jpg");
	loadimage(&blockx, L"img\\blockx.jpg");
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

	//lists of blocks
	blockList list1(350-151, true, 2, &tree0, &tree1, &treex, &block, &blockx, &bg);

	//main loop
	list1.addNode(true, 5);
	while (list1.tail->item.getX() < 800) {
		list1.move();
		Sleep(20);
	}
	list1.delNode();
	//_getch();
	return 0;
}