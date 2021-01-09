/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polynomial.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiliepham <emiliepham@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:04:49 by emiliepham        #+#    #+#             */
/*   Updated: 2021/01/09 22:45:14 by emiliepham       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <regex>
#include <string>
#include <iostream>

using namespace std;

class Polynomial
{
    public:
        double  x2;
        double  x1;
        double  x0;
        double  delta;
        int     degree;
        string  str;

        Polynomial();
        
        void    calculateDeterminant();
        int     parseFactors(smatch match);

        ~Polynomial() {};
};

#endif