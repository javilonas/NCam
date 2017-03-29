#ifndef UBIK2_DEBUG_H
#define UBIK2_DEBUG_H

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#define MAX_DEBUG_MESSAGE_LEN 1024

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
int ubik2_debug_init(void);
void ubik2_debug_cleanup(void);
void ubik2_DebugPrintf(const char *format, ...);
void ubik2_DebugPuts(char *DebugData, unsigned int length);

#endif /*--- #ifndef UBIK2_DEBUG_H ---*/
