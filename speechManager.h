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
	需求列表：
	1. 12个人
	2. 第一轮：6人晋级
	3. 胜利的前三名
	4. 存放编号 及 对应选手 容器
	5. 记录比赛轮数
*/

class SpeechManager
{
public:
	//菜单
	void showMenu();
	//退出
	void exitSystem();

	//初始化
	void initSpeech();

	//构造
	SpeechManager();
	//析构
	~SpeechManager();
	//新建12名选手
	void createSpeeker();
	//开始比赛
	void startSpeech();
	//抽签
	void speechDraw();
	//比赛中
	void speechContest();
	void showScore();

	//保存记录
	void saveRecord();
	//查看记录
	void loadRecord();
	//文件是否为空
	bool fileIsEmpty;
	//往届记录
	map<int, vector<string>>m_Record;

	//显示往届记录
	void showRecord();

	//清空文件
	void clearRecord();

	//成员属性
	//保存第一轮比赛选手编号
	vector<int>v1;
	//第一轮晋级选手编号
	vector<int>v2;
	//前三名
	vector<int>v3;
	//存放编号及对应具体选手容器
	map<int, Speaker>m_Speaker;
	//记录比赛轮数
	int m_index;

};
