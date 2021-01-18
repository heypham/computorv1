/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:09:20 by epham             #+#    #+#             */
/*   Updated: 2021/01/18 15:59:42 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_HPP
#define COMPUTOR_HPP

#include "parser.hpp"

/*
*** Equation format : x2 * x^2 + x1 * x^1 + x0 * x^0
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