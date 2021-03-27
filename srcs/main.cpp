/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiliepham <emiliepham@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:07:49 by epham             #+#    #+#             */
/*   Updated: 2021/03/27 20:20:54 by emiliepham       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.hpp"

/*
*** Usage
*/

string  usage()
{
    string ret;

    ret = "Usage :  ./computor [-v] 'a * X^2 + b * X^1 + c * X^0 = d * X^2 + e * X^1 + f * X^0'";
    return (ret);
}

/*
*** Equation format : a1 * x^0 + b1 * x^1 + c1 * x^2 = a2 * x^0 + b2 * x^1 + c2 * x^2
*/

int     main(int ac, char **av) 
{
    if (ac == 1)
    {
        cout << usage() << endl;
        return (-1);
    }
    Computor myComputor(ac, av);

    if (myComputor.parse() < 0)
        goto error;
    myComputor.solve();
    myComputor.display();
    error:
        return (-1);
    return (0);
}