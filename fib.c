// Name: Dominic Wrtaza
// Date: 9/20/2024
// File Purpose: To perfrom the Fibonacci sequence
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000  


unsigned long int fib_i_core(unsigned long int n);
unsigned long int fib_r_core(unsigned long int n);

unsigned long int memo[MAX_SIZE];

void init_memo() {
   for (unsigned long int i = 0; i < MAX_SIZE; i++) {
    memo[i] = 0;  
   }
}


unsigned long int fibonacci_iterative(unsigned long int n) {
    if (memo[n] != 0) {
      return memo[n];
    }
   unsigned long int result = fib_i_core(n);
   memo[n] = result;
   return result;
}


unsigned long int fibonacci_recursive(unsigned long int n) {
   if (memo[n] != 0) {
      return memo[n];
   }
   unsigned long int result = fib_r_core(n);
   memo[n] = result;
   return result;
}


unsigned long int fib_i_core(unsigned long int n) {
   if (n <= 1) {
      return n;
   }
   unsigned long int a = 0, b = 1, temp;
   for (unsigned long int i = 2; i <= n; i++) {
      temp = a + b;
      a = b;
      b = temp;
   }
   return b;
}


unsigned long int fib_r_core(unsigned long int n) {
    if (n <= 1) {
      return n;
    }
    return fib_r_core(n - 1) + fib_r_core(n - 2);
}
int main(int argc, char *argv[]) {
 

   unsigned long int first_num = atoi(argv[1]);
   unsigned long int num_sum = first_num -1;


   init_memo();

   unsigned long int result;
   if (argv[2][0] == 'r') {
      result = fibonacci_recursive(num_sum);
   } else if (argv[2][0] == 'i') {
      result = fibonacci_iterative(num_sum);
   }

   printf("%ld\n", result);

   return 0;
}