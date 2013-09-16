/*
 * Chef_of_the_Year.cpp
 *
 *  Created on: 06-Jan-2013
 *      Author: ARUPMADHU
 */
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;

int compareTo(string str1,string str2){
	int index1 = 0;
	int index2 = 0;
	int result = 0;
	while((str1[index1] != '\0' && str2[index2] != '\0') && (str1[index1] == str2[index2])){
		index1++;
		index2++;
	}

	if((str1[index1] == '\0') && (str1[index1] == '\0'))
		result = 0;
	else if(str1[index1] == '\0')
		result = -1;
	else if(str2[index2] == '\0')
		result = 1;
	else if(str1[index1] < str2[index2])
		result = -1;
	else
		result = 1;
	return result;
}

int main(void){
	vector<string>  Country;
	vector<string>  Chef;
	vector<int> 	Count;
	map<string,int> list;
	map<string,int> country_vote;

	int N = 0; // Num of Chef
	int M = 0; // Num Email
	cin>>N>>M;

	for(int index = 0; index < N;index++){
		string chef;
		string country;
		cin>>chef>>country;

		Chef.push_back(chef);
		Country.push_back(country);
		Count.push_back(0);

		list[chef] = index;
		country_vote[country] = 0;
	}

	for(int i = 0;i < M; i++){
		string email;
		cin>>email;
		int index = list[email];

		Count[index] = Count[index] + 1;
		country_vote[Country[index]] = country_vote[Country[index]] + 1;
	}

	int vote_cnt = INT_MIN;
	string winner;
	for(unsigned int index = 0; index < Count.size();index++)
	{
		int cnt = Count[index];
		if((vote_cnt < cnt) ||
		  ((vote_cnt == cnt)  &&  0 < compareTo(winner,Chef[index])))
		{
			vote_cnt = cnt;
			winner = Chef[index];
		}
	}


	string win_country;
	int max_vote = INT_MIN;
	for(map<string,int>::iterator it=country_vote.begin() ; it != country_vote.end(); it++ )
	{
		int cnt = (*it).second;
		if((max_vote < cnt) ||
		  ((vote_cnt == cnt)  &&  0 < compareTo(win_country,(*it).first)))
		{
			max_vote = cnt;
			win_country = (*it).first;
		}
	}
	cout<<win_country<<endl;
	cout<<winner<<endl;
	return 0;
}


