#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <time.h>

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

class button {
private:
	int width;
	int height;
	int x;
	int y;
	IMAGE* bg;
	IMAGE* bgx;
public:
	button(int w, int h, int x, int y, IMAGE* bg, IMAGE* bgx) {
		this->width = w;
		this->height = h;
		this->x = x;
		this->y = y;
		this->bg = bg;
		this->bgx = bgx;
		show();
	}

	void show() {
		transimg(x, y, bg, bgx);
	}

	bool chkRange(int mouseX, int mouseY) {
		if (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height)
			return true;
		else return false;
	}

};

class label {
private:
	int x;
	int y;
	int width;
	int height;

public:

};

class formMain {
private:
	int width;
	int height;
	IMAGE bg;
	button play, pause, stop, exit, hs;
public:
	formMain(int width, int height, IMAGE* bg,
		IMAGE* bt_play, IMAGE* bt_pause, IMAGE* bt_stop, IMAGE* bt_exit, IMAGE* bt_hs, IMAGE* btx) :
		play(btx->getwidth(), btx->getheight(), 35, 560, bt_play, btx),
		pause(btx->getwidth(), btx->getheight(), 188, 560, bt_pause, btx),
		stop(btx->getwidth(), btx->getheight(), 341, 560, bt_stop, btx),
		exit(btx->getwidth(), btx->getheight(), 494, 560, bt_exit, btx),
		hs(btx->getwidth(), btx->getheight(), 647, 560, bt_hs, btx) {

		initgraph(800, 600);

	}
};

int main() {
	//load resources
	IMAGE bg, bear, bearx, man, manx, block, blockx, tree0, tree1, treex;
	IMAGE bt_play, bt_pause, bt_stop, bt_exit, bt_hs, btx;
	loadimage(&bg, L"img\\bg.jpg");
	loadimage(&bear, L"img\\bear.jpg");
	loadimage(&bearx, L"img\\bearx.jpg");
	loadimage(&man, L"img\\man.jpg");
	loadimage(&manx, L"img\\manx.jpg");
	loadimage(&block, L"img\\block.jpg");
	loadimage(&blockx, L"img\\blockx.jpg");
	loadimage(&tree0, L"img\\tree0.jpg");
	loadimage(&tree1, L"img\\tree1.jpg");
	loadimage(&treex, L"img\\treex.jpg");
	loadimage(&bt_play, L"img\\bt_play.bmp");
	loadimage(&bt_pause, L"img\\bt_pause.bmp");
	loadimage(&bt_stop, L"img\\bt_stop.bmp");
	loadimage(&bt_exit, L"img\\bt_exit.bmp");
	loadimage(&bt_hs, L"img\\bt_hs.bmp");
	loadimage(&btx, L"img\\btx.bmp");
	//init

	return 0;
}