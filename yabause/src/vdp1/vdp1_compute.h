#ifndef VDP1_COMPUTE_H
#define VDP1_COMPUTE_H

enum
{
  TEST_PRG,
  NB_PRG
};

enum {
  POLYGON = 0,
  END_TYPE
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
  int SPCTL;
  int type;
  int padding[3];
} cmdparameter;

extern int* vdp1_compute_init(int width, int height, float ratiow, float ratioh);
extern int vdp1_compute();
extern int vdp1_add(cmdparameter* cmd);

#endif //VDP1_COMPUTE_H
