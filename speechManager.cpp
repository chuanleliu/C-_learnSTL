#include"speechManager.h"


void SpeechManager::showMenu() {
	cout << "************************" << endl;
	cout << "*** ��ӭ�μ��ݽ����� ***" << endl;
	cout << "******1.��ʼ���� *******" << endl;
	cout << "******2.�����¼ *******" << endl;
	cout << "******3.��ռ�¼ *******" << endl;
	cout << "******0.�˳����� *******" << endl;
	cout << "************************" << endl;
}
void SpeechManager::initSpeech() {
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m_Speaker.clear();
	//��ʼ����������
	this->m_index = 1;

}
SpeechManager::SpeechManager() {
	//��ʼ������������
	this->initSpeech();

	//����ѡ��
	this->createSpeeker();

	//���������¼�ļ�
	this->loadRecord();
}
SpeechManager::~SpeechManager() {


}
void SpeechManager::createSpeeker() {
	string nameSho = "NUAA: ";
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i <nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSho + nameSeed[i];
		//��������ѡ��
		Speaker sp;
		sp.m_name = name;
		for (int i = 0; i < 2; i++)
		{
			sp.m_score[i] = 0;
		}
		//��������ѡ�ֱ��
		this->v1.push_back(i + 1001);
		//ѡ�ֱ�źͶ�Ӧѡ�ַ���map
		this->m_Speaker.insert(make_pair(i + 1001, sp));


	}
}
void SpeechManager::startSpeech() {
	//----------------��һ�ֱ���--------------------
	//1.��ǩ
	this->speechDraw();
	//2.����
	this->speechContest();
	//3.��ʾ���
	this->showScore();
	//----------------�ڶ��ֱ���--------------------
	this->m_index++;
	//1.��ǩ
	this->speechDraw();
	//2.����
	this->speechContest();
	//3.��ʾ���ս��
	this->showScore();
	//�����ļ�
	this->saveRecord();

	//���ñ�����ȡ��¼

	//��ʼ������������
	this->initSpeech();

	//����ѡ��
	this->createSpeeker();

	//���������¼�ļ�
	this->loadRecord();

	cout << "���������ϣ�" << endl;
	system("pause");
	system("cls");




}
void SpeechManager::speechDraw() {

	cout << "��" << this->m_index << "�ֱ������ڳ�ǩ������" << endl;

	if (this->m_index==1)
	{
		random_shuffle(v1.begin(), v1.end());
		
		cout << "�ݽ�˳������" << endl;
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it<<" ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());

		cout << "�ݽ�˳������" << endl;
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it<<" ";
		}
		cout << endl;
	}
	system("pause");


}

void SpeechManager::speechContest() {
	cout <<"----------------��" << this->m_index << "�ֱ�����ʽ��ʼ------------------" << endl;
	
	//׼����ʱ���� ���С��ɼ�
	multimap<double, int, greater<double>>groupScore;
	int num = 0; //��¼��Ա���� 6��һ��
	
	vector<int>v_Src;
	if (this->m_index==1)
	{
		v_Src = this->v1;
	}
	else
	{
		v_Src = this->v2;
	}
	//���������е�ѡ�ֽ��б���

	for (vector<int>::iterator it = v_Src.begin(); it < v_Src.end(); it++)
	{
		num++;
		//��ί���
		deque<double>d;  //���У���ȥ��ͷ��β�������ȥ�������ͷ�
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;//600~1000
			//cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;
		sort(d.begin(), d.end(), greater<double>());  //����
		//ȥ����߷�
		d.pop_front();
		//ȥ����ͷ�
		d.pop_back();

		//�ܷ�
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		//ƽ����
		double avg = sum / (double)d.size(); //ǿ��תd.sizeΪ������
		//��ƽ���ַ���map������
		this->m_Speaker[*it].m_score[this->m_index - 1] = avg;

		//��ӡƽ����
		//cout << "��ţ�" << *it << " ѡ�֣�" << this->m_Speaker[*it].m_name << " ƽ���֣�" << this->m_Speaker[*it].m_score[this->m_index - 1] << endl;

		//ÿ������ȡһ��
			//��������ݷ��뵽��ʱС��������
		groupScore.insert(make_pair(avg, *it)); //key�ǵ÷֣�value�Ǿ���ѡ�ֱ��
		//ÿ����ȡ��ǰ����
		if (num%6==0)
		{
			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double,int,greater<double>>::iterator it = groupScore.begin(); it !=groupScore.end(); it++)
			{
				cout << " ��ţ�" << it->second << " ������" << this->m_Speaker[it->second].m_name << " �ɼ�" << this->m_Speaker[it->second].m_score[this->m_index - 1] << endl;
			}
			//ȡ��ǰ��������������
			int count = 0;//��ȷ����ȡ��ÿС���ǰ����
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
	cout << "--------------------------------��" << this->m_index << "�ֱ������--------------------------------" << endl;
	system("pause");
}


void SpeechManager::showScore() {
	cout << "��" << this->m_index << "�ֽ���ѡ����Ϣ����" << endl;
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
		cout << "ѡ�ֱ�ţ�" << *it << "����" << this->m_Speaker[*it].m_name << "����" << this->m_Speaker[*it].m_score[this->m_index-1] << endl;
	}
	system("pause");
	system("cls");
	this->showMenu();
	
}

void SpeechManager::saveRecord() {
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);
	//��ÿ��ѡ�ֵ�����д��������
	for (vector<int>::iterator it = v3.begin(); it !=v3.end(); it++)
	{
		ofs << *it<< "," 
			<< this->m_Speaker[*it].m_score[1] << ",";
	}
	ofs << endl;
	//�ر�
	ofs.close();
	cout << "�ļ�����ɹ�" << endl;
	//�����ļ���Ϊ�յ�״̬
	this->fileIsEmpty = false;
}

void SpeechManager::loadRecord() {
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		//�ļ�������
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ���Ϊ��
	this->fileIsEmpty = false;
	ifs.putback(ch); //�������ȡ�ĵ����ַ��Ż�
	string data;
	int index = 0;
	while (ifs>>data)
	{
		//cout << data << endl;
		//1009	83.575	1005	83.225	1006	82.7125
		vector<string>v;//��Ŷ�ȡ�ļ����ַ���
		int pos = -1;//�鵽����λ�õı���
		int start =  0;
		while (true)
		{
			pos = data.find(",", start);
			if (pos==-1)
			{
				//û���ҵ�
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
	//	cout << it->first << "�ھ���ţ�" << it->second[0] << " ����:" << it->second[1] << endl;
	//}


}

void SpeechManager::showRecord() {
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڣ����߼�¼Ϊ��" << endl;

	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "��" << i + 1 << "��"
				<< "�ھ���ţ�" << this->m_Record[i][0] << "�÷֣�" << this->m_Record[i][1]
				<< "�Ǿ���ţ�" << this->m_Record[i][2] << "�÷֣�" << this->m_Record[i][3]
				<< "������ţ�" << this->m_Record[i][4] << "�÷֣�" << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
	this->showMenu();
}


void SpeechManager::clearRecord() {
	cout << "�Ƿ�ȷ������ļ���" << endl;
	cout << "1. ȷ��" << endl;
	cout << "2. ȡ��" << endl;
	int select = 0;
	cin >> select;
	if (select==1)
	{
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//��ʼ������������
		this->initSpeech();

		//����ѡ��
		this->createSpeeker();

		//���������¼�ļ�
		this->loadRecord();

		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
	this->showMenu();
	
}
void SpeechManager::exitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	exit(0);
}

