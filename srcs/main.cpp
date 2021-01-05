/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:07:49 by epham             #+#    #+#             */
/*   Updated: 2021/01/05 16:54:51 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

/*
*** Equation format : a1 * x^0 + b1 * x^1 + c1 * x^2 = a2 * x^0 + b2 * x^1 + c2 * x^2
*/

int main() 
{
    Computor myComputor;

    cout << "Hello test " << myComputor.getDegree() << endl;
    return 0;
}