#ifndef __c3_dsmDemo_h__
#define __c3_dsmDemo_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_dsmDemoInstanceStruct
#define typedef_SFc3_dsmDemoInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_Ready;
  uint8_T c3_tp_P_Peak1;
  uint8_T c3_tp_N_Peak1;
  uint8_T c3_tp_N_Peak2;
  uint8_T c3_tp_P_Peak2;
  uint8_T c3_tp_Peak_Pair;
  uint8_T c3_is_active_c3_dsmDemo;
  uint8_T c3_is_c3_dsmDemo;
  real_T c3_CountN;
  real_T c3_t_h1;
  real_T c3_t_h2;
  real_T c3_CountP;
  real_T c3_CountPair;
  boolean_T c3_dataWrittenToVector[4];
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  void *c3_fEmlrtCtx;
  real_T *c3_Peak;
  real_T *c3_y;
  real_T *c3_THN;
  real_T *c3_THP;
  real_T *c3_NegPeak;
  real_T *c3_PosPeak;
  real_T *c3_en;
  real_T *c3_Pekcnt;
} SFc3_dsmDemoInstanceStruct;

#endif                                 /*typedef_SFc3_dsmDemoInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_dsmDemo_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_dsmDemo_get_check_sum(mxArray *plhs[]);
extern void c3_dsmDemo_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
