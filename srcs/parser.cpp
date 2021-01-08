/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:39:26 by epham             #+#    #+#             */
/*   Updated: 2021/01/08 12:19:33 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"
#include <string>

/*
*** Remove  string
*/

int remove_space(string arg)
{
    regex e (" ");

    cout << regex_replace(arg, e, "") << endl;
    return 0;
}

/*
*** Class parser
*/

int Computor::parser(int ac, char **av)
{
    int i;
    string args;

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
    remove_space(args);

    return 0;
}