/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polynomial.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiliepham <emiliepham@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:05:05 by emiliepham        #+#    #+#             */
/*   Updated: 2021/01/22 21:55:04 by emiliepham       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polynomial.hpp"

/*
*** Calculate square root of determinant using
*** Logarithmic approx then babylonian method
*** https://en.wikipedia.org/wiki/Methods_of_computing_square_roots
*/

float _sqrt(float delta)
{
    union
    {
        int i;
        float x;
    } u;
    u.x = delta;
    u.i = (1 << 29) + (u.i >> 1) - (1 << 22);
    u.x = 0.5 * (u.x + delta/u.x);
    u.x = 0.5 * (u.x + delta/u.x);
    u.x = 0.5 * (u.x + delta/u.x);
    return (u.x);
}

/*
*** Solve equation
*/

void Polynomial::solveEquation()
{
    if (degree == 1)
        sol1 = -x0 / x1;
    else if (delta > 0.0)
    {
        sqrt_delta = _sqrt(delta);
        sol1 = (- x1 + sqrt_delta) / (2 * x2);
        sol2 = (- x1 - sqrt_delta) / (2 * x2);
    }
    else if (delta == 0.0)
        sol1 = -x1 / (2 * x2);
    else if (delta < 0.0)
    {
        sqrt_delta = _sqrt(-delta);
        sol1 = -x1 / (2 * x2);
        sol2 = sqrt_delta / (2 * x2);
    }
}

/*
*** Calculate delta value from factors parsed in regex string
*/

void Polynomial::calculateDiscriminant()
{
    delta = x1*x1 - 4*x2*x0;
}

/*
*** Verify positive coefficients have a + sign if not first of expression except if first coefficient found
*/

int Polynomial::verifyCoef(float a, string s)
{
    if ((a > 0.0 && (s.length() > 0 && s[0] != '+')) || (s == "" && a == 1.0))
    {
        if (x2 == 0.0 && x1 == 0.0 && x0 == 0.0)
            return 0;
        return -1;
    }
    return 0;
}

/*
*** Parse polynomial factors from regex string matches
*** match[1]. term in form ax^b or a*x^b
*** match[2]. coefficient a of term 1.
*** match[3]. means found X value (x or x^b)
*** match[4]. means 3. is a x powered value (x^b)
*** match[5]. power value b of 4.
*** match[6]. means 3. is a X single value (= ax^1)
*** match[7]. single number value a (= a * x^0)
*** match[8]. ax^b where a = +-1
*** match[9]. sign of a (+-)
*** match[10]. -
*** match[11]. power b of 8 exists (if this group is empty then format +-x)
*** match[12]. value of b power
*/

int Polynomial::parseFactors(smatch match)
{
    float a;
    int b;
    int ret;

    a = 0.0;
    b = 0;
    ret = 0;
    if (match[1] != "")
    {
        a = stod(match[2]);
        b = match[5] != "" ? stoi(match[5]) : 1;
        ret = verifyCoef(a, match[2]);
    }
    else if (match[7] != "")
    {
        a = stod(match[7]);
        ret = verifyCoef(a, match[7]);
    }
    else if (match[8] != "")
    {
        a = match[9] == "-" ? -1.0 : 1.0;
        b = match[12] != "" ? stoi(match[12]) : 1;
        ret = verifyCoef(a, match[9]);
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
    return ret;
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
    sqrt_delta = 0.0;
    sol1 = 0.0;
    sol2 = 0.0;
    degree = 0;
    str = "";
}
