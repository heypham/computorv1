/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiliepham <emiliepham@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:04:15 by epham             #+#    #+#             */
/*   Updated: 2021/01/09 22:46:42 by emiliepham       ###   ########.fr       */
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
    cout << "Reduced form      : " << reducedEq.x2 << " * x^2 + " << reducedEq.x1 << " * x^1 + " << reducedEq.x0 << " * x^0 = 0\n";
    getDegree();
    cout << "Polynomial degree : " << reducedEq.degree << endl;
    reducedEq.calculateDeterminant();
    cout << "Determinant value : " << reducedEq.delta << endl;
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
}

/*
*** Computor solver
*/

int Computor::solver()
{
    return 0;
}