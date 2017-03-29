#ifndef _linux_capi_oslib_h_
#define _linux_capi_oslib_h_


/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
struct _stack_interrupt_library {
    void (*enable_irq)( void );
    void (*disable_irq)( void );
    void (*tasklet_func)(unsigned long);
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
struct _stack_init_params {
    int	io_addr;
    int	irq_num;
    int	dect_hw;
    int	dect_on;
    int	local_ec;
    int	debug_mode;
    int	trace_mode;
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
typedef struct __f {
	
	unsigned	nfuncs;
	void	     (* sched_ctrl) (unsigned);
	void         (* wakeup_ctrl) (unsigned);
} functions_t, * functions_p;

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
typedef struct __cb {
    unsigned int controllers;

	unsigned (* cm_start) (void);
	char * (* cm_init) (unsigned, unsigned);
	int (* cm_activate) (void);
	int (* cm_exit) (void);
	unsigned (* cm_handle_events) (void);
	int (* cm_schedule) (void);
	void (* cm_timer_irq_control) (unsigned);
	void (* cm_register_ca_functions) (functions_p);
	unsigned (* check_controller) (unsigned, unsigned *);
    unsigned (*cm_bufsize)(void);
    unsigned (*cm_ctrl_tasklet)(unsigned int);
    unsigned char *(*cm_getprofile)(unsigned int);

	void * (* lib_heap_init) (void *, unsigned);
	void (* lib_heap_exit) (void *);
	void * (* lib_heap_alloc) (void *, unsigned);
	void (* lib_heap_free) (void *, void *);
} lib_callback_t;

#ifdef __CAPI_OSLIB__
extern struct _stack_init_params  *capi_oslib_init_params;
extern struct _stack_interrupt_library *capi_oslib_interrupt_library;
extern lib_callback_t *capi_oslib_stack;
#endif /*--- #ifdef __CAPI_OSLIB__ ---*/

int avm_stack_attach(lib_callback_t *stack_library, struct _stack_interrupt_library *irq_library, struct _stack_init_params *p_params);
int avm_stack_detach(lib_callback_t *stack_library);


void os_trigger_scheduler(void);
void os_disable_scheduler (void);
void os_enable_scheduler (void);

void EnterCritical (void);
void _EnterCritical (char *, int);
void LeaveCritical (void);
void _LeaveCritical (char *, int);

#endif /*--- #ifndef _linux_capi_oslib_h_ ---*/
