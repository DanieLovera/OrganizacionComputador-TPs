# Salto incondicional a la instruccion 4 del programa.
# Por alguna extraña razon salta una instruccion mas alla de la indicada por el registro
# En este caso deberia saltar a la misma linea del jr $t0 pero lo hace en la linea del addi $t2, $zero, 12
# Parece tener logica si pensamos que el registro $t0 guarda la direccion del salto al que debe volver una
# instruccion pero en la implementacion no se esperaba este comportamiento.
addi $t0, $zero, 3
addi $t1, $zero, 8
jr $t0
addi $t2, $zero, 12
addi $t3, $zero, 16
addi $t4, $zero, 20
add $t5, $t0, $zero 