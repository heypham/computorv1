/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polynomial.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:05:05 by emiliepham        #+#    #+#             */
/*   Updated: 2021/01/10 16:45:14 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polynomial.hpp"

/*
*** Calculate square root of determinant using
*** Logarithmic approx then babylonian method
*/

float sqrt(float delta)
{
    union
    {
        int i;
        float x;
    } u;
    u.x = delta;
    // cout << "u.x " << u.x << " | u.i " << u.i << endl;
    u.i = (1 << 29) + (u.i >> 1) - (1 << 22);
    // cout << "u.x " << u.x << " | u.i " << u.i << endl;
    u.x = 0.5 * (u.x + delta/u.x);
    u.x = 0.5 * (u.x + delta/u.x);
    u.x = 0.5 * (u.x + delta/u.x);
    // cout << "u.x " << u.x << " | u.i " << u.i << endl;
    return (u.x);
}

/*
*** Solve equation
*/

void Polynomial::solveEquation()
{
    if (x2 == 0 && x1 > 0)
        sol1 = -x0 / x1;
    else if (delta > 0.0)
    {
        sqrt_delta = sqrt(delta);
        sol1 = (- x1 + sqrt_delta) / (2 * x2);
        sol2 = (- x1 - sqrt_delta) / (2 * x2);
    }
    else if (delta == 0.0)
        sol1 = -x1 / (2 * x2);
    else if (delta < 0.0)
    {
        sqrt_delta = sqrt(-delta);
        sol1 = -x1 / (2 * x2);
        sol2 = sqrt_delta / (2 * x2);
    }
}

/*
*** Calculate delta value from factors parsed in regex string
*/

void Polynomial::calculateDiscriminant()
{
    // cout << "b^2 - 4ac : " << x1 << "**2 - 4 * " << x2 << "*" << x0 << endl;
    delta = x1*x1 - 4*x2*x0;
}

/*
*** Parse polynomial factors from regex string matches
*/

int Polynomial::parseFactors(smatch match)
{
    float a;
    int b;

    a = 0.0;
    b = 0;

    // for (unsigned i=1; i<match.size(); ++i)
    // {
    //     cout << "[" << match[i] << "] ";
    // }
    if (match[1] != "")
    {
        a = stod(match[2]);
        b = match[5] != "" ? stoi(match[5]) : 1;
    }
    else if (match[7] != "")
    {
        a = stod(match[7]);
    }
    else if (match[8] != "")
    {
        a = match[9] == '-' ? -1.0 : 1;
        b = match[12] != "" ? stoi(match[12]) : 1;
    }
    switch (b)
    {
    case 2:
        x2 += a;
        break;
    case 1:
        x1 += a;
        break;
    case 0:
        x0 += a;
        break;
    }
    degree = degree > b ? degree : b;
    return 0;
}

/*
*** Polynomial Constructor
*/

Polynomial::Polynomial()
{
    x2 = 0.0;
    x1 = 0.0;
    x0 = 0.0;
    delta = 0.0;
    str = "";
}
