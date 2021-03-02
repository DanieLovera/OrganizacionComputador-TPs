# Salto incondicional a la instruccion 9 del programa.
# El 32 del salto es porque la instrucciones son de [0-n] y como quiero la 
# instruccion 8 se multiplica por 4 y da de resultado la direccion 32 para ese salto.
addi $t0, $zero, 32
addi $t1, $zero, 8
jalr $t0
addi $t2, $zero, 12  	
addi $t3, $zero, 16
addi $t4, $zero, 20		
add $t5, $t0, $zero 
j end

addi $t0, $zero, 4
addi $t1, $zero, 1
add $t2, $t0, $t1
addi $t2, $zero, 12
addi $t3, $zero, 16
addi $t4, $zero, 20
add $t5, $t0, $zero 
jr $ra

end:
	addi $t7, $zero, 50