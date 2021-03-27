/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiliepham <emiliepham@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:04:15 by epham             #+#    #+#             */
/*   Updated: 2021/03/27 20:21:56 by emiliepham       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.hpp"

/*
*** Get reduced form from left poly and right poly parsed and compute delta
*/

int Computor::parse()
{
    if (parser.parse() < 0)
        return (-1);
    reducedEq.x2 = parser.leftPoly.x2 - parser.rightPoly.x2;
    reducedEq.x1 = parser.leftPoly.x1 - parser.rightPoly.x1;
    reducedEq.x0 = parser.leftPoly.x0 - parser.rightPoly.x0;
    getDegree();
    reducedEq.calculateDiscriminant();

    return (0);
}

void Computor::getDegree()
{
    if (reducedEq.x2 != 0.0)
        reducedEq.degree = 2;
    else if (reducedEq.x1 != 0.0)
        reducedEq.degree = 1;
    else
        reducedEq.degree = 0;
}

void Computor::displayDetails()
{
    if (reducedEq.delta > 0.0 && reducedEq.degree > 1)
    {
        cout << "√Δ = " << reducedEq.sqrt_delta << endl;
        cout << "x₁ = (-b + √Δ) / 2a" << endl << "x₂ = (-b - √Δ) / 2a" << endl;
        cout << "x₁ = (" << -reducedEq.x1 << " + " << reducedEq.sqrt_delta << ") / 2*" << reducedEq.x2 << endl;
        cout << "x₂ = (" << -reducedEq.x1 << " - " << reducedEq.sqrt_delta << ") / 2*" << reducedEq.x2 << "\n\n";
    }
    else if ((reducedEq.delta == 0.0 && reducedEq.degree > 1) || reducedEq.degree == 1)
        cout << "x = -c / b" << endl;
    else if (reducedEq.delta < 0)
    {
        cout << "√Δ = " << reducedEq.sqrt_delta <<"i" << "\n\n";
        cout << "x₁ = (-b + √Δ) / 2a" << endl << "x₂ = (-b - √Δ) / 2a" << endl;
        cout << "x₁ = (" << -reducedEq.x1 << " + " << reducedEq.sqrt_delta << "i) / 2*" << reducedEq.x2 << endl;
        cout << "x₂ = (" << -reducedEq.x1 << " - " << reducedEq.sqrt_delta << "i) / 2*" << reducedEq.x2 << "\n\n";
    }
}

void Computor::displaySolutions()
{
    if (reducedEq.delta > 0.0 && reducedEq.degree > 1)
        cout << "x₁ = " << reducedEq.sol1 << endl << "x₂ = " << reducedEq.sol2 << endl;
    else if ((reducedEq.delta == 0.0 && reducedEq.degree > 1) || reducedEq.degree == 1)
        cout << "x = " << reducedEq.sol1 << endl;
    else if (reducedEq.delta < 0)
    {
        cout << "x₁ = ("<< reducedEq.sol1 << ") + (" << reducedEq.sol2 << ") * i" << endl;
        cout << "x₂ = ("<< reducedEq.sol1 << ") - (" << reducedEq.sol2 << ") * i" << endl;
    }
}

/*
*** Show output with more or less details depending on flags
*/

void Computor::display()
{
    cout << "Reduced form       : ";
    if (reducedEq.x2 != 0)
        cout << reducedEq.x2 << "x²";
    if (reducedEq.x1 != 0)
    {
        if (reducedEq.degree > 1)
            cout << " + ";
        cout << reducedEq.x1 << "x";
    }
    if (reducedEq.x0 != 0)
    {
        if (reducedEq.degree > 0)
            cout << " + ";
        cout << reducedEq.x0;
    }
    cout << " = 0\nPolynomial degree  : " << reducedEq.degree << endl;
    if (parser.verbose == 1 && reducedEq.degree > 1)
    {
        cout << "\nΔ = b² - 4ac" << endl;
        cout << "Δ = " << reducedEq.x1 << "² - 4 * " << reducedEq.x2 << " * " << reducedEq.x0 << endl;
        cout << "Δ = " << reducedEq.delta << "\n\n";
    }
    if (reducedEq.delta > 0.0 && reducedEq.degree > 1)
        cout << "Discriminant is strictly positive, the two solutions are:" << endl;
    else if (reducedEq.delta == 0.0 && reducedEq.degree == 0 && reducedEq.x0 == 0)
        cout << "Every number x in the set of real numbers ℝ is a solution. " << endl;
    else if ((reducedEq.delta == 0.0 && reducedEq.degree > 1) || reducedEq.degree == 1)
        cout << "The solution is:" << endl;
    else if (reducedEq.delta < 0)
        cout << "Discriminant is strictly negative, the two complex solutions are:" << endl;
    else
        cout << "The equation does not have any solution." << endl;
    if (parser.verbose == 1)
        displayDetails();
    displaySolutions();
}

/*
*** Computor solver calling the equation solver method
*/

void Computor::solve()
{
    reducedEq.solveEquation();
}