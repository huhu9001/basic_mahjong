#ifndef MJHAND_H
#define MJHAND_H

#include<mahjong.h>

void MJSUFFIXES(MjhandAnalyseConcise, MJSUFFIX)(MJSUFFIXES(mjhand, MJSUFFIX) data, void(*func)(MJSUFFIXES(mjhand, MJSUFFIX) const, void*), void*context);
void MJSUFFIXES(MjhandAnalyseVerbose, MJSUFFIX)(MJSUFFIXES(mjhand, MJSUFFIX) data, void(*func)(MJSUFFIXES(mjhand, MJSUFFIX) const, void*), void*context);

int MJSUFFIXES(MjhandProgressNormal, MJSUFFIX)(int sum_singlets, int sum_pairs, int sum_grouptwo_not_pair, int sum_flowers);
int MJSUFFIXES(MjhandProgressPair, MJSUFFIX)(int sum_singlets, int sum_pairs, int sum_flowers);
int MJSUFFIXES(MjhandProgress, MJSUFFIX)(MJSUFFIXES(mjhand, MJSUFFIX) h, int output[NUM_KIND_BUFFED]);

#endif
