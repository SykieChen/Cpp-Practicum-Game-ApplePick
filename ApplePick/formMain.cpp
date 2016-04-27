#include "apple.h"

formMain::formMain(LPCTSTR usrName, int width, int height, IMAGE* bg,
	IMAGE* bt_play, IMAGE* bt_pause, IMAGE* bt_stop, IMAGE* bt_exit, IMAGE* bt_hs, IMAGE* btx) :
	lbUsrName(150, 20, 50, 5, bg),
	lbTime(150, 20, 250, 5, bg),
	lbScore(150, 20, 450, 5, bg),
	lbHighScore(150, 20, 650, 5, bg),
	btPlay(btx->getwidth(), btx->getheight(), 35, 540, bt_play, btx),
	btPause(btx->getwidth(), btx->getheight(), 188, 540, bt_pause, btx),
	btStop(btx->getwidth(), btx->getheight(), 341, 540, bt_stop, btx),
	btExit(btx->getwidth(), btx->getheight(), 494, 540, bt_exit, btx),
	btHs(btx->getwidth(), btx->getheight(), 647, 540, bt_hs, btx)
{

	initgraph(800, 600);
	//paint bg
	putimage(0, 0, bg);
	//init boxes
	wchar_t txt[40];
	swprintf_s(txt, L"Player: %s", usrName);
	lbUsrName.setText(txt);
	swprintf_s(txt, L"Time: %d", time);
	lbTime.setText(txt);
	swprintf_s(txt, L"Score: %d", score);
	lbScore.setText(txt);
	swprintf_s(txt, L"High Score: %d", highScore);
	lbHighScore.setText(txt);

	//buttons
	btPlay.show();
	btPause.show();
	btStop.show();
	btExit.show();
	btHs.show();

}

formMain::~formMain() {
	closegraph();
}

int formMain::getTime() {
	return time;
}
void formMain::setTime(int time) {
	this->time = time;
	wchar_t txt[40];
	swprintf_s(txt, L"Time: %d", time);
	this->lbTime.setText(txt);
}
int formMain::getScore() {
	return score;
}
void formMain::setScore(int score) {
	this->score = score;
	wchar_t txt[40];
	swprintf_s(txt, L"Score: %d", score);
	this->lbScore.setText(txt);
}
int formMain::getHighScore() {
	return highScore;
}
void formMain::setHighScore(int hs) {
	this->highScore = hs;
	wchar_t txt[40];
	swprintf_s(txt, L"High Score: %d", highScore);
	this->lbHighScore.setText(txt);
}