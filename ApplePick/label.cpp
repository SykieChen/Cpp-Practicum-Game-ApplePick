#include "apple.h"

label::label(int w, int h, int x, int y, wchar_t* text,IMAGE* bg){
	this->width = w;
	this->height = h;
	this->x = x;
	this->y = y;
	this->text = text;
	this->main_bg = bg;
	show();
}

void label::show(){
	repaintBlock(x, y, x + width, y + height, main_bg);
	setbkmode(TRANSPARENT);
	RECT r = { x,y,x + width,y + height };
	drawtext(text, &r, DT_LEFT | DT_TOP);
}