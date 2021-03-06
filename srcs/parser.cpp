/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiliepham <emiliepham@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:39:26 by epham             #+#    #+#             */
/*   Updated: 2021/03/27 20:46:44 by emiliepham       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.hpp"

/*
*** Remove string spaces
*/

void Parser::removeSpace()
{
    regex e (" ");

    equation = regex_replace(equation, e, "");
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

void Parser::checkExpressionNumber(vector<string> expressions)
{
    if (errorCode < 0)
        return ;
    if (expressions.size() == 2)
    {
        leftPoly.str = expressions[0];
        rightPoly.str = expressions[1];
    }
    else
    {
        errorCode = -1;
        errorStr = "incorrect number of '='. You either have more than one equation, or no equation at all!";
    }
    
}

/*
*** Check each expression of the equation
*/

void Parser::verifyExpressions()
{
    if (errorCode < 0)
        return ;
    if (leftPoly.str == "" || rightPoly.str == "")
    {
        errorCode = -2;
        errorStr = "incomplete equation. Verify you have expressions on both sides of the '='.";
    }
}

/*
*** Regex polynomial function
***
*** smatch is detailed into 12 groups (0 is the match itself)
*** 0. SMatch found
*** 1. term in form ax^b or a*x^b
*** 2. coefficient a of term 1.
*** 3. means found X value (x or x^b)
*** 4. means 3. is a x powered value (x^b)
*** 5. power value b of 4.
*** 6. means 3. is a X single value (= ax^1)
*** 7. single number value a (= a * x^0)
*** 8. ax^b where a = +-1
*** 9. sign of a (+-)
*** 10. -
*** 11. power b of 8 exists (if this group is empty then format +-x)
*** 12. value of b power
*/

void Parser::parseExpression(Polynomial *poly)
{
    regex e("(([+-]?\\d*\\.?\\d+)\\*?(([Xx]{1}\\^(\\d+))|([Xx])))|([+-]?\\d*\\.?\\d+)|(([+-])?([Xx]{1}(\\^(\\d+))?))");
    sregex_iterator begin;
    sregex_iterator end;
    unsigned long pos;

    if (errorCode < 0)
        return ;
    begin = sregex_iterator(poly->str.begin(), poly->str.end(), e);
    end = sregex_iterator();
    pos = 0;
    while (begin != end)
    {
        smatch match = *begin++;
        string match_str = match.str();
        if (match.position() != (long)pos)
        {
            errorCode = -3;
            break ;
        }
        if (poly->parseFactors(match))
        {
            errorStr = "One factor is missing an operand.";
            errorCode = -4;
            return ;
        }
        if (poly->degree > 2)
        {
            errorStr = "The polynomial degree is strictly greater than 2, I can't solve.";
            errorCode = -5;
            return ;
        }
        pos += match.length();
    }
    if (pos != poly->str.length())
    {
        errorStr = "Unexpected character at position " + to_string(pos);
        errorCode = -3;
    }
}

/*
*** Adding level of abstraction to call from Computor class
*/

void Parser::parseExpressions()
{
    parseExpression(&leftPoly);
    parseExpression(&rightPoly);
}

int Parser::parse()
{
    removeSpace();
    checkExpressionNumber(splitEquation());
    verifyExpressions();
    parseExpressions();
    if (errorCode < 0)
    {
        cout << "Wrong equation format : " << errorStr << endl;
        return (-1);
    }
    return (0);
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
    verbose = 0;

    i = 1;
    if (ac != 2)
    {
        if (strcmp(av[i],"-v") == 0 || strcmp(av[i],"-V") == 0)
        {
            verbose = 1;
            i++;
        }
        while (i < ac)
        {
            args += av[i];
            i++;
        }
    }
    else
        args = av[1];
    equation = args;
}
