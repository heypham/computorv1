/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiliepham <emiliepham@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:26:01 by epham             #+#    #+#             */
/*   Updated: 2021/03/27 20:21:24 by emiliepham       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>
#include <sstream>
#include "polynomial.hpp"

class Parser
{
    public:
        Polynomial          leftPoly;
        Polynomial          rightPoly;
        string              equation;
        string              errorStr;
        int                 errorCode;
        int                 verbose;

        Parser(int ac, char **av);
        void                removeSpace();
        vector<string>      splitEquation();
        void                checkExpressionNumber(vector<string> expressions);
        void                verifyExpressions();
        void                parseExpression(Polynomial *poly);
        void                parseExpressions();
        int                 parse();
        ~Parser() {};
};

#endif