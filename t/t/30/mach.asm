START
MOV SP, 10
MOV BP, SP
PUSH R0
CALL MAIN
POP R0
HALT
Lprint:
PUSH BP
MOV BP, SP
MOV R1, 0
MOV R0, SP
ADD R0, R1
MOV SP, R0
MOV R1, [10]
MOV R2, 0
ADD R1, R2
MOV R0, [R1]
OUT R0
MOV R0, 0
MOV R1, BP
MOV R2, 2
SUB R1, R2
MOV [R1], R0
MOV SP, BP
POP BP
RET
MAIN:
PUSH BP
MOV BP, SP
MOV R1, 1
MOV R0, SP
ADD R0, R1
MOV SP, R0
L1:
MOV R0, [10]
MOV R1, 10
LT R0, R1
JZ R0, L2
MOV R1, [10]
IN R0
MOV R2, 0
ADD R1, R2
MOV [R1], R0
PUSH R0
CALL Lprint
POP R0
MOV R2, 0
MOV R1, SP
SUB R1, R2
MOV SP, R1
MOV R2, 1
MOV R1, BP
ADD R1, R2
MOV [R1], R0
MOV R0, [10]
MOV R1, 1
ADD R0, R1
MOV [10], R0
JMP L1
L2:
MOV R0, 0
MOV R1, BP
MOV R2, 2
SUB R1, R2
MOV [R1], R0
MOV SP, BP
POP BP
RET
