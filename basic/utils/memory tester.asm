org 28000
main
;Calculate the FREE SPACE left for BASIC Program in the system after you insert a clear command
LD HL,0
ADD HL,SP
LD DE,(23653)
AND A
SBC HL,DE
LD B,H
LD C,L
RET

main2
org 28020
;Returns the length of a BASIC Program
LD HL,(23627)
LD DE,(23635)
AND A
SBC HL,DE
LD B,H
LD C,L
RET

