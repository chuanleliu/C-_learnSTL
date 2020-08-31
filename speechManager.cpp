#include"speechManager.h"


void SpeechManager::showMenu() {
	cout << "************************" << endl;
	cout << "*** 欢迎参见演讲比赛 ***" << endl;
	cout << "******1.开始比赛 *******" << endl;
	cout << "******2.往届记录 *******" << endl;
	cout << "******3.清空记录 *******" << endl;
	cout << "******0.退出比赛 *******" << endl;
	cout << "************************" << endl;
}
void SpeechManager::initSpeech() {
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m_Speaker.clear();
	//初始化比赛轮数
	this->m_index = 1;

}
SpeechManager::SpeechManager() {
	//初始化容器和属性
	this->initSpeech();

	//创建选手
	this->createSpeeker();

	//加载往届记录文件
	this->loadRecord();
}
SpeechManager::~SpeechManager() {


}
void SpeechManager::createSpeeker() {
	string nameSho = "NUAA: ";
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i <nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSho + nameSeed[i];
		//创建具体选手
		Speaker sp;
		sp.m_name = name;
		for (int i = 0; i < 2; i++)
		{
			sp.m_score[i] = 0;
		}
		//创建具体选手编号
		this->v1.push_back(i + 1001);
		//选手编号和对应选手放入map
		this->m_Speaker.insert(make_pair(i + 1001, sp));


	}
}
void SpeechManager::startSpeech() {
	//----------------第一轮比赛--------------------
	//1.抽签
	this->speechDraw();
	//2.比赛
	this->speechContest();
	//3.显示结果
	this->showScore();
	//----------------第二轮比赛--------------------
	this->m_index++;
	//1.抽签
	this->speechDraw();
	//2.比赛
	this->speechContest();
	//3.显示最终结果
	this->showScore();
	//保存文件
	this->saveRecord();

	//重置比赛获取记录

	//初始化容器和属性
	this->initSpeech();

	//创建选手
	this->createSpeeker();

	//加载往届记录文件
	this->loadRecord();

	cout << "本届比赛完毕！" << endl;
	system("pause");
	system("cls");




}
void SpeechManager::speechDraw() {

	cout << "第" << this->m_index << "轮比赛正在抽签。。。" << endl;

	if (this->m_index==1)
	{
		random_shuffle(v1.begin(), v1.end());
		
		cout << "演讲顺序如下" << endl;
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it<<" ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());

		cout << "演讲顺序如下" << endl;
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it<<" ";
		}
		cout << endl;
	}
	system("pause");


}

void SpeechManager::speechContest() {
	cout <<"----------------第" << this->m_index << "轮比赛正式开始------------------" << endl;
	
	//准备临时容器 存放小组成绩
	multimap<double, int, greater<double>>groupScore;
	int num = 0; //记录人员个数 6人一组
	
	vector<int>v_Src;
	if (this->m_index==1)
	{
		v_Src = this->v1;
	}
	else
	{
		v_Src = this->v2;
	}
	//遍历容器中的选手进行比赛

	for (vector<int>::iterator it = v_Src.begin(); it < v_Src.end(); it++)
	{
		num++;
		//评委打分
		deque<double>d;  //队列，可去除头和尾，排序后去除最高最低分
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;//600~1000
			//cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;
		sort(d.begin(), d.end(), greater<double>());  //排序
		//去除最高分
		d.pop_front();
		//去除最低分
		d.pop_back();

		//总分
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		//平均分
		double avg = sum / (double)d.size(); //强制转d.size为浮点数
		//将平均分放入map容器中
		this->m_Speaker[*it].m_score[this->m_index - 1] = avg;

		//打印平均分
		//cout << "编号：" << *it << " 选手：" << this->m_Speaker[*it].m_name << " 平均分：" << this->m_Speaker[*it].m_score[this->m_index - 1] << endl;

		//每六个人取一组
			//将打分数据放入到临时小组容器中
		groupScore.insert(make_pair(avg, *it)); //key是得分，value是具体选手编号
		//每六人取出前三名
		if (num%6==0)
		{
			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double,int,greater<double>>::iterator it = groupScore.begin(); it !=groupScore.end(); it++)
			{
				cout << " 编号：" << it->second << " 姓名：" << this->m_Speaker[it->second].m_name << " 成绩" << this->m_Speaker[it->second].m_score[this->m_index - 1] << endl;
			}
			//取走前三名放入容器中
			int count = 0;//明确定义取出每小组的前三名
			for (multimap<double,int,greater<double>>::iterator it = groupScore.begin(); it !=groupScore.end() && (count<3); it++,count++)
			{
				if (this->m_index==1)
				{
					this->v2.push_back((*it).second);
				}
				else
				{
					this->v3.push_back((*it).second);
				}
			}
			groupScore.clear();
			cout << endl;

			
		}
	}
	cout << "--------------------------------第" << this->m_index << "轮比赛完毕--------------------------------" << endl;
	system("pause");
}


void SpeechManager::showScore() {
	cout << "第" << this->m_index << "轮晋级选手信息如下" << endl;
	vector<int>v;
	if (this->m_index==1)
	{
		v = v2;
	}
	else
	{
		v = v3;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "选手编号：" << *it << "姓名" << this->m_Speaker[*it].m_name << "分数" << this->m_Speaker[*it].m_score[this->m_index-1] << endl;
	}
	system("pause");
	system("cls");
	this->showMenu();
	
}

void SpeechManager::saveRecord() {
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);
	//将每个选手的数据写入数据中
	for (vector<int>::iterator it = v3.begin(); it !=v3.end(); it++)
	{
		ofs << *it<< "," 
			<< this->m_Speaker[*it].m_score[1] << ",";
	}
	ofs << endl;
	//关闭
	ofs.close();
	cout << "文件保存成功" << endl;
	//更改文件不为空的状态
	this->fileIsEmpty = false;
}

void SpeechManager::loadRecord() {
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		//文件不存在
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件清空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件不为空
	this->fileIsEmpty = false;
	ifs.putback(ch); //将上面读取的单个字符放回
	string data;
	int index = 0;
	while (ifs>>data)
	{
		//cout << data << endl;
		//1009	83.575	1005	83.225	1006	82.7125
		vector<string>v;//存放读取文件的字符串
		int pos = -1;//查到逗号位置的变量
		int start =  0;
		while (true)
		{
			pos = data.find(",", start);
			if (pos==-1)
			{
				//没有找到
				break;
			}
			string temp = data.substr(start, pos - start);
			//cout << temp<<endl;
			v.push_back(temp);
			start = pos + 1;	
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
	//for (map<int,vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
	//{
	//	cout << it->first << "冠军编号：" << it->second[0] << " 分数:" << it->second[1] << endl;
	//}


}

void SpeechManager::showRecord() {
	if (this->fileIsEmpty)
	{
		cout << "文件不存在，或者记录为空" << endl;

	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "第" << i + 1 << "届"
				<< "冠军标号：" << this->m_Record[i][0] << "得分：" << this->m_Record[i][1]
				<< "亚军标号：" << this->m_Record[i][2] << "得分：" << this->m_Record[i][3]
				<< "季军标号：" << this->m_Record[i][4] << "得分：" << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
	this->showMenu();
}


void SpeechManager::clearRecord() {
	cout << "是否确定清空文件？" << endl;
	cout << "1. 确定" << endl;
	cout << "2. 取消" << endl;
	int select = 0;
	cin >> select;
	if (select==1)
	{
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//初始化容器和属性
		this->initSpeech();

		//创建选手
		this->createSpeeker();

		//加载往届记录文件
		this->loadRecord();

		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
	this->showMenu();
	
}
void SpeechManager::exitSystem() {
	cout << "欢迎下次使用" << endl;
	exit(0);
}

