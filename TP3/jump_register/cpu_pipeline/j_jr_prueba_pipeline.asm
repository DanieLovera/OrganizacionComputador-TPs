# Salto incondicional a la instruccion 4 del programa.
addi $t0, $zero, 12
addi $t1, $zero, 8
jr $t0
addi $t2, $zero, 12  	# Linea del salto jr $t0
addi $t3, $zero, 16
addi $t4, $zero, 20		# Linea del salto jr $t2
add $t5, $t0, $zero

# Salto incondicional a la instruccion indicada por la suma de dos registros.
# No ocurre riesgos de datos porque ya venia implementada la unidad de fordwarding
# no hacia falta resolver nada
addi $t0, $zero, 16
addi $t1, $zero, 4
add $t2, $t0, $t1
jr $t2
