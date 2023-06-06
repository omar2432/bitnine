#include <stdio.h>


// we can use three different approaches: recursion, iteration loop, and memoization.
// advantages and disadvantages are down below the code

int fibonacciRecursion(int n) {
    if (n <= 2) {
        return n;
    }
    
    return fibonacciRecursion(n - 3) + fibonacciRecursion(n - 2);
}

int fibonacciIteration(int n) {
    if (n <= 2) {
        return n;
    }

    int prev3 = 0; // F(n-3)
    int prev2 = 1; // F(n-2)
    int prev1 = 2; // F(n-1)
    int current = 0; // F(n)

    for (int i = 3; i <= n; i++) {
        current = prev3 + prev2; // F(n) = F(n-3) + F(n-2)
        prev3 = prev2; // Shift values
        prev2 = prev1;
        prev1 = current;
    }

    return current;
}



int fibonacciMemoization(int n, int* memo) {
    if (n <= 2) {
        return n;
    }
    
    if (memo[n] != -1) {
        return memo[n];
    }
    
    memo[n] = fibonacciMemoization(n - 3, memo) + fibonacciMemoization(n - 2, memo);
    return memo[n];
}

int main() {
    int n = 5;

    // intializing the memo for the fibonacciMemoization function
    int memo[100];
    for (int i = 0; i < 100; i++) {
        memo[i] = -1;
    }
    
    int resultMemoization = fibonacciMemoization(n, memo);
    printf("Fibonacci using memoization: %d\n", resultMemoization);
    
    int resultIteration = fibonacciIteration(n);
    printf("Fibonacci using Iteration:  %d\n", resultIteration);

    int resultRecursion = fibonacciRecursion(n);
    printf("Fibonacci using recursion: %d\n", resultRecursion);
    
    return 0;
}

/*

recursion:

Advantages:
- Simple and intuitive implementation based on the mathematical recurrence relation.
- Easy to understand and implement.

Disadvantages:
- Inefficient for large values of n due to repeated function calls and redundant calculations.
- Exponential time complexity, which leads to slower execution as n increases.



Iteration: 

Advantages:
- Efficient in terms of time complexity,
  as it avoids the overhead of function calls by performing calculations in a loop.
  This makes it more efficient than the recursive approach for large values of n.
- Linear time complexity, resulting in faster execution compared to recursion for large values of n.

Disadvantages:
- May be slightly more complex to understand compared to recursion.
- Does not provide the elegance of the mathematical recurrence relation.



Memoization:

Advantages:
- Avoids repeated calculations by storing already computed Fibonacci numbers in an array.
- Efficient time complexity, providing faster execution for large values of n compared to recursion.

Disadvantages:
- Requires additional space to store the memoization array.
- Requires extra code for handling memoization logic.



*/
