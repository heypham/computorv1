/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:39:26 by epham             #+#    #+#             */
/*   Updated: 2021/01/10 12:55:06 by epham            ###   ########.fr       */
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
    if (s == "")
        cout << "end s : [" << s << "]\n";
    else if (s == "\0")
        cout << "s is \\0 !\n";
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
*** smatch is detailed into 7 groups (0 is the match itself)
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
    regex e("(([+-]?\\d*\\.?\\d+)\\*?(([Xx]{1}\\^([012]))|([Xx])))|([+-]?\\d*\\.?\\d+)|(([+-])?([Xx]{1}(\\^([012]))?))");
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
            errorStr = "Unexpected character at position " + to_string(pos);
            errorCode = -3;
        }
        poly->parseFactors(match);
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
    // cout << "Polynomial : " << leftPoly.x2 << "x^2 + " << leftPoly.x1 << "x^1 + " << leftPoly.x0 << "x^0\n"; 
    // cout << "Polynomial : " << rightPoly.x2 << "x^2 + " << rightPoly.x1 << "x^1 + " << rightPoly.x0 << "x^0\n";
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

    i = 0;
    if (ac != 2)
    {
        while (++i < ac)
            args += av[i];
    }
    else
        args = av[1];
    equation = args;
}
