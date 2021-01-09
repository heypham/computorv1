/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polynomial.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiliepham <emiliepham@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:05:05 by emiliepham        #+#    #+#             */
/*   Updated: 2021/01/09 02:26:38 by emiliepham       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polynomial.hpp"

double sqrt(double delta)
{
    return (0);
}

void Polynomial::setDeterminant()
{
    // delta = x1**2 - 4*x2*x0;
}

/*
*** Polynomial Constructor
*/

Polynomial::Polynomial()
{
    x0 = 0.0;
    x1 = 0.0;
    x2 = 0.0;
    delta = 0.0;
    str = "";
}