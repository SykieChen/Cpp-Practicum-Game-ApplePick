#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <time.h>
#include <fstream>

using namespace std;

void transimg(int dstX, int dstY, IMAGE *sImg, IMAGE *xImg);
void repaintBlock(int x1, int y1, int x2, int y2, IMAGE*);

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
	wchar_t text[30] = L"text";
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
	label lbUsrName, lbTime, lbScore, lbHighScore;
	int time = 60, score = 0;
	int highScore = 0;
public:
	button btPlay, btPause, btStop, btExit, btHs;
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

class man {
private:
	int x, y;
	int w, h;
	int pxJumped = 0;
	IMAGE* iman, *imanx;
	IMAGE* main_bg;
public:
	bool isJumping = false;
	bool isOnGround = true;
	man(int x, int y, IMAGE* iman, IMAGE* imanx, IMAGE* main_bg);
	int getPxJumped();
	int getX();
	int getY();
	void jump();
	void fall();
	void moveL();
	void moveR();
	void show();
	int getW();
	int getH();
	void hide();
	void setY(int y);
	void reset(int x, int y);
};

class block
{
private:
	IMAGE* itree0, *itree1, *itreex;
	IMAGE* iblock, *iblockx;
	IMAGE* main_bg;
	bool haveTree = false;
	bool haveApple = true;
	int x, y;
	int width, height;
public:
	block(bool haveTree, int x, int y,
		IMAGE* itree0, IMAGE* itree1, IMAGE* itreex, IMAGE* iblock, IMAGE* iblockx,
		IMAGE* main_bg);
	bool onBlock(man* man0);
	int getX();
	int getY();
	void moveL(int px);
	void moveR(int px);
	bool getApple();
	int getW();
	int getH();
	void show();
	void hide();

};

struct blockNode {
	block item;
	blockNode* next;
	blockNode(bool haveTree, int x, int y,
		IMAGE* itree0, IMAGE* itree1, IMAGE* itreex, IMAGE* iblock, IMAGE* iblockx,
		IMAGE* main_bg);
};

class blockList {
private:
	int y;
	int speed;
	IMAGE* itree0, *itree1, *itreex;
	IMAGE* iblock, *iblockx;
	IMAGE* main_bg;
public:
	bool isL2R = false;
	blockNode* head;
	blockNode* tail;
	blockList(int y, bool isL2R, int speed,
		IMAGE* itree0, IMAGE* itree1, IMAGE* itreex, IMAGE* iblock, IMAGE* iblockx,
		IMAGE* main_bg);
	void addNode(bool haveTree, int split);
	void delNode();
	void hide();
	void show();
	void move();
	void clear();
	~blockList();
};



class bear {
private:
	int x, y, w, h;
	bool isMovingUp = true;
	IMAGE* ibear, *ibearx;
	IMAGE* main_bg;
public:
	bear(int x, int y, IMAGE* ibear, IMAGE* ibearx, IMAGE* bg);
	bool ifCaught(man* man0);
	void move(int top, int bottom);
	void show();
	void hide();
	void reset(int x, int y);
};

void pause(formMain* frm);
void checkBlockBottom(man* GTQ, blockList* list);
void checkBlockTop(man* GTQ, blockList* list);
blockNode* checkManFall(man* GTQ, blockList* list);
blockNode* checkOnGround(man* GTQ, blockList* list1, blockList* list2, blockList* list3);
bool getApple(man* GTQ, blockList* list1, blockList* list2, blockList* list3);