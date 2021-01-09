/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polynomial.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:04:49 by emiliepham        #+#    #+#             */
/*   Updated: 2021/01/09 13:56:02 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <regex>
#include <string>

using namespace std;

class Polynomial
{
    public:
        double  x2;
        double  x1;
        double  x0;
        double  delta;
        string  str;

        Polynomial();
        
        void    setDeterminant();
        // int     parseFactors(smatch match, double lr);

        ~Polynomial() {};
};

#endif