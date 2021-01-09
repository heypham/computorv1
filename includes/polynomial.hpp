/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polynomial.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiliepham <emiliepham@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:04:49 by emiliepham        #+#    #+#             */
/*   Updated: 2021/01/08 22:16:30 by emiliepham       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <string>

using namespace std;

class Polynomial
{
    public:
        double x0;
        double x1;
        double x2;
        double delta;
        string str;

        Polynomial();
        
        void setDeterminant();

        ~Polynomial() {};
};

#endif