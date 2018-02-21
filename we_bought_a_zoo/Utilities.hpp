/***********************************************************************************
*Author: Alex McEvoy
*Date: 01/10/18
*Description: Header file for Utilities. Includes input validation, menu out and
* range builder functions.
************************************************************************************/

#ifndef VALIDINPUT_HPP
#define VALIDINPUT_HPP

#include<string>
#include<vector>
using std::string;
using std::vector;


int isInt(string);
int validIntInput(string, vector<int>&);
int menuInts(string, vector<string>&, vector<int>&);
vector<int> numRange(int, int);

double isDouble(string);
#endif
