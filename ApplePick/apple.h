#include <graphics.h>

void transimg(int,int,IMAGE*,IMAGE*);
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
	wchar_t* text;
	IMAGE* main_bg;

public:
	label(int w, int h, int x, int y, wchar_t* text, IMAGE*);
	void show();

};

class formMain 
{
private:
	int width;
	int height;
	IMAGE* bg;
	button play, pause, stop, exit, hs;
public:
	formMain(int width, int height, IMAGE* bg,
		IMAGE* bt_play, IMAGE* bt_pause, IMAGE* bt_stop, IMAGE* bt_exit, IMAGE* bt_hs, IMAGE* btx);

};