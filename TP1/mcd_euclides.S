#include <sys/regdef.h>

.text
.align 2
.globl mcd_euclides
.ent mcd_euclides 
/*
 * Espacio reservado para el stack de la funcion
 */
#define STACK_SIZE 40

/*
 * Argument building area (ABA) caller
 * 16 bytes
 * - a1
 * - a0
 */
#define O_A1 STACK_SIZE + 4 
#define O_A0 STACK_SIZE

/* 
 * Save register area (SRA) callee
 * 16 bytes
 * - padding
 * - ra
 * - fp
 * - gp
 */
#define O_RA STACK_SIZE - 8
#define O_FP STACK_SIZE - 12 
#define O_GP STACK_SIZE - 16

/*
 * Local and temporary area (LTA) callee
 * 8 bytes
 * - padding
 * - t0
 */
#define O_L0 STACK_SIZE - 24

/*
 * Argument building area (ABA) callee
 * 16 bytes
 * Se reserva para el llamado recursivo
 */

/* Firma de la funcion:
 * unsigned int mcd_euclides(unsigned int a, unsigned int b);
 */
mcd_euclides:
	.frame fp, STACK_SIZE, ra	
	addiu sp, sp, -STACK_SIZE
	sw ra, O_RA(sp)
	sw fp, O_FP(sp)
	.cprestore O_GP
	move fp, sp
	sw a0, O_A0(fp)
	sw a1, O_A1(fp)
	
	/* unsigned int r = 0 */
	move t0, zero
	sw t0, O_L0(fp)
	
	/* if (b == 0) */
	lw t0, O_A1(fp)
	beqz t0, return
	
	/* r = (a % b); */
	lw t0, O_A0(fp)
	lw t1, O_A1(fp)
	divu t0, t0, t1
	mfhi t0
	sw t0, O_L0(fp)	

return_recursivo:
	/* return mcd_euclides(b, r); */
	lw a0, O_A1(fp)
	lw a1, O_L0(fp)
	jal mcd_euclides
	
	lw ra, O_RA(sp)
	lw fp, O_FP(sp)
	lw gp, O_GP(sp)	
	addiu sp, sp, STACK_SIZE
	jr ra	

return:
	/* return a; */
	lw v0, O_A0(sp)

	lw ra, O_RA(sp)
	lw fp, O_FP(sp)
	lw gp, O_GP(sp)	
	addiu sp, sp, STACK_SIZE
	jr ra
.end mcd_euclides
