# Function clarification

- ```c
  int sumFibonacci(float num);
  ```

  Return the sum of Fibonacci sequence until num.

  1 1 2 3 5 8 ...
  
  4 = 1+1+2+3
  
  1 = 1+1
  
- ```c
  float getXdigit(float num, int n);
  ```

  Return 'n' digits of num.

  e.g. 

  getXdigit(301.14, 2) -->	30
  
  getXdigit(0.14, 2): 	  -->	0.1

# Homework0

It accomplishes by iteratively processing each character in the string and performing arithmetic operations according to the encountered characters.

# example

1+2+3-4

1+2=3

3+3=6

6-4=2



1*2+3

*

+



1+1+2*4

2

+

2

*

4



1*(2+3)

1

*

(

...

)



sinOfDegree(30)

(

sinOfDegree

...

)

# Approach

1. Iterate through the input string: The code goes through each character in the input string one by one.
2. If space or ','
3. If number
4. Handle operators: When it encounters an operator (+, -, *, /) or reaches the end of a number, it performs the operation based on the last operator seen and the number.
5. Handle '()'
6. Use a stack for intermediate results: The code utilizes a stack data structure to store intermediate results as it processes the expression. This allows it to maintain the correct order of operations.
7. Return the final result: After processing all characters in the string and evaluating the expression, the code returns the final result by summing up all the values stored in the stack.