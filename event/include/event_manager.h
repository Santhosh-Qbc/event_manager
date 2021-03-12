#include"module.h"

struct mod{
        int module_id;
        int event_map;
        fptr cb;
        struct mod *next;
        struct mod *prev;
};

void register_event(int module_num,int events, fptr cb_1);

void execute_event(int event);
