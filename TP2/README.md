## Implementacion de una memoria cache WB/WA con politica de reemplazo LRU


[Informe](https://www.overleaf.com/4586521534gvybxskhsrxh
)

### Casos de pruebas de la cátedra
- Caché 1:
    - 4KB tamaño de caché.
    - 4 vías.
    - 32 bytes tamaño del bloque.
- Caché 2:
    - 16KB tamaño de caché.
    - 1 vías.
    - 128 bytes tamaño del bloque.

#### Prueba 1:
``` 
init
W 0, 255
W 16384, 254
W 32768, 248
W 49152, 096
R 0
R 16384
R 32768
R 49152
MR
```

- En la caché 1:
    - Comando: ``` ./main -cs 4 -w 4 -bs 32 ./pruebas/prueba1.mem ```
    - Salida:
    ```
    Se inicia la caché
    Escribe � en la dirección 0
    Escribe � en la dirección 16384
    Escribe � en la dirección 32768
    Escribe ` en la dirección 49152
    Leo de la dirección 0 y obtengo �
    Leo de la dirección 16384 y obtengo �
    Leo de la dirección 32768 y obtengo �
    Leo de la dirección 49152 y obtengo `
    MR: %50
    ```
- En la caché 2:
    - Comando: ``` ./main -cs 16 -w 1 -bs 128 ./pruebas/prueba1.mem ```
    - Salida:
    ```
    Se inicia la caché
    Escribe � en la dirección 0
    Escribe � en la dirección 16384
    Escribe � en la dirección 32768
    Escribe ` en la dirección 49152
    Leo de la dirección 0 y obtengo �
    Leo de la dirección 16384 y obtengo �
    Leo de la dirección 32768 y obtengo �
    Leo de la dirección 49152 y obtengo `
    MR: %100
    ```

#### Prueba 2:
``` 
init
W 0, 123
W 1024, 234
W 2048, 33
W 3072, 44
W 4096, 55
R 0
R 1024
R 2048
R 3072
R 4096
MR
```

- En la caché 1:
    - Comando: ``` ./main -cs 4 -w 4 -bs 32 ./pruebas/prueba2.mem ```
    - Salida:
    ```
    Se inicia la caché
    Escribe { en la dirección 0
    Escribe � en la dirección 1024
    Escribe ! en la dirección 2048
    Escribe , en la dirección 3072
    Escribe 7 en la dirección 4096
    Leo de la dirección 0 y obtengo {
    Leo de la dirección 1024 y obtengo �
    Leo de la dirección 2048 y obtengo !
    Leo de la dirección 3072 y obtengo ,
    Leo de la dirección 4096 y obtengo 7
    MR: %70
    ```
- En la caché 2:
    - Comando: ``` ./main -cs 16 -w 1 -bs 128 ./pruebas/prueba2.mem ```
    - Salida:
    ```
    Se inicia la caché
    Escribe { en la dirección 0
    Escribe � en la dirección 1024
    Escribe ! en la dirección 2048
    Escribe , en la dirección 3072
    Escribe 7 en la dirección 4096
    Leo de la dirección 0 y obtengo {
    Leo de la dirección 1024 y obtengo �
    Leo de la dirección 2048 y obtengo !
    Leo de la dirección 3072 y obtengo ,
    Leo de la dirección 4096 y obtengo 7
    MR: %50
    ```
