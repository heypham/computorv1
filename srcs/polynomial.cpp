/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polynomial.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiliepham <emiliepham@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:05:05 by emiliepham        #+#    #+#             */
/*   Updated: 2021/01/09 22:45:33 by emiliepham       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polynomial.hpp"

double sqrt(double delta)
{
    return (delta);
}

void Polynomial::calculateDeterminant()
{
    delta = x1*x1 - 4*x2*x0;
}

/*
*** Parse polynomial factors from regex string matches
*/

int Polynomial::parseFactors(smatch match)
{
    double a;
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
