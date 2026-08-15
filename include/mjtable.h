#ifndef MJTABLE_H
#define MJTABLE_H

#include<mahjong.h>

#define MJS_N 0
#define MJS_DRAW 1
#define MJS_DISCARD 2
#define MJS_CHIPON 3
#define MJS_KAN_R 4
#define MJS_KAN_C 5

struct MJSUFFIXES(mjtable, MJSUFFIX) {
	MJSUFFIXES(mjhand, MJSUFFIX) hands[NUM_MJPLAYER];
	char handtiles[NUM_MJPLAYER][NUM_TILE_TOTAL];
	char ready[NUM_MJPLAYER];
	unsigned char meld[NUM_MJPLAYER];
	unsigned char quad[NUM_MJPLAYER];
	unsigned char flower[NUM_MJPLAYER];

	mjtile handtileLinkF[NUM_MJPLAYER][NUM_TILE_TOTAL + 1];
	mjtile handtileLinkB[NUM_MJPLAYER][NUM_TILE_TOTAL + 1];

	uint8_t state;
	mjtile posFront, posBack;
	unsigned char player;
	unsigned char playerDealer;

	struct {
		char win;
		char ready;
		unsigned char kan;
		char flower;

		mjkind kanCandidate[(NUM_TILE_IN_HAND + 1U) / 4U];
	} optionSelf;
	struct {
		char win[3];
		char kan[3];
		char pon[3];
		char chi[3];
	} optionOther;
	char(*predicateWin)(struct MJSUFFIXES(mjtable, MJSUFFIX) const*, unsigned char, void*);
	void*contextPredicateWin;
	char(*predicateReady)(struct MJSUFFIXES(mjtable, MJSUFFIX) const*, unsigned char, void*);
	void*contextPredicateReady;

	mjtile mount[NUM_TILE_TOTAL + NUM_TILE_TOTAL % 2U];
	mjkind kindFocus;
	mjtile tileFocus;
	mjtile tilesLastMeld[4];
};

void MJSUFFIXES(MjtableInit, MJSUFFIX)(
	struct MJSUFFIXES(mjtable, MJSUFFIX)*t,
	char(*predwin)(struct MJSUFFIXES(mjtable, MJSUFFIX) const*, unsigned char, void*),
	char(*predready)(struct MJSUFFIXES(mjtable, MJSUFFIX) const*, unsigned char, void*));

void MJSUFFIXES(MjtableDiscard, MJSUFFIX)(struct MJSUFFIXES(mjtable, MJSUFFIX)*t, mjkind kind);
void MJSUFFIXES(MjtablePass, MJSUFFIX)(struct MJSUFFIXES(mjtable, MJSUFFIX)*t);
void MJSUFFIXES(MjtableReady, MJSUFFIX)(struct MJSUFFIXES(mjtable, MJSUFFIX)*t);
void MJSUFFIXES(MjtableChi, MJSUFFIX)(struct MJSUFFIXES(mjtable, MJSUFFIX)*t, int type);
void MJSUFFIXES(MjtablePon, MJSUFFIX)(struct MJSUFFIXES(mjtable, MJSUFFIX)*t, int who);
void MJSUFFIXES(MjtableKanOther, MJSUFFIX)(struct MJSUFFIXES(mjtable, MJSUFFIX)*t, int who);
void MJSUFFIXES(MjtableKanSelf, MJSUFFIX)(struct MJSUFFIXES(mjtable, MJSUFFIX)*t, int which);
void MJSUFFIXES(MjtableFlower, MJSUFFIX)(struct MJSUFFIXES(mjtable, MJSUFFIX)*t);
/*Manually shuffle and set dealer before this*/
void MJSUFFIXES(MjtableNewround, MJSUFFIX)(struct MJSUFFIXES(mjtable, MJSUFFIX)*t);

void MJSUFFIXES(MjtableDiscardT, MJSUFFIX)(struct MJSUFFIXES(mjtable, MJSUFFIX)*t, mjtile tile);

#endif