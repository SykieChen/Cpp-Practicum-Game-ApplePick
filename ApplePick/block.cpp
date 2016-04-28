#include "apple.h"

block::block(bool haveTree, int x, int y,
	IMAGE* itree0, IMAGE* itree1, IMAGE* itreex, IMAGE* iblock, IMAGE* iblockx,
	IMAGE* main_bg) {
	this->haveTree = haveTree;
	this->x = x;
	this->y = y;
	this->width = itreex->getwidth();
	this->height = itreex->getheight();
	this->itree0 = itree0;
	this->itree1 = itree1;
	this->itreex = itreex;
	this->iblock = iblock;
	this->iblockx = iblockx;
	this->main_bg = main_bg;
	//show();
}
void block::show() {
	if (haveTree) {
		if (haveApple) transimg(x, y, itree1, itreex);
		else transimg(x, y, itree0, itreex);
	}
	else transimg(x, y, iblock, iblockx);
}
int block::getX() {
	return x;
}
int block::getY() {
	return y;
}
void block::moveL(int px) {
	//hide();
	x -= px;
	show();
}
void block::moveR(int px) {
	//hide();
	x += px;
	show();
}
bool block::getApple() {
	if (haveApple) {
		hide();
		haveApple = false;
		show();
		return true;
	}
	else return false;
}
int block::getW() {
	return width;
}
int block::getH() {
	return height;
}

void block::hide() {
	repaintBlock(x, y, x + width, y + height, main_bg);
}

bool block::onBlock(man* man0) {
	if (man0->getX() + man0->getW() - 10 > x &&
		man0->getX() + 10 < x + width )
		return true;
	return false;
}