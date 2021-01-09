/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiliepham <emiliepham@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:07:49 by epham             #+#    #+#             */
/*   Updated: 2021/01/09 22:43:46 by emiliepham       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.hpp"

/*
*** Equation format : a1 * x^0 + b1 * x^1 + c1 * x^2 = a2 * x^0 + b2 * x^1 + c2 * x^2
*/

int main(int ac, char **av) 
{
    Computor myComputor(ac, av);

    if (myComputor.parse() < 0)
        goto error;
    error:
        return (-1);
    return (0);
}