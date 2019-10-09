/*
 * Implementation_data.c
 *
 * Code generation for model "Implementation.mdl".
 *
 * Model version              : 1.23
 * Simulink Coder version : 8.1 (R2011b) 08-Jul-2011
 * C source code generated on : Tue Nov 24 15:12:46 2015
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "Implementation.h"
#include "Implementation_private.h"

/* Block parameters (auto storage) */
Parameters_Implementation Implementation_P = {
  0.00044285714285714284,              /* Expression: 1/1000*2.17/4.9
                                        * Referenced by: '<S2>/gain for 2DPanto amplifier'
                                        */
  -0.0017714285714285714,              /* Expression: -1/1000*4*2.17/4.9
                                        * Referenced by: '<S2>/gain for 2DPanto new amplifier'
                                        */
  -8.1812308687234189E-5,              /* Expression: -2*pi/1024/75
                                        * Referenced by: '<S3>/gain t1 for 2dPanto'
                                        */
  8.1812308687234189E-5,               /* Expression: 2*pi/1024/75
                                        * Referenced by: '<S3>/gain t1 for 2dPanto new'
                                        */
  0.0,                                 /* Expression: set_other_outputs_at_start
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: set_other_outputs_at_switch_in
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: set_other_outputs_at_terminate
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: set_other_outputs_at_switch_out
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  10.0,                                /* Expression: analog_input_maximums
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  -10.0,                               /* Expression: analog_input_minimums
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  10.0,                                /* Expression: analog_output_maximums
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  -10.0,                               /* Expression: analog_output_minimums
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: initial_analog_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: final_analog_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: watchdog_analog_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1.6666666666666668E+7,               /* Expression: encoder_filter_frequency
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  16276.041666666668,                  /* Expression: pwm_frequency
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: initial_pwm_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: final_pwm_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: NewPanto
                                        * Referenced by: '<S3>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Switch'
                                        */
  0.78539816339744828,                 /* Expression: q1
                                        * Referenced by: '<S3>/Constant2'
                                        */
  0.78539816339744828,                 /* Expression: q2
                                        * Referenced by: '<S3>/Constant3'
                                        */
  0.0012566370614359172,               /* Expression: 2*pi/1000/5
                                        * Referenced by: '<S3>/gain t1 for 2dPanto new1'
                                        */

  /*  Expression: [q1 q2]
   * Referenced by: '<Root>/Linearization Point'
   */
  { 0.78539816339744828, 0.78539816339744828 },
  0.001,                               /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<Root>/Discrete-Time Integrator'
                                        */

  /*  Expression: [0 0 0 0]'
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: -K
   * Referenced by: '<Root>/Controller Gain K'
   */
  { 7726.2953535043407, 5089.4373878789384, 1345.67251096122, 474.18179671728166
  },

  /*  Expression: [1 1]*0
   * Referenced by: '<S2>/Constant'
   */
  { 0.0, 0.0 },
  50.0,                                /* Expression: 50
                                        * Referenced by: '<Root>/Constant'
                                        */
  0.0,                                 /* Expression: NewPanto
                                        * Referenced by: '<S2>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Switch'
                                        */

  /*  Expression: [1 1]
   * Referenced by: '<S2>/K1'
   */
  { 1.0, 1.0 },

  /*  Expression: [1 1 1 1]
   * Referenced by: '<S4>/Constant'
   */
  { 1.0, 1.0, 1.0, 1.0 },

  /*  Expression: A
   * Referenced by: '<Root>/A Matrix'
   */
  { 0.0, 0.0, 0.49404371119507751, 110.51869814774386, 0.0, 0.0,
    -3.088394167244334, 124.72783090118169, 1.0, 0.0, -2.5895967797573345,
    10.271196785546552, 0.0, 1.0, 0.0040549965969400607, -0.12653121802308717 },

  /*  Expression: B
   * Referenced by: '<Root>/B Matrix'
   */
  { 0.0, 0.0, 0.092104025457296013, -0.36531500873333878 },

  /*  Expression: C
   * Referenced by: '<Root>/C Matrix'
   */
  { 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: L
   * Referenced by: '<Root>/Gain4'
   */
  { 266.08133061582191, 16.299421910654342, 17136.25569814532, 3630.248661450355,
    4.10084663898807, 251.20254138643753, 523.36257254186057, 15710.205917150413
  },

  /*  Computed Parameter: HILInitialize_CKChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0, 1 },

  /*  Computed Parameter: HILInitialize_CKModes
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0, 0 },
  2,                                   /* Computed Parameter: HILInitialize_DOWatchdog
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_EIInitial
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_POModes
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILReadTimebase_Clock
                                        * Referenced by: '<S3>/HIL Read Timebase'
                                        */

  /*  Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U },

  /*  Computed Parameter: HILInitialize_AOChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U },

  /*  Computed Parameter: HILInitialize_DOChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U },

  /*  Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U },
  4U,                                  /* Computed Parameter: HILInitialize_EIQuadrature
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1000U,                               /* Computed Parameter: HILReadTimebase_SamplesInBuffer
                                        * Referenced by: '<S3>/HIL Read Timebase'
                                        */

  /*  Computed Parameter: HILReadTimebase_EncoderChannels
   * Referenced by: '<S3>/HIL Read Timebase'
   */
  { 0U, 1U, 2U },

  /*  Computed Parameter: HILWriteAnalog_Channels
   * Referenced by: '<S2>/HIL Write Analog'
   */
  { 0U, 1U },

  /*  Computed Parameter: HILWriteDigital_Channels
   * Referenced by: '<S2>/HIL Write Digital'
   */
  { 0U, 1U, 2U, 3U },
  1,                                   /* Computed Parameter: HILInitialize_Active
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_CKPStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_CKPEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_CKStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_CKEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_AIPStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_AIPEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_AOPStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_AOPEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_AOStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_AOEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_AOTerminate
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_AOExit
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_AOReset
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_DOPStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_DOPEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_DOStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_DOEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_DOTerminate
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_DOExit
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_DOReset
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_EIPStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_EIPEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_EIStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_EIEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_POPStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_POPEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_POStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_POEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_POTerminate
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_POExit
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_POReset
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_OOReset
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_DOInitial
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_DOFinal
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILReadTimebase_Active
                                        * Referenced by: '<S3>/HIL Read Timebase'
                                        */
  0,                                   /* Computed Parameter: HILWriteAnalog_Active
                                        * Referenced by: '<S2>/HIL Write Analog'
                                        */
  0                                    /* Computed Parameter: HILWriteDigital_Active
                                        * Referenced by: '<S2>/HIL Write Digital'
                                        */
};
