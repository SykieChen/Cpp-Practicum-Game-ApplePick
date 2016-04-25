#include "apple.h"

blockList::blockList(int y,bool isL2R,int speed,
	IMAGE* itree0, IMAGE* itree1, IMAGE* itreex, IMAGE* iblock, IMAGE* iblockx,
	IMAGE* main_bg) 
{

	head = new blockNode(false, 0, y, itree0, itree1, itreex, iblock, iblockx, main_bg);
	head->next = NULL;
	tail = head;
	this->isL2R = isL2R;
	this->y = y;
	this->speed = speed;
	this->itree0 = itree0;
	this->itree1 = itree1;
	this->itreex = itreex;
	this->iblock = iblock;
	this->iblockx = iblockx;
	this->main_bg = main_bg;
}
void blockList::addNode(bool haveTree, int split)
{
	int newx;
	if (isL2R) newx = tail->item.getX() - tail->item.getW() - split;
	else newx = tail->item.getX() + tail->item.getW() + split;
	tail->next = new blockNode(haveTree, newx, y, itree0, itree1, itreex, iblock, iblockx, main_bg);
	tail = tail->next;
	tail->next = NULL;
	tail->item.show();
}
void blockList::delNode() {
	tail->item.hide();
	blockNode* t = head->next;
	head->next = t->next;
	delete t;
}
void blockList::move() {
	blockNode *p = head->next;
	BeginBatchDraw();
	while (p != NULL) {
		if (isL2R) p->item.moveR(speed);
		else p->item.moveL(speed);
		p = p->next;
	}
	EndBatchDraw();
}
blockList::~blockList() {
	blockNode* t = head;
	while (t != NULL) {
		head = t->next;
		delete t;
		t = head;
	}
}