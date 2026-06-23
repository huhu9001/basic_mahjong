#include<mjhand.h>
#define MJHAND_VERBOSE_ANALYSE
#include"mjhand_MjhandAnalyse.h"

void MJSUFFIXES(MjhandAnalyseVerbose, MJSUFFIX)(MJSUFFIXES(mjhand, MJSUFFIX) data, void(*func)(MJSUFFIXES(mjhand, MJSUFFIX) const, void*), void*context) {
	MjhandAnalyse(data, func, context);
}
