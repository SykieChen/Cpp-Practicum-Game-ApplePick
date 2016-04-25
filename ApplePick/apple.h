#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <time.h>

void transimg(int, int, IMAGE*, IMAGE*);
void repaintBlock(int x1, int x2, int y1, int y2, IMAGE*);

class button
{
private:
	int width;
	int height;
	int x;
	int y;
	IMAGE* bg;
	IMAGE* bgx;
public:
	button(int w, int h, int x, int y, IMAGE* bg, IMAGE* bgx);
	void show();
	bool chkRange(int mouseX, int mouseY);
};

class label
{
private:
	int x;
	int y;
	int width;
	int height;
	//int value;
	wchar_t text[30]=L"text";
	IMAGE* main_bg;

public:
	label(int w, int h, int x, int y, IMAGE* main_bg);
	void show();
	void setText(LPCTSTR);

};

class formMain
{
private:
	int width;
	int height;
	IMAGE* bg;
	button btPlay, btPause, btStop, btExit, btHs;
	label lbUsrName, lbTime, lbScore, lbHighScore;
	int time = 60, score = 0;
	int highScore = 0;
public:
	formMain(LPCTSTR usrName, int width, int height, IMAGE* bg,
		IMAGE* bt_play, IMAGE* bt_pause, IMAGE* bt_stop, IMAGE* bt_exit, IMAGE* bt_hs, IMAGE* btx);
	int getTime();
	void setTime(int);
	int getScore();
	void setScore(int);
	int getHighScore();
	void setHighScore(int);
	~formMain();
};

class block 
{
private:
	IMAGE* tree0, tree1, treex;
	IMAGE* block, blockx;

};