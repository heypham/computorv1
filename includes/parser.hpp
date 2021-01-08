/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:26:01 by epham             #+#    #+#             */
/*   Updated: 2021/01/08 18:50:22 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include <regex>
#include <string>
#include <vector>
#include "computor.hpp"

using namespace std;

class Parser
{
    public:
        double a1;
        double a2;
        double b1;
        double b2;
        double c1;
        double c2;
        int error;
        string equation;

        Parser(int ac, char **av);
        int removeSpace();
        ~Parser();
};

#endif