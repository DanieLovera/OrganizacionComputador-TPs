# Salto incondicional a la instruccion 4 del programa.
# Se repitio la prueba realizada para el cpu unicycle para obtener el mismo resultado
# Por alguna extraña razon salta una instruccion mas alla de la indicada por el registro
# En este caso deberia saltar a la misma linea del jr $t0 pero lo hace en la linea del addi $t2, $zero, 12
# Parece tener logica si pensamos que el registro $t0 guarda la direccion del salto al que debe volver una
# instruccion pero en la implementacion no se esperaba este comportamiento.
addi $t0, $zero, 3
addi $t1, $zero, 8
jr $t0
addi $t2, $zero, 12  	# Linea del salto jr $t0
addi $t3, $zero, 16
addi $t4, $zero, 20		# Linea del salto jr $t2
add $t5, $t0, $zero 

# Salto incondicional a la instruccion indicada por la suma de dos registros.
# En este caso se prueba que no ocurran riesgos de datos ya que la el registro $t2 es utilizado por 
# la instruccion de salto, en este caso el pipeline ya tiene implementado una unidad de fordwarding
# por lo cual la instruccion se ejecuta correctamente y luego del salto a 5 posiciones + 1 se ejecuta
# la linea addi $t4, $zero, 20 del programa.
addi $t0, $zero, 4
addi $t1, $zero, 1
add $t2, $t0, $t1
jr $t2
addi $t2, $zero, 12
addi $t3, $zero, 16
addi $t4, $zero, 20
add $t5, $t0, $zero 

