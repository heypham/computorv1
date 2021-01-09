/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polynomial.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:05:05 by emiliepham        #+#    #+#             */
/*   Updated: 2021/01/09 13:55:56 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polynomial.hpp"

double sqrt(double delta)
{
    return (delta);
}

void Polynomial::setDeterminant()
{
    // delta = x1**2 - 4*x2*x0;
}

/*
*** Parse polynomial factors from regex string matches
*/

// int Polynomial::parseFactors(smatch match, double lr)
// {
//     double a;
//     int b;

//     a = 0.0;
//     b = 0;
//     return 0;
// }

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