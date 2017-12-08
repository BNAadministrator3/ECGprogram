#ifndef __c4_dsmDemo_h__
#define __c4_dsmDemo_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_dsmDemoInstanceStruct
#define typedef_SFc4_dsmDemoInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_dsmDemo;
  real_T c4_sum[8];
  boolean_T c4_sum_not_empty;
  real_T c4_alpha;
  boolean_T c4_alpha_not_empty;
  real_T c4_temp;
  boolean_T c4_temp_not_empty;
  void *c4_fEmlrtCtx;
  real_T *c4_Pek;
  real_T *c4_THPout;
  real_T *c4_Enable;
  real_T *c4_cnt;
} SFc4_dsmDemoInstanceStruct;

#endif                                 /*typedef_SFc4_dsmDemoInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_dsmDemo_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_dsmDemo_get_check_sum(mxArray *plhs[]);
extern void c4_dsmDemo_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
