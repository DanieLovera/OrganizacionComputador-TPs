	.file	1 "tp0.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.globl	BASE64
	.rdata
	.align	2
$LC0:
	.ascii	"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123"
	.ascii	"456789+/\000"
	.section	.data.rel.local,"aw",@progbits
	.align	2
	.type	BASE64, @object
	.size	BASE64, 4
BASE64:
	.word	$LC0
	.rdata
	.align	2
$LC1:
	.ascii	"-h\000"
	.align	2
$LC2:
	.ascii	"--help\000"
	.align	2
$LC3:
	.ascii	"-V\000"
	.align	2
$LC4:
	.ascii	"--version\000"
	.align	2
$LC5:
	.ascii	"Version 1.0.0\012\000"
	.align	2
$LC6:
	.ascii	"-d\000"
	.align	2
$LC7:
	.ascii	"--decode\000"
	.align	2
$LC8:
	.ascii	"-i\000"
	.align	2
$LC9:
	.ascii	"--input\000"
	.align	2
$LC10:
	.ascii	"r\000"
	.align	2
$LC11:
	.ascii	"Error: Cannot open/find the specified input file\000"
	.align	2
$LC12:
	.ascii	"-o\000"
	.align	2
$LC13:
	.ascii	"--output\000"
	.align	2
$LC14:
	.ascii	"w\000"
	.text
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp,120,$31		# vars= 56, regs= 10/0, args= 16, gp= 8
	.mask	0xc0ff0000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$25
	.set	nomacro
	addiu	$sp,$sp,-120
	sw	$31,116($sp)
	sw	$fp,112($sp)
	sw	$23,108($sp)
	sw	$22,104($sp)
	sw	$21,100($sp)
	sw	$20,96($sp)
	sw	$19,92($sp)
	sw	$18,88($sp)
	sw	$17,84($sp)
	sw	$16,80($sp)
	move	$fp,$sp
	.cprestore	16
	sw	$4,120($fp)
	sw	$5,124($fp)
	li	$2,1			# 0x1
	sb	$2,24($fp)
	lw	$2,%got(stdin)($28)
	lw	$2,0($2)
	sw	$2,28($fp)
	lw	$2,%got(stdout)($28)
	lw	$2,0($2)
	sw	$2,32($fp)
	lw	$2,%got(codification)($28)
	sw	$2,36($fp)
	li	$2,1			# 0x1
	sw	$2,40($fp)
	b	$L2
	nop

$L15:
	lw	$2,40($fp)
	sll	$2,$2,2
	lw	$3,124($fp)
	addu	$2,$3,$2
	lw	$3,0($2)
	lw	$2,%got($LC1)($28)
	addiu	$5,$2,%lo($LC1)
	move	$4,$3
	lw	$2,%call16(strcmp)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,strcmp
1:	jalr	$25
	nop

	lw	$28,16($fp)
	beq	$2,$0,$L3
	nop

	lw	$2,40($fp)
	sll	$2,$2,2
	lw	$3,124($fp)
	addu	$2,$3,$2
	lw	$3,0($2)
	lw	$2,%got($LC2)($28)
	addiu	$5,$2,%lo($LC2)
	move	$4,$3
	lw	$2,%call16(strcmp)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,strcmp
1:	jalr	$25
	nop

	lw	$28,16($fp)
	bne	$2,$0,$L4
	nop

$L3:
	lw	$2,%got(printHelp)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,printHelp
1:	jalr	$25
	nop

	lw	$28,16($fp)
	move	$2,$0
	b	$L27
	nop

$L4:
	lw	$2,40($fp)
	sll	$2,$2,2
	lw	$3,124($fp)
	addu	$2,$3,$2
	lw	$3,0($2)
	lw	$2,%got($LC3)($28)
	addiu	$5,$2,%lo($LC3)
	move	$4,$3
	lw	$2,%call16(strcmp)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,strcmp
1:	jalr	$25
	nop

	lw	$28,16($fp)
	beq	$2,$0,$L6
	nop

	lw	$2,40($fp)
	sll	$2,$2,2
	lw	$3,124($fp)
	addu	$2,$3,$2
	lw	$3,0($2)
	lw	$2,%got($LC4)($28)
	addiu	$5,$2,%lo($LC4)
	move	$4,$3
	lw	$2,%call16(strcmp)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,strcmp
1:	jalr	$25
	nop

	lw	$28,16($fp)
	bne	$2,$0,$L7
	nop

$L6:
	lw	$2,%got(stdout)($28)
	lw	$2,0($2)
	move	$7,$2
	li	$6,14			# 0xe
	li	$5,1			# 0x1
	lw	$2,%got($LC5)($28)
	addiu	$4,$2,%lo($LC5)
	lw	$2,%call16(fwrite)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,fwrite
1:	jalr	$25
	nop

	lw	$28,16($fp)
	move	$2,$0
	b	$L27
	nop

$L7:
	lw	$2,40($fp)
	sll	$2,$2,2
	lw	$3,124($fp)
	addu	$2,$3,$2
	lw	$3,0($2)
	lw	$2,%got($LC6)($28)
	addiu	$5,$2,%lo($LC6)
	move	$4,$3
	lw	$2,%call16(strcmp)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,strcmp
1:	jalr	$25
	nop

	lw	$28,16($fp)
	beq	$2,$0,$L8
	nop

	lw	$2,40($fp)
	sll	$2,$2,2
	lw	$3,124($fp)
	addu	$2,$3,$2
	lw	$3,0($2)
	lw	$2,%got($LC7)($28)
	addiu	$5,$2,%lo($LC7)
	move	$4,$3
	lw	$2,%call16(strcmp)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,strcmp
1:	jalr	$25
	nop

	lw	$28,16($fp)
	bne	$2,$0,$L9
	nop

$L8:
	sb	$0,24($fp)
	lw	$2,%got(decodification)($28)
	sw	$2,36($fp)
	b	$L10
	nop

$L9:
	lw	$2,40($fp)
	sll	$2,$2,2
	lw	$3,124($fp)
	addu	$2,$3,$2
	lw	$3,0($2)
	lw	$2,%got($LC8)($28)
	addiu	$5,$2,%lo($LC8)
	move	$4,$3
	lw	$2,%call16(strcmp)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,strcmp
1:	jalr	$25
	nop

	lw	$28,16($fp)
	beq	$2,$0,$L11
	nop

	lw	$2,40($fp)
	sll	$2,$2,2
	lw	$3,124($fp)
	addu	$2,$3,$2
	lw	$3,0($2)
	lw	$2,%got($LC9)($28)
	addiu	$5,$2,%lo($LC9)
	move	$4,$3
	lw	$2,%call16(strcmp)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,strcmp
1:	jalr	$25
	nop

	lw	$28,16($fp)
	bne	$2,$0,$L12
	nop

$L11:
	lw	$2,40($fp)
	addiu	$2,$2,1
	sll	$2,$2,2
	lw	$3,124($fp)
	addu	$2,$3,$2
	lw	$3,0($2)
	lw	$2,%got($LC10)($28)
	addiu	$5,$2,%lo($LC10)
	move	$4,$3
	lw	$2,%call16(fopen)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,fopen
1:	jalr	$25
	nop

	lw	$28,16($fp)
	sw	$2,28($fp)
	lw	$2,28($fp)
	bne	$2,$0,$L10
	nop

	lw	$2,%got(stderr)($28)
	lw	$2,0($2)
	move	$7,$2
	li	$6,48			# 0x30
	li	$5,1			# 0x1
	lw	$2,%got($LC11)($28)
	addiu	$4,$2,%lo($LC11)
	lw	$2,%call16(fwrite)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,fwrite
1:	jalr	$25
	nop

	lw	$28,16($fp)
	li	$2,1			# 0x1
	b	$L27
	nop

$L12:
	lw	$2,40($fp)
	sll	$2,$2,2
	lw	$3,124($fp)
	addu	$2,$3,$2
	lw	$3,0($2)
	lw	$2,%got($LC12)($28)
	addiu	$5,$2,%lo($LC12)
	move	$4,$3
	lw	$2,%call16(strcmp)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,strcmp
1:	jalr	$25
	nop

	lw	$28,16($fp)
	beq	$2,$0,$L14
	nop

	lw	$2,40($fp)
	sll	$2,$2,2
	lw	$3,124($fp)
	addu	$2,$3,$2
	lw	$3,0($2)
	lw	$2,%got($LC13)($28)
	addiu	$5,$2,%lo($LC13)
	move	$4,$3
	lw	$2,%call16(strcmp)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,strcmp
1:	jalr	$25
	nop

	lw	$28,16($fp)
	bne	$2,$0,$L10
	nop

$L14:
	lw	$2,40($fp)
	addiu	$2,$2,1
	sll	$2,$2,2
	lw	$3,124($fp)
	addu	$2,$3,$2
	lw	$3,0($2)
	lw	$2,%got($LC14)($28)
	addiu	$5,$2,%lo($LC14)
	move	$4,$3
	lw	$2,%call16(fopen)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,fopen
1:	jalr	$25
	nop

	lw	$28,16($fp)
	sw	$2,32($fp)
	lw	$2,32($fp)
	bne	$2,$0,$L10
	nop

	lw	$2,%got(stderr)($28)
	lw	$2,0($2)
	move	$7,$2
	li	$6,48			# 0x30
	li	$5,1			# 0x1
	lw	$2,%got($LC11)($28)
	addiu	$4,$2,%lo($LC11)
	lw	$2,%call16(fwrite)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,fwrite
1:	jalr	$25
	nop

	lw	$28,16($fp)
	li	$2,1			# 0x1
	b	$L27
	nop

$L10:
	lw	$2,40($fp)
	addiu	$2,$2,1
	sw	$2,40($fp)
$L2:
	lw	$2,120($fp)
	lw	$3,40($fp)
	sltu	$2,$3,$2
	bne	$2,$0,$L15
	nop

	lbu	$2,24($fp)
	beq	$2,$0,$L16
	nop

	li	$2,4			# 0x4
	b	$L17
	nop

$L16:
	li	$2,5			# 0x5
$L17:
	sw	$2,44($fp)
	lw	$2,44($fp)
	move	$4,$2
	sw	$4,72($fp)
	move	$2,$sp
	sw	$2,76($fp)
	move	$2,$4
	addiu	$2,$2,-1
	sw	$2,48($fp)
	move	$2,$4
	move	$23,$2
	move	$22,$0
	srl	$2,$23,29
	sll	$18,$22,3
	or	$18,$2,$18
	sll	$19,$23,3
	move	$2,$4
	move	$21,$2
	move	$20,$0
	srl	$2,$21,29
	sll	$16,$20,3
	or	$16,$2,$16
	sll	$17,$21,3
	move	$2,$4
	addiu	$2,$2,7
	srl	$2,$2,3
	sll	$2,$2,3
	subu	$sp,$sp,$2
	addiu	$2,$sp,16
	addiu	$2,$2,0
	sw	$2,52($fp)
	lw	$2,44($fp)
	addiu	$2,$2,-1
	lw	$3,52($fp)
	addu	$2,$3,$2
	sb	$0,0($2)
	lw	$2,52($fp)
	move	$3,$4
	addiu	$3,$3,-1
	lw	$7,28($fp)
	move	$6,$3
	li	$5,1			# 0x1
	move	$4,$2
	lw	$2,%call16(fread)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,fread
1:	jalr	$25
	nop

	lw	$28,16($fp)
	sw	$2,68($fp)
	b	$L18
	nop

$L26:
	lbu	$2,24($fp)
	xori	$2,$2,0x1
	andi	$2,$2,0x00ff
	beq	$2,$0,$L19
	nop

	lw	$2,52($fp)
	li	$5,61			# 0x3d
	move	$4,$2
	lw	$2,%call16(strchr)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,strchr
1:	jalr	$25
	nop

	lw	$28,16($fp)
	bne	$2,$0,$L20
	nop

	lw	$2,52($fp)
	li	$5,10			# 0xa
	move	$4,$2
	lw	$2,%call16(strchr)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,strchr
1:	jalr	$25
	nop

	lw	$28,16($fp)
	beq	$2,$0,$L19
	nop

$L20:
	lw	$2,52($fp)
	li	$5,61			# 0x3d
	move	$4,$2
	lw	$2,%call16(strchr)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,strchr
1:	jalr	$25
	nop

	lw	$28,16($fp)
	beq	$2,$0,$L21
	nop

	li	$2,61			# 0x3d
	b	$L22
	nop

$L21:
	li	$2,10			# 0xa
$L22:
	sb	$2,56($fp)
	lw	$2,52($fp)
	addiu	$4,$fp,68
	lb	$3,56($fp)
	move	$6,$4
	move	$5,$3
	move	$4,$2
	lw	$2,%got(removeCharacter)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,removeCharacter
1:	jalr	$25
	nop

	lw	$28,16($fp)
	lw	$2,68($fp)
	beq	$2,$0,$L28
	nop

$L19:
	lw	$2,52($fp)
	lw	$3,68($fp)
	lbu	$4,24($fp)
	move	$6,$4
	move	$5,$3
	move	$4,$2
	lw	$2,%got(combineBytes)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,combineBytes
1:	jalr	$25
	nop

	lw	$28,16($fp)
	sw	$2,60($fp)
	lw	$2,60($fp)
	bgez	$2,$L24
	nop

	li	$2,1			# 0x1
	b	$L25
	nop

$L24:
	lw	$3,68($fp)
	lw	$2,36($fp)
	move	$5,$3
	lw	$4,60($fp)
	move	$25,$2
	jalr	$25
	nop

	lw	$28,16($fp)
	sw	$2,64($fp)
	lw	$4,64($fp)
	lw	$2,%call16(strlen)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,strlen
1:	jalr	$25
	nop

	lw	$28,16($fp)
	lw	$7,32($fp)
	move	$6,$2
	li	$5,1			# 0x1
	lw	$4,64($fp)
	lw	$2,%call16(fwrite)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,fwrite
1:	jalr	$25
	nop

	lw	$28,16($fp)
	lw	$4,64($fp)
	lw	$2,%call16(free)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,free
1:	jalr	$25
	nop

	lw	$28,16($fp)
	lw	$2,52($fp)
	move	$4,$2
	lw	$2,%got(resetBuffer)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,resetBuffer
1:	jalr	$25
	nop

	lw	$28,16($fp)
	lw	$2,52($fp)
	lw	$3,72($fp)
	addiu	$3,$3,-1
	lw	$7,28($fp)
	move	$6,$3
	li	$5,1			# 0x1
	move	$4,$2
	lw	$2,%call16(fread)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,fread
1:	jalr	$25
	nop

	lw	$28,16($fp)
	sw	$2,68($fp)
$L18:
	lw	$4,28($fp)
	lw	$2,%call16(feof)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,feof
1:	jalr	$25
	nop

	lw	$28,16($fp)
	beq	$2,$0,$L26
	nop

	lw	$2,68($fp)
	bne	$2,$0,$L26
	nop

	b	$L23
	nop

$L28:
	nop
$L23:
	move	$2,$0
$L25:
	lw	$sp,76($fp)
$L27:
	move	$sp,$fp
	lw	$31,116($sp)
	lw	$fp,112($sp)
	lw	$23,108($sp)
	lw	$22,104($sp)
	lw	$21,100($sp)
	lw	$20,96($sp)
	lw	$19,92($sp)
	lw	$18,88($sp)
	lw	$17,84($sp)
	lw	$16,80($sp)
	addiu	$sp,$sp,120
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.rdata
	.align	2
$LC15:
	.ascii	"Usage:\012\011tp0 -h\012\011tp0 -V\012\011tp0 [options]\012"
	.ascii	"\000"
	.align	2
$LC16:
	.ascii	"Options:\012\011-V, --version \011Print version and quit"
	.ascii	".\012\011-h, --help\011Print this information.\012\011-o"
	.ascii	", --output \011Path to output file.\012\011-i, --input\011"
	.ascii	"Path to input file.\012\011-d, --decode \011Decode a bas"
	.ascii	"e64-encoded file.\012\000"
	.align	2
$LC17:
	.ascii	"Examples: \012\011tp0 -i input.txt -o output.txt\012\000"
	.text
	.align	2
	.globl	printHelp
	.set	nomips16
	.set	nomicromips
	.ent	printHelp
	.type	printHelp, @function
printHelp:
	.frame	$fp,32,$31		# vars= 0, regs= 2/0, args= 16, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$25
	.set	nomacro
	addiu	$sp,$sp,-32
	sw	$31,28($sp)
	sw	$fp,24($sp)
	move	$fp,$sp
	.cprestore	16
	lw	$2,%got(stdout)($28)
	lw	$2,0($2)
	move	$7,$2
	li	$6,38			# 0x26
	li	$5,1			# 0x1
	lw	$2,%got($LC15)($28)
	addiu	$4,$2,%lo($LC15)
	lw	$2,%call16(fwrite)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,fwrite
1:	jalr	$25
	nop

	lw	$28,16($fp)
	lw	$2,%got(stdout)($28)
	lw	$2,0($2)
	move	$7,$2
	li	$6,199			# 0xc7
	li	$5,1			# 0x1
	lw	$2,%got($LC16)($28)
	addiu	$4,$2,%lo($LC16)
	lw	$2,%call16(fwrite)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,fwrite
1:	jalr	$25
	nop

	lw	$28,16($fp)
	lw	$2,%got(stdout)($28)
	lw	$2,0($2)
	move	$7,$2
	li	$6,43			# 0x2b
	li	$5,1			# 0x1
	lw	$2,%got($LC17)($28)
	addiu	$4,$2,%lo($LC17)
	lw	$2,%call16(fwrite)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,fwrite
1:	jalr	$25
	nop

	lw	$28,16($fp)
	nop
	move	$sp,$fp
	lw	$31,28($sp)
	lw	$fp,24($sp)
	addiu	$sp,$sp,32
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	printHelp
	.size	printHelp, .-printHelp
	.rdata
	.align	2
$LC18:
	.ascii	"Error: El caracter %c no se encuentra en base 64\012\000"
	.text
	.align	2
	.globl	combineBytes
	.set	nomips16
	.set	nomicromips
	.ent	combineBytes
	.type	combineBytes, @function
combineBytes:
	.frame	$fp,56,$31		# vars= 24, regs= 2/0, args= 16, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$25
	.set	nomacro
	addiu	$sp,$sp,-56
	sw	$31,52($sp)
	sw	$fp,48($sp)
	move	$fp,$sp
	.cprestore	16
	sw	$4,56($fp)
	sw	$5,60($fp)
	move	$2,$6
	sb	$2,64($fp)
	sw	$0,24($fp)
	li	$2,24			# 0x18
	sw	$2,32($fp)
	lbu	$2,64($fp)
	beq	$2,$0,$L31
	nop

	li	$2,8			# 0x8
	b	$L32
	nop

$L31:
	li	$2,6			# 0x6
$L32:
	sw	$2,36($fp)
	sw	$0,28($fp)
	b	$L33
	nop

$L38:
	lw	$2,28($fp)
	addiu	$3,$2,1
	lw	$2,36($fp)
	mul	$2,$3,$2
	lw	$3,32($fp)
	subu	$2,$3,$2
	sw	$2,40($fp)
	lbu	$2,64($fp)
	beq	$2,$0,$L34
	nop

	lw	$2,28($fp)
	lw	$3,56($fp)
	addu	$2,$3,$2
	lb	$2,0($2)
	b	$L35
	nop

$L34:
	lw	$2,28($fp)
	lw	$3,56($fp)
	addu	$2,$3,$2
	lb	$2,0($2)
	move	$4,$2
	lw	$2,%got(findPosition)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,findPosition
1:	jalr	$25
	nop

	lw	$28,16($fp)
$L35:
	sw	$2,44($fp)
	lw	$2,44($fp)
	bgez	$2,$L36
	nop

	lw	$2,%got(stderr)($28)
	lw	$4,0($2)
	lw	$2,28($fp)
	lw	$3,56($fp)
	addu	$2,$3,$2
	lb	$2,0($2)
	move	$6,$2
	lw	$2,%got($LC18)($28)
	addiu	$5,$2,%lo($LC18)
	lw	$2,%call16(fprintf)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,fprintf
1:	jalr	$25
	nop

	lw	$28,16($fp)
	li	$2,-1			# 0xffffffffffffffff
	b	$L37
	nop

$L36:
	lw	$3,44($fp)
	lw	$2,40($fp)
	sll	$2,$3,$2
	lw	$3,24($fp)
	or	$2,$3,$2
	sw	$2,24($fp)
	lw	$2,28($fp)
	addiu	$2,$2,1
	sw	$2,28($fp)
$L33:
	lw	$3,28($fp)
	lw	$2,60($fp)
	sltu	$2,$3,$2
	bne	$2,$0,$L38
	nop

	lw	$2,24($fp)
$L37:
	move	$sp,$fp
	lw	$31,52($sp)
	lw	$fp,48($sp)
	addiu	$sp,$sp,56
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	combineBytes
	.size	combineBytes, .-combineBytes
	.align	2
	.globl	codification
	.set	nomips16
	.set	nomicromips
	.ent	codification
	.type	codification, @function
codification:
	.frame	$fp,72,$31		# vars= 40, regs= 2/0, args= 16, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$25
	.set	nomacro
	addiu	$sp,$sp,-72
	sw	$31,68($sp)
	sw	$fp,64($sp)
	move	$fp,$sp
	.cprestore	16
	sw	$4,72($fp)
	sw	$5,76($fp)
	li	$2,8			# 0x8
	sw	$2,44($fp)
	li	$2,14			# 0xe
	sw	$2,48($fp)
	li	$2,20			# 0x14
	sw	$2,52($fp)
	li	$2,26			# 0x1a
	sw	$2,56($fp)
	li	$2,26			# 0x1a
	sw	$2,32($fp)
	li	$4,5			# 0x5
	lw	$2,%call16(malloc)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,malloc
1:	jalr	$25
	nop

	lw	$28,16($fp)
	sw	$2,36($fp)
	lw	$2,36($fp)
	li	$3,61			# 0x3d
	sb	$3,0($2)
	lw	$2,36($fp)
	addiu	$2,$2,1
	li	$3,61			# 0x3d
	sb	$3,0($2)
	lw	$2,36($fp)
	addiu	$2,$2,2
	li	$3,61			# 0x3d
	sb	$3,0($2)
	lw	$2,36($fp)
	addiu	$2,$2,3
	li	$3,61			# 0x3d
	sb	$3,0($2)
	lw	$2,36($fp)
	addiu	$2,$2,4
	sb	$0,0($2)
	sw	$0,24($fp)
	sw	$0,28($fp)
	b	$L40
	nop

$L41:
	lw	$2,72($fp)
	sw	$2,40($fp)
	lw	$2,28($fp)
	sll	$2,$2,2
	addiu	$3,$fp,24
	addu	$2,$3,$2
	lw	$2,20($2)
	lw	$3,40($fp)
	sll	$2,$3,$2
	sw	$2,40($fp)
	lw	$3,40($fp)
	lw	$2,32($fp)
	srl	$2,$3,$2
	sw	$2,40($fp)
	lw	$2,24($fp)
	addiu	$3,$2,1
	sw	$3,24($fp)
	lw	$3,36($fp)
	addu	$2,$3,$2
	lw	$3,%got(BASE64)($28)
	lw	$4,0($3)
	lw	$3,40($fp)
	addu	$3,$4,$3
	lb	$3,0($3)
	sb	$3,0($2)
	lw	$2,28($fp)
	addiu	$2,$2,1
	sw	$2,28($fp)
$L40:
	lw	$2,76($fp)
	addiu	$3,$2,1
	lw	$2,28($fp)
	sltu	$2,$2,$3
	bne	$2,$0,$L41
	nop

	lw	$2,36($fp)
	move	$sp,$fp
	lw	$31,68($sp)
	lw	$fp,64($sp)
	addiu	$sp,$sp,72
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	codification
	.size	codification, .-codification
	.align	2
	.globl	decodification
	.set	nomips16
	.set	nomicromips
	.ent	decodification
	.type	decodification, @function
decodification:
	.frame	$fp,64,$31		# vars= 32, regs= 2/0, args= 16, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$25
	.set	nomacro
	addiu	$sp,$sp,-64
	sw	$31,60($sp)
	sw	$fp,56($sp)
	move	$fp,$sp
	.cprestore	16
	sw	$4,64($fp)
	sw	$5,68($fp)
	li	$2,8			# 0x8
	sw	$2,44($fp)
	li	$2,16			# 0x10
	sw	$2,48($fp)
	li	$2,24			# 0x18
	sw	$2,52($fp)
	li	$2,24			# 0x18
	sw	$2,32($fp)
	lw	$4,68($fp)
	lw	$2,%call16(malloc)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,malloc
1:	jalr	$25
	nop

	lw	$28,16($fp)
	sw	$2,36($fp)
	lw	$2,68($fp)
	addiu	$2,$2,-1
	lw	$3,36($fp)
	addu	$2,$3,$2
	sb	$0,0($2)
	sw	$0,24($fp)
	sw	$0,28($fp)
	b	$L44
	nop

$L45:
	lw	$2,64($fp)
	sw	$2,40($fp)
	lw	$2,28($fp)
	sll	$2,$2,2
	addiu	$3,$fp,24
	addu	$2,$3,$2
	lw	$2,20($2)
	lw	$3,40($fp)
	sll	$2,$3,$2
	sw	$2,40($fp)
	lw	$3,40($fp)
	lw	$2,32($fp)
	srl	$2,$3,$2
	sw	$2,40($fp)
	lw	$2,24($fp)
	addiu	$3,$2,1
	sw	$3,24($fp)
	lw	$3,36($fp)
	addu	$2,$3,$2
	lw	$3,40($fp)
	seb	$3,$3
	sb	$3,0($2)
	lw	$2,28($fp)
	addiu	$2,$2,1
	sw	$2,28($fp)
$L44:
	lw	$2,68($fp)
	addiu	$3,$2,-1
	lw	$2,28($fp)
	sltu	$2,$2,$3
	bne	$2,$0,$L45
	nop

	lw	$2,36($fp)
	move	$sp,$fp
	lw	$31,60($sp)
	lw	$fp,56($sp)
	addiu	$sp,$sp,64
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	decodification
	.size	decodification, .-decodification
	.align	2
	.globl	findPosition
	.set	nomips16
	.set	nomicromips
	.ent	findPosition
	.type	findPosition, @function
findPosition:
	.frame	$fp,40,$31		# vars= 8, regs= 2/0, args= 16, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$25
	.set	nomacro
	addiu	$sp,$sp,-40
	sw	$31,36($sp)
	sw	$fp,32($sp)
	move	$fp,$sp
	.cprestore	16
	move	$2,$4
	sb	$2,40($fp)
	sw	$0,24($fp)
	b	$L48
	nop

$L51:
	lw	$2,%got(BASE64)($28)
	lw	$3,0($2)
	lw	$2,24($fp)
	addu	$2,$3,$2
	lb	$2,0($2)
	lb	$3,40($fp)
	bne	$3,$2,$L49
	nop

	lw	$2,24($fp)
	b	$L50
	nop

$L49:
	lw	$2,24($fp)
	addiu	$2,$2,1
	sw	$2,24($fp)
$L48:
	lw	$2,%got(BASE64)($28)
	lw	$2,0($2)
	move	$4,$2
	lw	$2,%call16(strlen)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,strlen
1:	jalr	$25
	nop

	lw	$28,16($fp)
	move	$3,$2
	lw	$2,24($fp)
	sltu	$2,$2,$3
	bne	$2,$0,$L51
	nop

	li	$2,-1			# 0xffffffffffffffff
$L50:
	move	$sp,$fp
	lw	$31,36($sp)
	lw	$fp,32($sp)
	addiu	$sp,$sp,40
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	findPosition
	.size	findPosition, .-findPosition
	.align	2
	.globl	removeCharacter
	.set	nomips16
	.set	nomicromips
	.ent	removeCharacter
	.type	removeCharacter, @function
removeCharacter:
	.frame	$fp,40,$31		# vars= 8, regs= 2/0, args= 16, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$25
	.set	nomacro
	addiu	$sp,$sp,-40
	sw	$31,36($sp)
	sw	$fp,32($sp)
	move	$fp,$sp
	.cprestore	16
	sw	$4,40($fp)
	move	$2,$5
	sw	$6,48($fp)
	sb	$2,44($fp)
	sw	$0,24($fp)
	b	$L53
	nop

$L55:
	lw	$3,40($fp)
	lw	$2,24($fp)
	addu	$2,$3,$2
	lb	$2,0($2)
	lb	$3,44($fp)
	bne	$3,$2,$L54
	nop

	lw	$2,48($fp)
	lw	$2,0($2)
	addiu	$3,$2,-1
	lw	$2,48($fp)
	sw	$3,0($2)
$L54:
	lw	$2,24($fp)
	addiu	$2,$2,1
	sw	$2,24($fp)
$L53:
	lw	$4,40($fp)
	lw	$2,%call16(strlen)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,strlen
1:	jalr	$25
	nop

	lw	$28,16($fp)
	move	$3,$2
	lw	$2,24($fp)
	sltu	$2,$2,$3
	bne	$2,$0,$L55
	nop

	nop
	move	$sp,$fp
	lw	$31,36($sp)
	lw	$fp,32($sp)
	addiu	$sp,$sp,40
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	removeCharacter
	.size	removeCharacter, .-removeCharacter
	.align	2
	.globl	resetBuffer
	.set	nomips16
	.set	nomicromips
	.ent	resetBuffer
	.type	resetBuffer, @function
resetBuffer:
	.frame	$fp,24,$31		# vars= 8, regs= 1/0, args= 0, gp= 8
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-24
	sw	$fp,20($sp)
	move	$fp,$sp
	sw	$4,24($fp)
	sw	$0,8($fp)
	b	$L57
	nop

$L58:
	lw	$2,8($fp)
	addiu	$3,$2,1
	sw	$3,8($fp)
	lw	$3,24($fp)
	addu	$2,$3,$2
	sb	$0,0($2)
$L57:
	lw	$3,24($fp)
	lw	$2,8($fp)
	addu	$2,$3,$2
	lb	$2,0($2)
	bne	$2,$0,$L58
	nop

	nop
	move	$sp,$fp
	lw	$fp,20($sp)
	addiu	$sp,$sp,24
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	resetBuffer
	.size	resetBuffer, .-resetBuffer
	.ident	"GCC: (Debian 6.3.0-18+deb9u1) 6.3.0 20170516"
