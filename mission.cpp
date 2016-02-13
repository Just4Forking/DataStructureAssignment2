#include "DetectMemoryLeak.h"
#include <string>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>

using std::string;
using std::vector;
using std::list;
using std::map;
using std::stack;
using std::queue;

// DO NOT MODIFY ANY LINE ABOVE OR ADD EXTRA INCLUDES

/*! 
 *  \brief     DM2126 Assignment 2
 *  \details   Submit the whole solution, but only this file will be used to grade
 *  \author    Terence Tan Ming Jie
 *  \date      2016 
 *  \note      151131H
 */


// Balanced parenthesis
 bool Brackets(const string& input)
{
	 stack<char> S;
	 if (input.empty())
	 {
		 return false;
	 }
	 else
	 {
		 for (unsigned int i = 0; i < input.length(); i++)
		 {
			 if (input[i] == '(' || input[i] == '{' || input[i] == '[' || input[i] == '<')
			 {
				 S.push(input[i]);
			 }
			 else if (S.empty())
			 {
			 	return false;
			 }
			 else if (input[i] == ')' || input[i] == '}' || input[i] == ']' || input[i] == '>')
			 {
			 	if (S.top() == '(' && input[i] == ')')
			 	{
			 		S.pop();
			 	}
			 	else if (S.top() == '{' && input[i] == '}')
			 	{
			 		S.pop();
			 	}
			 	else if (S.top() == '[' && input[i] == ']')
			 	{
			 		S.pop();	
			 	}
			 	else if (S.top() == '<' && input[i] == '>')
			 	{
			 		S.pop();
			 	}
				else
				{
					return false;
				}
			 }
		 }
		 if (S.empty())
		 {
			 return true;
		 }
	 }
	 return false;
}

// Query machine, hits
void QueryMachine(vector<int>& data, vector<int>& queries, vector<unsigned int>& results)
{
	int answer = 0;
	if (data.size() == 0)
	{
		results.push_back(0);
	}
	else
	{
		for (unsigned int i = 0; i < queries.size(); i++)
		{
			answer = 0;
			for (unsigned int k = 0; k < data.size(); k++)
			{
				if (data[k] == queries[i])
				{
					answer++;
				}
			}
			results.push_back(answer);
		}
	}

}