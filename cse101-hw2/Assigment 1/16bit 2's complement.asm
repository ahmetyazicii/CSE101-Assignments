load R0,047h
load R1,004h
load R2,01
load R3,0
load R4,0FFh
xor R0,R0,R4
xor R1,R1,R4
move RA,R0
load R0,0FFh
jmpEQ R1=R0,a
jmp b 
a:addi RA,RA,R2
b:addi R1,R1,R2
move R0,RA
move R2,R3
move R4,R3
move RA,R3
halt
