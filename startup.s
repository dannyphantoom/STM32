.syntax unified 
.cpu cortex-m3 
.thumb

.global _start
.section .isr_vector, "a", %progbits
.word 0x20005000
.word _start

.text
_start:
    bl main

halt:
    wfi
    b halt
