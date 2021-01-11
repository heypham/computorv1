/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:09:20 by epham             #+#    #+#             */
/*   Updated: 2021/01/11 17:27:57 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_HPP
#define COMPUTOR_HPP

#include "parser.hpp"

/*
*** Equation format : a1 * x^0 + b1 * x^1 + c1 * x^2 = a2 * x^0 + b2 * x^1 + c2 * x^2
*/

class Computor
{
        Parser      parser;
        Polynomial  reducedEq;

    public:
        Computor (int ac, char **av) : parser(ac, av), reducedEq() {};

        int         parse();
        void        solve();
        void        display();
        void        displayDetails();
        void        displaySolutions();
        void        getDegree();

        ~Computor() {};
};

#endif