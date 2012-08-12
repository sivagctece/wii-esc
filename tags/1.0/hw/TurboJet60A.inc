.include "common.inc"

#define Typ "TurboJet 60A"

;*********************
; PORT B definitions *
;*********************
;#define                7     
;#define                6     
#define    DbgLED       5;o   (sck stk200 interface) 
;#define                4     (miso stk200 interface)
;#define                3     (mosi stk200 interface) 
;#define                2     
;#define                1     
;#define                0

#define INIT_PB         0
#define DIR_PB          (1<<DbgLED)
#define BRAKE_PB        0

#define DbgLEDOn        sbi     PORTB,5
#define DbgLEDOff       cbi     PORTB,5

;*********************
; PORT C definitions *
;*********************
#define INIT_PC         0
#define DIR_PC          0
#define BRAKE_PC        0

;*********************
; PORT D definitions *
;*********************  
#define BpFET		7;o
#define c_comp		6;i common comparator input (AIN0)
#define ApFET		5;o
#define CpFET		4;o
#define CnFET		3;o
#define rcp_in		2;i r/c pulse input
#define BnFET		1;o
#define AnFET		0;o

#define INIT_PD         0
#define DIR_PD          (1<<ApFET)+(1<<BpFET)+(1<<CpFET)+(1<<AnFET)+(1<<BnFET)+(1<<CnFET)
#define BRAKE_PD        (1<<AnFET)+(1<<BnFET)+(1<<CnFET)

;*********************
; ADC definitions    *
;*********************
#define mux_a           2     ; ADC2
#define mux_b           3     ; ADC3
#define mux_c           4     ; ADC4
#define ACCU_MUX        7     ; ADC7 voltage control input 

;*********************
; FET Control        *
;*********************
#define ApFET_on        sbi     PORTD, ApFET
#define ApFET_off       cbi     PORTD, ApFET
#define AnFET_on        sbi     PORTD, AnFET
#define AnFET_off       cbi     PORTD, AnFET

#define BpFET_on        sbi     PORTD, BpFET
#define BpFET_off       cbi     PORTD, BpFET
#define BnFET_on        sbi     PORTD, BnFET
#define BnFET_off       cbi     PORTD, BnFET

#define CpFET_on        sbi     PORTD, CpFET
#define CpFET_off       cbi     PORTD, CpFET
#define CnFET_on        sbi     PORTD, CnFET
#define CnFET_off       cbi     PORTD, CnFET

;*************************
; Comparator definitions *
;*************************
.macro AcInit
  ACMultiplexed
.endmacro

.macro AcPhaseA
  ACChannel mux_a
.endmacro

.macro AcPhaseB
  ACChannel mux_b
.endmacro

.macro AcPhaseC
  ACChannel mux_c
.endmacro

;*************************
; Parameters             *
;*************************
#undef     MOT_BRAKE      
#undef     READ_CALIBRATION
#define    F_CPU               16000000          ; 16Mhz oscilator 
#undef     COMP_PWM
#define    CHARGE_BOOTSTRAP
#define    TIMING_ADV          0

;*************************
; Power settings         *
;*************************
#define    PCT_PWR_MIN         5                 ; Min power 5%

;*************************
; Power curve            *
;*************************
PWR_CURVE_POINT(01, 3500, 25)
PWR_CURVE_POINT(02, 7000, 50)

;*************************
; Startup settings       *
;*************************
#define    RPM_STEP_INITIAL    155
#define    RPM_STEP_MAX        200
#define    PCT_PWR_STARTUP     15
#define    PCT_PWR_MAX_STARTUP 20
#define    RPM_START_MIN_RPM   4200
#define    ENOUGH_GOODIES      20

;*************************
; Run settings           *
;*************************
#define    RPM_RUN_MIN_RPM     3200