#include "apple.h"
man::man(int x, int y, IMAGE* iman, IMAGE* imanx, IMAGE* main_bg) {
	this->x = x;
	this->y = y;
	this->iman = iman;
	this->imanx = imanx;
	this->main_bg = main_bg;
	w = imanx->getwidth();
	h = imanx->getheight();
	show();
}
int man::getX() {
	return x;
}
int man::getY() {
	return y;
}
int man::getPxJumped() {
	return pxJumped;
}
void man::jump() {
	pxJumped += 1;
	hide();
	y -= 1;
	show();
}
void man::fall() {
	pxJumped = 0;
	hide();
	y += 1;
	show();
}
void man::moveL() {
	hide();
	x -= 1;
	show();
}
void man::moveR() {
	hide();
	x += 1;
	show();
}

void man::show() {
	transimg(x, y, iman, imanx);
}
void man::hide() {
	repaintBlock(x, y, x + w, y + h, main_bg);
}
int man::getW() {
	return w;
}
int man::getH() {
	return h;
}