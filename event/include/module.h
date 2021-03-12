#include <stddef.h>

void freeall_module();

typedef void (*fptr)(void);

fptr get_fptr(int module_num);

void module_1();

void module_2();

void module_3();

void module_4();

void module_5();

void module_init(int num_events);


