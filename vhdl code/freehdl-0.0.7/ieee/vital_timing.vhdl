-------------------------------------------------------------------------------
-- Title        : Standard VITAL TIMING Package
--              : $Revision: 1.1 $
--              :
-- Library      : This package shall be compiled into a library
--              : symbolically named IEEE.
--              :
-- Developers   : IEEE DASC Timing Working Group (TWG), PAR 1076.4
--              :
-- Purpose      : This packages defines standard types, attributes, constants,
--              : functions and procedures for use in developing ASIC models.
--              :
-- Known Errors : 
--              :
-- Note         : No declarations or definitions shall be included in,
--              : or excluded from this package. The "package declaration"
--              : defines the objects (types, subtypes, constants, functions,
--              : procedures ... etc.) that can be used by a user.  The package
--              : body shall be considered the formal definition of the
--              : semantics of this package.  Tool developers may choose to
--              : implement the package body in the most efficient manner
--              : available to them.
-- ----------------------------------------------------------------------------
--
-- ----------------------------------------------------------------------------
-- Acknowledgments:
--   This code was originally developed under the "VHDL Initiative Toward ASIC
--   Libraries" (VITAL), an industry sponsored initiative.  Technical
--   Director: William Billowitch, VHDL Technology Group; U.S. Coordinator:
--   Steve Schultz;  Steering Committee Members: Victor Berman, Cadence Design
--   Systems; Oz Levia, Synopsys Inc.; Ray Ryan, Ryan & Ryan; Herman van Beek,
--   Texas Instruments; Victor Martin, Hewlett-Packard Company.
-- ----------------------------------------------------------------------------
--
-- ----------------------------------------------------------------------------
-- Modification History :
-- ----------------------------------------------------------------------------
-- Version No:|Auth:| Mod.Date:| Changes Made:
--   v95.0 A  |     | 06/02/95 | Initial ballot draft 1995
--   v95.1    |     | 08/31/95 | #203 - Timing violations at time 0
--                               #204 - Output mapping prior to glitch detection 
-- ---------------------------------------------------------------------------- 
LIBRARY IEEE;
USE     IEEE.Std_Logic_1164.ALL;

PACKAGE VITAL_Timing IS
    TYPE VitalTransitionType IS ( tr01, tr10, tr0z, trz1, tr1z, trz0,
                                  tr0X, trx1, tr1x, trx0, trxz, trzx);

    SUBTYPE VitalDelayType     IS TIME;
    TYPE VitalDelayType01   IS ARRAY (VitalTransitionType   RANGE tr01 to tr10)
         OF TIME;
    TYPE VitalDelayType01Z  IS ARRAY (VitalTransitionType   RANGE tr01 to trz0)
         OF TIME;
    TYPE VitalDelayType01ZX IS ARRAY (VitalTransitionType   RANGE tr01 to trzx)
         OF TIME;

    TYPE VitalDelayArrayType     IS ARRAY (NATURAL RANGE <>) OF VitalDelayType;
    TYPE VitalDelayArrayType01   IS ARRAY (NATURAL RANGE <>) OF VitalDelayType01;
    TYPE VitalDelayArrayType01Z  IS ARRAY (NATURAL RANGE <>) OF VitalDelayType01Z;
    TYPE VitalDelayArrayType01ZX IS ARRAY (NATURAL RANGE <>) OF VitalDelayType01ZX;
    -- ----------------------------------------------------------------------
    -- **********************************************************************
    -- ----------------------------------------------------------------------

    CONSTANT VitalZeroDelay     : VitalDelayType     :=   0 ns;
    CONSTANT VitalZeroDelay01   : VitalDelayType01   := ( 0 ns, 0 ns );
    CONSTANT VitalZeroDelay01Z  : VitalDelayType01Z  := ( OTHERS => 0 ns );
    CONSTANT VitalZeroDelay01ZX : VitalDelayType01ZX := ( OTHERS => 0 ns );

    ---------------------------------------------------------------------------
    -- examples of usage:
    ---------------------------------------------------------------------------
    -- tpd_CLK_Q : VitalDelayType  := 5 ns;
    -- tpd_CLK_Q : VitalDelayType01  := (tr01 => 2 ns, tr10 => 3 ns);
    -- tpd_CLK_Q : VitalDelayType01Z := ( 1 ns, 2 ns, 3 ns, 4 ns, 5 ns, 6 ns );
    -- tpd_CLK_Q : VitalDelayArrayType(0 to 1)
    --                          := (0 => 5 ns, 1 => 6 ns);
    -- tpd_CLK_Q : VitalDelayArrayType01(0 to 1)
    --                          := (0 => (tr01 => 2 ns, tr10 => 3 ns),
    --                              1 => (tr01 => 2 ns, tr10 => 3 ns));
    -- tpd_CLK_Q : VitalDelayArrayType01Z(0 to 1)
    --                        := (0 => ( 1 ns, 2 ns, 3 ns, 4 ns, 5 ns, 6 ns ),
    --                            1 => ( 1 ns, 2 ns, 3 ns, 4 ns, 5 ns, 6 ns ));
    ---------------------------------------------------------------------------

    -- TRUE if the model is LEVEL0 | LEVEL1 compliant
    ATTRIBUTE VITAL_Level0 : BOOLEAN;
    ATTRIBUTE VITAL_Level1 : BOOLEAN;

    SUBTYPE std_logic_vector2 IS std_logic_vector(1 DOWNTO 0);
    SUBTYPE std_logic_vector3 IS std_logic_vector(2 DOWNTO 0);
    SUBTYPE std_logic_vector4 IS std_logic_vector(3 DOWNTO 0);
    SUBTYPE std_logic_vector8 IS std_logic_vector(7 DOWNTO 0);

    -- Types for strength mapping of outputs
    TYPE VitalOutputMapType  IS ARRAY ( std_ulogic ) OF std_ulogic;
    TYPE VitalResultMapType  IS ARRAY ( UX01       ) OF std_ulogic;
    TYPE VitalResultZMapType IS ARRAY ( UX01Z      ) OF std_ulogic;
    CONSTANT VitalDefaultOutputMap  : VitalOutputMapType
                                    := "UX01ZWLH-";
    CONSTANT VitalDefaultResultMap  : VitalResultMapType
                                    := ( 'U', 'X', '0', '1' );
    CONSTANT VitalDefaultResultZMap : VitalResultZMapType
                                    := ( 'U', 'X', '0', '1', 'Z' );

    -- Types for fields of VitalTimingDataType
    TYPE VitalTimeArrayT  IS ARRAY (INTEGER RANGE <>) OF TIME;
    TYPE VitalTimeArrayPT IS ACCESS VitalTimeArrayT;
    TYPE VitalBoolArrayT  IS ARRAY (INTEGER RANGE <>) OF BOOLEAN;
    TYPE VitalBoolArrayPT IS ACCESS VitalBoolArrayT;
    TYPE VitalLogicArrayPT IS ACCESS std_logic_vector;

    TYPE VitalTimingDataType IS RECORD
        NotFirstFlag : BOOLEAN;
        RefLast   : X01;
        RefTime   : TIME;
        HoldEn    : BOOLEAN;
        TestLast  : std_ulogic;
        TestTime  : TIME;
        SetupEn   : BOOLEAN;
        TestLastA : VitalLogicArrayPT;
        TestTimeA : VitalTimeArrayPT;
        HoldEnA   : VitalBoolArrayPT;
        SetupEnA  : VitalBoolArrayPT;
    END RECORD;

    FUNCTION VitalTimingDataInit RETURN VitalTimingDataType;

    -- type for internal data of VitalPeriodPulseCheck
    TYPE VitalPeriodDataType IS RECORD
        Last : X01;
        Rise : TIME;
        Fall : TIME;
        NotFirstFlag : BOOLEAN;
    END RECORD;
    CONSTANT VitalPeriodDataInit : VitalPeriodDataType 
                                 := ('X', 0 ns, 0 ns, FALSE );

    -- Type for specifying the kind of Glitch handling to use
    TYPE VitalGlitchKindType IS (OnEvent,
                                 OnDetect,
                                 VitalInertial,
                                 VitalTransport);

    TYPE VitalGlitchDataType IS
      RECORD
        SchedTime    : TIME;
        GlitchTime   : TIME;
        SchedValue   : std_ulogic;
        LastValue    : std_ulogic;
      END RECORD;
    TYPE VitalGlitchDataArrayType IS ARRAY (NATURAL RANGE <>)
         OF VitalGlitchDataType;

    -- PathTypes: for handling simple PathDelay info
    TYPE VitalPathType IS RECORD
        InputChangeTime : TIME;             -- timestamp for path input signal
        PathDelay       : VitalDelayType;   -- delay for this path
        PathCondition   : BOOLEAN;          -- path sensitize condition
    END RECORD;
    TYPE VitalPath01Type IS RECORD
        InputChangeTime : TIME;             -- timestamp for path input signal
        PathDelay       : VitalDelayType01; -- delay for this path
        PathCondition   : BOOLEAN;          -- path sensitize condition
    END RECORD;
    TYPE VitalPath01ZType IS RECORD
        InputChangeTime : TIME;             -- timestamp for path input signal
        PathDelay       : VitalDelayType01Z;-- delay for this path
        PathCondition   : BOOLEAN;          -- path sensitize condition
    END RECORD;

    -- For representing multiple paths to an output
    TYPE VitalPathArrayType    IS ARRAY (NATURAL RANGE <> ) OF VitalPathType;
    TYPE VitalPathArray01Type  IS ARRAY (NATURAL RANGE <> ) OF VitalPath01Type;
    TYPE VitalPathArray01ZType IS ARRAY (NATURAL RANGE <> ) OF VitalPath01ZType;

    TYPE VitalTableSymbolType IS (
       '/',      -- 0 -> 1                                      
       '\',      -- 1 -> 0                                      
       'P',      -- Union of '/' and '^' (any edge to 1)                     
       'N',      -- Union of '\' and 'v' (any edge to 0)                       
       'r',      -- 0 -> X                                      
       'f',      -- 1 -> X                                      
       'p',      -- Union of '/' and 'r' (any edge from 0)               
       'n',      -- Union of '\' and 'f' (any edge from 1)               
       'R',      -- Union of '^' and 'p' (any possible rising edge)      
       'F',      -- Union of 'v' and 'n' (any possible falling edge)     
       '^',      -- X -> 1                                      
       'v',      -- X -> 0                                      
       'E',      -- Union of 'v' and '^' (any edge from X)               
       'A',      -- Union of 'r' and '^' (rising edge to or from 'X')                           
       'D',      -- Union of 'f' and 'v' (falling edge to or from 'X')                          
       '*',      -- Union of 'R' and 'F' (any edge)                      
       'X',      -- Unknown level                               
       '0',      -- low level                                   
       '1',      -- high level                                  
       '-',      -- don't care                                  
       'B',      -- 0 or 1                                      
       'Z',      -- High Impedance                              
       'S'       -- steady value                                
    );

    SUBTYPE VitalEdgeSymbolType IS VitalTableSymbolType RANGE '/' TO '*';

    -- ------------------------------------------------------------------------
    --
    -- Function Name:   VitalExtendToFillDelay
    --
    -- Description:     A six element array of delay values of type 
    --                  VitalDelayType01Z is returned when a 1, 2 or 6
    --                  element array is given.  This function will convert
    --                  VitalDelayType and VitalDelayType01 delay values into
    --                  a VitalDelayType01Z type following these rules:
    --
    --                  When a VitalDelayType is passed, all six transition
    --                  values are assigned the input value.  When a 
    --                  VitalDelayType01 is passed, the 01 transitions are
    --                  assigned to the 01, 0Z and Z1 transitions and the 10
    --                  transitions are assigned to 10, 1Z and Z0 transition
    --                  values.  When a VitalDelayType01Z is passed, the values
    --                  are kept as is.
    --
    --                  The function is overloaded based on input type.
    --
    --                  There is no function to fill a 12 value delay
    --                  type.
    --
    -- Arguments:         
    --
    --  IN                 Type           Description
    --                     Delay          A one, two or six delay value Vital-
    --                                    DelayType is passed and a six delay,
    --                                    VitalDelayType01Z, item is returned.        
    --                    
    --  INOUT
    --   none
    --
    --  OUT
    --   none
    --
    --  Returns              
    --   VitalDelayType01Z
    --
    -- -------------------------------------------------------------------------
    FUNCTION VitalExtendToFillDelay (
            CONSTANT Delay : IN VitalDelayType
          ) RETURN VitalDelayType01Z;
    FUNCTION VitalExtendToFillDelay (
            CONSTANT Delay : IN VitalDelayType01
          ) RETURN VitalDelayType01Z;
    FUNCTION VitalExtendToFillDelay (
            CONSTANT Delay : IN VitalDelayType01Z
          ) RETURN VitalDelayType01Z;

    -- ------------------------------------------------------------------------
    --
    -- Function Name:   VitalCalcDelay
    --
    -- Description:     This function accepts a 1, 2 or 6 value delay and 
    --                  chooses the correct delay time to delay the NewVal 
    --                  signal.  This function is overloaded based on the
    --                  delay type passed. The function returns a single value
    --                  of time.
    --
    --                  This function is provided for Level 0 models in order
    --                  to calculate the delay which should be applied 
    --                  for the passed signal. The delay selection is performed
    --                  using the OldVal and the NewVal to determine the 
    --                  transition to select.  The default value of OldVal is X.
    --
    --                  This function cannot be used in a Level 1 model since
    --                  the VitalPathDelay routines perform the delay path
    --                  selection and output driving function.
    --
    -- Arguments:         
    --
    --  IN                 Type           Description
    --                      NewVal         New value of the signal to be
    --                                     assigned   
    --                      OldVal         Previous value of the signal.
    --                                     Default value is 'X'
    --                      Delay          The delay structure from which to
    --                                     select the appropriate delay.  The
    --                                     function overload is based on the
    --                                     type of delay passed.  In the case of
    --                                     the single delay, VitalDelayType, no
    --                                     selection is performed, since there
    --                                     is only one value to choose from.
    --                                     For the other cases, the transition
    --                                     from the old value to the new value
    --                                     decide the value returned.  
    --                    
    --  INOUT
    --   none 
    --
    --  OUT
    --   none
    --
    --  Returns              
    --   Time                              The time value selected from the
    --                                     Delay INPUT is returned.
    --
    -- -------------------------------------------------------------------------
    FUNCTION VitalCalcDelay (
            CONSTANT NewVal : IN std_ulogic   := 'X';
            CONSTANT OldVal : IN std_ulogic   := 'X';
            CONSTANT Delay  : IN VitalDelayType
          ) RETURN TIME;
    FUNCTION VitalCalcDelay (
            CONSTANT NewVal : IN std_ulogic   := 'X';
            CONSTANT OldVal : IN std_ulogic   := 'X';
            CONSTANT Delay  : IN VitalDelayType01
          ) RETURN TIME;
    FUNCTION VitalCalcDelay (
            CONSTANT NewVal : IN std_ulogic   := 'X';
            CONSTANT OldVal : IN std_ulogic   := 'X';
            CONSTANT Delay  : IN VitalDelayType01Z
          ) RETURN TIME;

    -- ------------------------------------------------------------------------
    --
    -- Function Name:   VitalPathDelay
    --
    -- Description:     VitalPathDelay is the Level 1 routine used to select
    --                  the propagation delay path and schedule a new output 
    --                  value.
    --
    --                  For single and dual delay values, VitalDelayType and
    --                  VitalDelayType01 are used.  The output value is
    --                  scheduled with a calculated delay without strength
    --                  modification.  
    --
    --                  For the six delay value, VitalDelayType01Z, the output       
    --                  value is scheduled with a calculated delay.  The drive 
    --                  strength can be modified to handle weak signal strengths
    --                  to model tri-state devices, pull-ups and pull-downs as
    --                  an example.
    --
    --                  The correspondence between the delay type and the
    --                  path delay function is as follows:
    --
    --                  Delay Type                Path Type
    --
    --                  VitalDelayType            VitalPathDelay
    --                  VitalDelayType01          VitalPathDelay01
    --                  VitalDelayType01Z         VitalPathDelay01Z
    --
    --                  For each of these routines, the following capabilities
    --                  is provided:
    --     
    --                  o Transition dependent path delay selection
    --                  o User controlled glitch detection with the ability
    --                    to generate "X" on output and report the violation
    --                  o Control of the severity level for message generation
    --                  o Scheduling of the computed values on the specified
    --                    signal.
    --                  
    --                  Selection of the appropriate path delay begins with the
    --                  candidate paths.  The candidate paths are selected by
    --                  identifying the paths for which the PathCondition is 
    --                  true.  If there is a single candidate path, then that
    --                  delay is selected.  If there is more than one candidate
    --                  path, then the shortest delay is selected using 
    --                  transition dependent delay selection.  If there is no 
    --                  candidate paths, then the delay specified by the 
    --                  DefaultDelay parameter to the path delay is used.
    --                  
    --                  Once the delay is known, the output signal is then
    --                  scheduled with that delay.  In the case of 
    --                  VitalPathDelay01Z, an additional result mapping of
    --                  the output value is performed before scheduling.  The
    --                  result mapping is performed after transition dependent
    --                  delay selection but before scheduling the final output.
    --                      
    --                  In order to perform glitch detection, the user is
    --                  obligated to provide a variable of VitalGlitchDataType
    --                  for the propagation delay functions to use.  The user
    --                  cannot modify or use this information.
    --
    -- Arguments:         
    --
    --  IN             Type                   Description
    --   OutSignalName  string                 The name of the output signal
    --   OutTemp        std_logic              The new output value to be driven
    --   Paths          VitalPathArrayType     A list of paths of VitalPathArray
    --                  VitalPathArrayType01   type.  The VitalPathDelay routine
    --                  VitalPathArrayType01Z  is overloaded based on the type
    --                                         of constant passed in.  With
    --                                         VitalPathArrayType01Z, the
    --                                         resulting output strengths can be
    --                                         mapped.
    --   DefaultDelay   VitalDelayType         The default delay can be changed  
    --                  VitalDelayType01       from zero-delay to another set of 
    --                  VitalDelayType01Z      values.   
    --   Mode           VitalGlitchKindType    The value of this constant
    --                                         selects the type of glitch
    --                                         detection.
    --                       OnEvent           Glitch on transition event
    --                     | OnDetect          Glitch immediate on detection
    --                     | VitalInertial     No glitch, use INERTIAL
    --                                         assignment
    --                     | VitalTransport    No glitch, use TRANSPORT 
    --                                         assignment
    --   XOn            BOOLEAN                Control for generation of 'X' on 
    --                                         glitch.  When TRUE, 'X's are
    --                                         scheduled for glitches, otherwise
    --                                         no are generated.             
    --   MsgOn          BOOLEAN                Control for message generation on
    --                                         glitch detect.  When TRUE,
    --                                         glitches are reported, otherwise
    --                                         they are not reported.      
    --   MsgSeverity    SEVERITY_LEVEL         The level at which the message,
    --                                         or assertion, will be reported. 
    --   OutputMap      VitalOutputMapType     For VitalPathDelay01Z, the output
    --                                         can be mapped to alternate
    --                                         strengths to model tri-state 
    --                                         devices, pull-ups and pull-downs.  
    -- 
    --  INOUT
    --   GlitchData     VitalGlitchDataType    The internal data storage
    --                                         variable required to detect
    --                                         glitches.
    --
    --  OUT
    --   OutSignal      std_logic              The output signal to be driven
    --
    --  Returns              
    --   none 
    --
    -- -------------------------------------------------------------------------
    PROCEDURE VitalPathDelay (
        SIGNAL   OutSignal     : OUT   std_logic;
        VARIABLE GlitchData    : INOUT VitalGlitchDataType;
        CONSTANT OutSignalName : IN    string;
        CONSTANT OutTemp       : IN    std_logic;
        CONSTANT Paths         : IN    VitalPathArrayType;
        CONSTANT DefaultDelay  : IN    VitalDelayType      := VitalZeroDelay;
        CONSTANT Mode          : IN    VitalGlitchKindType := OnEvent;
        CONSTANT XOn           : IN    BOOLEAN             := TRUE;
        CONSTANT MsgOn         : IN    BOOLEAN             := TRUE;
        CONSTANT MsgSeverity   : IN    SEVERITY_LEVEL      := WARNING
    );
    PROCEDURE VitalPathDelay01 (
        SIGNAL   OutSignal     : OUT   std_logic;
        VARIABLE GlitchData    : INOUT VitalGlitchDataType;
        CONSTANT OutSignalName : IN    string;
        CONSTANT OutTemp       : IN    std_logic;
        CONSTANT Paths         : IN    VitalPathArray01Type;
        CONSTANT DefaultDelay  : IN    VitalDelayType01    := VitalZeroDelay01;
        CONSTANT Mode          : IN    VitalGlitchKindType := OnEvent;
        CONSTANT XOn           : IN    BOOLEAN             := TRUE;
        CONSTANT MsgOn         : IN    BOOLEAN             := TRUE;
        CONSTANT MsgSeverity   : IN    SEVERITY_LEVEL      := WARNING
    );
    PROCEDURE VitalPathDelay01Z (
        SIGNAL   OutSignal     : OUT   std_logic;
        VARIABLE GlitchData    : INOUT VitalGlitchDataType;
        CONSTANT OutSignalName : IN    string;
        CONSTANT OutTemp       : IN    std_logic;
        CONSTANT Paths         : IN    VitalPathArray01ZType;
        CONSTANT DefaultDelay  : IN    VitalDelayType01Z   := VitalZeroDelay01Z;
        CONSTANT Mode          : IN    VitalGlitchKindType := OnEvent;
        CONSTANT XOn           : IN    BOOLEAN             := TRUE;
        CONSTANT MsgOn         : IN    BOOLEAN             := TRUE;
        CONSTANT MsgSeverity   : IN    SEVERITY_LEVEL      := WARNING;
        CONSTANT OutputMap     : IN    VitalOutputMapType
                                        := VitalDefaultOutputMap
    );

    -- ------------------------------------------------------------------------
    --
    -- Function Name:   VitalWireDelay
    --
    -- Description:     VitalWireDelay is used to delay an input signal.
    --                  The delay is selected from the input parameter passed.
    --                  The function is useful for back annotation of actual
    --                  net delays.  
    --                  
    --                  The function is overloaded to permit passing a delay
    --                  value for twire for VitalDelayType, VitalDelayType01
    --                  and VitalDelayType01Z.  twire is a generic which can
    --                  be back annotated and must be constructed to follow
    --                  the SDF to generic mapping rules.       
    --                  
    -- Arguments:         
    --
    --  IN          Type                  Description         
    --   InSig       std_ulogic            The input signal (port) to be
    --                                     delayed.
    --   twire       VitalDelayType        The delay value for which the input 
    --               VitalDelayType01      signal should be delayed.  For Vital-
    --               VitalDelayType01Z     DelayType, the value is single value 
    --                                     passed.  For VitalDelayType01 and
    --                                     VitalDelayType01Z, the appropriate
    --                                     delay value is selected by VitalCalc-
    --                                     Delay.
    --
    --  INOUT
    --   none 
    --
    --  OUT
    --   OutSig      std_ulogic            The internal delayed signal
    --
    --  Returns              
    --   none 
    --
    -- -------------------------------------------------------------------------
    PROCEDURE VitalWireDelay (
            SIGNAL   OutSig     : OUT   std_ulogic;
            SIGNAL   InSig      : IN    std_ulogic;
            CONSTANT twire      : IN    VitalDelayType
        );

    PROCEDURE VitalWireDelay (
            SIGNAL   OutSig     : OUT   std_ulogic;
            SIGNAL   InSig      : IN    std_ulogic;
            CONSTANT twire      : IN    VitalDelayType01
        );

    PROCEDURE VitalWireDelay (
            SIGNAL   OutSig     : OUT   std_ulogic;
            SIGNAL   InSig      : IN    std_ulogic;
            CONSTANT twire      : IN    VitalDelayType01Z
        );

    -- ------------------------------------------------------------------------
    --
    -- Function Name:   VitalSignalDelay
    --
    -- Description:     The VitalSignalDelay procedure is called in a signal
    --                  delay block in the architecture to delay the 
    --                  appropriate test or reference signal in order to 
    --                  accommodate negative constraint checks.
    --
    --                  The amount of delay is of type TIME and is a constant.
    --
    -- Arguments:         
    --
    --  IN                Type            Description         
    --   InSig             std_ulogic      The signal to be delayed.
    --   dly               TIME            The amount of time the signal is
    --                                     delayed.
    --
    --  INOUT
    --   none
    --
    --  OUT
    --   OutSig            std_ulogic      The delayed signal
    --
    --  Returns              
    --   none
    --
    -- -------------------------------------------------------------------------
    PROCEDURE VitalSignalDelay (
            SIGNAL   OutSig     : OUT   std_ulogic;
            SIGNAL   InSig      : IN    std_ulogic;
            CONSTANT dly        : IN   TIME
    );

    -- ------------------------------------------------------------------------
    --
    -- Function Name:  VitalSetupHoldCheck
    --
    -- Description:    The VitalSetupHoldCheck procedure detects a setup or a 
    --                 hold violation on the input test signal with respect
    --                 to the corresponding input reference signal.  The timing 
    --                 constraints are specified through parameters 
    --                 representing the high and low values for the setup and
    --                 hold values for the setup and hold times.  This 
    --                 procedure assumes non-negative values for setup and hold 
    --                 timing constraints. 
    --
    --                 It is assumed that negative timing constraints
    --                 are handled by internally delaying the test or
    --                 reference signals.  Negative setup times result in
    --                 a delayed reference signal.  Negative hold times
    --                 result in a delayed test signal.  Furthermore, the
    --                 delays and constraints associated with these and
    --                 other signals may need to be appropriately
    --                 adjusted so that all constraint intervals overlap
    --                 the delayed reference signals and all constraint
    --                 values (with respect to the delayed signals) are
    --                 non-negative.
    --
    --                 This function is overloaded based on the input
    --                 TestSignal.  A vector and scalar form are provided.
    --                  
    -- TestSignal XXXXXXXXXXXX____________________________XXXXXXXXXXXXXXXXXXXXXX
    --            :
    --            :        -->|       error region       |<--
    --            :
    --            _______________________________
    -- RefSignal                                 \______________________________
    --            :           |                  |       |
    --            :           |               -->|       |<-- thold
    --            :        -->|     tsetup       |<--
    --
    -- Arguments:         
    --
    --  IN                 Type           Description    
    --   TestSignal         std_ulogic     Value of test signal
    --                      std_logic_vector
    --   TestSignalName     STRING         Name of test signal
    --   TestDelay          TIME           Model's internal delay associated
    --                                     with TestSignal
    --   RefSignal          std_ulogic     Value of reference signal
    --   RefSignalName      STRING         Name of reference signal
    --   RefDelay           TIME           Model's internal delay associated
    --                                     with RefSignal
    --   SetupHigh          TIME           Absolute minimum time duration before
    --                                     the transition of RefSignal for which
    --                                     transitions of TestSignal are allowed
    --                                     to proceed to the "1" state without
    --                                     causing a setup violation.      
    --   SetupLow           TIME           Absolute minimum time duration before 
    --                                     the transition of RefSignal for which
    --                                     transitions of TestSignal are allowed
    --                                     to proceed to the "0" state without
    --                                     causing a setup violation.      
    --   HoldHigh           TIME           Absolute minimum time duration after
    --                                     the transition of RefSignal for which
    --                                     transitions of TestSignal are allowed
    --                                     to proceed to the "1" state without
    --                                     causing a hold violation.      
    --   HoldLow            TIME           Absolute minimum time duration after 
    --                                     the transition of RefSignal for which
    --                                     transitions of TestSignal are allowed
    --                                     to proceed to the "0" state without
    --                                     causing a hold violation.      
    --   CheckEnabled       BOOLEAN        Check performed if TRUE.
    --   RefTransition      VitalEdgeSymbolType
    --                                     Reference edge specified. Events on
    --                                     the RefSignal which match the edge
    --                                     spec. are used as reference edges.      
    --   HeaderMsg          STRING         String that will accompany any
    --                                     assertion messages produced.      
    --   XOn                BOOLEAN        If TRUE, Violation output parameter
    --                                     is set to "X". Otherwise, Violation
    --                                     is always set to "0."      
    --   MsgOn              BOOLEAN        If TRUE, set and hold violation 
    --                                     message will be generated.
    --                                     Otherwise, no messages are generated,
    --                                     even upon violations.      
    --   MsgSeverity        SEVERITY_LEVEL Severity level for the assertion.      
    --              
    --  INOUT
    --   TimingData         VitalTimingDataType  
    --                                     VitalSetupHoldCheck information
    --                                     storage area.  This is used
    --                                     internally to detect reference edges
    --                                     and record the time of the last edge.
    --
    --  OUT
    --   Violation   X01                   This is the violation flag returned. 
    --
    --  Returns              
    --   none    
    --
    -- -------------------------------------------------------------------------
    PROCEDURE VitalSetupHoldCheck (
            VARIABLE Violation     : OUT    X01;
            VARIABLE TimingData    : INOUT  VitalTimingDataType;
            SIGNAL   TestSignal    : IN     std_ulogic;
            CONSTANT TestSignalName: IN     STRING := "";
            CONSTANT TestDelay     : IN     TIME := 0 ns;
            SIGNAL   RefSignal     : IN     std_ulogic;
            CONSTANT RefSignalName : IN     STRING := "";
            CONSTANT RefDelay      : IN     TIME := 0 ns;
            CONSTANT SetupHigh     : IN     TIME := 0 ns;
            CONSTANT SetupLow      : IN     TIME := 0 ns;
            CONSTANT HoldHigh      : IN     TIME := 0 ns;
            CONSTANT HoldLow       : IN     TIME := 0 ns;
            CONSTANT CheckEnabled  : IN     BOOLEAN := TRUE;
            CONSTANT RefTransition : IN     VitalEdgeSymbolType;
            CONSTANT HeaderMsg     : IN     STRING := " ";
            CONSTANT XOn           : IN     BOOLEAN := TRUE;
            CONSTANT MsgOn         : IN     BOOLEAN := TRUE;
            CONSTANT MsgSeverity   : IN     SEVERITY_LEVEL := WARNING
    );

    PROCEDURE VitalSetupHoldCheck (
            VARIABLE Violation     : OUT    X01;
            VARIABLE TimingData    : INOUT  VitalTimingDataType;
            SIGNAL   TestSignal    : IN     std_logic_vector;
            CONSTANT TestSignalName: IN     STRING := "";
            CONSTANT TestDelay     : IN     TIME := 0 ns;
            SIGNAL   RefSignal     : IN     std_ulogic;
            CONSTANT RefSignalName : IN     STRING := "";
            CONSTANT RefDelay      : IN     TIME := 0 ns;
            CONSTANT SetupHigh     : IN     TIME := 0 ns;
            CONSTANT SetupLow      : IN     TIME := 0 ns;
            CONSTANT HoldHigh      : IN     TIME := 0 ns;
            CONSTANT HoldLow       : IN     TIME := 0 ns;
            CONSTANT CheckEnabled  : IN     BOOLEAN := TRUE;
            CONSTANT RefTransition : IN     VitalEdgeSymbolType;
            CONSTANT HeaderMsg     : IN     STRING := " ";
            CONSTANT XOn           : IN     BOOLEAN := TRUE;
            CONSTANT MsgOn         : IN     BOOLEAN := TRUE;
            CONSTANT MsgSeverity   : IN     SEVERITY_LEVEL := WARNING
    );

    -- ------------------------------------------------------------------------
    --
    -- Function Name:   VitalRecoveryRemovalCheck
    --
    -- Description:     The VitalRecoveryRemovalCheck detects the presence of
    --                  a recovery or removal violation on the input test 
    --                  signal with respect to the corresponding input reference
    --                  signal.  It assumes non-negative values of setup and
    --                  hold timing constraints.  The timing constraint is 
    --                  specified through parameters representing the recovery
    --                  and removal times associated with a reference edge of 
    --                  the reference signal.  A flag indicates whether a test
    --                  signal is asserted when it is high or when it is low.
    --                  
    --                  It is assumed that negative timing constraints 
    --                  are handled by internally delaying the test or 
    --                  reference signals.  Negative recovery times result in 
    --                  a delayed reference signal.  Negative removal times 
    --                  result in a delayed test signal.  Furthermore, the 
    --                  delays and constraints associated with these and
    --                  other signals may need to be appropriately
    --                  adjusted so that all constraint intervals overlap 
    --                  the delayed reference signals and all constraint
    --                  values (with respect to the delayed signals) are
    --                  non-negative.
    --                  
    -- Arguments:         
    --
    --  IN               Type             Description
    --   TestSignal       std_ulogic       Value of TestSignal.  The routine is
    --   TestSignalName   STRING           Name of TestSignal 
    --   TestDelay        TIME             Model internal delay associated with
    --                                     the TestSignal
    --   RefSignal        std_ulogic       Value of RefSignal
    --   RefSignalName    STRING           Name of RefSignal
    --   RefDelay         TIME             Model internal delay associated with
    --                                     the RefSignal
    --   Recovery         TIME             A change to an unasserted value on
    --                                     the asynchronous TestSignal must
    --                                     precede reference edge (on RefSignal)
    --                                     by at least this time.
    --   Removal          TIME             An asserted condition must be present
    --                                     on the asynchronous TestSignal for at
    --                                     least the removal time following a
    --                                     reference edge on RefSignal.
    --   ActiveLow        BOOLEAN          A flag which indicates if TestSignal
    --                                     is asserted when it is low - "0."
    --                                     FALSE indicate that TestSignal is
    --                                     asserted when it has a value "1."
    --   CheckEnabled     BOOLEAN          The check in enabled when the value
    --                                     is TRUE, otherwise the constraints 
    --                                     are not checked.
    --   RefTransition    VitalEdgeSymbolType  
    --                                     Reference edge specifier.  Events on
    --                                     RefSignal will match the edge
    --                                     specified.
    --   HeaderMsg         STRING          A header message that will accompany
    --                                     any assertion message.
    --   XOn               BOOLEAN         When TRUE, the output Violation is
    --                                     set to "X."  When FALSE, it is always 
    --                                     "0."
    --   MsgOn             BOOLEAN         When TRUE, violation messages are
    --                                     output.  When FALSE, no messages are
    --                                     generated.
    --   MsgSeverity       SEVERITY_LEVEL  Severity level of the asserted
    --                                     message.
    --                             
    --   INOUT
    --    TimingData       VitalTimingDataType 
    --                                     VitalRecoveryRemovalCheck information
    --                                     storage area.  This is used
    --                                     internally to detect reference edges
    --                                     and record the time of the last edge.
    --   OUT
    --    Violation        X01             This is the violation flag returned.
    --
    --   Returns              
    --           none
    --
    -- -------------------------------------------------------------------------
    PROCEDURE VitalRecoveryRemovalCheck (
            VARIABLE Violation     : OUT    X01;
            VARIABLE TimingData    : INOUT  VitalTimingDataType;
            SIGNAL   TestSignal    : IN     std_ulogic;
            CONSTANT TestSignalName: IN     STRING := "";
            CONSTANT TestDelay     : IN     TIME := 0 ns;
            SIGNAL   RefSignal     : IN     std_ulogic;
            CONSTANT RefSignalName : IN     STRING := "";
            CONSTANT RefDelay      : IN     TIME := 0 ns;
            CONSTANT Recovery      : IN     TIME := 0 ns;
            CONSTANT Removal       : IN     TIME := 0 ns;
            CONSTANT ActiveLow     : IN     BOOLEAN := TRUE;
            CONSTANT CheckEnabled  : IN     BOOLEAN := TRUE;
            CONSTANT RefTransition : IN     VitalEdgeSymbolType;
            CONSTANT HeaderMsg     : IN     STRING := " ";
            CONSTANT XOn           : IN     BOOLEAN := TRUE;
            CONSTANT MsgOn         : IN     BOOLEAN := TRUE;
            CONSTANT MsgSeverity   : IN     SEVERITY_LEVEL := WARNING
    );

    -- ------------------------------------------------------------------------
    --
    -- Function Name:  VitalPeriodPulseCheck
    --
    -- Description:    VitalPeriodPulseCheck checks for minimum and maximum
    --                 periodicity and pulse width for "1" and "0" values of
    --                 the input test signal.  The timing constraint is 
    --                 specified through parameters representing the minimal
    --                 period between successive rising and falling edges of
    --                 the input test signal and the minimum pulse widths 
    --                 associated with high and low values.  
    --                 
    --                 VitalPeriodCheck's accepts rising and falling edges
    --                 from 1 and 0 as well as transitions to and from 'X.'
    --                 
    --                    _______________         __________
    --       ____________|               |_______|
    --
    --                   |<--- pw_hi --->|
    --                   |<-------- period ----->|
    --                                -->| pw_lo |<--
    --                 
    -- Arguments:
    --  IN                 Type           Description
    --    TestSignal        std_ulogic     Value of test signal  
    --    TestSignalName    STRING         Name of the test signal
    --    TestDelay         TIME           Model's internal delay associated
    --                                     with TestSignal
    --    Period            TIME           Minimum period allowed between
    --                                     consecutive rising ('P') or 
    --                                     falling ('F') transitions.
    --    PulseWidthHigh    TIME           Minimum time allowed for a high
    --                                     pulse ('1' or 'H')
    --    PulseWidthLow     TIME           Minimum time allowed for a low
    --                                     pulse ('0' or 'L')
    --    CheckEnabled      BOOLEAN        Check performed if TRUE.
    --    HeaderMsg         STRING         String that will accompany any
    --                                     assertion messages produced.   
    --    XOn               BOOLEAN        If TRUE, Violation output parameter
    --                                     is set to "X". Otherwise, Violation
    --                                     is always set to "0." 
    --    MsgOn             BOOLEAN        If TRUE, period/pulse violation
    --                                     message will be generated.
    --                                     Otherwise, no messages are generated,
    --                                     even though a violation is detected. 
    --    MsgSeverity       SEVERITY_LEVEL Severity level for the assertion.
    --         
    --   INOUT
    --    PeriodData        VitalPeriodDataType 
    --                                     VitalPeriodPulseCheck information
    --                                     storage area.  This is used
    --                                     internally to detect reference edges
    --                                     and record the pulse and period
    --                                     times.
    --   OUT
    --    Violation         X01            This is the violation flag returned. 
    --
    --   Returns              
    --    none
    --
    -- ------------------------------------------------------------------------
    PROCEDURE VitalPeriodPulseCheck  (
            VARIABLE Violation      : OUT    X01;
            VARIABLE PeriodData     : INOUT  VitalPeriodDataType;
            SIGNAL   TestSignal     : IN     std_ulogic;
            CONSTANT TestSignalName : IN     STRING := "";
            CONSTANT TestDelay      : IN     TIME := 0 ns;
            CONSTANT Period         : IN     TIME := 0 ns;
            CONSTANT PulseWidthHigh : IN     TIME := 0 ns;
            CONSTANT PulseWidthLow  : IN     TIME := 0 ns;
            CONSTANT CheckEnabled   : IN     BOOLEAN := TRUE;
            CONSTANT HeaderMsg      : IN     STRING := " ";
            CONSTANT XOn            : IN     BOOLEAN := TRUE;
            CONSTANT MsgOn          : IN     BOOLEAN := TRUE;
            CONSTANT MsgSeverity    : IN     SEVERITY_LEVEL := WARNING
        );
 
END VITAL_Timing;
-------------------------------------------------------------------------------
-- Title        : Standard VITAL TIMING Package
--              : $Revision: 1.1 $
-- Library      : VITAL
--              :  
-- Developers   : IEEE DASC Timing Working Group (TWG), PAR 1076.4
--              :  
-- Purpose      : This packages defines standard types, attributes, constants,
--              : functions and procedures for use in developing ASIC models.
--              : This file contains the Package Body.
-- ----------------------------------------------------------------------------
--
-- ----------------------------------------------------------------------------
-- Modification History : 
-- ----------------------------------------------------------------------------
-- Version No:|Auth:| Mod.Date:| Changes Made:
--   v95.0 A  |     | 06/08/95 | Initial ballot draft 1995
--   v95.1    |     | 08/31/95 | #203 - Timing violations at time 0
--                               #204 - Output mapping prior to glitch detection
-- ----------------------------------------------------------------------------

LIBRARY STD;
USE STD.TEXTIO.ALL;

PACKAGE BODY VITAL_Timing IS

    -- --------------------------------------------------------------------
    -- Package Local Declarations
    -- --------------------------------------------------------------------
    TYPE CheckType IS ( SetupCheck, HoldCheck, RecoveryCheck, RemovalCheck,
                        PulseWidCheck, PeriodCheck );

    TYPE CheckInfoType IS RECORD
            Violation : BOOLEAN;
            CheckKind : CheckType;
            ObsTime   : TIME;
            ExpTime   : TIME;
            DetTime   : TIME;
            State     : X01;
    END RECORD;

    TYPE LogicCvtTableType IS ARRAY (std_ulogic) OF CHARACTER; 
    TYPE HiLoStrType IS ARRAY (std_ulogic RANGE 'X' TO '1') OF STRING(1 TO 4); 

    CONSTANT LogicCvtTable : LogicCvtTableType 
                     := ( 'U', 'X', '0', '1', 'Z', 'W', 'L', 'H', '-'); 
    CONSTANT HiLoStr     : HiLoStrType := ("  X ", " Low", "High" ); 

    TYPE EdgeSymbolMatchType IS ARRAY (X01,X01,VitalEdgeSymbolType) OF BOOLEAN;
    -- last value, present value, edge symbol
    CONSTANT EdgeSymbolMatch : EdgeSymbolMatchType :=  (
      'X'=>('X'=>(                                 OTHERS => FALSE),
            '0'=>('N'|'F'|'v'|'E'|'D'|'*' => TRUE, OTHERS => FALSE ),
            '1'=>('P'|'R'|'^'|'E'|'A'|'*' => TRUE, OTHERS => FALSE ) ),
      '0'=>('X'=>(    'r'|'p'|'R'|'A'|'*' => TRUE, OTHERS => FALSE ),
            '0'=>(                                 OTHERS => FALSE ),
            '1'=>(    '/'|'P'|'p'|'R'|'*' => TRUE, OTHERS => FALSE ) ),
      '1'=>('X'=>(    'f'|'n'|'F'|'D'|'*' => TRUE, OTHERS => FALSE ),
            '0'=>(    '\'|'N'|'n'|'F'|'*' => TRUE, OTHERS => FALSE ),
            '1'=>(                                 OTHERS => FALSE ) ) );

    ---------------------------------------------------------------------------
    ---------------------------------------------------------------------------
    -- Misc Utilities Local Utilities
    ---------------------------------------------------------------------------
    -----------------------------------------------------------------------
    FUNCTION Minimum ( CONSTANT t1,t2 : IN TIME ) RETURN TIME IS
    BEGIN
        IF ( t1 < t2 ) THEN RETURN (t1); ELSE RETURN (t2); END IF;
    END Minimum;
    -----------------------------------------------------------------------
    FUNCTION Maximum ( CONSTANT t1,t2 : IN TIME ) RETURN TIME IS
    BEGIN
        IF ( t1 > t2 ) THEN RETURN (t1); ELSE RETURN (t2); END IF;
    END Maximum;

    --------------------------------------------------------------------
    -- Error Message Types and Tables
    --------------------------------------------------------------------
    TYPE VitalErrorType IS (
        ErrVctLng  ,
        ErrNoPath  ,
        ErrNegPath ,
        ErrNegDel
    );
 
    TYPE VitalErrorSeverityType IS ARRAY (VitalErrorType) OF SEVERITY_LEVEL;
    CONSTANT VitalErrorSeverity : VitalErrorSeverityType := (
        ErrVctLng    => ERROR,
        ErrNoPath    => WARNING,
        ErrNegPath   => WARNING,
        ErrNegDel    => WARNING
    );
 
    CONSTANT MsgNoPath : STRING :=
      "No Delay Path Condition TRUE.  0-delay used. Output signal is: ";
    CONSTANT MsgNegPath : STRING :=
      "Path Delay less than time since input. 0 delay used. Output signal is: ";
    CONSTANT MsgNegDel : STRING :=
      "Negative delay. New output value not scheduled. Output signal is: ";
    CONSTANT MsgVctLng : STRING :=
      "Vector (array) lengths not equal. ";
 
    CONSTANT MsgUnknown : STRING :=
      "Unknown error message.";
 
    FUNCTION VitalMessage (
            CONSTANT ErrorId : IN VitalErrorType
          ) RETURN STRING IS
    BEGIN
        CASE ErrorId IS
            WHEN ErrVctLng    => RETURN MsgVctLng;
            WHEN ErrNoPath    => RETURN MsgNoPath;
            WHEN ErrNegPath   => RETURN MsgNegPath;
            WHEN ErrNegDel    => RETURN MsgNegDel;
            WHEN OTHERS       => RETURN MsgUnknown;
        END CASE;
    END;

    PROCEDURE VitalError (
            CONSTANT Routine : IN STRING;
            CONSTANT ErrorId : IN VitalErrorType
    ) IS
    BEGIN
        ASSERT FALSE
          REPORT Routine & ": " & VitalMessage(ErrorId)
          SEVERITY VitalErrorSeverity(ErrorId);
    END;
 
    PROCEDURE VitalError (
            CONSTANT Routine : IN STRING;
            CONSTANT ErrorId : IN VitalErrorType;
            CONSTANT Info    : IN STRING
    ) IS
    BEGIN
        ASSERT FALSE
          REPORT Routine & ": " & VitalMessage(ErrorId) & Info
          SEVERITY VitalErrorSeverity(ErrorId);
    END;
 
    PROCEDURE VitalError (
            CONSTANT Routine : IN STRING;
            CONSTANT ErrorId : IN VitalErrorType;
            CONSTANT Info    : IN CHARACTER
    ) IS
    BEGIN
        ASSERT FALSE
          REPORT Routine & ": " & VitalMessage(ErrorId) & Info
          SEVERITY VitalErrorSeverity(ErrorId);
    END;
 
    ---------------------------------------------------------------------------
    -- Time Delay Assignment Subprograms
    ---------------------------------------------------------------------------
    FUNCTION VitalExtendToFillDelay ( 
            CONSTANT Delay : IN VitalDelayType
          ) RETURN VitalDelayType01Z IS
    BEGIN
        RETURN (OTHERS => Delay);
    END VitalExtendToFillDelay;

    FUNCTION VitalExtendToFillDelay ( 
            CONSTANT Delay : IN VitalDelayType01
          ) RETURN VitalDelayType01Z IS
        VARIABLE Delay01Z  : VitalDelayType01Z;
    BEGIN
        Delay01Z(tr01) := Delay(tr01);
        Delay01Z(tr0z) := Delay(tr01);
        Delay01Z(trz1) := Delay(tr01);
        Delay01Z(tr10) := Delay(tr10);
        Delay01Z(tr1z) := Delay(tr10);
        Delay01Z(trz0) := Delay(tr10);
        RETURN (Delay01Z);
    END VitalExtendToFillDelay;

    FUNCTION VitalExtendToFillDelay ( 
            CONSTANT Delay : IN VitalDelayType01Z
          ) RETURN VitalDelayType01Z IS
    BEGIN
        RETURN Delay;
    END VitalExtendToFillDelay;

    ---------------------------------------------------------------------------
    FUNCTION VitalCalcDelay (
            CONSTANT NewVal : IN std_ulogic   := 'X';
            CONSTANT OldVal : IN std_ulogic   := 'X';
            CONSTANT Delay  : IN VitalDelayType
          ) RETURN TIME IS
    BEGIN
          RETURN delay;
    END VitalCalcDelay;

    FUNCTION VitalCalcDelay (
            CONSTANT NewVal : IN std_ulogic   := 'X';
            CONSTANT OldVal : IN std_ulogic   := 'X';
            CONSTANT Delay  : IN VitalDelayType01
          ) RETURN TIME IS
        VARIABLE Result : TIME;
    BEGIN
        CASE Newval IS
          WHEN '0' | 'L' => Result := Delay(tr10);
          WHEN '1' | 'H' => Result := Delay(tr01);
          WHEN 'Z' =>
            CASE Oldval IS
              WHEN '0' | 'L' => Result := Delay(tr01);
              WHEN '1' | 'H' => Result := Delay(tr10);
              WHEN OTHERS    => Result := MAXIMUM(Delay(tr10), Delay(tr01));
            END CASE;
          WHEN OTHERS =>
            CASE Oldval IS
              WHEN '0' | 'L' => Result := Delay(tr01);
              WHEN '1' | 'H' => Result := Delay(tr10);
              WHEN 'Z'       => Result := MINIMUM(Delay(tr10), Delay(tr01));
              WHEN OTHERS    => Result := MAXIMUM(Delay(tr10), Delay(tr01));
            END CASE;
        END CASE;
        RETURN Result;
    END VitalCalcDelay;

    FUNCTION VitalCalcDelay (
            CONSTANT NewVal : IN std_ulogic   := 'X';
            CONSTANT OldVal : IN std_ulogic   := 'X';
            CONSTANT Delay  : IN VitalDelayType01Z
          ) RETURN TIME IS
        VARIABLE Result : TIME;
    BEGIN
        CASE Oldval IS
          WHEN '0' | 'L' =>
            CASE Newval IS
              WHEN '0' | 'L' => Result := Delay(tr10);
              WHEN '1' | 'H' => Result := Delay(tr01);
              WHEN 'Z'       => Result := Delay(tr0z);
              WHEN OTHERS    => Result := MINIMUM(Delay(tr01), Delay(tr0z));
            END CASE;
          WHEN '1' | 'H' =>
            CASE Newval IS
              WHEN '0' | 'L' => Result := Delay(tr10);
              WHEN '1' | 'H' => Result := Delay(tr01);
              WHEN 'Z'       => Result := Delay(tr1z);
              WHEN OTHERS    => Result := MINIMUM(Delay(tr10), Delay(tr1z));
            END CASE;
          WHEN 'Z' =>
            CASE Newval IS
              WHEN '0' | 'L' => Result := Delay(trz0);
              WHEN '1' | 'H' => Result := Delay(trz1);
              WHEN 'Z'       => Result := MAXIMUM (Delay(tr0z), Delay(tr1z));
              WHEN OTHERS    => Result := MINIMUM (Delay(trz1), Delay(trz0));
            END CASE;
          WHEN 'U' | 'X' | 'W' | '-'  =>
            CASE Newval IS
              WHEN '0' | 'L' => Result := MAXIMUM(Delay(tr10), Delay(trz0));
              WHEN '1' | 'H' => Result := MAXIMUM(Delay(tr01), Delay(trz1));
              WHEN 'Z'       => Result := MAXIMUM(Delay(tr1z), Delay(tr0z));
              WHEN OTHERS    => Result := MAXIMUM(Delay(tr10), Delay(tr01));
            END CASE;
        END CASE;
        RETURN Result;
    END VitalCalcDelay;

    ---------------------------------------------------------------------------
    FUNCTION VitalSelectPathDelay (
            CONSTANT NewValue      : IN  std_logic;
            CONSTANT OldValue      : IN  std_logic;
            CONSTANT OutSignalName : IN  string;
            CONSTANT Paths         : IN  VitalPathArrayType;
            CONSTANT DefaultDelay  : IN  VitalDelayType
          ) RETURN TIME IS
 
        VARIABLE TmpDelay  : TIME;
        VARIABLE InputAge  : TIME := TIME'HIGH;
        VARIABLE PropDelay : TIME := TIME'HIGH;
    BEGIN
        -- for each delay path
        FOR i IN Paths'RANGE LOOP
            -- ignore the delay path if it is not enabled
            NEXT WHEN NOT Paths(i).PathCondition;
            -- ignore the delay path if a more recent input event has been seen
            NEXT WHEN Paths(i).InputChangeTime > InputAge;
 
            -- This is the most recent input change (so far)
            -- Get the transition dependent delay
            TmpDelay := VitalCalcDelay(NewValue, OldValue, Paths(i).PathDelay);
 
            -- If other inputs changed at the same time,
            --  then use the minimum of their propagation delays,
            --  else use the propagation delay from this input.
            IF Paths(i).InputChangeTime < InputAge THEN
                PropDelay := TmpDelay;
            ELSE -- Simultaneous inputs change
                IF TmpDelay < PropDelay THEN PropDelay := TmpDelay; END IF;
            end if;
 
            InputAge := Paths(i).InputChangeTime;
        END LOOP;
 
        -- If there were no paths (with an enabled condition),
        --  use the default the delay
        IF (PropDelay  = TIME'HIGH ) THEN
            PropDelay := VitalCalcDelay(NewValue, OldValue, DefaultDelay);
 
        -- If the time since the most recent input event is greater than the
        -- propagation delay from that input then
        --  use the default the delay
        ELSIF (InputAge > PropDelay) THEN
            PropDelay := VitalCalcDelay(NewValue, OldValue, DefaultDelay);
 
        -- Adjust the propagation delay by the time since the
        -- the input event occurred  (Usually 0 ns).
        ELSE
            PropDelay := PropDelay - InputAge;
        END IF;
 
        RETURN PropDelay;
    END;
 
    FUNCTION VitalSelectPathDelay (
            CONSTANT NewValue      : IN  std_logic;
            CONSTANT OldValue      : IN  std_logic;
            CONSTANT OutSignalName : IN  string;
            CONSTANT Paths         : IN  VitalPathArray01Type;
            CONSTANT DefaultDelay  : IN  VitalDelayType01
          ) RETURN TIME IS
 
        VARIABLE TmpDelay  : TIME;
        VARIABLE InputAge  : TIME := TIME'HIGH;
        VARIABLE PropDelay : TIME := TIME'HIGH;
    BEGIN
        -- for each delay path
        FOR i IN Paths'RANGE LOOP
            -- ignore the delay path if it is not enabled
            NEXT WHEN NOT Paths(i).PathCondition;
            -- ignore the delay path if a more recent input event has been seen
            NEXT WHEN Paths(i).InputChangeTime > InputAge;
 
            -- This is the most recent input change (so far)
            -- Get the transition dependent delay
            TmpDelay := VitalCalcDelay(NewValue, OldValue, Paths(i).PathDelay);
 
            -- If other inputs changed at the same time,
            --  then use the minimum of their propagation delays,
            --  else use the propagation delay from this input.
            IF Paths(i).InputChangeTime < InputAge THEN
                PropDelay := TmpDelay;
            ELSE -- Simultaneous inputs change
                IF TmpDelay < PropDelay THEN PropDelay := TmpDelay; END IF;
            end if;
 
            InputAge := Paths(i).InputChangeTime;
        END LOOP;
 
        -- If there were no paths (with an enabled condition),
        --  use the default the delay
        IF (PropDelay  = TIME'HIGH ) THEN
            PropDelay := VitalCalcDelay(NewValue, OldValue, DefaultDelay);
 
        -- If the time since the most recent input event is greater than the
        -- propagation delay from that input then
        --  use the default the delay
        ELSIF (InputAge > PropDelay) THEN
            PropDelay := VitalCalcDelay(NewValue, OldValue, DefaultDelay);
 
        -- Adjust the propagation delay by the time since the
        -- the input event occurred  (Usually 0 ns).
        ELSE
            PropDelay := PropDelay - InputAge;
        END IF;
 
        RETURN PropDelay;
    END;
 
    FUNCTION VitalSelectPathDelay (
            CONSTANT NewValue      : IN  std_logic;
            CONSTANT OldValue      : IN  std_logic;
            CONSTANT OutSignalName : IN  string;
            CONSTANT Paths         : IN  VitalPathArray01ZType;
            CONSTANT DefaultDelay  : IN  VitalDelayType01Z
          ) RETURN TIME IS
 
        VARIABLE TmpDelay  : TIME;
        VARIABLE InputAge  : TIME := TIME'HIGH;
        VARIABLE PropDelay : TIME := TIME'HIGH;
    BEGIN
        -- for each delay path
        FOR i IN Paths'RANGE LOOP
            -- ignore the delay path if it is not enabled
            NEXT WHEN NOT Paths(i).PathCondition;
            -- ignore the delay path if a more recent input event has been seen
            NEXT WHEN Paths(i).InputChangeTime > InputAge;
 
            -- This is the most recent input change (so far)
            -- Get the transition dependent delay
            TmpDelay := VitalCalcDelay(NewValue, OldValue, Paths(i).PathDelay);
 
            -- If other inputs changed at the same time,
            --  then use the minimum of their propagation delays,
            --  else use the propagation delay from this input.
            IF Paths(i).InputChangeTime < InputAge THEN
                PropDelay := TmpDelay;
            ELSE -- Simultaneous inputs change
                IF TmpDelay < PropDelay THEN PropDelay := TmpDelay; END IF;
            end if;
 
            InputAge := Paths(i).InputChangeTime;
        END LOOP;
 
        -- If there were no paths (with an enabled condition),
        --  use the default the delay
        IF (PropDelay  = TIME'HIGH ) THEN
            PropDelay := VitalCalcDelay(NewValue, OldValue, DefaultDelay);
 
        -- If the time since the most recent input event is greater than the
        -- propagation delay from that input then
        --  use the default the delay
        ELSIF (InputAge > PropDelay) THEN
            PropDelay := VitalCalcDelay(NewValue, OldValue, DefaultDelay);
 
        -- Adjust the propagation delay by the time since the
        -- the input event occurred  (Usually 0 ns).
        ELSE
            PropDelay := PropDelay - InputAge;
        END IF;
 
        RETURN PropDelay;
    END;
 
    ---------------------------------------------------------------------------
    ---------------------------------------------------------------------------
    -- Glitch Handlers
    ---------------------------------------------------------------------------
    ---------------------------------------------------------------------------
    PROCEDURE ReportGlitch ( 
            CONSTANT GlitchRoutine  : IN  STRING;
            CONSTANT OutSignalName  : IN  STRING;
            CONSTANT PreemptedTime  : IN  TIME;
            CONSTANT PreemptedValue : IN  std_ulogic;
            CONSTANT NewTime        : IN  TIME;
            CONSTANT NewValue       : IN  std_ulogic;
            CONSTANT Index          : IN  INTEGER := 0;
            CONSTANT IsArraySignal  : IN  BOOLEAN := FALSE;
            CONSTANT MsgSeverity    : IN  SEVERITY_LEVEL := WARNING
    ) IS

        VARIABLE StrPtr1, StrPtr2, StrPtr3, StrPtr4, StrPtr5 : LINE;
    BEGIN

        Write (StrPtr1, PreemptedTime );
        Write (StrPtr2, NewTime);
        Write (StrPtr3, LogicCvtTable(PreemptedValue));
        Write (StrPtr4, LogicCvtTable(NewValue));
        IF IsArraySignal THEN
            Write (StrPtr5, STRING'( "(" ) );
            Write (StrPtr5, Index);
            Write (StrPtr5, STRING'( ")" ) );
        ELSE
            Write (StrPtr5, STRING'( " " ) );
        END IF;

        -- Issue Report only if Preempted value has not been
        --  removed from event queue
        ASSERT PreemptedTime >  NewTime
          REPORT GlitchRoutine & ": GLITCH Detected on port " & 
                 OutSignalName & StrPtr5.ALL &
                 "; Preempted Future Value := " & StrPtr3.ALL &
                 " @ " & StrPtr1.ALL &
                 "; Newly Scheduled Value := " & StrPtr4.ALL &
                 " @ " & StrPtr2.ALL &
                 ";"
          SEVERITY MsgSeverity;

        DEALLOCATE(StrPtr1);
        DEALLOCATE(StrPtr2);
        DEALLOCATE(StrPtr3);
        DEALLOCATE(StrPtr4); 
        DEALLOCATE(StrPtr5); 
        RETURN;
    END ReportGlitch;

    ---------------------------------------------------------------------------
    PROCEDURE VitalGlitch (
        SIGNAL   OutSignal     : OUT   std_logic;
        VARIABLE GlitchData    : INOUT VitalGlitchDataType;
        CONSTANT OutSignalName : IN    string;
        CONSTANT NewValue      : IN    std_logic;
        CONSTANT NewDelay      : IN    TIME           := 0 ns;
        CONSTANT Mode          : IN    VitalGlitchKindType := OnEvent;
        CONSTANT XOn           : IN    BOOLEAN        := TRUE;
        CONSTANT MsgOn         : IN    BOOLEAN        := FALSE;
        CONSTANT MsgSeverity   : IN    SEVERITY_LEVEL := WARNING
        ) IS
    ---------------------------------------------------------------------------
        VARIABLE NewGlitch : BOOLEAN := TRUE;
        VARIABLE dly       : TIME    := NewDelay;
 
    BEGIN
        -- If nothing to schedule, just return
        IF NewDelay < 0 ns THEN
            IF (NewValue /= GlitchData.SchedValue) THEN
                VitalError ( "VitalGlitch", ErrNegDel, OutSignalName );
            END IF;
            RETURN;
        END IF;
 
        -- If simple signal assignment
        --   perform the signal assignment
        IF    ( Mode = VitalInertial) THEN
            OutSignal <= NewValue AFTER dly;
        ELSIF ( Mode = VitalTransport ) THEN
            OutSignal <= TRANSPORT NewValue AFTER dly;
        ELSE
            -- Glitch Processing ---
            -- If nothing currently scheduled
            IF GlitchData.SchedTime <= NOW THEN
                -- Note: NewValue is always /= OldValue when called from VPPD
                IF (NewValue = GlitchData.SchedValue) THEN RETURN; END IF;
                -- No new glitch, save time for possable future glitch
                NewGlitch := FALSE;
                GlitchData.GlitchTime := NOW+dly;
     
            -- New value earlier than the earliest previous value scheduled
            ELSIF (NOW+dly <= GlitchData.GlitchTime)
                  AND (NOW+dly <= GlitchData.SchedTime) THEN
                -- No new glitch, save time for possible future glitch
                NewGlitch := FALSE;
                GlitchData.GlitchTime := NOW+dly;
         
            -- Transaction currently scheduled - if glitch already happened
            ELSIF GlitchData.GlitchTime <= NOW THEN
                IF (GlitchData.SchedValue = NewValue) THEN
                    dly := Minimum( GlitchData.SchedTime-NOW, NewDelay );
                END IF;
                NewGlitch := FALSE;
     
            -- Transaction currently scheduled (no glitch if same value)
            ELSIF (GlitchData.SchedValue = NewValue)
                  AND (GlitchData.SchedTime = GlitchData.GlitchTime) THEN
                -- revise scheduled output time if new delay is sooner
                dly := Minimum( GlitchData.SchedTime-NOW, NewDelay );
                -- No new glitch, save time for possable future glitch
                NewGlitch := FALSE;
                GlitchData.GlitchTime := NOW+dly;
     
            -- Transaction currently scheduled represents a glitch
            ELSE
                -- A new glitch has been detected
                NewGlitch := TRUE;
            END IF;
     
            IF NewGlitch THEN
                -- If  messages requested, report the glitch
                IF MsgOn THEN
                    ReportGlitch ("VitalGlitch", OutSignalName,
                                   GlitchData.GlitchTime, GlitchData.SchedValue,
                                   (dly + NOW), NewValue,
                                   MsgSeverity=>MsgSeverity );
                END IF;
     
                -- Force immediate glitch for "OnDetect" mode.
                IF (Mode = OnDetect) THEN
                    GlitchData.GlitchTime := NOW;
                END IF;
     
                -- If 'X' generation is requested, schedule the new value 
                --  preceeded by a glitch pulse.
                -- Otherwise just schedule the new value (inertial mode).
                IF XOn THEN
                    OutSignal <= 'X' AFTER GlitchData.GlitchTime-NOW;
                    OutSignal <= TRANSPORT NewValue AFTER dly;
                ELSE
                    OutSignal <= NewValue AFTER dly;
                END IF;
     
            -- If there no new glitch was detected, just schedule the new value.
            ELSE
                OutSignal <= NewValue AFTER dly;
            END IF;

        END IF;
 
        -- Record the new value and time just scheduled.
        GlitchData.SchedValue := NewValue;
        GlitchData.SchedTime  := NOW+dly;
        RETURN;
    END;
 
    ---------------------------------------------------------------------------
    PROCEDURE VitalPathDelay (
        SIGNAL   OutSignal     : OUT   std_logic;
        VARIABLE GlitchData    : INOUT VitalGlitchDataType;
        CONSTANT OutSignalName : IN    string;
        CONSTANT OutTemp       : IN    std_logic;
        CONSTANT Paths         : IN    VitalPathArrayType;
        CONSTANT DefaultDelay  : IN    VitalDelayType      := VitalZeroDelay;
        CONSTANT Mode          : IN    VitalGlitchKindType := OnEvent;
        CONSTANT XOn           : IN    BOOLEAN             := TRUE;
        CONSTANT MsgOn         : IN    BOOLEAN             := TRUE;
        CONSTANT MsgSeverity   : IN    SEVERITY_LEVEL      := WARNING
    ) IS
 
        VARIABLE PropDelay : TIME;
    BEGIN
        -- Check if the new value to be scheduled is different than the
        -- previously scheduled value
        IF (GlitchData.SchedTime <= NOW) AND
           (GlitchData.SchedValue = OutTemp)
             THEN RETURN;
        END IF;
 
        -- Evaluate propagation delay paths
        PropDelay := VitalSelectPathDelay (OutTemp, GlitchData.LastValue,
                                           OutSignalName, Paths, DefaultDelay);
        GlitchData.LastValue := OutTemp;
 
        -- Schedule the output transactions - including glitch handling
        VitalGlitch (OutSignal, GlitchData, OutSignalName, OutTemp,
                     PropDelay, Mode, XOn, MsgOn, MsgSeverity );
 
    END VitalPathDelay;

    PROCEDURE VitalPathDelay01 (
        SIGNAL   OutSignal     : OUT   std_logic;
        VARIABLE GlitchData    : INOUT VitalGlitchDataType;
        CONSTANT OutSignalName : IN    string;
        CONSTANT OutTemp       : IN    std_logic;
        CONSTANT Paths         : IN    VitalPathArray01Type;
        CONSTANT DefaultDelay  : IN    VitalDelayType01    := VitalZeroDelay01;
        CONSTANT Mode          : IN    VitalGlitchKindType := OnEvent;
        CONSTANT XOn           : IN    BOOLEAN             := TRUE;
        CONSTANT MsgOn         : IN    BOOLEAN             := TRUE;
        CONSTANT MsgSeverity   : IN    SEVERITY_LEVEL      := WARNING
    ) IS
 
        VARIABLE PropDelay : TIME;
    BEGIN
        -- Check if the new value to be scheduled is different than the
        -- previously scheduled value
        IF (GlitchData.SchedTime <= NOW) AND
           (GlitchData.SchedValue = OutTemp)
             THEN RETURN;
        END IF;
 
        -- Evaluate propagation delay paths
        PropDelay := VitalSelectPathDelay (OutTemp, GlitchData.LastValue,
                                           OutSignalName, Paths, DefaultDelay);
        GlitchData.LastValue := OutTemp;
 
        -- Schedule the output transactions - including glitch handling
        VitalGlitch (OutSignal, GlitchData, OutSignalName, OutTemp,
                     PropDelay, Mode, XOn, MsgOn, MsgSeverity );
 
    END VitalPathDelay01;

    PROCEDURE VitalPathDelay01Z (
        SIGNAL   OutSignal     : OUT   std_logic;
        VARIABLE GlitchData    : INOUT VitalGlitchDataType;
        CONSTANT OutSignalName : IN    string;
        CONSTANT OutTemp       : IN    std_logic;
        CONSTANT Paths         : IN    VitalPathArray01ZType;
        CONSTANT DefaultDelay  : IN    VitalDelayType01Z   := VitalZeroDelay01Z;
        CONSTANT Mode          : IN    VitalGlitchKindType := OnEvent;
        CONSTANT XOn           : IN    BOOLEAN             := TRUE;
        CONSTANT MsgOn         : IN    BOOLEAN             := TRUE;
        CONSTANT MsgSeverity   : IN    SEVERITY_LEVEL      := WARNING;
        CONSTANT OutputMap     : IN    VitalOutputMapType 
                                        := VitalDefaultOutputMap
    ) IS
 
        VARIABLE PropDelay : TIME;
    BEGIN
        -- Check if the new value to be scheduled is different than the
        -- previously scheduled value
        IF (GlitchData.SchedTime <= NOW) AND
           (GlitchData.SchedValue = OutputMap(OutTemp) )
             THEN RETURN;
        END IF;
 
        -- Evaluate propagation delay paths
        PropDelay := VitalSelectPathDelay (OutTemp, GlitchData.LastValue,
                                           OutSignalName, Paths, DefaultDelay);
        GlitchData.LastValue := OutTemp;
 
        -- Schedule the output transactions - including glitch handling
        VitalGlitch (OutSignal, GlitchData, OutSignalName, OutputMap(OutTemp),
                     PropDelay, Mode, XOn, MsgOn, MsgSeverity );
 
    END VitalPathDelay01Z;

    ----------------------------------------------------------------------------
    PROCEDURE VitalWireDelay (
            SIGNAL   OutSig  : OUT   std_ulogic;
            SIGNAL   InSig   : IN    std_ulogic;
            CONSTANT twire   : IN    VitalDelayType
    ) IS
    BEGIN
        OutSig <= TRANSPORT InSig AFTER twire;
    END VitalWireDelay;    

    PROCEDURE VitalWireDelay (
            SIGNAL   OutSig  : OUT   std_ulogic;
            SIGNAL   InSig   : IN    std_ulogic;
            CONSTANT twire   : IN    VitalDelayType01
    ) IS
       VARIABLE Delay   : TIME;
    BEGIN
        Delay := VitalCalcDelay( InSig, InSig'LAST_VALUE, twire );
        OutSig <= TRANSPORT InSig AFTER Delay;
    END VitalWireDelay;    

    PROCEDURE VitalWireDelay (
            SIGNAL   OutSig  : OUT   std_ulogic;
            SIGNAL   InSig   : IN    std_ulogic;
            CONSTANT twire   : IN    VitalDelayType01Z
    ) IS
       VARIABLE Delay   : TIME;
    BEGIN
        Delay := VitalCalcDelay( InSig, InSig'LAST_VALUE, twire );
        OutSig <= TRANSPORT InSig AFTER Delay;
    END VitalWireDelay;    

    ----------------------------------------------------------------------------
    PROCEDURE VitalSignalDelay (
            SIGNAL   OutSig     : OUT   std_ulogic;
            SIGNAL   InSig      : IN    std_ulogic;
            CONSTANT dly        : IN   TIME
    ) IS
    BEGIN
        OutSig <= TRANSPORT InSig AFTER dly;
    END;

    ---------------------------------------------------------------------------
    ---------------------------------------------------------------------------
    -- Setup and Hold Time Check Routine 
    ---------------------------------------------------------------------------
    ---------------------------------------------------------------------------
    PROCEDURE ReportViolation (
            CONSTANT TestSignalName : IN STRING := "";
            CONSTANT RefSignalName  : IN STRING := "";
            CONSTANT HeaderMsg      : IN STRING := " ";
            CONSTANT CheckInfo      : IN CheckInfoType;
            CONSTANT MsgSeverity    : IN SEVERITY_LEVEL := WARNING
    ) IS
        VARIABLE Message : LINE;
    BEGIN
        IF NOT CheckInfo.Violation THEN RETURN; END IF;

        Write ( Message, HeaderMsg );
        Case CheckInfo.CheckKind IS
          WHEN    SetupCheck => Write ( Message, STRING'(" SETUP ")      );
          WHEN     HoldCheck => Write ( Message, STRING'(" HOLD ")       );
          WHEN RecoveryCheck => Write ( Message, STRING'(" RECOVERY ")   );
          WHEN  RemovalCheck => Write ( Message, STRING'(" REMOVAL ")    );
          WHEN PulseWidCheck => Write ( Message, STRING'(" PULSE WIDTH "));
          WHEN   PeriodCheck => Write ( Message, STRING'(" PERIOD ")     );
        END CASE;
        Write ( Message, HiLoStr(CheckInfo.State) );
        Write ( Message, STRING'(" VIOLATION ON ") );
        Write ( Message, TestSignalName );
        IF (RefSignalName'LENGTH > 0) THEN
            Write ( Message, STRING'(" WITH RESPECT TO ") );
            Write ( Message, RefSignalName );
        END IF;
        Write ( Message, ';' & LF );
        Write ( Message, STRING'("  Expected := ")  );
        Write ( Message, CheckInfo.ExpTime);
        Write ( Message, STRING'("; Observed := ")  );
        Write ( Message, CheckInfo.ObsTime);
        Write ( Message, STRING'("; At : ")         );
        Write ( Message, CheckInfo.DetTime);

        ASSERT FALSE REPORT Message.ALL SEVERITY MsgSeverity;

        DEALLOCATE (Message);
    END ReportViolation;

    ---------------------------------------------------------------------------
    -- Procedure  : InternalTimingCheck
    ---------------------------------------------------------------------------
    PROCEDURE InternalTimingCheck (
            CONSTANT TestSignal    : IN     std_ulogic;
            CONSTANT RefSignal     : IN     std_ulogic;
            CONSTANT TestDelay     : IN     TIME := 0 ns;
            CONSTANT RefDelay      : IN     TIME := 0 ns;
            CONSTANT SetupHigh     : IN     TIME := 0 ns;
            CONSTANT SetupLow      : IN     TIME := 0 ns;
            CONSTANT HoldHigh      : IN     TIME := 0 ns;
            CONSTANT HoldLow       : IN     TIME := 0 ns;
            VARIABLE RefTime       : IN     TIME;
            VARIABLE RefEdge       : IN     BOOLEAN;
            VARIABLE TestTime      : IN     TIME;
            VARIABLE TestEvent     : IN     BOOLEAN;
            VARIABLE SetupEn       : INOUT  BOOLEAN;
            VARIABLE HoldEn        : INOUT  BOOLEAN;
            VARIABLE CheckInfo     : INOUT  CheckInfoType;
            CONSTANT MsgOn         : IN     BOOLEAN
    ) IS
        VARIABLE bias, b2 : TIME;
    BEGIN
        -- Check SETUP constraint
      IF RefEdge THEN
          IF SetupEn THEN
            CheckInfo.ObsTime   := RefTime - TestTime;
            CheckInfo.State     := To_X01(TestSignal);
            CASE CheckInfo.State IS
              WHEN '0' => CheckInfo.ExpTime := SetupLow;
              WHEN '1' => CheckInfo.ExpTime := SetupHigh;
              WHEN 'X' => CheckInfo.ExpTime := Maximum(SetupHigh,SetupLow);
            END CASE;
            CheckInfo.Violation := CheckInfo.ObsTime < CheckInfo.ExpTime;
            SetupEn  := FALSE;
          ELSE
            CheckInfo.Violation := FALSE;
          END IF;
  
        -- Check HOLD constraint
      ELSIF TestEvent THEN
          IF HoldEn THEN
            CheckInfo.ObsTime := TestTime - RefTime;
            CheckInfo.State := To_X01(TestSignal);
            CASE CheckInfo.State IS
              WHEN '0' => CheckInfo.ExpTime := HoldHigh;
              WHEN '1' => CheckInfo.ExpTime := HoldLow;
              WHEN 'X' => CheckInfo.ExpTime := Maximum(HoldHigh,HoldLow);
            END CASE;
            CheckInfo.Violation   := CheckInfo.ObsTime < CheckInfo.ExpTime;
            HoldEn := NOT CheckInfo.Violation;
          ELSE
            CheckInfo.Violation := FALSE;
          END IF;
      ELSE
          CheckInfo.Violation := FALSE;
      END IF;

      -- Adjust report values to account for internal model delays
      -- Note: TestDelay, RefDelay, TestTime, RefTime and bias are non-negative
      IF MsgOn AND CheckInfo.Violation THEN
          bias := TestDelay - RefDelay;
          IF TestTime - RefTime <= bias THEN
            CheckInfo.CheckKind := SetupCheck;
            b2 := TIME'HIGH - bias;
            IF (CheckInfo.ObsTime <= b2)
              THEN CheckInfo.ObsTime := CheckInfo.ObsTime + bias;
              ELSE CheckInfo.ObsTime := Time'HIGH;
            END IF;
            IF (CheckInfo.ExpTime <= b2)
              THEN CheckInfo.ExpTime := CheckInfo.ExpTime + bias;
              ELSE CheckInfo.ExpTime := Time'HIGH;
            END IF;
            CheckInfo.DetTime := RefTime - RefDelay;
          ELSE
            CheckInfo.CheckKind :=  HoldCheck;
            CheckInfo.ObsTime := CheckInfo.ObsTime - bias;
            IF (CheckInfo.ExpTime >= 0 ns) THEN
              CheckInfo.ExpTime := CheckInfo.ExpTime - bias;
            END IF;
            CheckInfo.DetTime := TestTime - TestDelay;
          END IF;
      END IF;
    END InternalTimingCheck;

    ---------------------------------------------------------------------------
    ---------------------------------------------------------------------------
    FUNCTION VitalTimingDataInit 
            RETURN VitalTimingDataType IS
    BEGIN
        RETURN (FALSE,'X', 0 ns, FALSE, 'X', 0 ns, FALSE, NULL, NULL, NULL, NULL);
    END;

    ---------------------------------------------------------------------------
    -- Procedure  : VitalSetupHoldCheck
    ---------------------------------------------------------------------------
    PROCEDURE VitalSetupHoldCheck (
            VARIABLE Violation     : OUT    X01;
            VARIABLE TimingData    : INOUT  VitalTimingDataType;
            SIGNAL   TestSignal    : IN     std_ulogic;
            CONSTANT TestSignalName: IN     STRING := "";
            CONSTANT TestDelay     : IN     TIME := 0 ns;
            SIGNAL   RefSignal     : IN     std_ulogic;
            CONSTANT RefSignalName : IN     STRING := "";
            CONSTANT RefDelay      : IN     TIME := 0 ns;
            CONSTANT SetupHigh     : IN     TIME := 0 ns;
            CONSTANT SetupLow      : IN     TIME := 0 ns;
            CONSTANT HoldHigh      : IN     TIME := 0 ns;
            CONSTANT HoldLow       : IN     TIME := 0 ns;
            CONSTANT CheckEnabled  : IN     BOOLEAN := TRUE;
            CONSTANT RefTransition : IN     VitalEdgeSymbolType;
            CONSTANT HeaderMsg     : IN     STRING  := " ";
            CONSTANT XOn           : IN     BOOLEAN := TRUE;
            CONSTANT MsgOn         : IN     BOOLEAN := TRUE;
            CONSTANT MsgSeverity   : IN     SEVERITY_LEVEL := WARNING
    ) IS 

        VARIABLE CheckInfo : CheckInfoType;
        VARIABLE RefEdge, TestEvent : BOOLEAN;
        VARIABLE TestDly : TIME := Maximum(0 ns, TestDelay);
        VARIABLE RefDly  : TIME := Maximum(0 ns, RefDelay);
        VARIABLE bias : TIME;
    BEGIN

      IF (TimingData.NotFirstFlag = FALSE) THEN
         TimingData.TestLast := To_X01(TestSignal);
         TimingData.RefLast := To_X01(RefSignal);
         TimingData.NotFirstFlag := TRUE;
      END IF;

      -- Detect reference edges and record the time of the last edge
      RefEdge := EdgeSymbolMatch(TimingData.RefLast, To_X01(RefSignal),
                                 RefTransition);
      TimingData.RefLast := To_X01(RefSignal);
      IF RefEdge THEN
        TimingData.RefTime := NOW;
        TimingData.HoldEn  := TRUE;
      END IF;

      -- Detect test (data) changes and record the time of the last change
      TestEvent := TimingData.TestLast /= To_X01Z(TestSignal);
      TimingData.TestLast := To_X01Z(TestSignal);
      IF TestEvent THEN
        TimingData.TestTime := NOW;
        TimingData.SetupEn  := TRUE;
      END IF;

      -- Perform timing checks (if enabled)
      Violation := '0';
      IF (CheckEnabled) THEN
         InternalTimingCheck (
             TestSignal   => TestSignal,
             RefSignal    => RefSignal,
             TestDelay    => TestDly,
             RefDelay     => RefDly,
             SetupHigh    => SetupHigh,
             SetupLow     => SetupLow,
             HoldHigh     => HoldHigh,
             HoldLow      => HoldLow,
             RefTime      => TimingData.RefTime,
             RefEdge      => RefEdge,
             TestTime     => TimingData.TestTime,
             TestEvent    => TestEvent,
             SetupEn      => TimingData.SetupEn,
             HoldEn       => TimingData.HoldEn,
             CheckInfo    => CheckInfo,
             MsgOn        => MsgOn );

        -- Report any detected violations and set return violation flag
        IF CheckInfo.Violation THEN
            IF (MsgOn) THEN
                ReportViolation (TestSignalName, RefSignalName,
                                 HeaderMsg, CheckInfo, MsgSeverity );
            END IF;
            IF (XOn) THEN Violation := 'X'; END IF;
        END IF;
      END IF;

    END VitalSetupHoldCheck;

    ---------------------------------------------------------------------------
    PROCEDURE VitalSetupHoldCheck (
            VARIABLE Violation     : OUT    X01;
            VARIABLE TimingData    : INOUT  VitalTimingDataType;
            SIGNAL   TestSignal    : IN     std_logic_vector;
            CONSTANT TestSignalName: IN     STRING := "";
            CONSTANT TestDelay     : IN     TIME := 0 ns;
            SIGNAL   RefSignal     : IN     std_ulogic;
            CONSTANT RefSignalName : IN     STRING := "";
            CONSTANT RefDelay      : IN     TIME := 0 ns;
            CONSTANT SetupHigh     : IN     TIME := 0 ns;
            CONSTANT SetupLow      : IN     TIME := 0 ns;
            CONSTANT HoldHigh      : IN     TIME := 0 ns;
            CONSTANT HoldLow       : IN     TIME := 0 ns;
            CONSTANT CheckEnabled  : IN     BOOLEAN := TRUE;
            CONSTANT RefTransition : IN     VitalEdgeSymbolType;
            CONSTANT HeaderMsg     : IN     STRING := " ";
            CONSTANT XOn           : IN     BOOLEAN := TRUE;
            CONSTANT MsgOn         : IN     BOOLEAN := TRUE;
            CONSTANT MsgSeverity   : IN     SEVERITY_LEVEL := WARNING
    ) IS 

        VARIABLE CheckInfo : CheckInfoType;
        VARIABLE RefEdge : BOOLEAN;
        VARIABLE TestEvent : VitalBoolArrayT(TestSignal'RANGE);
        VARIABLE TestDly : TIME := Maximum(0 ns, TestDelay);
        VARIABLE RefDly  : TIME := Maximum(0 ns, RefDelay);
        VARIABLE bias : TIME;
        VARIABLE ChangedAllAtOnce : BOOLEAN := TRUE;
        VARIABLE StrPtr1 : LINE;

    BEGIN
      -- Initialization of working area. 
      IF (TimingData.NotFirstFlag = FALSE) THEN
        TimingData.TestLastA := NEW std_logic_vector(TestSignal'RANGE);
        TimingData.TestTimeA := NEW  VitalTimeArrayT(TestSignal'RANGE);
        TimingData.HoldEnA   := NEW  VitalBoolArrayT(TestSignal'RANGE);
        TimingData.SetupEnA  := NEW  VitalBoolArrayT(TestSignal'RANGE);
        FOR i IN TestSignal'RANGE LOOP
          TimingData.TestLastA(i) := To_X01(TestSignal(i));
        END LOOP;
        TimingData.RefLast := To_X01(RefSignal);
        TimingData.NotFirstFlag := TRUE;
      END IF;

      -- Detect reference edges and record the time of the last edge
      RefEdge := EdgeSymbolMatch(TimingData.RefLast, To_X01(RefSignal),
                                 RefTransition);
      TimingData.RefLast := To_X01(RefSignal);
      IF RefEdge THEN
        TimingData.RefTime     := NOW;
        TimingData.HoldEnA.all := (TestSignal'RANGE=>TRUE);
      END IF;
  
      -- Detect test (data) changes and record the time of the last change
      FOR i IN TestSignal'RANGE LOOP
        TestEvent(i) := TimingData.TestLastA(i) /= To_X01Z(TestSignal(i));
        TimingData.TestLastA(i) := To_X01Z(TestSignal(i));
        IF TestEvent(i) THEN
          TimingData.TestTimeA(i) := NOW;
          TimingData.SetupEnA(i)  := TRUE;
          TimingData.TestTime := NOW;
        END IF;
      END LOOP;

      -- Check to see if the Bus subelements changed all at the same time.
      -- If so, then we can reduce the volume of error messages since we no
      -- longer have to report every subelement individually
      FOR i IN TestSignal'RANGE LOOP
        IF TimingData.TestTimeA(i) /= TimingData.TestTime THEN
            ChangedAllAtOnce := FALSE;
            EXIT;
        END IF;
      END LOOP;
  
      -- Perform timing checks (if enabled)
      Violation := '0';
      IF (CheckEnabled) THEN
        FOR i IN TestSignal'RANGE LOOP
          InternalTimingCheck (
              TestSignal   => TestSignal(i),
              RefSignal    => RefSignal,
              TestDelay    => TestDly,
              RefDelay     => RefDly,
              SetupHigh    => SetupHigh,
              SetupLow     => SetupLow,
              HoldHigh     => HoldHigh,
              HoldLow      => HoldLow,
              RefTime      => TimingData.RefTime,
              RefEdge      => RefEdge,
              TestTime     => TimingData.TestTimeA(i),
              TestEvent    => TestEvent(i),
              SetupEn      => TimingData.SetupEnA(i),
              HoldEn       => TimingData.HoldEnA(i),
              CheckInfo    => CheckInfo,
              MsgOn        => MsgOn );

          -- Report any detected violations and set return violation flag
          IF CheckInfo.Violation THEN
            IF (MsgOn) THEN
              IF ( ChangedAllAtOnce AND (i = TestSignal'LEFT) ) THEN
                ReportViolation (TestSignalName&"(...)", RefSignalName,
                                 HeaderMsg, CheckInfo, MsgSeverity );
              ELSIF (NOT ChangedAllAtOnce) THEN
                Write (StrPtr1, i);
                ReportViolation (TestSignalName & "(" & StrPtr1.ALL & ")", 
                                 RefSignalName,
                                 HeaderMsg, CheckInfo, MsgSeverity );
                DEALLOCATE (StrPtr1);
              END IF;
            END IF;
            IF (XOn) THEN
              Violation := 'X';
            END IF;
          END IF;
        END LOOP;
      END IF;

      DEALLOCATE (StrPtr1);

    END VitalSetupHoldCheck;
    
    ---------------------------------------------------------------------------
    -- Function   : VitalRecoveryRemovalCheck
    ---------------------------------------------------------------------------
    PROCEDURE VitalRecoveryRemovalCheck (
            VARIABLE Violation     : OUT    X01;
            VARIABLE TimingData    : INOUT  VitalTimingDataType;
            SIGNAL   TestSignal    : IN     std_ulogic;
            CONSTANT TestSignalName: IN     STRING := "";
            CONSTANT TestDelay     : IN     TIME := 0 ns;
            SIGNAL   RefSignal     : IN     std_ulogic;
            CONSTANT RefSignalName : IN     STRING := "";
            CONSTANT RefDelay      : IN     TIME := 0 ns;
            CONSTANT Recovery      : IN     TIME := 0 ns;
            CONSTANT Removal       : IN     TIME := 0 ns;
            CONSTANT ActiveLow     : IN     BOOLEAN := TRUE;
            CONSTANT CheckEnabled  : IN     BOOLEAN := TRUE;
            CONSTANT RefTransition : IN     VitalEdgeSymbolType;
            CONSTANT HeaderMsg     : IN     STRING := " ";
            CONSTANT XOn           : IN     BOOLEAN := TRUE;
            CONSTANT MsgOn         : IN     BOOLEAN := TRUE;
            CONSTANT MsgSeverity   : IN     SEVERITY_LEVEL := WARNING
    ) IS
        VARIABLE CheckInfo : CheckInfoType;
        VARIABLE RefEdge, TestEvent : BOOLEAN;
        VARIABLE TestDly : TIME := Maximum(0 ns, TestDelay);
        VARIABLE RefDly  : TIME := Maximum(0 ns, RefDelay);
        VARIABLE bias : TIME;
    BEGIN
 
      IF (TimingData.NotFirstFlag = FALSE) THEN
         TimingData.TestLast := To_X01(TestSignal);
         TimingData.RefLast := To_X01(RefSignal);
         TimingData.NotFirstFlag := TRUE;
      END IF;

      -- Detect reference edges and record the time of the last edge
      RefEdge := EdgeSymbolMatch(TimingData.RefLast, To_X01(RefSignal),
                                 RefTransition);
      TimingData.RefLast := To_X01(RefSignal);
      IF RefEdge THEN
        TimingData.RefTime := NOW;
        TimingData.HoldEn  := TRUE;
      END IF;
 
      -- Detect test (data) changes and record the time of the last change
      TestEvent := TimingData.TestLast /= To_X01Z(TestSignal);
      TimingData.TestLast := To_X01Z(TestSignal);
      IF TestEvent THEN
        TimingData.TestTime := NOW;
        TimingData.SetupEn  := TRUE;
      END IF;
 
      -- Perform timing checks (if enabled)
      Violation := '0';
      IF (CheckEnabled) THEN

        IF ActiveLow THEN
         InternalTimingCheck (
             TestSignal, RefSignal, TestDly, RefDly,
             Recovery, 0 ns, 0 ns, Removal,
             TimingData.RefTime, RefEdge,
             TimingData.TestTime, TestEvent,
             TimingData.SetupEn, TimingData.HoldEn,
             CheckInfo, MsgOn );
        ELSE 
         InternalTimingCheck (
             TestSignal, RefSignal, TestDly, RefDly,
             0 ns, Recovery, Removal, 0 ns,
             TimingData.RefTime, RefEdge,
             TimingData.TestTime, TestEvent,
             TimingData.SetupEn, TimingData.HoldEn,
             CheckInfo, MsgOn );
        END IF;

 
        -- Report any detected violations and set return violation flag
        IF CheckInfo.Violation THEN
            IF CheckInfo.CheckKind = SetupCheck THEN
                CheckInfo.CheckKind := RecoveryCheck;
            ELSE
                CheckInfo.CheckKind := RemovalCheck;
            END IF;
            IF (MsgOn) THEN
                ReportViolation (TestSignalName, RefSignalName, 
                                 HeaderMsg, CheckInfo, MsgSeverity );
            END IF;
            IF (XOn) THEN Violation := 'X'; END IF;
        END IF;
      END IF;

    END VitalRecoveryRemovalCheck;

    ---------------------------------------------------------------------------
    PROCEDURE VitalPeriodPulseCheck  (
            VARIABLE Violation      : OUT    X01;
            VARIABLE PeriodData     : INOUT  VitalPeriodDataType;
            SIGNAL   TestSignal     : IN     std_ulogic;
            CONSTANT TestSignalName : IN     STRING := "";
            CONSTANT TestDelay      : IN     TIME := 0 ns;
            CONSTANT Period         : IN     TIME := 0 ns;
            CONSTANT PulseWidthHigh : IN     TIME := 0 ns;
            CONSTANT PulseWidthLow  : IN     TIME := 0 ns;
            CONSTANT CheckEnabled   : IN     BOOLEAN := TRUE;
            CONSTANT HeaderMsg      : IN     STRING := " ";
            CONSTANT XOn            : IN     BOOLEAN := TRUE;
            CONSTANT MsgOn          : IN     BOOLEAN := TRUE;
            CONSTANT MsgSeverity    : IN     SEVERITY_LEVEL := WARNING
    ) IS 

        VARIABLE TestDly : TIME := Maximum(0 ns, TestDelay);
        VARIABLE CheckInfo : CheckInfoType;
        VARIABLE PeriodObs : TIME;
        VARIABLE PulseTest, PeriodTest : BOOLEAN;
        VARIABLE TestValue : X01 := To_X01(TestSignal);
    BEGIN

        IF (PeriodData.NotFirstFlag = FALSE) THEN
           PeriodData.Rise :=
                -maximum(Period, maximum(PulseWidthHigh, PulseWidthLow));
           PeriodData.Fall :=
                -maximum(Period, maximum(PulseWidthHigh, PulseWidthLow));
           PeriodData.Last := To_X01(TestSignal);
           PeriodData.NotFirstFlag := TRUE;
        END IF;

        -- Initialize for no violation
        -- No violation possible if no test signal change
        Violation := '0';
        IF (PeriodData.Last = TestValue) THEN
            RETURN;
        END IF;

        -- record starting pulse times
        IF EdgeSymbolMatch(PeriodData.Last, TestValue, 'P') THEN
            -- Compute period times, then record the High Rise Time
            PeriodObs := NOW - PeriodData.Rise;
            PeriodData.Rise := NOW;
            PeriodTest := TRUE;
        ELSIF EdgeSymbolMatch(PeriodData.Last, TestValue, 'N') THEN
            -- Compute period times, then record the Low Fall Time
            PeriodObs := NOW - PeriodData.Fall;
            PeriodData.Fall := NOW;
            PeriodTest := TRUE;
        ELSE
            PeriodTest := FALSE;
	END IF;

        -- do checks on pulse ends
        IF EdgeSymbolMatch(PeriodData.Last, TestValue, 'p') THEN
            -- Compute pulse times
            CheckInfo.ObsTime := NOW - PeriodData.Fall;
            CheckInfo.ExpTime := PulseWidthLow;
            PulseTest := TRUE;
        ELSIF EdgeSymbolMatch(PeriodData.Last, TestValue, 'n') THEN
            -- Compute pulse times
            CheckInfo.ObsTime := NOW - PeriodData.Rise;
            CheckInfo.ExpTime := PulseWidthHigh;
            PulseTest := TRUE;
        ELSE
            PulseTest := FALSE;
        END IF;

        IF PulseTest AND CheckEnabled THEN
           -- Verify Pulse Width [ignore 1st edge]
            IF ( CheckInfo.ObsTime < CheckInfo.ExpTime ) THEN
                IF (XOn) THEN Violation := 'X'; END IF;
                IF (MsgOn) THEN
                    CheckInfo.Violation := TRUE;
                    CheckInfo.CheckKind := PulseWidCheck;
                    CheckInfo.DetTime   := NOW - TestDly;
                    CheckInfo.State     := PeriodData.Last;
                    ReportViolation (TestSignalName, "", 
                                     HeaderMsg, CheckInfo, MsgSeverity );
                END IF; -- MsgOn
            END IF;
        END IF;

        IF PeriodTest AND CheckEnabled THEN
            -- Verify the Period [ignore 1st edge]
            CheckInfo.ObsTime := PeriodObs;
            CheckInfo.ExpTime := Period;
            IF ( CheckInfo.ObsTime < CheckInfo.ExpTime ) THEN
                IF (XOn) THEN Violation := 'X'; END IF;
                IF (MsgOn) THEN
                    CheckInfo.Violation := TRUE;
                    CheckInfo.CheckKind := PeriodCheck;
                    CheckInfo.DetTime   := NOW - TestDly;
                    CheckInfo.State     := TestValue;
                    ReportViolation (TestSignalName, "",
                                     HeaderMsg, CheckInfo, MsgSeverity );
                END IF; -- MsgOn
            END IF;
        END IF;

        PeriodData.Last := TestValue;

    END VitalPeriodPulseCheck;

END VITAL_Timing;

