/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiliepham <emiliepham@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:39:26 by epham             #+#    #+#             */
/*   Updated: 2021/01/09 02:24:14 by emiliepham       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.hpp"

/*
*** Remove string spaces
*/

int Parser::removeSpace()
{
    regex e (" ");

    equation = regex_replace(equation, e, "");
    return 0;
}

/*
*** Split string with = into two expressions
*/

vector<string> Parser::splitEquation()
{
    vector<string> result;
    string s;
    string token;
    size_t pos;

    pos = 0;
    s = equation;
    while ((pos = s.find('=')) != string::npos)
    {
        token = s.substr(0, pos);
        s.erase(0, pos + 1);
        result.push_back(token);
    }
    result.push_back(s);
    return result;
}

/*
*** Check how many expressions in equation
*/

int Parser::checkExpressionNumber(vector<string> expressions)
{
    if (expressions.size() != 2)
    {
        errorCode = -1;
        errorStr = "incorrect number of '='. You either have more than one equation, or no equation at all!";
        return -1;
    }
    leftPoly.str = expressions[0];
    rightPoly.str = expressions[1];
    return 0;
}

/*
*** Check each expression of the equation
*/

int Parser::verifyExpressions()
{
    if (errorCode < 0)
        return errorCode;
    if (leftPoly.str == "" || rightPoly.str == "")
    {
        errorCode = -2;
        errorStr = "incomplete equation. Verify you have expressions on both sides of the '='.";
        return -1;
    }
    return 0;
}

/*
*** Regex polynomial function
***
*** smatch is detailed into 7 groups (0 is the match itself)
*** 0. SMatch found
*** 1. term in form ax^b or a*x^b
*** 2. coefficient a of term 1.
*** 3. means found X value (x or x^b)
*** 4. means 3. is a x powered value (x^b)
*** 5. power value b of 4.
*** 6. means 3. is a X single value (= x^0)
*** 7. single number value a (= a * x^0)
*/

int Parser::parseExpression(Polynomial poly)
{
    static const regex e("(([+-]?\\d*\\.?\\d+)\\*?(([Xx]?\\^([012]))|([Xx])))|([+-]?\\d*\\.?\\d+)");
    const char *s;
    // smatch cm;

    // s = poly.str.c_str();
    // cout << s << endl;
    sregex_iterator begin;
    sregex_iterator end;

    begin = sregex_iterator(poly.str.begin(), poly.str.end(), e);
    end = sregex_iterator();
    cout << std::distance(begin, end) << " matches found." << endl;
    for (std::sregex_iterator i = begin; i != end; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str(); 
        std::cout << match_str << '\n';
        for (unsigned i=1; i<match.size(); ++i) 
        {
            cout << "[" << match[i] << "] ";
        }
        cout << endl;
    }   
  return 0;
}

/*
*** Parser Constructor
*/

Parser::Parser(int ac, char **av) : leftPoly(), rightPoly()
{
    int i;
    string args;

    errorStr = "";
    errorCode = 0;

    i = 0;
    if (ac != 2)
    {
        while (++i < ac)
        {
            // cout << "current arg : " << av[i] << endl;
            args += av[i];
        }
    }
    else
        args = av[1];
    equation = args;
    removeSpace();
    // cout << "equation after remove space " << equation << endl;
    
    checkExpressionNumber(splitEquation());
    verifyExpressions();
    parseExpression(leftPoly);
    parseExpression(rightPoly);
    if (errorCode < 0)
        cout << "Wrong equation format : " << errorStr << endl;
}
