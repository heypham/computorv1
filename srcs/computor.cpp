/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:04:15 by epham             #+#    #+#             */
/*   Updated: 2021/01/08 18:41:27 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.hpp"

/*
*** Class Constructor
*/

Computor::Computor (int ac, char **av) : parser(ac, av) 
{
    a = 0.0;
    b = 0.0;
    c = 0.0;
    degree = 0;
}

void Computor::display()
{
    
}

/*
*** Class solver
*/

int Computor::solver()
{
    return 0;
}