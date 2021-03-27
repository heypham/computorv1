# Computorv1 

The purpose of this project is to write a program that solves simple polynomial equations.
The program takes a polynomial equation up to degree 2.

## How to  
- Build the project:  
`make`

- Run the project:  
`./computor [equation]`  
e.g. `./computor "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"`  
The program should print  
    - The reduced form of the equation
    - Its degree
    - Its solution(s) (real and complex) and the polarity of the discriminant if it makes sense.

## Bonuses  
- You don't need to give the equation in quotes, you can also give the equation as many arguments. You'll just have to escape the multiplication signs `./computor 5 \* X^0 + 4 \* X^1 - 9.3 \* X^2 = 1 \* X^0`
- For simplicity, instead of writing factors as `a * X^b`, you can write `ax^b`
- Verbose flag for the details of equation solver
- Errors are managed. If input is not as expected specific error is yielded
