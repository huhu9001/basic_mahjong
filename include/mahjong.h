#ifndef MAHJONG_H
#define MAHJONG_H

#include<stdint.h>

#ifndef NUM_TILE_EACHKIND
#define NUM_TILE_EACHKIND 4U
#endif
#ifndef NUM_SUIT
#define NUM_SUIT 3U
#endif
#ifndef NUM_KIND_EACHSUIT
#define NUM_KIND_EACHSUIT 9U
#endif
#ifndef NUM_KIND_CHAR
#define NUM_KIND_CHAR 7U
#endif
#ifndef NUM_TILE_FLOWER
#define NUM_TILE_FLOWER 8U
#endif

#ifndef NUM_MJPLAYER
#define NUM_MJPLAYER 4U
#endif
#ifndef NUM_GROUP_IN_HAND
#define NUM_GROUP_IN_HAND 4U
#endif
#ifndef NUM_TILE_DEAD
#define NUM_TILE_DEAD 0U
#endif

#define KIND_FIRSTCHAR (NUM_SUIT * NUM_KIND_EACHSUIT)
#define KIND_FIRSTFLOWER (KIND_FIRSTCHAR + NUM_KIND_CHAR)
#define KIND_FIRSTCHAR_BUFFED (NUM_SUIT * (NUM_KIND_EACHSUIT + 2U) + 2U)
#define KIND_FLOWER_BUFFED (KIND_FIRSTCHAR_BUFFED + NUM_KIND_CHAR * 3U)
#define KIND_LASTCHAR_BUFFED (KIND_FLOWER_BUFFED - 3U)
#define NUM_TILE_TOTAL (((NUM_KIND_EACHSUIT * NUM_SUIT) + NUM_KIND_CHAR) * NUM_TILE_EACHKIND + NUM_TILE_FLOWER)
#define NUM_KIND_BUFFED (KIND_FLOWER_BUFFED + 1U)
#define NUM_TILE_IN_HAND (NUM_GROUP_IN_HAND * 3U + 1U)

#if NUM_TILE_TOTAL < 0x100
typedef uint8_t mjtile;
#elif NUM_TILE_TOTAL < 0x10000
typedef uint16_t mjtile;
#elif NUM_TILE_TOTAL < 0x100000000
typedef uint32_t mjtile;
#else
typedef uintmax_t mjtile;
#endif

#if NUM_KIND_BUFFED < 0x100
typedef uint8_t mjkind;
#elif NUM_KIND_BUFFED < 0x10000
typedef uint16_t mjkind;
#elif NUM_KIND_BUFFED < 0x100000000
typedef uint32_t mjkind;
#else
typedef uintmax_t mjkind;
#endif

#if NUM_TILE_EACHKIND < 0x100
typedef uint8_t numkind;
#elif NUM_TILE_EACHKIND < 0x10000
typedef uint16_t numkind;
#elif NUM_TILE_EACHKIND < 0x100000000
typedef uint32_t numkind;
#else
typedef uintmax_t numkind;
#endif

#ifndef MJSUFFIX
#define MJSUFFIX
#endif

#define MJSUFFIX_CAT(name, suffix) name##suffix
#define MJSUFFIXES(name, suffix) MJSUFFIX_CAT(name, suffix)

typedef numkind MJSUFFIXES(mjhand, MJSUFFIX)[NUM_KIND_BUFFED * 6U + 2U];

#define MjBuffKind(k) (mjkind)(\
	(k) < KIND_FIRSTCHAR ? (k) + ((k) / NUM_KIND_EACHSUIT + 1U) * 2U :\
	(k) < KIND_FIRSTFLOWER ? ((k) - KIND_FIRSTCHAR) * 3U + KIND_FIRSTCHAR_BUFFED :\
	KIND_FLOWER_BUFFED)

#define MjUnbuffKind(k) (mjkind)(\
	(k) < KIND_FIRSTCHAR_BUFFED ? (k) - ((k) / (NUM_KIND_EACHSUIT + 2U) + 1U) * 2U :\
	(k) < KIND_FLOWER_BUFFED ? ((k) - KIND_FIRSTCHAR_BUFFED) / 3U + KIND_FIRSTCHAR :\
	KIND_FIRSTFLOWER)

#endif
