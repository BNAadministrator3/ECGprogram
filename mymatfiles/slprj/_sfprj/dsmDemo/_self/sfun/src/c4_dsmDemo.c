/* Include files */

#include "dsmDemo_sfun.h"
#include "c4_dsmDemo.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "dsmDemo_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c4_debug_family_names[9] = { "nargin", "nargout", "Pek",
  "Enable", "cnt", "THPout", "sum", "alpha", "temp" };

/* Function Declarations */
static void initialize_c4_dsmDemo(SFc4_dsmDemoInstanceStruct *chartInstance);
static void initialize_params_c4_dsmDemo(SFc4_dsmDemoInstanceStruct
  *chartInstance);
static void enable_c4_dsmDemo(SFc4_dsmDemoInstanceStruct *chartInstance);
static void disable_c4_dsmDemo(SFc4_dsmDemoInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_dsmDemo(SFc4_dsmDemoInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c4_dsmDemo(SFc4_dsmDemoInstanceStruct
  *chartInstance);
static void set_sim_state_c4_dsmDemo(SFc4_dsmDemoInstanceStruct *chartInstance,
  const mxArray *c4_st);
static void finalize_c4_dsmDemo(SFc4_dsmDemoInstanceStruct *chartInstance);
static void sf_gateway_c4_dsmDemo(SFc4_dsmDemoInstanceStruct *chartInstance);
static void mdl_start_c4_dsmDemo(SFc4_dsmDemoInstanceStruct *chartInstance);
static void initSimStructsc4_dsmDemo(SFc4_dsmDemoInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static real_T c4_emlrt_marshallIn(SFc4_dsmDemoInstanceStruct *chartInstance,
  const mxArray *c4_b_temp, const char_T *c4_identifier, boolean_T *c4_svPtr);
static real_T c4_b_emlrt_marshallIn(SFc4_dsmDemoInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, boolean_T
  *c4_svPtr);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_c_emlrt_marshallIn(SFc4_dsmDemoInstanceStruct *chartInstance,
  const mxArray *c4_b_sum, const char_T *c4_identifier, boolean_T *c4_svPtr,
  real_T c4_y[8]);
static void c4_d_emlrt_marshallIn(SFc4_dsmDemoInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, boolean_T
  *c4_svPtr, real_T c4_y[8]);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_e_emlrt_marshallIn(SFc4_dsmDemoInstanceStruct *chartInstance,
  const mxArray *c4_b_THPout, const char_T *c4_identifier);
static real_T c4_f_emlrt_marshallIn(SFc4_dsmDemoInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_g_emlrt_marshallIn(SFc4_dsmDemoInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_h_emlrt_marshallIn(SFc4_dsmDemoInstanceStruct *chartInstance,
  const mxArray *c4_b_is_active_c4_dsmDemo, const char_T *c4_identifier);
static uint8_T c4_i_emlrt_marshallIn(SFc4_dsmDemoInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_dsmDemoInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc4_dsmDemoInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_dsmDemo(SFc4_dsmDemoInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc4_dsmDemo(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_sum_not_empty = false;
  chartInstance->c4_alpha_not_empty = false;
  chartInstance->c4_temp_not_empty = false;
  chartInstance->c4_is_active_c4_dsmDemo = 0U;
}

static void initialize_params_c4_dsmDemo(SFc4_dsmDemoInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_dsmDemo(SFc4_dsmDemoInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_dsmDemo(SFc4_dsmDemoInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c4_update_debugger_state_c4_dsmDemo(SFc4_dsmDemoInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_dsmDemo(SFc4_dsmDemoInstanceStruct
  *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  real_T c4_hoistedGlobal;
  const mxArray *c4_b_y = NULL;
  real_T c4_b_hoistedGlobal;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_d_y = NULL;
  real_T c4_c_hoistedGlobal;
  const mxArray *c4_e_y = NULL;
  uint8_T c4_d_hoistedGlobal;
  const mxArray *c4_f_y = NULL;
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(5, 1), false);
  c4_hoistedGlobal = *chartInstance->c4_THPout;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_hoistedGlobal, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = chartInstance->c4_alpha;
  c4_c_y = NULL;
  if (!chartInstance->c4_temp_not_empty) {
    sf_mex_assign(&c4_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_hoistedGlobal, 0, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_d_y = NULL;
  if (!chartInstance->c4_sum_not_empty) {
    sf_mex_assign(&c4_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_d_y, sf_mex_create("y", chartInstance->c4_sum, 0, 0U, 1U,
      0U, 2, 1, 8), false);
  }

  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_c_hoistedGlobal = chartInstance->c4_temp;
  c4_e_y = NULL;
  if (!chartInstance->c4_temp_not_empty) {
    sf_mex_assign(&c4_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_c_hoistedGlobal, 0, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c4_y, 3, c4_e_y);
  c4_d_hoistedGlobal = chartInstance->c4_is_active_c4_dsmDemo;
  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_d_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 4, c4_f_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_dsmDemo(SFc4_dsmDemoInstanceStruct *chartInstance,
  const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv0[8];
  int32_T c4_i0;
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  *chartInstance->c4_THPout = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("THPout", c4_u, 0)), "THPout");
  chartInstance->c4_alpha = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("alpha", c4_u, 1)), "alpha",
    &chartInstance->c4_alpha_not_empty);
  c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("sum", c4_u, 2)),
                        "sum", &chartInstance->c4_sum_not_empty, c4_dv0);
  for (c4_i0 = 0; c4_i0 < 8; c4_i0++) {
    chartInstance->c4_sum[c4_i0] = c4_dv0[c4_i0];
  }

  chartInstance->c4_temp = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("temp", c4_u, 3)), "temp", &chartInstance->c4_temp_not_empty);
  chartInstance->c4_is_active_c4_dsmDemo = c4_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_active_c4_dsmDemo", c4_u, 4)),
    "is_active_c4_dsmDemo");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_dsmDemo(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_dsmDemo(SFc4_dsmDemoInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c4_dsmDemo(SFc4_dsmDemoInstanceStruct *chartInstance)
{
  real_T c4_hoistedGlobal;
  real_T c4_b_hoistedGlobal;
  real_T c4_c_hoistedGlobal;
  real_T c4_b_Pek;
  real_T c4_b_Enable;
  real_T c4_b_cnt;
  uint32_T c4_debug_family_var_map[9];
  real_T c4_nargin = 3.0;
  real_T c4_nargout = 1.0;
  real_T c4_b_THPout;
  int32_T c4_i1;
  real_T c4_x;
  real_T c4_b_x;
  real_T c4_c_x;
  real_T c4_d_hoistedGlobal;
  real_T c4_d_x;
  int32_T c4_i2;
  real_T c4_e_x;
  real_T c4_f_x;
  boolean_T c4_b;
  real_T c4_y;
  real_T c4_e_hoistedGlobal[8];
  boolean_T c4_b0;
  int32_T c4_k;
  real_T c4_g_x;
  boolean_T c4_b_b;
  boolean_T c4_b1;
  real_T c4_A;
  boolean_T c4_c_b;
  real_T c4_h_x;
  real_T c4_i_x;
  real_T c4_r;
  real_T c4_b_y;
  boolean_T c4_rEQ0;
  real_T c4_f_hoistedGlobal;
  int32_T c4_i3;
  real_T c4_c_y;
  int32_T c4_b_k;
  real_T c4_b_A;
  real_T c4_j_x;
  real_T c4_k_x;
  real_T c4_d_y;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_cnt, 2U, 1U, 0U,
                        chartInstance->c4_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_Enable, 1U, 1U, 0U,
                        chartInstance->c4_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_Pek, 0U, 1U, 0U,
                        chartInstance->c4_sfEvent, false);
  chartInstance->c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
  c4_hoistedGlobal = *chartInstance->c4_Pek;
  c4_b_hoistedGlobal = *chartInstance->c4_Enable;
  c4_c_hoistedGlobal = *chartInstance->c4_cnt;
  c4_b_Pek = c4_hoistedGlobal;
  c4_b_Enable = c4_b_hoistedGlobal;
  c4_b_cnt = c4_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_Pek, 2U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_Enable, 3U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_b_cnt, 4U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_THPout, 5U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c4_sum, 6U,
    c4_b_sf_marshallOut, c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c4_alpha, 7U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c4_temp, 8U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 3);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 5);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c4_sum_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 6);
    for (c4_i1 = 0; c4_i1 < 8; c4_i1++) {
      chartInstance->c4_sum[c4_i1] = 0.0;
    }

    chartInstance->c4_sum_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 7);
    chartInstance->c4_alpha = 0.5;
    chartInstance->c4_alpha_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 8);
    chartInstance->c4_temp = 0.3;
    chartInstance->c4_temp_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 11);
  if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 0, c4_b_Enable, 1.0, -1, 0U,
        c4_b_Enable == 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 12);
    switch ((int32_T)sf_integer_check(chartInstance->S, 1U, 290U, 3U, c4_b_cnt))
    {
     case 1:
     case 2:
     case 3:
     case 4:
     case 5:
     case 6:
     case 7:
      CV_EML_SWITCH(0, 1, 0, 1);
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 14);
      chartInstance->c4_sum[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 337, 3, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 337U, 3U, c4_b_cnt), 1,
         8) - 1] = c4_b_Pek;
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 15);
      c4_b_THPout = 0.3;
      break;

     case 8:
      CV_EML_SWITCH(0, 1, 0, 2);
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 17);
      chartInstance->c4_sum[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 402, 3, MAX_uint32_T,
         (int32_T)sf_integer_check(chartInstance->S, 1U, 402U, 3U, c4_b_cnt), 1,
         8) - 1] = c4_b_Pek;
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 18);
      c4_d_hoistedGlobal = chartInstance->c4_alpha;
      for (c4_i2 = 0; c4_i2 < 8; c4_i2++) {
        c4_e_hoistedGlobal[c4_i2] = chartInstance->c4_sum[c4_i2];
      }

      c4_y = c4_e_hoistedGlobal[0];
      for (c4_k = 1; c4_k + 1 < 9; c4_k++) {
        c4_y += c4_e_hoistedGlobal[c4_k];
      }

      c4_A = c4_y;
      c4_h_x = c4_A;
      c4_i_x = c4_h_x;
      c4_b_y = c4_i_x / 8.0;
      c4_b_THPout = c4_d_hoistedGlobal * c4_b_y;
      break;

     default:
      CV_EML_SWITCH(0, 1, 0, 0);
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 20);
      c4_x = c4_b_cnt;
      c4_b_x = c4_x;
      c4_c_x = c4_b_x;
      c4_d_x = c4_c_x;
      c4_e_x = c4_d_x;
      c4_f_x = c4_e_x;
      c4_b = muDoubleScalarIsInf(c4_f_x);
      c4_b0 = !c4_b;
      c4_g_x = c4_e_x;
      c4_b_b = muDoubleScalarIsNaN(c4_g_x);
      c4_b1 = !c4_b_b;
      c4_c_b = (c4_b0 && c4_b1);
      if (c4_c_b) {
        if (c4_d_x == 0.0) {
          c4_r = 0.0;
        } else {
          c4_r = muDoubleScalarRem(c4_d_x, 8.0);
          c4_rEQ0 = (c4_r == 0.0);
          if (c4_rEQ0) {
            c4_r = 0.0;
          } else {
            if (c4_d_x < 0.0) {
              c4_r += 8.0;
            }
          }
        }
      } else {
        c4_r = rtNaN;
      }

      chartInstance->c4_sum[sf_eml_array_bounds_check
        (sfGlobalDebugInstanceStruct, chartInstance->S, 1U, 484, 12,
         MAX_uint32_T, (int32_T)sf_integer_check(chartInstance->S, 1U, 484U, 12U,
          c4_r + 1.0), 1, 8) - 1] = c4_b_Pek;
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 21);
      c4_f_hoistedGlobal = chartInstance->c4_alpha;
      for (c4_i3 = 0; c4_i3 < 8; c4_i3++) {
        c4_e_hoistedGlobal[c4_i3] = chartInstance->c4_sum[c4_i3];
      }

      c4_c_y = c4_e_hoistedGlobal[0];
      for (c4_b_k = 1; c4_b_k + 1 < 9; c4_b_k++) {
        c4_c_y += c4_e_hoistedGlobal[c4_b_k];
      }

      c4_b_A = c4_c_y;
      c4_j_x = c4_b_A;
      c4_k_x = c4_j_x;
      c4_d_y = c4_k_x / 8.0;
      c4_b_THPout = c4_f_hoistedGlobal * c4_d_y;
      break;
    }

    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 23);
    chartInstance->c4_temp = c4_b_THPout;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 25);
    c4_b_THPout = chartInstance->c4_temp;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -25);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c4_THPout = c4_b_THPout;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_dsmDemoMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_THPout, 3U, 1U, 0U,
                        chartInstance->c4_sfEvent, false);
}

static void mdl_start_c4_dsmDemo(SFc4_dsmDemoInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc4_dsmDemo(SFc4_dsmDemoInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber)
{
  (void)(c4_machineNumber);
  (void)(c4_chartNumber);
  (void)(c4_instanceNumber);
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_dsmDemoInstanceStruct *chartInstance;
  chartInstance = (SFc4_dsmDemoInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  if (!chartInstance->c4_temp_not_empty) {
    sf_mex_assign(&c4_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_emlrt_marshallIn(SFc4_dsmDemoInstanceStruct *chartInstance,
  const mxArray *c4_b_temp, const char_T *c4_identifier, boolean_T *c4_svPtr)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_temp), &c4_thisId,
    c4_svPtr);
  sf_mex_destroy(&c4_b_temp);
  return c4_y;
}

static real_T c4_b_emlrt_marshallIn(SFc4_dsmDemoInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, boolean_T
  *c4_svPtr)
{
  real_T c4_y;
  real_T c4_d0;
  (void)chartInstance;
  if (mxIsEmpty(c4_u)) {
    *c4_svPtr = false;
  } else {
    *c4_svPtr = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
    c4_y = c4_d0;
  }

  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_temp;
  const char_T *c4_identifier;
  boolean_T *c4_svPtr;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_dsmDemoInstanceStruct *chartInstance;
  chartInstance = (SFc4_dsmDemoInstanceStruct *)chartInstanceVoid;
  c4_b_temp = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_svPtr = &chartInstance->c4_temp_not_empty;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_temp), &c4_thisId,
    c4_svPtr);
  sf_mex_destroy(&c4_b_temp);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_i4;
  const mxArray *c4_y = NULL;
  real_T c4_u[8];
  SFc4_dsmDemoInstanceStruct *chartInstance;
  chartInstance = (SFc4_dsmDemoInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  for (c4_i4 = 0; c4_i4 < 8; c4_i4++) {
    c4_u[c4_i4] = (*(real_T (*)[8])c4_inData)[c4_i4];
  }

  c4_y = NULL;
  if (!chartInstance->c4_sum_not_empty) {
    sf_mex_assign(&c4_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 1, 8), false);
  }

  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_c_emlrt_marshallIn(SFc4_dsmDemoInstanceStruct *chartInstance,
  const mxArray *c4_b_sum, const char_T *c4_identifier, boolean_T *c4_svPtr,
  real_T c4_y[8])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sum), &c4_thisId,
                        c4_svPtr, c4_y);
  sf_mex_destroy(&c4_b_sum);
}

static void c4_d_emlrt_marshallIn(SFc4_dsmDemoInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, boolean_T
  *c4_svPtr, real_T c4_y[8])
{
  real_T c4_dv1[8];
  int32_T c4_i5;
  (void)chartInstance;
  if (mxIsEmpty(c4_u)) {
    *c4_svPtr = false;
  } else {
    *c4_svPtr = true;
    sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv1, 1, 0, 0U, 1, 0U, 2, 1,
                  8);
    for (c4_i5 = 0; c4_i5 < 8; c4_i5++) {
      c4_y[c4_i5] = c4_dv1[c4_i5];
    }
  }

  sf_mex_destroy(&c4_u);
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sum;
  const char_T *c4_identifier;
  boolean_T *c4_svPtr;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[8];
  int32_T c4_i6;
  SFc4_dsmDemoInstanceStruct *chartInstance;
  chartInstance = (SFc4_dsmDemoInstanceStruct *)chartInstanceVoid;
  c4_b_sum = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_svPtr = &chartInstance->c4_sum_not_empty;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sum), &c4_thisId,
                        c4_svPtr, c4_y);
  sf_mex_destroy(&c4_b_sum);
  for (c4_i6 = 0; c4_i6 < 8; c4_i6++) {
    (*(real_T (*)[8])c4_outData)[c4_i6] = c4_y[c4_i6];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_dsmDemoInstanceStruct *chartInstance;
  chartInstance = (SFc4_dsmDemoInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_e_emlrt_marshallIn(SFc4_dsmDemoInstanceStruct *chartInstance,
  const mxArray *c4_b_THPout, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_THPout),
    &c4_thisId);
  sf_mex_destroy(&c4_b_THPout);
  return c4_y;
}

static real_T c4_f_emlrt_marshallIn(SFc4_dsmDemoInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d1;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d1, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d1;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_THPout;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_dsmDemoInstanceStruct *chartInstance;
  chartInstance = (SFc4_dsmDemoInstanceStruct *)chartInstanceVoid;
  c4_b_THPout = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_THPout),
    &c4_thisId);
  sf_mex_destroy(&c4_b_THPout);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_dsmDemo_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_dsmDemoInstanceStruct *chartInstance;
  chartInstance = (SFc4_dsmDemoInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_g_emlrt_marshallIn(SFc4_dsmDemoInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i7;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i7, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i7;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_dsmDemoInstanceStruct *chartInstance;
  chartInstance = (SFc4_dsmDemoInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_h_emlrt_marshallIn(SFc4_dsmDemoInstanceStruct *chartInstance,
  const mxArray *c4_b_is_active_c4_dsmDemo, const char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_dsmDemo), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_dsmDemo);
  return c4_y;
}

static uint8_T c4_i_emlrt_marshallIn(SFc4_dsmDemoInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_dsmDemoInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc4_dsmDemoInstanceStruct *chartInstance)
{
  chartInstance->c4_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c4_Pek = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c4_THPout = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c4_Enable = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c4_cnt = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c4_dsmDemo_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(505104195U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(773662525U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1164648389U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1623192953U);
}

mxArray* sf_c4_dsmDemo_get_post_codegen_info(void);
mxArray *sf_c4_dsmDemo_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("5FWKW3Fcy4Jl6r4Xz2HMSH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c4_dsmDemo_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_dsmDemo_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_dsmDemo_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("hasBreakpoints");
  mxArray *hiddenFallbackType = mxCreateString("none");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c4_dsmDemo_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c4_dsmDemo_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c4_dsmDemo(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[5],T\"THPout\",},{M[4],M[0],T\"alpha\",S'l','i','p'{{M1x2[85 90],M[0],}}},{M[4],M[0],T\"sum\",S'l','i','p'{{M1x2[81 84],M[0],}}},{M[4],M[0],T\"temp\",S'l','i','p'{{M1x2[91 95],M[0],}}},{M[8],M[0],T\"is_active_c4_dsmDemo\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_dsmDemo_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_dsmDemoInstanceStruct *chartInstance = (SFc4_dsmDemoInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _dsmDemoMachineNumber_,
           4,
           1,
           1,
           0,
           4,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_dsmDemoMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_dsmDemoMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _dsmDemoMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Pek");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Enable");
          _SFD_SET_DATA_PROPS(2,1,1,0,"cnt");
          _SFD_SET_DATA_PROPS(3,2,0,1,"THPout");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,2,0,0,1,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,605);
        _SFD_CV_INIT_EML_IF(0,1,0,123,138,-1,197);
        _SFD_CV_INIT_EML_IF(0,1,1,261,277,570,598);

        {
          static int caseStart[] = { 460, 302, 381 };

          static int caseExprEnd[] = { 469, 322, 387 };

          _SFD_CV_INIT_EML_SWITCH(0,1,0,283,294,550,3,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,265,276,-1,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)c4_c_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _dsmDemoMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_dsmDemoInstanceStruct *chartInstance = (SFc4_dsmDemoInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c4_Pek);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c4_THPout);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c4_Enable);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c4_cnt);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "soBuB1ZMrC1dhNonCuRK2KB";
}

static void sf_opaque_initialize_c4_dsmDemo(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_dsmDemoInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c4_dsmDemo((SFc4_dsmDemoInstanceStruct*) chartInstanceVar);
  initialize_c4_dsmDemo((SFc4_dsmDemoInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_dsmDemo(void *chartInstanceVar)
{
  enable_c4_dsmDemo((SFc4_dsmDemoInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_dsmDemo(void *chartInstanceVar)
{
  disable_c4_dsmDemo((SFc4_dsmDemoInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_dsmDemo(void *chartInstanceVar)
{
  sf_gateway_c4_dsmDemo((SFc4_dsmDemoInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_dsmDemo(SimStruct* S)
{
  return get_sim_state_c4_dsmDemo((SFc4_dsmDemoInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_dsmDemo(SimStruct* S, const mxArray *st)
{
  set_sim_state_c4_dsmDemo((SFc4_dsmDemoInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c4_dsmDemo(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_dsmDemoInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_dsmDemo_optimization_info();
    }

    finalize_c4_dsmDemo((SFc4_dsmDemoInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_dsmDemo((SFc4_dsmDemoInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_dsmDemo(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_dsmDemo((SFc4_dsmDemoInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c4_dsmDemo(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_dsmDemo_optimization_info(sim_mode_is_rtw_gen(S),
      sim_mode_is_modelref_sim(S), sim_mode_is_external(S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,4,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 4);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3061401369U));
  ssSetChecksum1(S,(2997601839U));
  ssSetChecksum2(S,(1205138766U));
  ssSetChecksum3(S,(1323192366U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_dsmDemo(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_dsmDemo(SimStruct *S)
{
  SFc4_dsmDemoInstanceStruct *chartInstance;
  chartInstance = (SFc4_dsmDemoInstanceStruct *)utMalloc(sizeof
    (SFc4_dsmDemoInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc4_dsmDemoInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_dsmDemo;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_dsmDemo;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_dsmDemo;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_dsmDemo;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_dsmDemo;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_dsmDemo;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_dsmDemo;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c4_dsmDemo;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_dsmDemo;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_dsmDemo;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_dsmDemo;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c4_dsmDemo(chartInstance);
}

void c4_dsmDemo_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_dsmDemo(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_dsmDemo(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_dsmDemo(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_dsmDemo_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
