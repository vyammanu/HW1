#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * input :  integer 
 * returns :  true if the given input integer is a prime 
 *            false if the given input integer is not a prime
*/
bool is_prime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

/**
 * Returns the nearest prime number below the given number.
 * It only checks odd numbers as even numbers are not prime (except 2).
 * 
 * @param num The number from which to start searching.
 * @return The nearest prime number below 'num'.
 */
int nearest_prime_below(int num) {
    if (num <= 2) {
        return 2;
    }
    if (num % 2 == 0) {
        num--;
    }
    for (int i = num; i > 2; i -= 2) {
        if (is_prime(i)) {
            return i;
        }
    }
    return 2;
}

/**
 * input : integer  num
 * returns : true if the given input integer is a power of 2
 *           false if the given input integer is not a power of 2
*/
bool is_power_of_two(int num) {
    return (num && !(num & (num - 1)));
}


/**
 * input :  integer num
 * output : return the sum of digits of the given number num
*/
int sum_of_digits(int num) {
    int ans = 0;
    while (num > 0 ) {
        ans += num % 10;
        num /= 10;
    }
    return ans;
}


/**
 * Transforms the number based on various conditions.
 * Optimizes the checks for prime numbers and powers of two.
 * 
 * @param n The number to transform.
 * @return A string representing the transformation result.
 */
const char* numberTransformer(int n) {
    if (is_prime(n) && n != 3 && n != 5) {
        return "Go Blazers";
    }
    if (is_power_of_two(n)) {
        int result = n + nearest_prime_below(n);
        static char buffer[20];
        sprintf(buffer, "%d", result);
        return buffer;
    }
    if (n % 3 == 0 && n % 5 == 0) {
        return "UAB CS 332&532";
    }
    if (sum_of_digits(n) % 3 == 0) {
        return "CS";
    }
   
    int sum = sum_of_digits(n);
    static char buffer[20];
    sprintf(buffer, "%d", sum * sum);
    return buffer;
}

int sum_of_divisors(int num) {
    int sum = 1; // 1 is always a divisor
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum;
}

/**
 * param :  null
 * returns : true if the value of the number taken as input is equal to the sum of its
             positive divisors
*/
bool UABNumber() {
    int n2;
    printf("UABNumber :: Enter an integer: ");
    scanf("%d", &n2);
    
    if (n2 < 0) {
        printf("Please enter a non-negative integer.\n");
        return false;
    }

    return sum_of_divisors(n2) == n2;
}

/**
 * param :  integer n3
* returns : an integer that is reversed order of the digits of given parameter
*/
int reverseNum(int n3) {
    int reversed = 0;
    while (n3) {
        reversed = reversed * 10 + n3 % 10;
        n3 /= 10;
    }
    return reversed;
}
/**
 * param: integer pointer *arr pointing to the start of an array
 * returns: an integer representing the count of numbers in the array 
 *          whose value is smaller than their respective indices.
 */
int smallerThanIndex(int *arr) {
    int n = 5;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (*(arr + i) < i) {
            ans++;
        }
    }
    return ans;
}

/**
 * param: integer pointer *arr pointing to the start of an array
 * param: integer n representing the number of elements in the array
 * returns: void (prints an array containing the number of elements, minimum value, 
 *          minimum value's index, mean, maximum value, and maximum value's index)
 */

void arrayDetails(int arr[6]) {
    int min = arr[0], max = arr[0];
    int minIndex = 0, maxIndex = 0;
    int sum = 0;

    // Iterate through the array to find min, max, and sum
    for (int i = 0; i < 6; ++i) {
        sum += arr[i];

        if (arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }

        if (arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
    }

    double mean = (double) (sum * 1.00000) / 6;

    // Print the results
    printf("Result: [%d, %d, %d, %d, %d]\n", min, minIndex, sum, max, maxIndex);
}

int main() {
  while (true) {
    int choice;
    printf("Select the function to execute:\n");
    printf("1. Number Transformer\n");
    printf("2. UAB Number\n");
    printf("3. Reverse Number\n");
    printf("4. Smaller Than Index\n");
    printf("5. Array Details\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int n;
                printf("Enter a positive integer: ");
                scanf("%d", &n);
                printf("Result: %s\n", numberTransformer(n));
                break;
            }
            case 2: {
                if (UABNumber()) {
                    printf("True\n");
                } else {
                    printf("False\n");
                }
                break;
            }
            case 3: {
                int n3;
                printf("Enter a number to reverse: ");
                scanf("%d", &n3);
                printf("Reversed Number: %d\n", reverseNum(n3));
                break;
            }
            case 4: {
                int n = 5;
                int arr[n];
                printf("Enter %d integers:\n", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                printf("Count Smaller Than Index: %d\n", smallerThanIndex(arr));
                break;
            }
            case 5: {
                int n =6;
                int arr[n];
                printf("Enter %d integers:\n", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                arrayDetails(arr);
                break;
            }
            default: {
                printf("Invalid choice.\n");
                return 0;
            }
        }
    }
    return 0;
}

