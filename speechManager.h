#pragma once
#include<iostream>
#include<fstream>
#include<ostream>
#include<vector>
#include<map>
#include"speaker.h"
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>

using namespace std;

/*
	�����б�
	1. 12����
	2. ��һ�֣�6�˽���
	3. ʤ����ǰ����
	4. ��ű�� �� ��Ӧѡ�� ����
	5. ��¼��������
*/

class SpeechManager
{
public:
	//�˵�
	void showMenu();
	//�˳�
	void exitSystem();

	//��ʼ��
	void initSpeech();

	//����
	SpeechManager();
	//����
	~SpeechManager();
	//�½�12��ѡ��
	void createSpeeker();
	//��ʼ����
	void startSpeech();
	//��ǩ
	void speechDraw();
	//������
	void speechContest();
	void showScore();

	//�����¼
	void saveRecord();
	//�鿴��¼
	void loadRecord();
	//�ļ��Ƿ�Ϊ��
	bool fileIsEmpty;
	//�����¼
	map<int, vector<string>>m_Record;

	//��ʾ�����¼
	void showRecord();

	//����ļ�
	void clearRecord();

	//��Ա����
	//�����һ�ֱ���ѡ�ֱ��
	vector<int>v1;
	//��һ�ֽ���ѡ�ֱ��
	vector<int>v2;
	//ǰ����
	vector<int>v3;
	//��ű�ż���Ӧ����ѡ������
	map<int, Speaker>m_Speaker;
	//��¼��������
	int m_index;

};
