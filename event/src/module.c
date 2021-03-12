#include<stdio.h>
#include<stdlib.h>
#include"module.h"
#include"event_manager.h"

#define bitmap(a,b) (a|(1<<(b-1)));

extern struct mod *first;
extern struct mod *last;




void module_1(){
	printf("%s\n", __func__);
}

void module_2(){
	printf("%s\n", __func__);
}

void module_3(){
	printf("%s\n", __func__);
}

void module_4(){
	printf("%s\n", __func__);
}

void module_5(){
	printf("%s\n", __func__);
}

fptr get_fptr(int module_num){
	switch(module_num){
		case 1:
			return(&module_1);
		case 2:
			return(&module_2);
		case 3:
			return(&module_3);
		case 4:
			return(&module_4);
		case 5:
			return(&module_5);
		default:
			return(NULL);
	}
}
void module_init(int num_events){
        int module_num, n_events, events, ev_list;
        for(module_num = 1; module_num < 6; module_num++){
                printf("Enter the total num of events module %d is interested in\n",module_num);
                scanf("%d",&n_events);
                events = 0;
                while(n_events){
                        printf("Enter the event\n");
                        scanf("%d",&ev_list);
                        events = bitmap(events,ev_list);
                        n_events--;
                }
                register_event(module_num,events,get_fptr(module_num));
        }
}       

void freeall_module(){
        struct mod *temp = first;
        while(first != NULL){
                first = temp->next;
                free(temp);
                temp = first;
        }
        last = NULL;
        return;
}

