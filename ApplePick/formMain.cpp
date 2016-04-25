#include "apple.h"

formMain::formMain(int width, int height, IMAGE* bg,
	IMAGE* bt_play, IMAGE* bt_pause, IMAGE* bt_stop, IMAGE* bt_exit, IMAGE* bt_hs, IMAGE* btx) :
	play(btx->getwidth(), btx->getheight(), 35, 560, bt_play, btx),
	pause(btx->getwidth(), btx->getheight(), 188, 560, bt_pause, btx),
	stop(btx->getwidth(), btx->getheight(), 341, 560, bt_stop, btx),
	exit(btx->getwidth(), btx->getheight(), 494, 560, bt_exit, btx),
	hs(btx->getwidth(), btx->getheight(), 647, 560, bt_hs, btx)
{

	initgraph(800, 600);

}