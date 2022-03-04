#include <stdio.h>    
#include <stdlib.h>
#include <string.h>   
#include <unistd.h>   
#include <getopt.h>
#include "arduino-serial-lib.c"
#include "arduino-serial-lib.h"
#include <stdint.h>

int menu(); /* menu function for selecting from menu*/
int cont(); /* function for returning menu*/

int main(){

	int oprnd,sqr;
	char arry[256];
	
	const char* pr="x"; /* parameters for data which sending to Arduino */
	const char* pr2="y";
	const char* pr3="z";

	int port = serialport_init("/dev/ttyACM0",9600); /*for start comminication with Arduino*/
	
	oprnd=menu();

	switch(oprnd)
	{
		case 1:						
  					
					serialport_write(port,pr); /*sending data to Arduino*/  					  					
  					
  					main();
  					
  					break;
  					
  		case 2:
  					
					serialport_write(port,pr2); /*sending data to Arduino*/
  														
  					main();
  					
  					break;
  		
  		case 3:
  					do
  					{
						serialport_write(port,pr3); /*sending data to Arduino*/
  					
  					} while(cont() !=1);
  					
  									
  					main();
  					
  					break;
  		case 4:
  					do
  					{
						
						memset(arry,0,256); /* memset function for clear  char array of arry */
						
						printf("\nPLEASE WRITE THE NUMBER THAT WANT TO CALCULATE SQUARE\n");
						scanf("%d",&sqr);
						
						sqr=sqr+100; /* for negative numbers */
						
						serialport_writebyte(port,sqr); /*sending data to Arduino*/
						serialport_read_until(port,arry, '\n',256,30); /*receiving data from Arduino*/
						
						printf("THE SQUARE OF GIVEN NUMBER:%s\n",arry );
				
  					} while(cont() !=1);

  					main();
  					
  					break;

  		case 0:
  					serialport_close(port);/*for stop comminication with Arduino*/
	
  					printf("\nTHANKS FOR USING, SEE U LATER\n");
  					
  					break;			
  		
  		default: 
  					printf("\nPLEASE SELECT FROM MENU");
  					
  					main();
  					
  					break;			
	}
	
return 0;

}
int menu()  
{
	int oprnd;

	printf("\n\t\t\tWELCOME TO GTU ARDUINO LAB");
	printf("\nSTUDENT NAME:AHMET YAZICI");
	printf("\nPLEASE SELECT FROM THE FOLLOWING");
	printf("\nMENU:");
	printf("\n(1) TURN ON LED ON ARDUINO");
	printf("\n(2) TURN OFF LED ON ARDUINO");
	printf("\n(3) FLASH ARDUINO LED 3 TIMES");
	printf("\n(4) SEND A NUMBER TO ARDUINO TO COMPUTE SQUARE BY ARDUINO");
	printf("\n(0) EXIT");
	printf("\nPLEASE SELECT   ");
	scanf(" %d",&oprnd);

	return oprnd;

}

int cont() 
{

	char cont;

	printf("PRESS 'c' TO CONTINUE THE OPERATION OR PRESS 'm' TO RETURN THE MENU  ");
	scanf(" %c",&cont);
	
	if (cont =='c')
	{
		return 0;
	}

	else if (cont =='m')
	{
		printf("\nRETURNING MENU...");
		return 1;
	}
    
    else{
    	return 0;
    }
	

	return 0;

}