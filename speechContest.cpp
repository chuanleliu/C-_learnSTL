#include<vector>
#include<iostream>
#include"speechManager.h"
#include<time.h>
using namespace std;

int main() {
	srand((unsigned int)time(NULL));

	SpeechManager spm;
	//测试选手创建
	for (map<int,Speaker>::iterator it = spm.m_Speaker.begin(); it!= spm.m_Speaker.end(); it++)
	{
		cout << "编号：" << it->first << " 姓名：" << it->second.m_name <<" 分数："<<it->second.m_score[0]<< endl;
	}


	spm.showMenu();
	while (true)
	{
	int selectNum = 0;
	cin >> selectNum;

		switch (selectNum)
		{
		case 1://开始比赛
			spm.startSpeech();
			break;
		case 2://查看记录
			spm.showRecord();
			break;
		case 3://清空记录
			spm.clearRecord();
			break;
		case 0://退出系统
			spm.exitSystem();
			break;
		default:
			break;
		}
	}
	return 0;
}