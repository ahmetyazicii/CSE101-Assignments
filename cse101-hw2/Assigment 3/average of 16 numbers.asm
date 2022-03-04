org 0A0h
db   3,11,17,6,21,13,15,4,13,17,7,5,9,4,1,18
org 000h
load R3,0A1h
load R9,0
load R4,1
load R5,00001111b
load R0,0B0h
load R1,[0A0h]
b:load R2,[R3]
addi R1,R2,R1
addi R3,R3,R4
jmpEQ R3=R0,a
jmp b
a:ror R1,4
and R1,R1,R5
move R0,R1
move R1,R9
move R2,R9
move R3,R9
move R4,R9
move R5,R9
halt


