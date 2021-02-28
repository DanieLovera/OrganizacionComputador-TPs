#Salto incondicional de mas de tres instrucciones no debe ejecutar las instrucciones posteriores al salto
addi $t0, $zero, 5
j test_1
addi $t1, $zero, 10		#NO SE DEBE EJECUTAR
and $t2, $t1, $t0		#NO SE DEBE EJECUTAR
add $t3, $t1, $t0		#NO SE DEBE EJECUTAR
add $t4, $t3, $t1		#NO SE DEBE EJECUTAR
test_1:
	addi $t5, $zero, 55	

#Salto incondicional de menos de tres instrucciones no debe ejecutar las instrucciones posteriores al salto
addi $t0, $zero, 77
j test_2
addi $t1, $zero, 10		#NO SE DEBE EJECUTAR
test_2:
	add $t2, $t0, $t0
	add $t3, $t2, $t0
	addi $t4, $zero, 101	