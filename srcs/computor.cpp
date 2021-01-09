/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiliepham <emiliepham@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:04:15 by epham             #+#    #+#             */
/*   Updated: 2021/01/08 21:28:43 by emiliepham       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.hpp"

/*
*** Computor Constructor
*/

Computor::Computor (int ac, char **av) : parser(ac, av), reducedEq()
{
    degree = 0;
}

void Computor::display()
{
    
}

/*
*** Computor solver
*/

int Computor::solver()
{
    return 0;
}