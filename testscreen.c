// we test functions of screen.c
#include <stdio.h>
#include <unistd.h>
#include "screen.h"
#include "comm.h"
#include "sound.h"

int main(void){
	Position cur = getscreensize();
	char poststr[100];
	sprintf(poststr, "row=%d&col=%d", cur.row, cur.col);
	senddata(poststr, URL);
	gotoXY(1,1);
	printf("Screen size, ROW=%d, COL=%d\n", cur.row, cur.col);
	printf("HTTP post is sent to %s\n", URL);
	getchar();		// waiting for the user to press a key
	getchar();
	for(int i=0; i<cur.row; i++){
		setcolors(RED, GREEN);
		clearscreen();
		float step = (float)cur.col/cur.row;
		gotoXY(i+1, step*i+1);
		printf("HELLO\n");
		usleep(500000);
	}

//	printf("The following message will be in YELLOW color\n");
	gotoXY(14, 35);
	setfgcolor(YELLOW);
	printf("Hello, world!\n");
	getchar();
	drawbar(30, 30);
	drawbar(50, 30);

	getchar();
	resetcolors();
	clearscreen();
	printf("This line is back to default color\n");
	FILE *fp;
	fp = fopen("test.wav", "r");
	WAVheader h = readwavhdr(fp);
	fclose(fp);
	displayWAVhdr(h);
}
