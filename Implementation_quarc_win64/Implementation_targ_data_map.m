  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Implementation_P)
    ;%
      section.nData     = 38;
      section.data(38)  = dumData; %prealloc
      
	  ;% Implementation_P.gainfor2DPantoamplifier_Gain
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Implementation_P.gainfor2DPantonewamplifier_Gain
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Implementation_P.gaint1for2dPanto_Gain
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Implementation_P.gaint1for2dPantonew_Gain
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Implementation_P.HILInitialize_OOStart
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Implementation_P.HILInitialize_OOEnter
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Implementation_P.HILInitialize_OOTerminate
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Implementation_P.HILInitialize_OOExit
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Implementation_P.HILInitialize_AIHigh
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Implementation_P.HILInitialize_AILow
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Implementation_P.HILInitialize_AOHigh
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Implementation_P.HILInitialize_AOLow
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Implementation_P.HILInitialize_AOInitial
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Implementation_P.HILInitialize_AOFinal
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Implementation_P.HILInitialize_AOWatchdog
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Implementation_P.HILInitialize_EIFrequency
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Implementation_P.HILInitialize_POFrequency
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Implementation_P.HILInitialize_POInitial
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Implementation_P.HILInitialize_POFinal
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Implementation_P.Constant1_Value
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Implementation_P.Switch_Threshold
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Implementation_P.Constant2_Value
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Implementation_P.Constant3_Value
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Implementation_P.gaint1for2dPantonew1_Gain
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Implementation_P.LinearizationPoint_Value
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Implementation_P.DiscreteTimeIntegrator_gainval
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 26;
	
	  ;% Implementation_P.DiscreteTimeIntegrator_IC
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 27;
	
	  ;% Implementation_P.ControllerGainK_Gain
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 31;
	
	  ;% Implementation_P.Constant_Value
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 35;
	
	  ;% Implementation_P.Constant_Value_o
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 37;
	
	  ;% Implementation_P.Constant1_Value_c
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 38;
	
	  ;% Implementation_P.Switch_Threshold_g
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 39;
	
	  ;% Implementation_P.K1_Gain
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 40;
	
	  ;% Implementation_P.Constant_Value_j
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 42;
	
	  ;% Implementation_P.AMatrix_Gain
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 46;
	
	  ;% Implementation_P.BMatrix_Gain
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 62;
	
	  ;% Implementation_P.CMatrix_Gain
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 66;
	
	  ;% Implementation_P.Gain4_Gain
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 74;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% Implementation_P.HILInitialize_CKChannels
	  section.data(1).logicalSrcIdx = 38;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Implementation_P.HILInitialize_CKModes
	  section.data(2).logicalSrcIdx = 39;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Implementation_P.HILInitialize_DOWatchdog
	  section.data(3).logicalSrcIdx = 40;
	  section.data(3).dtTransOffset = 4;
	
	  ;% Implementation_P.HILInitialize_EIInitial
	  section.data(4).logicalSrcIdx = 41;
	  section.data(4).dtTransOffset = 5;
	
	  ;% Implementation_P.HILInitialize_POModes
	  section.data(5).logicalSrcIdx = 42;
	  section.data(5).dtTransOffset = 6;
	
	  ;% Implementation_P.HILReadTimebase_Clock
	  section.data(6).logicalSrcIdx = 43;
	  section.data(6).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% Implementation_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Implementation_P.HILInitialize_AOChannels
	  section.data(2).logicalSrcIdx = 45;
	  section.data(2).dtTransOffset = 4;
	
	  ;% Implementation_P.HILInitialize_DOChannels
	  section.data(3).logicalSrcIdx = 46;
	  section.data(3).dtTransOffset = 8;
	
	  ;% Implementation_P.HILInitialize_EIChannels
	  section.data(4).logicalSrcIdx = 47;
	  section.data(4).dtTransOffset = 12;
	
	  ;% Implementation_P.HILInitialize_EIQuadrature
	  section.data(5).logicalSrcIdx = 48;
	  section.data(5).dtTransOffset = 16;
	
	  ;% Implementation_P.HILReadTimebase_SamplesInBuffer
	  section.data(6).logicalSrcIdx = 49;
	  section.data(6).dtTransOffset = 17;
	
	  ;% Implementation_P.HILReadTimebase_EncoderChannels
	  section.data(7).logicalSrcIdx = 50;
	  section.data(7).dtTransOffset = 18;
	
	  ;% Implementation_P.HILWriteAnalog_Channels
	  section.data(8).logicalSrcIdx = 51;
	  section.data(8).dtTransOffset = 21;
	
	  ;% Implementation_P.HILWriteDigital_Channels
	  section.data(9).logicalSrcIdx = 52;
	  section.data(9).dtTransOffset = 23;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 38;
      section.data(38)  = dumData; %prealloc
      
	  ;% Implementation_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 53;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Implementation_P.HILInitialize_CKPStart
	  section.data(2).logicalSrcIdx = 54;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Implementation_P.HILInitialize_CKPEnter
	  section.data(3).logicalSrcIdx = 55;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Implementation_P.HILInitialize_CKStart
	  section.data(4).logicalSrcIdx = 56;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Implementation_P.HILInitialize_CKEnter
	  section.data(5).logicalSrcIdx = 57;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Implementation_P.HILInitialize_AIPStart
	  section.data(6).logicalSrcIdx = 58;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Implementation_P.HILInitialize_AIPEnter
	  section.data(7).logicalSrcIdx = 59;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Implementation_P.HILInitialize_AOPStart
	  section.data(8).logicalSrcIdx = 60;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Implementation_P.HILInitialize_AOPEnter
	  section.data(9).logicalSrcIdx = 61;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Implementation_P.HILInitialize_AOStart
	  section.data(10).logicalSrcIdx = 62;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Implementation_P.HILInitialize_AOEnter
	  section.data(11).logicalSrcIdx = 63;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Implementation_P.HILInitialize_AOTerminate
	  section.data(12).logicalSrcIdx = 64;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Implementation_P.HILInitialize_AOExit
	  section.data(13).logicalSrcIdx = 65;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Implementation_P.HILInitialize_AOReset
	  section.data(14).logicalSrcIdx = 66;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Implementation_P.HILInitialize_DOPStart
	  section.data(15).logicalSrcIdx = 67;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Implementation_P.HILInitialize_DOPEnter
	  section.data(16).logicalSrcIdx = 68;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Implementation_P.HILInitialize_DOStart
	  section.data(17).logicalSrcIdx = 69;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Implementation_P.HILInitialize_DOEnter
	  section.data(18).logicalSrcIdx = 70;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Implementation_P.HILInitialize_DOTerminate
	  section.data(19).logicalSrcIdx = 71;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Implementation_P.HILInitialize_DOExit
	  section.data(20).logicalSrcIdx = 72;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Implementation_P.HILInitialize_DOReset
	  section.data(21).logicalSrcIdx = 73;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Implementation_P.HILInitialize_EIPStart
	  section.data(22).logicalSrcIdx = 74;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Implementation_P.HILInitialize_EIPEnter
	  section.data(23).logicalSrcIdx = 75;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Implementation_P.HILInitialize_EIStart
	  section.data(24).logicalSrcIdx = 76;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Implementation_P.HILInitialize_EIEnter
	  section.data(25).logicalSrcIdx = 77;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Implementation_P.HILInitialize_POPStart
	  section.data(26).logicalSrcIdx = 78;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Implementation_P.HILInitialize_POPEnter
	  section.data(27).logicalSrcIdx = 79;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Implementation_P.HILInitialize_POStart
	  section.data(28).logicalSrcIdx = 80;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Implementation_P.HILInitialize_POEnter
	  section.data(29).logicalSrcIdx = 81;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Implementation_P.HILInitialize_POTerminate
	  section.data(30).logicalSrcIdx = 82;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Implementation_P.HILInitialize_POExit
	  section.data(31).logicalSrcIdx = 83;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Implementation_P.HILInitialize_POReset
	  section.data(32).logicalSrcIdx = 84;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Implementation_P.HILInitialize_OOReset
	  section.data(33).logicalSrcIdx = 85;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Implementation_P.HILInitialize_DOInitial
	  section.data(34).logicalSrcIdx = 86;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Implementation_P.HILInitialize_DOFinal
	  section.data(35).logicalSrcIdx = 87;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Implementation_P.HILReadTimebase_Active
	  section.data(36).logicalSrcIdx = 88;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Implementation_P.HILWriteAnalog_Active
	  section.data(37).logicalSrcIdx = 89;
	  section.data(37).dtTransOffset = 36;
	
	  ;% Implementation_P.HILWriteDigital_Active
	  section.data(38).logicalSrcIdx = 90;
	  section.data(38).dtTransOffset = 37;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Implementation_B)
    ;%
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% Implementation_B.Sum
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Implementation_B.Sum1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Implementation_B.Add1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Implementation_B.DiscreteTimeIntegrator
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% Implementation_B.ControllerGainK
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% Implementation_B.K1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 9;
	
	  ;% Implementation_B.Add2
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Implementation_DWork)
    ;%
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% Implementation_DWork.DiscreteTimeIntegrator_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Implementation_DWork.HILInitialize_AIMinimums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 4;
	
	  ;% Implementation_DWork.HILInitialize_AIMaximums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 8;
	
	  ;% Implementation_DWork.HILInitialize_AOMinimums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 12;
	
	  ;% Implementation_DWork.HILInitialize_AOMaximums
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 16;
	
	  ;% Implementation_DWork.HILInitialize_AOVoltages
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 20;
	
	  ;% Implementation_DWork.HILInitialize_FilterFrequency
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 24;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Implementation_DWork.HILReadTimebase_Task
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Implementation_DWork.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% Implementation_DWork.LinkAngles_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Implementation_DWork.LinkAngles1_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Implementation_DWork.TheControlSignalu_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Implementation_DWork.ToWorkspace_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 12;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Implementation_DWork.ToWorkspace1_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 13;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Implementation_DWork.ToWorkspace2_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 14;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Implementation_DWork.xhatwhichequalstoerrorinthiscas.LoggedData
	  section.data(7).logicalSrcIdx = 15;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Implementation_DWork.HILWriteAnalog_PWORK
	  section.data(8).logicalSrcIdx = 16;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Implementation_DWork.Scope_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 17;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Implementation_DWork.HILWriteDigital_PWORK
	  section.data(10).logicalSrcIdx = 18;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Implementation_DWork.HILInitialize_DOStates
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Implementation_DWork.HILInitialize_QuadratureModes
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 4;
	
	  ;% Implementation_DWork.HILInitialize_InitialEICounts
	  section.data(3).logicalSrcIdx = 21;
	  section.data(3).dtTransOffset = 8;
	
	  ;% Implementation_DWork.HILReadTimebase_EncoderBuffer
	  section.data(4).logicalSrcIdx = 22;
	  section.data(4).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Implementation_DWork.HILInitialize_DOBits
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Implementation_DWork.HILWriteDigital_Buffer
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2862216419;
  targMap.checksum1 = 837169904;
  targMap.checksum2 = 1435101276;
  targMap.checksum3 = 910492603;

