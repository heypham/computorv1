/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiliepham <emiliepham@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:26:01 by epham             #+#    #+#             */
/*   Updated: 2021/01/09 00:21:48 by emiliepham       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <regex>
#include <vector>
#include <sstream>
#include "polynomial.hpp"

class Parser
{
        Polynomial leftPoly;
        Polynomial rightPoly;
    public:
        string equation;
        string errorStr;
        int errorCode;

        Parser(int ac, char **av);
        int             removeSpace();
        vector<string>  splitEquation();
        int             checkExpressionNumber(vector<string> expressions);
        int             verifyExpressions();
        int             parseExpression(Polynomial poly);
        ~Parser() {};
};

#endif