START
MOV SP, 1
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
MOV R2, -3
MOV R1, BP
ADD R1, R2
MOV R0, [R1]
MOV R2, [R0]
MOV R0, R2
MOV R2, 1
MOV R1, BP
ADD R1, R2
MOV [R1], R0
MOV R2, -4
MOV R1, BP
ADD R1, R2
MOV R0, [R1]
MOV R2, [R0]
MOV R0, R2
MOV R2, -3
MOV R1, BP
ADD R1, R2
MOV R2, [R1]
MOV [R2], R0
MOV R2, 1
MOV R1, BP
ADD R1, R2
MOV R0, [R1]
MOV R2, -4
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
MAIN:
PUSH BP
MOV BP, SP
MOV R1, 1
MOV R0, SP
ADD R0, R1
MOV SP, R0
MOV R1, 0
IN R0
MOV R2, 0
ADD R1, R2
MOV [R1], R0
MOV R1, 1
IN R0
MOV R2, 0
ADD R1, R2
MOV [R1], R0
MOV R1, 0
MOV R0, 0
ADD R0, R1
PUSH R0
MOV R1, 1
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
MOV R2, 1
MOV R1, BP
ADD R1, R2
MOV [R1], R0
MOV R1, 0
MOV R2, 0
ADD R1, R2
MOV R0, [R1]
OUT R0
MOV R1, 1
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
