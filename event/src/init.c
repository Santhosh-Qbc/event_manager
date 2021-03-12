#include<stdio.h>
#include"module.h"
#include"event_manager.h"
#include<stdlib.h>


struct mod *first =NULL;
struct mod *last = NULL;

int main(){

	int num_events, enter = 1, Event;
	printf("enter the num of events\n");
	scanf("%d",&num_events);
	module_init(num_events);

	printf("Enter the events to be executed:\n");
	while(enter){
		printf("Enter 0 to exit\n");
		scanf("%d",&Event);
		if(Event != 0){
			if(Event <= num_events)
				execute_event(Event);
			else
				printf("UNKNOWN EVENT\n");
		}else{
			freeall_module();
			enter = 0;
		}	
	}
	return(0);
}
