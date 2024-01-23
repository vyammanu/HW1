# C Program: Number Transformer and Utilities

This C program provides various functionalities including checking if a number is a prime, if it is a power of two, finding the nearest prime number below a given number, reversing a number, and others. The program includes a menu-driven interface to access these functionalities.

## Compilation

To compile this program, you need a C compiler like GCC. You can compile the source file using the following command:

gcc -o number_utility your_source_file.c -lm

Replace `your_source_file.c` with the name of your C source file. The `-lm` flag is used to link the math library which is required for math functions used in the program.

## Running the Executable

After successful compilation, an executable file named `number_utility` will be created. You can run this executable using the following command in the terminal:

./number_utility

## Usage

Once you run the program, you will be presented with a menu of options:

1. **Number Transformer**: Enter a positive integer to receive a transformed number based on specific criteria.
2. **UAB Number**: Check if the entered integer is equal to the sum of its positive divisors.
3. **Reverse Number**: Reverse the digits of the entered number.
4. **Smaller Than Index**: For an array of integers, count how many numbers are smaller than their respective indices.
5. **Array Details**: Enter an array to receive various details like min, max, mean, etc.

Choose the appropriate option by entering the corresponding number and follow the on-screen instructions.

## Exiting the Program

To exit the program, enter an invalid choice (not between 1 and 5) when prompted to select a function.
