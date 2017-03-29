/*------------------------------------------------------------------------------------------*\
 *
\*------------------------------------------------------------------------------------------*/
#ifndef _ENV_H_
#define _ENV_H_

extern void env_init(int *penv);
extern char *prom_getenv(char *name);
extern char *getcmdline(void);

#endif
