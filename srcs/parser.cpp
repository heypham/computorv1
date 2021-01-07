/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:39:26 by epham             #+#    #+#             */
/*   Updated: 2021/01/07 17:58:00 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"
#include <string>

/*
*** Split input string
*/

int split_input(string arg)
{
    if (regex_match (arg, regex("\\d+\\*[X|x]^0[+|-]\\d+\\*[X|x]^1[+|-]\\d+\\*[X|x]^2") ))
        cout << "test OK" << endl;
    return 0;
}

/*
*** Class parser
*/

int Computor::parser(int ac, char **av)
{
    int i;

    i = 0;
    if (ac == 2)
        split_input(av[1]);
    return 0;
}