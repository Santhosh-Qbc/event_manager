#include<stdio.h>
#include"module.h"
#include"event_manager.h"
#include<stdlib.h>

extern struct mod *first;
extern struct mod *last;


void register_event(int module_num,int events, fptr cb_1){
	struct mod *ptr = NULL;
	ptr = (struct mod*) malloc(sizeof(struct mod));
	ptr->module_id = module_num;
	ptr->event_map = events;
	ptr->cb = cb_1;
	ptr->next = NULL;
	if(!first){
		first = ptr;
		ptr->prev = NULL;
		last = ptr;
	}
	else{
		ptr->prev = last;
		last->next = ptr;
		last = ptr;
	}
	return;
}

int checkbit(int a,int b){
	if(a&(1<<(b-1))){
		return 1;
	}
	else{
		return 0;
	}
}

void execute_event(int event){
	struct mod *temp = first;
	while(temp != NULL){
		if (checkbit(temp->event_map,event)){
			temp->cb();
		}
		temp = temp->next;
	}
}
