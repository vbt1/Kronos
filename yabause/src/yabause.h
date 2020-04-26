/*  Copyright 2003-2005 Guillaume Duhamel
    Copyright 2004-2006 Theo Berkau
    Copyright 2006      Anders Montonen

    This file is part of Yabause.

    Yabause is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Yabause is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Yabause; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
*/

#ifndef YABAUSE_H
#define YABAUSE_H

#include "core.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
   int percoretype;
   int sh2coretype;
   int vidcoretype;
   int sndcoretype;
   int m68kcoretype;
   int cdcoretype;
   int carttype;
   int stvgame;
   u8 regionid;
   const char *biospath;
   const char *cdpath;
   const char *ssfpath;
   const char *buppath;
   const char *mpegpath;
   const char *cartpath;
   const char *stvbiospath;
   const char *stvgamepath;
   const char *supportdir;
   const char *eepromdir;
   const char *modemip;
   const char *modemport;
   int vsyncon; //This shall be renamed as out of sync
   int clocksync;  // 1 = sync internal clock to emulation, 0 = realtime clock
   u32 basetime;   // Initial time in clocksync mode (0 = start w/ system time)
   int usethreads;
   int numthreads;
   int osdcoretype;
   int skip_load;//skip loading in YabauseInit so tests can be run without a bios
   int auto_cart_select;
   int video_filter_type;
   int video_upscale_type;
   int polygon_generation_mode;
   int stretch;
   int use_cs;
   int scanline;
   int meshmode;
   int play_ssf;
   int resolution_mode;
   int extend_backup;
   int usecache;
   int skipframe; //This should be used for real frame skip mechanism
   int wireframe_mode;
   int stv_favorite_region;
#ifdef SPRITE_CACHE
   int useVdp1cache;
#endif
} yabauseinit_struct;

#define CLKTYPE_26MHZ           0
#define CLKTYPE_28MHZ           1

#define VIDEOFORMATTYPE_NTSC    0
#define VIDEOFORMATTYPE_PAL     1

#ifndef NO_CLI
void print_usage(const char *program_name);
#endif

void YabauseChangeTiming(int freqtype);
int YabauseInit(yabauseinit_struct *init);
int YabauseSh2Init(yabauseinit_struct *init);
void YabFlushBackups(void);
void YabauseDeInit(void);
void YabauseResetNoLoad(void);
void YabauseReset(void);
void YabauseResetButton(void);
int YabauseExec(void);
void YabauseStartSlave(void);
void YabauseStopSlave(void);
u64 YabauseGetTicks(void);
void YabauseSetVideoFormat(int type);
void YabauseSetSkipframe(int skipframe);
void YabauseSpeedySetup(void);
int YabauseQuickLoadGame(void);

void EnableAutoFrameSkip(void);
int isAutoFrameSkip(void);
void DisableAutoFrameSkip(void);

#define YABSYS_TIMING_BITS  20
#define YABSYS_TIMING_MASK  ((1 << YABSYS_TIMING_BITS) - 1)

typedef struct
{
   int DecilineCount;
   int LineCount;
   int VBlankLineCount;
   int MaxLineCount;
   u32 DecilineStop;  // Fixed point
   u32 DecilineUsec;  // Fixed point
   u32 UsecFrac;      // Fixed point
   int CurSH2FreqType;
   int IsPal;
   int isRotated;
   u8 isSTV;
   u8 UseThreads;
   int NumThreads;
   u8 IsSSH2Running;
   u64 OneFrameTime;
   u64 tickfreq;
   int emulatebios;
   int usequickload;
   int wait_line_count;
   int playing_ssf;
   u32 frame_count;
   int usecache;
   int vsyncon;
   int skipframe;
   int wireframe_mode;
   int stvInputType;
#ifdef SPRITE_CACHE
   int useVdp1cache;
#endif
   int vdp1cycles;
} yabsys_struct;

extern yabsys_struct yabsys;

int YabauseEmulate(void);
extern void resetSyncVideo(void);

extern void dropFrameDisplay();
extern void resetFrameSkip();

extern u32 saved_scsp_cycles;
#define SCSP_FRACTIONAL_BITS 20
u32 get_cycles_per_line_division(u32 clock, int frames, int lines, int divisions_per_line);
u32 YabauseGetCpuTime();

#ifdef __cplusplus
}
#endif


#endif
