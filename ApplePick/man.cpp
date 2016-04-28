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
int man::getPxFallen() {
	return pxFallen;
}
void man::jump() {
	pxJumped += 10;
	pxFallen = 0;
	//hide();
	y -= 10;
	show();
}
void man::fall() {
	pxJumped = 0;
	pxFallen += 10;
	//hide();
	y += 10;
	show();
}
void man::moveL() {
	//hide();
	x -= 3;
	pxFallen = 0;
	show();
}
void man::moveR() {
	//hide();
	x += 3;
	pxFallen = 0;
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

void man::setY(int y) {
	this->y = y;
}

void man::reset(int x, int y) {
	this->x = x;
	this->y = y;
	pxJumped = 0;
	isJumping = false;
	isOnGround = true;
	show();
}