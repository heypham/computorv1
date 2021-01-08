/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:39:26 by epham             #+#    #+#             */
/*   Updated: 2021/01/08 18:47:53 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.hpp"

/*
*** Remove string
*/

int Parser::removeSpace()
{
    regex e (" ");

    cout << regex_replace(equation, e, "") << endl;
    equation = regex_replace(equation, e, "");
    return 0;
}

/*
*** Class parser
*/

Parser::Parser(int ac, char **av)
{
    int i;
    string args;

    a1 = 0.0;
    a2 = 0.0;
    b1 = 0.0;
    b2 = 0.0;
    c1 = 0.0;
    c2 = 0.0;
    error = 0;

    i = 0;
    if (ac != 2)
    {
        while (++i < ac)
        {
            cout << "current arg : " << av[i] << endl;
            args += av[i];
        }
    }
    else
        args = av[1];
    equation = args;
    removeSpace();
    cout << "equation after remove space " << equation << endl;
}
