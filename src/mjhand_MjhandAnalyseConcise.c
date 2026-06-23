#include<mjhand.h>
#undef MJHAND_VERBOSE_ANALYSE
#include"mjhand_MjhandAnalyse.h"

void MJSUFFIXES(MjhandAnalyseConcise, MJSUFFIX)(MJSUFFIXES(mjhand, MJSUFFIX) data, void(*func)(MJSUFFIXES(mjhand, MJSUFFIX) const, void*), void*context) {
	MjhandAnalyse(data, func, context);
}
