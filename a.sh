#!/bin/bash

echo "========= TESTS PUSH_SWAP ========="
echo

### PRUEBA 1: Stack ordenado ###
echo "Test 1: Stack ya ordenado (no debe imprimir nada)"
ARG="1 2 3 4 5"
RES=$(./push_swap $ARG)
if [ -z "$RES" ]; then
  echo "OK (sin salida)"
else
  echo "KO (debería estar vacío)"
fi
echo

### PRUEBA 2: Stack ya ordenado + checker ###
echo "Test 2: Ordenado con checker"
./push_swap $ARG | ./checker_linux $ARG
echo

### PRUEBA 3: Repetidos ###
echo "Test 3: Repetidos (debe dar Error)"
./push_swap 1 2 3 3 4
echo

### PRUEBA 4: Argumento no numérico ###
echo "Test 4: Argumento no numérico (debe dar Error)"
./push_swap 1 2 hola 3
echo

### PRUEBA 5: Argumento fuera de rango (int) ###
echo "Test 5: Número demasiado grande (debe dar Error)"
./push_swap 1 2147483648 2
echo

### PRUEBA 6: Argumento vacío ###
echo "Test 6: Argumento vacío (debe dar Error)"
./push_swap ""
echo

### PRUEBA 7: Sin argumentos ###
echo "Test 7: Sin argumentos (no debe imprimir nada)"
./push_swap
echo

### PRUEBA 8: 100 números ###
echo -e "\nTest 8: 100 números aleatorios (debe dar < 700 operaciones y OK)"
ARG=$(seq 1 100 | shuf | tr '\n' ' ')
NUM=$(./push_swap $ARG | wc -l)
echo "Instrucciones: $NUM"
./push_swap $ARG | ./checker_linux $ARG
echo

### PRUEBA 9: 500 números ###
echo -e "Test 9: 500 números aleatorios (debe dar < 5500 operaciones y OK)"
ARG=$(seq 1 500 | shuf | tr '\n' ' ')
NUM=$(./push_swap $ARG | wc -l)
echo "Instrucciones: $NUM"
./push_swap $ARG | ./checker_linux $ARG
echo
