Pingala Algorithm (Binary Exponentiation)
This project implements the Pingala Algorithm (commonly known as Fast Exponentiation or Square-and-Multiply) in C.
It utilizes the GNU Multiple Precision Arithmetic Library (GMP) to handle calculations involving arbitrarily large numbers that exceed standard integer limits.

The Pingala algorithm reduces the computational complexity of calculating b^e from O(n) to O(log n).
This recursive implementation follows the "Divide and Conquer" principle, making it highly efficient for cryptographic applications or heavy mathematical computations.

Key Features
Arbitrary Precision: Uses the mpz_t data type from the GMP library to handle massive integers.
Optimized Performance: Implements the binary exponentiation method to minimize the number of multiplications.
Self-Testing: Includes a suite of assert statements to verify the mathematical correctness of the algorithm during execution.

Prerequisites
To compile and run this project, you must have the GMP library installed on your system.

Compile the code: You must link the GMP library using the -lgmp flag: 
gcc main.c -o pingala -lgmp

Input Configuration:
The program reads from a file named date.in. 
Create this file in the root directory with the following format: base exponent.
echo "2 100" > date.in

Run the executable:
./pingala
