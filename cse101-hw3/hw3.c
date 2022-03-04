#include<stdio.h>
#define HALT 123456

int menu();
void add();
void subt();
void multi();
void div();
int cont();
void power();
void avg();
void max();

int main(){
    int oprt;
    
    printf("\t\t\t\tWELCOME TO MY CALCULATOR MACHINE");
    printf("\nSTUDENT NAME:\tAHMET YAZICI");
    
    oprt=menu();
    
    switch (oprt)
    {
        case 1:
                do
                {
                        add();
                } while (cont()!=1);
           
                main();
            break;
        
        case 2:
                do
                {
                         subt();
                } while (cont()!=1);
           
                main();
            break;
        
        case 3:
                do
                {
                        multi();
                } while (cont()!=1);
           
                main();
            break;
        
        case 4:
                do
                {
                        div();
                } while (cont()!=1);
           
                main();
            break;
        
        case 5:
               do
                {
                        power();
                } while (cont()!=1);
            
                main();
            break;
        
        case 6:
                do
                {
                        avg();
                } while (cont()!=1);
            
                main();
       
            break;
        
        case 7:
                do
                {
                        max();
                } while (cont()!=1);
            
                main();
       
            break;
        
        case 0: 
            
            printf("\nTHANKS FOR USING CALCULATOR SEE U LATER :)");
       
            break;   
    }
    return 0;
}

int menu(){
    int oprt;
    
    printf("\nPLEASE SELECT FROM THE FOLLOWING");
    printf("\nMENU:");
    printf("\n(1) ADD TWO NUMBERS");
    printf("\n(2) SUBTRACT TWO NUMBERS");
    printf("\n(3) MULTIPLY TWO NUMBERS");
    printf("\n(4) DIVIDE TWO NUMBERS");
    printf("\n(5) TAKE THE NTH POWER OF A NUMBER");
    printf("\n(6) FIND AVERAGE OF NUMBERS INPUTTED");
    printf("\n(7) FIND THE MAXIMUM OF NUMBERS INPUTTED");
    printf("\n(0) EXIT\n");
    scanf("%d",&oprt);
    
    return oprt;
}

void add(){
    float num1,num2;
    
    printf("\nPLEASE WRITE THE FIRST NUMBER ");
    scanf("%f",&num1);
    printf("PLEASE WRITE THE SECOND NUMBER ");
    scanf("%f",&num2);  
    printf("\nTHE RESULT IS: %0.4f",num1+num2);
}

void subt(){
    float num1,num2;
   
    printf("\nPLEASE WRITE THE FIRST NUMBER ");
    scanf("%f",&num1);
    printf("PLEASE WRITE THE SECOND NUMBER ");
    scanf("%f",&num2);
    printf("\nTHE RESULT IS: %0.4f",num1-num2);
}

void multi(){
    float num1,num2;
    
    printf("\nPLEASE WRITE THE FIRST NUMBER ");
    scanf("%f",&num1);
    printf("PLEASE WRITE THE SECOND NUMBER ");
    scanf("%f",&num2);
    printf("\nTHE RESULT IS: %0.4f",num1*num2);
}

void div(){
    float num1,num2;
    
    printf("\nPLEASE WRITE THE FIRST NUMBER ");
    scanf("%f",&num1);
    printf("PLEASE WRITE THE SECOND NUMBER ");
    scanf("%f",&num2);
    
    if (num2==0){
        printf("\nNUMBER CAN NOT BE DIVIDED ZERO");}
    
    else {
        printf("\nTHE RESULT IS: %0.4f",num1/num2); }
}

int cont(){
    char let;

    printf("\nPRESS 'c' TO CONTINUE THE OPERATION OR PRESS 'm' TO RETURN THE MENU  ");
    scanf(" %c",&let);
    
    if (let=='c'){
        return 0; }
    
    if (let=='m'){
        return 1; }

    return 0;
}

void power(){
    float num1,a;
    int i,num2;
    
    printf("\nPLEASE WRITE THE FIRST NUMBER ");
    scanf("%f",&num1);
    printf("PLEASE WRITE THE SECOND NUMBER ");
    scanf("%d",&num2);
    
    if(num1==0 && num2==0){
        printf("\n0^0=THE RESULT IS UNCERTAIN"); }
    
    else if (num2==0){
        printf("\n%.2f^0=1",num1); }
    
    else{
        printf("\n%.2f",num1);    
        
        a=num1;
        
        for ( i = 0; i < num2-1; i++)
        {
            a=a*num1;
            printf("*%.2f",num1);
        }
        
        printf(" = %.2f^%d = %.2f",num1,num2,a);
    }
}

void avg(){
    float nums=0,res=0;
    int step=0;
   
    printf("\nPLEASE WRITE THE NUMBERS AND WRITE 123456 TO STOP\n");
  
    while (nums !=HALT)
    {
        res=res+nums;
        step=step+1;
        scanf("%f",&nums);
    }
    
    res=res/(step-1);
    printf("\nTHE AVERAGE OF GIVEN NUMBERS=%.2f",res);
}

void max(){
    float nums=0,res=0;
    
    printf("\nPLEASE WRITE THE NUMBERS AND WRITE 123456 TO STOP\n");
  
    do
    {
        scanf("%f",&nums);
        
        if (nums==HALT){
            break;}
        if(res<nums){
            res=nums; }
        
    } while (nums !=HALT);
    
    printf("\nTHE MAXIMUM NUMBER OF GIVEN NUMBERS=%.2f",res);
}