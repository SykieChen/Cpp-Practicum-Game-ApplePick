#include "apple.h"

void transimg(int dstX, int dstY, IMAGE *sImg, IMAGE *xImg) {
	// Trick to display transparent images
	IMAGE *workImg = GetWorkingImage();
	IMAGE *hImg = new IMAGE; // make a copy of the origional image
	Resize(hImg, sImg->getwidth(), sImg->getheight());
	SetWorkingImage(hImg);
	putimage(0, 0, sImg);
	putimage(0, 0, xImg, SRCINVERT);
	SetWorkingImage(workImg);
	putimage(dstX, dstY, xImg, SRCAND);
	putimage(dstX, dstY, hImg, SRCPAINT);
	delete hImg;
}

void repaintBlock(int x1, int y1, int x2, int y2, IMAGE* bg) {
	putimage(x1, y1, x2 - x1, y2 - y1, bg, x1, y1);
}

void pause(formMain* frm) {
	MOUSEMSG mouseMsg = GetMouseMsg();
	while (1) {
		if (MouseHit()) {
			mouseMsg = GetMouseMsg();
			if (mouseMsg.uMsg == WM_LBUTTONDOWN) {
				//clicked
				if (frm->btPause.chkRange(mouseMsg.x, mouseMsg.y))
					return;
			}
		}
		Sleep(1);
	}
}

blockNode::blockNode(bool haveTree, int x, int y,
	IMAGE* itree0, IMAGE* itree1, IMAGE* itreex, IMAGE* iblock, IMAGE* iblockx,
	IMAGE* main_bg) :
	item(haveTree, x, y, itree0, itree1, itreex, iblock, iblockx, main_bg) {}



void checkBlockBottom(man* GTQ, blockList* list) {
	if (GTQ->getY() <= list->tail->item.getY() + list->tail->item.getH()  &&
		GTQ->getY() >= list->tail->item.getY() + list->tail->item.getH() - 10) {
		blockNode* p = list->head->next;
		while (p != NULL) {
			if (p->item.onBlock(GTQ)) {
				GTQ->isJumping = false;
			}
			p = p->next;
		}
	}
}

void checkBlockTop(man* GTQ, blockList* list) {
	if (GTQ->getY() + GTQ->getH() <= list->tail->item.getY() + 100 &&
		GTQ->getY() + GTQ->getH() >= list->tail->item.getY() + 100 - 10) {
		blockNode* p = list->head->next;
		while (p != NULL) {
			if (p->item.onBlock(GTQ)) {
				GTQ->isOnGround = true;
				GTQ->setY(list->tail->item.getY() + 100 - GTQ->getH());
			}
			p = p->next;
		}
	}
}

blockNode* checkManFall(man* GTQ, blockList* list) {
	blockNode* p = list->head->next;
	while (p != NULL) {
		if (p->item.onBlock(GTQ) 
			&& GTQ->getY() == p->item.getY() + 100 - GTQ->getH()
			) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

blockNode* checkOnGround(man* GTQ, blockList* list1, blockList* list2, blockList* list3) {
	blockNode* p;
	p = checkManFall(GTQ, list1);
	if (p != NULL) return p;
	else {
		p = checkManFall(GTQ, list2);
		if (p != NULL) return p;
		else {
			p = checkManFall(GTQ, list3);
			if (p != NULL) return p;
		}
	}
	return NULL;
}

bool getApple(man* GTQ, blockList* list1, blockList* list2, blockList* list3) {
	blockNode* p = checkOnGround(GTQ, list1, list2, list3);

	if (p != NULL) {
		//on block
		return p->item.getApple();	//try to get apple
	}
	return false;	//not on block

}