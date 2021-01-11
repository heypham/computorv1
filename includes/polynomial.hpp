/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polynomial.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:04:49 by emiliepham        #+#    #+#             */
/*   Updated: 2021/01/11 16:27:03 by epham            ###   ########.fr       */
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
        float   x2;
        float   x1;
        float   x0;
        float   delta;
        float   sqrt_delta;
        float   sol1;
        float   sol2;
        int     degree;
        string  str;

        Polynomial();
        
        void    calculateDiscriminant();
        int     parseFactors(smatch match);
        int     verifyCoef(float a, string s);
        void    solveEquation();

        ~Polynomial() {};
};

#endif