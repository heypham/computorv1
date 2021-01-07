/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:09:20 by epham             #+#    #+#             */
/*   Updated: 2021/01/07 17:34:28 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_H
#define COMPUTOR_H

#include <iostream>

// Parser
#include <regex>

using namespace std;

/*
*** Equation format : a1 * x^0 + b1 * x^1 + c1 * x^2 = a2 * x^0 + b2 * x^1 + c2 * x^2
*/

class Computor
{
    private:
        int a1;
        int a2;
        int b1;
        int b2;
        int c1;
        int c2;
        int degree;

    public:
        Computor ();

        int parser(int ac, char **av);
        int solver();
        void display();
        int getDegree() { return degree; }
};

#endif