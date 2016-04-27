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