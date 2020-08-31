#include<vector>
#include<iostream>
#include"speechManager.h"
#include<time.h>
using namespace std;

int main() {
	srand((unsigned int)time(NULL));

	SpeechManager spm;
	//����ѡ�ִ���
	for (map<int,Speaker>::iterator it = spm.m_Speaker.begin(); it!= spm.m_Speaker.end(); it++)
	{
		cout << "��ţ�" << it->first << " ������" << it->second.m_name <<" ������"<<it->second.m_score[0]<< endl;
	}


	spm.showMenu();
	while (true)
	{
	int selectNum = 0;
	cin >> selectNum;

		switch (selectNum)
		{
		case 1://��ʼ����
			spm.startSpeech();
			break;
		case 2://�鿴��¼
			spm.showRecord();
			break;
		case 3://��ռ�¼
			spm.clearRecord();
			break;
		case 0://�˳�ϵͳ
			spm.exitSystem();
			break;
		default:
			break;
		}
	}
	return 0;
}