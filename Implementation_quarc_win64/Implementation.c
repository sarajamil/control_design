/*
 * Implementation.c
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
#include "Implementation_dt.h"

/* Block signals (auto storage) */
BlockIO_Implementation Implementation_B;

/* Block states (auto storage) */
D_Work_Implementation Implementation_DWork;

/* Real-time model */
RT_MODEL_Implementation Implementation_M_;
RT_MODEL_Implementation *const Implementation_M = &Implementation_M_;

/* Model output function */
void Implementation_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_HILReadTimebase[3];
  real_T rtb_Sum;
  real_T tmp[2];
  int32_T i;
  real_T tmp_0[4];
  real_T tmp_1[4];
  real_T rtb_Add_idx;

  /* S-Function (hil_read_timebase_block): '<S3>/HIL Read Timebase' */

  /* S-Function Block: Implementation/2 DOF PantoGraph/Encoders/HIL Read Timebase (hil_read_timebase_block) */
  {
    t_error result;
    result = hil_task_read(Implementation_DWork.HILReadTimebase_Task, 1,
      NULL,
      &Implementation_DWork.HILReadTimebase_EncoderBuffer[0],
      NULL,
      NULL
      );
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Implementation_M, _rt_error_message);
    } else {
      rtb_HILReadTimebase[0] =
        Implementation_DWork.HILReadTimebase_EncoderBuffer[0];
      rtb_HILReadTimebase[1] =
        Implementation_DWork.HILReadTimebase_EncoderBuffer[1];
      rtb_HILReadTimebase[2] =
        Implementation_DWork.HILReadTimebase_EncoderBuffer[2];
    }
  }

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Gain: '<S3>/gain t1 for 2dPanto'
   *  Gain: '<S3>/gain t1 for 2dPanto new'
   */
  if (Implementation_P.Constant1_Value > Implementation_P.Switch_Threshold) {
    rtb_Sum = Implementation_P.gaint1for2dPantonew_Gain * rtb_HILReadTimebase[0];
  } else {
    rtb_Sum = Implementation_P.gaint1for2dPanto_Gain * rtb_HILReadTimebase[0];
  }

  /* End of Switch: '<S3>/Switch' */

  /* Sum: '<S3>/Sum' incorporates:
   *  Constant: '<S3>/Constant2'
   */
  Implementation_B.Sum = rtb_Sum + Implementation_P.Constant2_Value;

  /* Sum: '<S3>/Sum1' incorporates:
   *  Constant: '<S3>/Constant3'
   *  Gain: '<S3>/gain t1 for 2dPanto new1'
   */
  Implementation_B.Sum1 = Implementation_P.gaint1for2dPantonew1_Gain *
    rtb_HILReadTimebase[2] + Implementation_P.Constant3_Value;

  /* Sum: '<Root>/Add1' incorporates:
   *  Constant: '<Root>/Linearization Point'
   */
  Implementation_B.Add1[0] = Implementation_B.Sum -
    Implementation_P.LinearizationPoint_Value[0];
  Implementation_B.Add1[1] = Implementation_B.Sum1 -
    Implementation_P.LinearizationPoint_Value[1];

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  Implementation_B.DiscreteTimeIntegrator[0] =
    Implementation_DWork.DiscreteTimeIntegrator_DSTATE[0];
  Implementation_B.DiscreteTimeIntegrator[1] =
    Implementation_DWork.DiscreteTimeIntegrator_DSTATE[1];
  Implementation_B.DiscreteTimeIntegrator[2] =
    Implementation_DWork.DiscreteTimeIntegrator_DSTATE[2];
  Implementation_B.DiscreteTimeIntegrator[3] =
    Implementation_DWork.DiscreteTimeIntegrator_DSTATE[3];

  /* Gain: '<Root>/Controller Gain K' */
  Implementation_B.ControllerGainK = ((Implementation_P.ControllerGainK_Gain[0] *
    Implementation_B.DiscreteTimeIntegrator[0] +
    Implementation_P.ControllerGainK_Gain[1] *
    Implementation_B.DiscreteTimeIntegrator[1]) +
    Implementation_P.ControllerGainK_Gain[2] *
    Implementation_B.DiscreteTimeIntegrator[2]) +
    Implementation_P.ControllerGainK_Gain[3] *
    Implementation_B.DiscreteTimeIntegrator[3];

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_Sum = Implementation_P.Constant_Value_o + Implementation_B.ControllerGainK;

  /* Sum: '<S2>/Add' incorporates:
   *  Constant: '<S2>/Constant'
   */
  rtb_Add_idx = Implementation_P.Constant_Value[0] + rtb_Sum;
  rtb_Sum += Implementation_P.Constant_Value[1];

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Gain: '<S2>/gain for 2DPanto amplifier'
   *  Gain: '<S2>/gain for 2DPanto new amplifier'
   */
  if (Implementation_P.Constant1_Value_c > Implementation_P.Switch_Threshold_g)
  {
    rtb_Add_idx *= Implementation_P.gainfor2DPantonewamplifier_Gain;
    rtb_Sum *= Implementation_P.gainfor2DPantonewamplifier_Gain;
  } else {
    rtb_Add_idx *= Implementation_P.gainfor2DPantoamplifier_Gain;
    rtb_Sum *= Implementation_P.gainfor2DPantoamplifier_Gain;
  }

  /* End of Switch: '<S2>/Switch' */

  /* Gain: '<S2>/K1' */
  Implementation_B.K1[0] = Implementation_P.K1_Gain[0] * rtb_Add_idx;
  Implementation_B.K1[1] = Implementation_P.K1_Gain[1] * rtb_Sum;

  /* S-Function (hil_write_analog_block): '<S2>/HIL Write Analog' */

  /* S-Function Block: Implementation/2 DOF PantoGraph/2Dpanto motor/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(Implementation_DWork.HILInitialize_Card,
      Implementation_P.HILWriteAnalog_Channels, 2, Implementation_B.K1);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Implementation_M, _rt_error_message);
    }
  }

  /* S-Function (hil_write_digital_block): '<S2>/HIL Write Digital' */

  /* S-Function Block: Implementation/2 DOF PantoGraph/2Dpanto motor/HIL Write Digital (hil_write_digital_block) */
  {
    t_error result;
    Implementation_DWork.HILWriteDigital_Buffer[0] =
      (Implementation_P.Constant_Value_j[0] != 0);
    Implementation_DWork.HILWriteDigital_Buffer[1] =
      (Implementation_P.Constant_Value_j[1] != 0);
    Implementation_DWork.HILWriteDigital_Buffer[2] =
      (Implementation_P.Constant_Value_j[2] != 0);
    Implementation_DWork.HILWriteDigital_Buffer[3] =
      (Implementation_P.Constant_Value_j[3] != 0);
    result = hil_write_digital(Implementation_DWork.HILInitialize_Card,
      Implementation_P.HILWriteDigital_Channels, 4,
      &Implementation_DWork.HILWriteDigital_Buffer[0]);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Implementation_M, _rt_error_message);
    }
  }

  /* Sum: '<Root>/Add3' incorporates:
   *  Gain: '<Root>/C Matrix'
   *  Gain: '<Root>/Gain4'
   */
  for (i = 0; i < 2; i++) {
    tmp[i] = Implementation_B.Add1[i] - (((Implementation_P.CMatrix_Gain[i + 2] *
      Implementation_B.DiscreteTimeIntegrator[1] +
      Implementation_P.CMatrix_Gain[i] *
      Implementation_B.DiscreteTimeIntegrator[0]) +
      Implementation_P.CMatrix_Gain[i + 4] *
      Implementation_B.DiscreteTimeIntegrator[2]) +
      Implementation_P.CMatrix_Gain[i + 6] *
      Implementation_B.DiscreteTimeIntegrator[3]);
  }

  /* End of Sum: '<Root>/Add3' */

  /* Sum: '<Root>/Add2' incorporates:
   *  Gain: '<Root>/A Matrix'
   *  Gain: '<Root>/B Matrix'
   */
  for (i = 0; i < 4; i++) {
    tmp_0[i] = (((Implementation_P.AMatrix_Gain[i + 4] *
                  Implementation_B.DiscreteTimeIntegrator[1] +
                  Implementation_P.AMatrix_Gain[i] *
                  Implementation_B.DiscreteTimeIntegrator[0]) +
                 Implementation_P.AMatrix_Gain[i + 8] *
                 Implementation_B.DiscreteTimeIntegrator[2]) +
                Implementation_P.AMatrix_Gain[i + 12] *
                Implementation_B.DiscreteTimeIntegrator[3]) +
      Implementation_P.BMatrix_Gain[i] * Implementation_B.ControllerGainK;
  }

  /* Gain: '<Root>/Gain4' incorporates:
   *  Sum: '<Root>/Add2'
   */
  for (i = 0; i < 4; i++) {
    tmp_1[i] = Implementation_P.Gain4_Gain[i + 4] * tmp[1] +
      Implementation_P.Gain4_Gain[i] * tmp[0];
  }

  /* Sum: '<Root>/Add2' */
  Implementation_B.Add2[0] = tmp_0[0] + tmp_1[0];
  Implementation_B.Add2[1] = tmp_0[1] + tmp_1[1];
  Implementation_B.Add2[2] = tmp_0[2] + tmp_1[2];
  Implementation_B.Add2[3] = tmp_0[3] + tmp_1[3];

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void Implementation_update(int_T tid)
{
  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  Implementation_DWork.DiscreteTimeIntegrator_DSTATE[0] =
    Implementation_P.DiscreteTimeIntegrator_gainval * Implementation_B.Add2[0] +
    Implementation_DWork.DiscreteTimeIntegrator_DSTATE[0];
  Implementation_DWork.DiscreteTimeIntegrator_DSTATE[1] =
    Implementation_P.DiscreteTimeIntegrator_gainval * Implementation_B.Add2[1] +
    Implementation_DWork.DiscreteTimeIntegrator_DSTATE[1];
  Implementation_DWork.DiscreteTimeIntegrator_DSTATE[2] =
    Implementation_P.DiscreteTimeIntegrator_gainval * Implementation_B.Add2[2] +
    Implementation_DWork.DiscreteTimeIntegrator_DSTATE[2];
  Implementation_DWork.DiscreteTimeIntegrator_DSTATE[3] =
    Implementation_P.DiscreteTimeIntegrator_gainval * Implementation_B.Add2[3] +
    Implementation_DWork.DiscreteTimeIntegrator_DSTATE[3];

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Implementation_M->Timing.clockTick0)) {
    ++Implementation_M->Timing.clockTickH0;
  }

  Implementation_M->Timing.t[0] = Implementation_M->Timing.clockTick0 *
    Implementation_M->Timing.stepSize0 + Implementation_M->Timing.clockTickH0 *
    Implementation_M->Timing.stepSize0 * 4294967296.0;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void Implementation_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Implementation_M, 0,
                sizeof(RT_MODEL_Implementation));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Implementation_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    Implementation_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Implementation_M->Timing.sampleTimes =
      (&Implementation_M->Timing.sampleTimesArray[0]);
    Implementation_M->Timing.offsetTimes =
      (&Implementation_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Implementation_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    Implementation_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Implementation_M, &Implementation_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Implementation_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Implementation_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Implementation_M, -1);
  Implementation_M->Timing.stepSize0 = 0.001;

  /* external mode info */
  Implementation_M->Sizes.checksums[0] = (2862216419U);
  Implementation_M->Sizes.checksums[1] = (837169904U);
  Implementation_M->Sizes.checksums[2] = (1435101276U);
  Implementation_M->Sizes.checksums[3] = (910492603U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    Implementation_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Implementation_M->extModeInfo,
      &Implementation_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Implementation_M->extModeInfo,
                        Implementation_M->Sizes.checksums);
    rteiSetTPtr(Implementation_M->extModeInfo, rtmGetTPtr(Implementation_M));
  }

  Implementation_M->solverInfoPtr = (&Implementation_M->solverInfo);
  Implementation_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Implementation_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Implementation_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Implementation_M->ModelData.blockIO = ((void *) &Implementation_B);
  (void) memset(((void *) &Implementation_B), 0,
                sizeof(BlockIO_Implementation));

  /* parameters */
  Implementation_M->ModelData.defaultParam = ((real_T *)&Implementation_P);

  /* states (dwork) */
  Implementation_M->Work.dwork = ((void *) &Implementation_DWork);
  (void) memset((void *)&Implementation_DWork, 0,
                sizeof(D_Work_Implementation));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Implementation_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }
}

/* Model terminate function */
void Implementation_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Implementation/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    hil_task_stop_all(Implementation_DWork.HILInitialize_Card);
    hil_monitor_stop_all(Implementation_DWork.HILInitialize_Card);
    is_switching = false;
    if ((Implementation_P.HILInitialize_AOTerminate && !is_switching) ||
        (Implementation_P.HILInitialize_AOExit && is_switching)) {
      Implementation_DWork.HILInitialize_AOVoltages[0] =
        Implementation_P.HILInitialize_AOFinal;
      Implementation_DWork.HILInitialize_AOVoltages[1] =
        Implementation_P.HILInitialize_AOFinal;
      Implementation_DWork.HILInitialize_AOVoltages[2] =
        Implementation_P.HILInitialize_AOFinal;
      Implementation_DWork.HILInitialize_AOVoltages[3] =
        Implementation_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 4U;
    }

    if ((Implementation_P.HILInitialize_DOTerminate && !is_switching) ||
        (Implementation_P.HILInitialize_DOExit && is_switching)) {
      Implementation_DWork.HILInitialize_DOBits[0] =
        Implementation_P.HILInitialize_DOFinal;
      Implementation_DWork.HILInitialize_DOBits[1] =
        Implementation_P.HILInitialize_DOFinal;
      Implementation_DWork.HILInitialize_DOBits[2] =
        Implementation_P.HILInitialize_DOFinal;
      Implementation_DWork.HILInitialize_DOBits[3] =
        Implementation_P.HILInitialize_DOFinal;
      num_final_digital_outputs = 4U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_digital_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(Implementation_DWork.HILInitialize_Card
                         , Implementation_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , Implementation_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , NULL, 0
                         , &Implementation_DWork.HILInitialize_AOVoltages[0]
                         , NULL
                         , &Implementation_DWork.HILInitialize_DOBits[0]
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (Implementation_DWork.HILInitialize_Card,
             Implementation_P.HILInitialize_AOChannels, num_final_analog_outputs,
             &Implementation_DWork.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (Implementation_DWork.HILInitialize_Card,
             Implementation_P.HILInitialize_DOChannels,
             num_final_digital_outputs,
             &Implementation_DWork.HILInitialize_DOBits[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Implementation_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Implementation_DWork.HILInitialize_Card);
    hil_monitor_delete_all(Implementation_DWork.HILInitialize_Card);
    hil_close(Implementation_DWork.HILInitialize_Card);
    Implementation_DWork.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Implementation_output(tid);
}

void MdlUpdate(int_T tid)
{
  Implementation_update(tid);
}

void MdlInitializeSizes(void)
{
  Implementation_M->Sizes.numContStates = (0);/* Number of continuous states */
  Implementation_M->Sizes.numY = (0);  /* Number of model outputs */
  Implementation_M->Sizes.numU = (0);  /* Number of model inputs */
  Implementation_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Implementation_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Implementation_M->Sizes.numBlocks = (45);/* Number of blocks */
  Implementation_M->Sizes.numBlockIO = (7);/* Number of block outputs */
  Implementation_M->Sizes.numBlockPrms = (155);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  Implementation_DWork.DiscreteTimeIntegrator_DSTATE[0] =
    Implementation_P.DiscreteTimeIntegrator_IC[0];
  Implementation_DWork.DiscreteTimeIntegrator_DSTATE[1] =
    Implementation_P.DiscreteTimeIntegrator_IC[1];
  Implementation_DWork.DiscreteTimeIntegrator_DSTATE[2] =
    Implementation_P.DiscreteTimeIntegrator_IC[2];
  Implementation_DWork.DiscreteTimeIntegrator_DSTATE[3] =
    Implementation_P.DiscreteTimeIntegrator_IC[3];
}

void MdlStart(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Implementation/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q4", "0", &Implementation_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Implementation_M, _rt_error_message);
      return;
    }

    is_switching = false;
    if ((Implementation_P.HILInitialize_CKPStart && !is_switching) ||
        (Implementation_P.HILInitialize_CKPEnter && is_switching)) {
      result = hil_set_clock_mode(Implementation_DWork.HILInitialize_Card,
        (t_clock *) Implementation_P.HILInitialize_CKChannels, 2U, (t_clock_mode
        *) Implementation_P.HILInitialize_CKModes);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Implementation_M, _rt_error_message);
        return;
      }
    }

    result = hil_watchdog_clear(Implementation_DWork.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Implementation_M, _rt_error_message);
      return;
    }

    if ((Implementation_P.HILInitialize_AIPStart && !is_switching) ||
        (Implementation_P.HILInitialize_AIPEnter && is_switching)) {
      Implementation_DWork.HILInitialize_AIMinimums[0] =
        Implementation_P.HILInitialize_AILow;
      Implementation_DWork.HILInitialize_AIMinimums[1] =
        Implementation_P.HILInitialize_AILow;
      Implementation_DWork.HILInitialize_AIMinimums[2] =
        Implementation_P.HILInitialize_AILow;
      Implementation_DWork.HILInitialize_AIMinimums[3] =
        Implementation_P.HILInitialize_AILow;
      Implementation_DWork.HILInitialize_AIMaximums[0] =
        Implementation_P.HILInitialize_AIHigh;
      Implementation_DWork.HILInitialize_AIMaximums[1] =
        Implementation_P.HILInitialize_AIHigh;
      Implementation_DWork.HILInitialize_AIMaximums[2] =
        Implementation_P.HILInitialize_AIHigh;
      Implementation_DWork.HILInitialize_AIMaximums[3] =
        Implementation_P.HILInitialize_AIHigh;
      result = hil_set_analog_input_ranges
        (Implementation_DWork.HILInitialize_Card,
         Implementation_P.HILInitialize_AIChannels, 4U,
         &Implementation_DWork.HILInitialize_AIMinimums[0],
         &Implementation_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Implementation_M, _rt_error_message);
        return;
      }
    }

    if ((Implementation_P.HILInitialize_AOPStart && !is_switching) ||
        (Implementation_P.HILInitialize_AOPEnter && is_switching)) {
      Implementation_DWork.HILInitialize_AOMinimums[0] =
        Implementation_P.HILInitialize_AOLow;
      Implementation_DWork.HILInitialize_AOMinimums[1] =
        Implementation_P.HILInitialize_AOLow;
      Implementation_DWork.HILInitialize_AOMinimums[2] =
        Implementation_P.HILInitialize_AOLow;
      Implementation_DWork.HILInitialize_AOMinimums[3] =
        Implementation_P.HILInitialize_AOLow;
      Implementation_DWork.HILInitialize_AOMaximums[0] =
        Implementation_P.HILInitialize_AOHigh;
      Implementation_DWork.HILInitialize_AOMaximums[1] =
        Implementation_P.HILInitialize_AOHigh;
      Implementation_DWork.HILInitialize_AOMaximums[2] =
        Implementation_P.HILInitialize_AOHigh;
      Implementation_DWork.HILInitialize_AOMaximums[3] =
        Implementation_P.HILInitialize_AOHigh;
      result = hil_set_analog_output_ranges
        (Implementation_DWork.HILInitialize_Card,
         Implementation_P.HILInitialize_AOChannels, 4U,
         &Implementation_DWork.HILInitialize_AOMinimums[0],
         &Implementation_DWork.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Implementation_M, _rt_error_message);
        return;
      }
    }

    if ((Implementation_P.HILInitialize_AOStart && !is_switching) ||
        (Implementation_P.HILInitialize_AOEnter && is_switching)) {
      Implementation_DWork.HILInitialize_AOVoltages[0] =
        Implementation_P.HILInitialize_AOInitial;
      Implementation_DWork.HILInitialize_AOVoltages[1] =
        Implementation_P.HILInitialize_AOInitial;
      Implementation_DWork.HILInitialize_AOVoltages[2] =
        Implementation_P.HILInitialize_AOInitial;
      Implementation_DWork.HILInitialize_AOVoltages[3] =
        Implementation_P.HILInitialize_AOInitial;
      result = hil_write_analog(Implementation_DWork.HILInitialize_Card,
        Implementation_P.HILInitialize_AOChannels, 4U,
        &Implementation_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Implementation_M, _rt_error_message);
        return;
      }
    }

    if (Implementation_P.HILInitialize_AOReset) {
      Implementation_DWork.HILInitialize_AOVoltages[0] =
        Implementation_P.HILInitialize_AOWatchdog;
      Implementation_DWork.HILInitialize_AOVoltages[1] =
        Implementation_P.HILInitialize_AOWatchdog;
      Implementation_DWork.HILInitialize_AOVoltages[2] =
        Implementation_P.HILInitialize_AOWatchdog;
      Implementation_DWork.HILInitialize_AOVoltages[3] =
        Implementation_P.HILInitialize_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (Implementation_DWork.HILInitialize_Card,
         Implementation_P.HILInitialize_AOChannels, 4U,
         &Implementation_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Implementation_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(Implementation_DWork.HILInitialize_Card,
      NULL, 0U, Implementation_P.HILInitialize_DOChannels, 4U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Implementation_M, _rt_error_message);
      return;
    }

    if ((Implementation_P.HILInitialize_DOStart && !is_switching) ||
        (Implementation_P.HILInitialize_DOEnter && is_switching)) {
      Implementation_DWork.HILInitialize_DOBits[0] =
        Implementation_P.HILInitialize_DOInitial;
      Implementation_DWork.HILInitialize_DOBits[1] =
        Implementation_P.HILInitialize_DOInitial;
      Implementation_DWork.HILInitialize_DOBits[2] =
        Implementation_P.HILInitialize_DOInitial;
      Implementation_DWork.HILInitialize_DOBits[3] =
        Implementation_P.HILInitialize_DOInitial;
      result = hil_write_digital(Implementation_DWork.HILInitialize_Card,
        Implementation_P.HILInitialize_DOChannels, 4U, (t_boolean *)
        &Implementation_DWork.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Implementation_M, _rt_error_message);
        return;
      }
    }

    if (Implementation_P.HILInitialize_DOReset) {
      Implementation_DWork.HILInitialize_DOStates[0] =
        Implementation_P.HILInitialize_DOWatchdog;
      Implementation_DWork.HILInitialize_DOStates[1] =
        Implementation_P.HILInitialize_DOWatchdog;
      Implementation_DWork.HILInitialize_DOStates[2] =
        Implementation_P.HILInitialize_DOWatchdog;
      Implementation_DWork.HILInitialize_DOStates[3] =
        Implementation_P.HILInitialize_DOWatchdog;
      result = hil_watchdog_set_digital_expiration_state
        (Implementation_DWork.HILInitialize_Card,
         Implementation_P.HILInitialize_DOChannels, 4U, (const t_digital_state *)
         &Implementation_DWork.HILInitialize_DOStates[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Implementation_M, _rt_error_message);
        return;
      }
    }

    if ((Implementation_P.HILInitialize_EIPStart && !is_switching) ||
        (Implementation_P.HILInitialize_EIPEnter && is_switching)) {
      Implementation_DWork.HILInitialize_QuadratureModes[0] =
        Implementation_P.HILInitialize_EIQuadrature;
      Implementation_DWork.HILInitialize_QuadratureModes[1] =
        Implementation_P.HILInitialize_EIQuadrature;
      Implementation_DWork.HILInitialize_QuadratureModes[2] =
        Implementation_P.HILInitialize_EIQuadrature;
      Implementation_DWork.HILInitialize_QuadratureModes[3] =
        Implementation_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (Implementation_DWork.HILInitialize_Card,
         Implementation_P.HILInitialize_EIChannels, 4U,
         (t_encoder_quadrature_mode *)
         &Implementation_DWork.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Implementation_M, _rt_error_message);
        return;
      }

      Implementation_DWork.HILInitialize_FilterFrequency[0] =
        Implementation_P.HILInitialize_EIFrequency;
      Implementation_DWork.HILInitialize_FilterFrequency[1] =
        Implementation_P.HILInitialize_EIFrequency;
      Implementation_DWork.HILInitialize_FilterFrequency[2] =
        Implementation_P.HILInitialize_EIFrequency;
      Implementation_DWork.HILInitialize_FilterFrequency[3] =
        Implementation_P.HILInitialize_EIFrequency;
      result = hil_set_encoder_filter_frequency
        (Implementation_DWork.HILInitialize_Card,
         Implementation_P.HILInitialize_EIChannels, 4U,
         &Implementation_DWork.HILInitialize_FilterFrequency[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Implementation_M, _rt_error_message);
        return;
      }
    }

    if ((Implementation_P.HILInitialize_EIStart && !is_switching) ||
        (Implementation_P.HILInitialize_EIEnter && is_switching)) {
      Implementation_DWork.HILInitialize_InitialEICounts[0] =
        Implementation_P.HILInitialize_EIInitial;
      Implementation_DWork.HILInitialize_InitialEICounts[1] =
        Implementation_P.HILInitialize_EIInitial;
      Implementation_DWork.HILInitialize_InitialEICounts[2] =
        Implementation_P.HILInitialize_EIInitial;
      Implementation_DWork.HILInitialize_InitialEICounts[3] =
        Implementation_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(Implementation_DWork.HILInitialize_Card,
        Implementation_P.HILInitialize_EIChannels, 4U,
        &Implementation_DWork.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Implementation_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_timebase_block): '<S3>/HIL Read Timebase' */

  /* S-Function Block: Implementation/2 DOF PantoGraph/Encoders/HIL Read Timebase (hil_read_timebase_block) */
  {
    t_error result;
    result = hil_task_create_reader(Implementation_DWork.HILInitialize_Card,
      Implementation_P.HILReadTimebase_SamplesInBuffer,
      NULL, 0U,
      Implementation_P.HILReadTimebase_EncoderChannels, 3U,
      NULL, 0U,
      NULL, 0U,
      &Implementation_DWork.HILReadTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Implementation_M, _rt_error_message);
    }
  }

  MdlInitialize();
}

void MdlTerminate(void)
{
  Implementation_terminate();
}

RT_MODEL_Implementation *Implementation(void)
{
  Implementation_initialize(1);
  return Implementation_M;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
