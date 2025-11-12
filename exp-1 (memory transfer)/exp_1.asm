// EXT - EXT

ORG 00H
MOV R0, #0AH
MOV R1, #00H
MOV R2, #50H
MOV DPTR, #0100H
JUMP:
MOVX A, @DPTR
PUSH DPL
PUSH DPH
MOV DPL, R1
MOV DPH, R2
MOVX @DPTR, A
POP DPH
POP DPL
INC R1
INC DPTR
DJNZ R0, JUMP
END

//////////////////////////////////////////////////////////////////////

// INT - INT

ORG 00H

MOV R0, #30H      ; Source starting address in internal RAM
MOV R1, #40H      ; Destination starting address in internal RAM
MOV R2, #0AH      ; Counter for 10 bytes to transfer

LOOP:
    MOV A, @R0    ; Move data from source into accumulator
    MOV @R1, A    ; Move data from accumulator to destination
    INC R0        ; Increment source pointer
    INC R1        ; Increment destination pointer
    DJNZ R2, LOOP ; Decrement counter and repeat until zero

END

/////////////////////////////////////////////////////////////////////

// INT - EXT

 ORG 00H
 MOV R0, #30H
 MOV R2, #0AH
 MOV DPTR, #0100H
 JUMP:
 MOV A, @R0
 MOVX @DPTR, A
 INC R0
 INC DPTR
 DJNZ R2, JUMP
 END


/////////////////////////////////////////////////////////////////////

// EXT - INT

ORG 00H
 MOV R0, #30H
 MOV R2, #0AH
 MOV DPTR, #0100H
 JUMP:
 MOVX A, @DPTR
 MOV @R0, A
 INC R0
 INC DPTR
 DJNZ R2, JUMP
 END
