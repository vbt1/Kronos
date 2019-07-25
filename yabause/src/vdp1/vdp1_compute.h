#ifndef VDP1_COMPUTE_H
#define VDP1_COMPUTE_H

#include "vdp1_prog_compute.h"

enum
{
  VDP1_0_PAL = 0,
  VDP1_0_MIX,
  TEST_PRG,
  NB_PRG
};

typedef struct
{
  int P[8];
  int G[4];
  int priority;
  int w;
  int h;
  int flip;
  int cor;
  int cog;
  int cob;
  int type;

  int CMDCTRL;
  int CMDLINK;
  int CMDPMOD;
  int CMDCOLR;
  int CMDSRCA;
  int CMDSIZE;
  int CMDGRDA;

  int SPCTL;

} cmdparameter;

extern int* vdp1_compute_init(int width, int height, float ratiow, float ratioh);
extern int vdp1_compute(Vdp2 *varVdp2Regs);
extern int vdp1_add(cmdparameter* cmd);

#endif //VDP1_COMPUTE_H
