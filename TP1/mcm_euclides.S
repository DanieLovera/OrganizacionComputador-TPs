#include <sys/regdef.h>

.text
.align 2
.globl mcm_euclides
.extern mcd_euclides
.ent mcm_euclides 
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
 * - t0
 * - t1
 */
#define O_L0 STACK_SIZE - 20
#define O_L1 STACK_SIZE - 24

/*
 * Argument building area (ABA) callee
 * 16 bytes
 * Se reserva para el llamado a mcd_euclides
 */

/* Firma de la funcion:
 * unsigned int mcm_euclides(unsigned int a, unsigned int b);
 */
mcm_euclides:
	.frame fp, STACK_SIZE, ra	
	addiu sp, sp, -STACK_SIZE
	sw ra, O_RA(sp)
	sw fp, O_FP(sp)
	.cprestore O_GP
	move fp, sp
	sw a0, O_A0(fp)
	sw a1, O_A1(fp)
	
	/* unsigned int mcd = mcd_euclides(a, b); */
	lw a0, O_A0(fp)
	lw a1, O_A1(fp)
	jal mcd_euclides
	sw v0, O_L0(sp)

	/* unsigned int a_x_b = (a * b); */
	lw t0, O_A0(fp)
	lw t1, O_A1(fp)
	multu t0, t1
	mflo t0
	sw t0, O_L1(fp)

return:
	/* return (a_x_b / mcd); */
	lw t0, O_L0(fp)
	lw t1, O_L1(fp)
	divu v0, t1, t0

	lw ra, O_RA(sp)
	lw fp, O_FP(sp)
	lw gp, O_GP(sp)	
	addiu sp, sp, STACK_SIZE
	jr ra
.end mcm_euclides
