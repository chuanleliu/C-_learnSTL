#pragma once
#include<iostream>

using namespace std;
class Speaker
{
public:
	string getSpeakerName() {
		return m_name;
	}
	double* getSpeakerScore() {
		return m_score;
	}
	string m_name;
	double m_score[2];
private:

	
};
