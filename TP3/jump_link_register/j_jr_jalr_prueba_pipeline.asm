# Salto incondicional a la instruccion 9 del programa y enlace de la vuelta al $ra
# Misma prueba que en unicycle, se mantiene el resultado.
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

# Salto indoncidicional y ejecucion de una instruccion dependiente del $ra
# Esto no tiene mucho sentido en realidad pero para probar no hay riesgos
# por dependencias, el salto de retorno se calcula bien porque cuando se 
# decide la direccion del salto jalr $t0 (en MEM) se actualiza el PC, y se busca
# la instruccion jr que es la correcta, en ese momento ya jalr esta en etapa WB
# en el siguiente ciclo de reloj se habra actualizado en directorio de registros y
# tendra el $ra correcto y entra en un bucle siempre saltando sobre si mismo.
addi $t0, $zero, 80
addi $t1, $zero, 8
jalr $t0
jr $ra
