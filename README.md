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
- You don't need to write the spaces `5 * X^0` can be `5*X^0`
- Instead of writing factors as `a * X^b`, you can write `ax^b`, e.g. `./computor 5X^0 + 4X^1 - 9.3X^2 = 1X^0`
- You can write inputs in their natural form, e.g. instead of writing `5 * X^0` and `1 * X^1` you can just write respectively `5` and `x`
- Verbose flag for the details of equation solver `-v`
- Errors are managed. If input is not as expected specific error is yielded
