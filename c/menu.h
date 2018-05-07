#include <stdio.h>

void printmenu(){
	printf("**********Student Score Manage System**********");
	printf("\n***********************************************\n");
	printf("                   Menu Items \n");
	printf("***********************************************\n");
	printf("*      1__System Initialize                   *\n");
	printf("*      2__Data Loading                        *\n");
	printf("*      3__Input Students Information          *\n");
	printf("*      4__Edit Students Information           *\n");
	printf("*      5__Query Students Information          *\n");
	printf("*      6__Statistic Students Information      *\n");
	printf("*      7__OutPut Data to File                 *\n");
	printf("*      8__Display Students Information        *\n");
	printf("*      0__Exit System                         *\n");
	printf("***********************************************\n");
	} 

void Editmenu(){
	printf("-----------------------------------------------\n");
	printf("                   Edit  Sub_Meun\n");
	printf("-----------------------------------------------\n");
	printf("                1__Add Record\n");
	printf("                2__Delect Record\n");
	printf("                3__Modify Record\n");
	printf("                4__Return\n");
	printf("-----------------------------------------------\n");
}

void Querymenu(){
	printf("-----------------------------------------------\n");
	printf("                   Query Sub_Meun\n");
	printf("                1__Query by No\n");
	printf("                2__Query by Name\n");
	printf("                3__Return\n");
	printf("-----------------------------------------------\n");
}
