START
MOV SP, 99
MOV BP, SP
PUSH R0
CALL MAIN
POP R0
HALT
Lswap:
PUSH BP
MOV BP, SP
MOV R1, 1
MOV R0, SP
ADD R0, R1
MOV SP, R0
MOV R2, -4
MOV R1, BP
ADD R1, R2
MOV R0, [R1]
MOV R2, [R0]
MOV R0, R2
MOV R2, 1
MOV R1, BP
ADD R1, R2
MOV [R1], R0
MOV R2, -3
MOV R1, BP
ADD R1, R2
MOV R0, [R1]
MOV R2, [R0]
MOV R0, R2
MOV R2, -4
MOV R1, BP
ADD R1, R2
MOV R2, [R1]
MOV [R2], R0
MOV R2, 1
MOV R1, BP
ADD R1, R2
MOV R0, [R1]
MOV R2, -3
MOV R1, BP
ADD R1, R2
MOV R2, [R1]
MOV [R2], R0
MOV R0, 0
MOV R1, BP
MOV R2, 2
SUB R1, R2
MOV [R1], R0
MOV SP, BP
POP BP
RET
Lsort:
PUSH BP
MOV BP, SP
MOV R1, 3
MOV R0, SP
ADD R0, R1
MOV SP, R0
MOV R0, 0
MOV R2, 1
MOV R1, BP
ADD R1, R2
MOV [R1], R0
L1:
MOV R2, 1
MOV R1, BP
ADD R1, R2
MOV R0, [R1]
MOV R3, -3
MOV R2, BP
ADD R2, R3
MOV R1, [R2]
LT R0, R1
JZ R0, L2
MOV R0, 0
MOV R2, 2
MOV R1, BP
ADD R1, R2
MOV [R1], R0
L3:
MOV R2, 2
MOV R1, BP
ADD R1, R2
MOV R0, [R1]
MOV R3, -3
MOV R2, BP
ADD R2, R3
MOV R1, [R2]
MOV R2, 1
SUB R1, R2
LT R0, R1
JZ R0, L4
MOV R3, 2
MOV R2, BP
ADD R2, R3
MOV R1, [R2]
MOV R2, 0
ADD R1, R2
MOV R0, [R1]
MOV R4, 2
MOV R3, BP
ADD R3, R4
MOV R2, [R3]
MOV R3, 1
ADD R2, R3
MOV R3, 0
ADD R2, R3
MOV R1, [R2]
GT R0, R1
JZ R0, L5
MOV R3, 2
MOV R2, BP
ADD R2, R3
MOV R1, [R2]
MOV R0, 0
ADD R0, R1
PUSH R0
MOV R3, 2
MOV R2, BP
ADD R2, R3
MOV R1, [R2]
MOV R2, 1
ADD R1, R2
MOV R0, 0
ADD R0, R1
PUSH R0
PUSH R0
CALL Lswap
POP R0
MOV R2, 2
MOV R1, SP
SUB R1, R2
MOV SP, R1
MOV R2, 3
MOV R1, BP
ADD R1, R2
MOV [R1], R0
L5:
MOV R2, 2
MOV R1, BP
ADD R1, R2
MOV R0, [R1]
MOV R1, 1
ADD R0, R1
MOV R2, 2
MOV R1, BP
ADD R1, R2
MOV [R1], R0
JMP L3
L4:
MOV R2, 1
MOV R1, BP
ADD R1, R2
MOV R0, [R1]
MOV R1, 1
ADD R0, R1
MOV R2, 1
MOV R1, BP
ADD R1, R2
MOV [R1], R0
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
MAIN:
PUSH BP
MOV BP, SP
MOV R1, 3
MOV R0, SP
ADD R0, R1
MOV SP, R0
IN R0
MOV R2, 1
MOV R1, BP
ADD R1, R2
MOV [R1], R0
MOV R0, 0
MOV R2, 2
MOV R1, BP
ADD R1, R2
MOV [R1], R0
L6:
MOV R2, 2
MOV R1, BP
ADD R1, R2
MOV R0, [R1]
MOV R3, 1
MOV R2, BP
ADD R2, R3
MOV R1, [R2]
LT R0, R1
JZ R0, L7
MOV R3, 2
MOV R2, BP
ADD R2, R3
MOV R1, [R2]
IN R0
MOV R2, 0
ADD R1, R2
MOV [R1], R0
MOV R2, 2
MOV R1, BP
ADD R1, R2
MOV R0, [R1]
MOV R1, 1
ADD R0, R1
MOV R2, 2
MOV R1, BP
ADD R1, R2
MOV [R1], R0
JMP L6
L7:
MOV R2, 1
MOV R1, BP
ADD R1, R2
MOV R0, [R1]
PUSH R0
PUSH R0
CALL Lsort
POP R0
MOV R2, 1
MOV R1, SP
SUB R1, R2
MOV SP, R1
MOV R2, 3
MOV R1, BP
ADD R1, R2
MOV [R1], R0
MOV R0, 0
MOV R2, 2
MOV R1, BP
ADD R1, R2
MOV [R1], R0
L8:
MOV R2, 2
MOV R1, BP
ADD R1, R2
MOV R0, [R1]
MOV R3, 1
MOV R2, BP
ADD R2, R3
MOV R1, [R2]
LT R0, R1
JZ R0, L9
MOV R3, 2
MOV R2, BP
ADD R2, R3
MOV R1, [R2]
MOV R2, 0
ADD R1, R2
MOV R0, [R1]
OUT R0
MOV R2, 2
MOV R1, BP
ADD R1, R2
MOV R0, [R1]
MOV R1, 1
ADD R0, R1
MOV R2, 2
MOV R1, BP
ADD R1, R2
MOV [R1], R0
JMP L8
L9:
MOV R0, 0
MOV R1, BP
MOV R2, 2
SUB R1, R2
MOV [R1], R0
MOV SP, BP
POP BP
RET
