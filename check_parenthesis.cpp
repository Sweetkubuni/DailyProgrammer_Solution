
/*
*
*
*  solution to https://www.reddit.com/r/dailyprogrammer/comments/5llkbj/2017012_challenge_298_easy_too_many_parentheses/
*
*
*/
#include <iostream>
#include <stack>
#include <string>
#include <utility>
using namespace std;

void correct_parenthesis(string & test)
{
	stack<pair<int,int>> unpaired_groups;
	stack<pair<int,int>> paired_groups;
	for(int it = 0; it < test.length(); it++)
	{
		if(test[it] == '(')
		{
			cout<< "unpaired" << endl;
			unpaired_groups.push(make_pair(it, -1));
		}
		
		if(test[it] == ')')
		{
			pair<int,int> temp  = unpaired_groups.top();
			temp.second = it;
			cout<< "paired";
			if( paired_groups.size() > 0 )
			{
				cout <<" - checking";
				pair<int,int> check = paired_groups.top();
				string parent = test.substr(temp.first, (temp.second + 1) - temp.first);
				string child  = test.substr(check.first,(check.second + 1) - check.first);
				if( (parent.find(child) && ((parent.size() - 2) == child.size())) )
				{
					cout << " - deleting parenthesis";
					test.erase(temp.second, 1);
					--paired_groups.top().first;
					--paired_groups.top().second;
					test.erase(temp.first,  1);
					it -= 2;
				}
				else
				{
					cout<< " - pushing paired parenthesis";
					paired_groups.push(temp);
				}
			}
			else 
			{
				cout<< " - first push";
				paired_groups.push(temp);	
			}
			cout << endl;
			unpaired_groups.pop();
		}
		
	}
}

int main() {
	string test;
	cin >> test;
	correct_parenthesis(test);
	cout << test;
	return 0;
}