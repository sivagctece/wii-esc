#ifndef config_h
#define config_h

//#define SERIAL_COM_SPEED 256000
//#define SERIAL_COM_SPEED 115200
#define SERIAL_COM_SPEED 57600
#define OSC_DEBUG

//*************************
// Power settings         *
//*************************
#define    PCT_PWR_MIN         8

//*************************
// Startup settings       *
//*************************
#define    RPM_STEP_INITIAL    155
#define    RPM_STEP_MAX        200
#define    PCT_PWR_STARTUP     10
#define    PCT_PWR_MAX_STARTUP 30
#define    RPM_START_MIN_RPM   7000
#define    ENOUGH_GOODIES      240

//*************************
// Run settings           *
//*************************
#define    RPM_RUN_MIN_RPM     3200

//*************************
// RC Input               *
//*************************
#define RCP_MIN                900
#define RCP_MAX                2200
#define RCP_START              1060
#define RCP_FULL               1860
#define RCP_DEADBAND           5


#endif
