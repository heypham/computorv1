/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:04:15 by epham             #+#    #+#             */
/*   Updated: 2021/01/10 16:46:34 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.hpp"

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

void Computor::display()
{    
    cout << "Reduced form       : " << reducedEq.x2 << " * x^2 + " << reducedEq.x1 << " * x^1 + " << reducedEq.x0 << " * x^0 = 0\n";
    cout << "Polynomial degree  : " << reducedEq.degree << endl;
    // cout << "Discriminant value : " << reducedEq.delta << endl;
    if (reducedEq.delta > 0.0 && reducedEq.degree > 1)
        cout << "Discriminant is strictly positive, the two solutions are:" << endl;
    else if (reducedEq.delta == 0.0 || reducedEq.degree == 1)
        cout << "The solution is:" << endl;
    else if (reducedEq.delta == 0.0 && reducedEq.degree == 0)
        cout << "Every number x in the set of real numbers ℝ is a solution. " << endl;
    else
        cout << "Discriminant is strictly negative, the two complex solutions are:" << endl;
}

/*
*** Computor solver
*/

int Computor::solve()
{
    if (reducedEq.delta > 0.0 && reducedEq.degree > 1)
    {
        reducedEq.solveEquation();
        cout << reducedEq.sol1 << endl << reducedEq.sol2 << endl;
    }
    else if (reducedEq.delta == 0.0 || reducedEq.degree == 1)
    {
        reducedEq.solveEquation();
        cout << reducedEq.sol1 << endl;
    }
    else if (reducedEq.delta < 0)
    {
        reducedEq.solveEquation();
        cout << reducedEq.sol1 << " + (" << reducedEq.sol2 << ") i" << endl;
    }
    return 0;
}