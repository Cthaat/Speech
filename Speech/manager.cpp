#define _CRT_SECURE_NO_WARINGS 1
#include "manager.hh"


bool SortingOfScores::operator()(double a,double b) const
{
	return a > b;
}


SpeechManager::SpeechManager()
{
	this->initSpeech();
}

void SpeechManager::ShowMenu()
{
	cout << "***********************************" << endl;
	cout << "******     欢迎参加演讲比赛    ******" << endl;
	cout << "******      1.开始演讲比赛   ********" << endl;
	cout << "******      2.查看往届比赛   ********" << endl;
	cout << "*******     3.清空比赛记录     ******" << endl;
	cout << "********    0.  退出            ****" << endl;
	cout << "***********************************" << endl;
}


void SpeechManager::initSpeech()
{
	this->ma_Speaker.clear();
	this->Speakers.clear();
	this->winer.clear();
	this->winers.clear();
	this->MyIndex = 0;
}

void SpeechManager::CreatSpeakers()
{
	string NameSeed = "ABCDEFGHIGKL";
	for (int i = 0; i < NameSeed.size(); i++)
	{
		string BaseName = "选手";
		BaseName += NameSeed[i];
		Speaker temp_Speaker;
		temp_Speaker.name = BaseName;
		temp_Speaker.score[0] = 0;
		temp_Speaker.score[1] = 0;
		this->Speakers.push_back(10000 + i);
		this->ma_Speaker.insert(make_pair(this->Speakers[i], temp_Speaker));
	}
}

void SpeechManager::ShowSpeakers()
{
	if (MyIndex == 1)
	{
		for (vector<int>::iterator it = Speakers.begin(); it != Speakers.end(); it++)
		{
			map<int, Speaker>::iterator MAP_Speaker = this->ma_Speaker.find(*it);
			cout << "选手编号： " << *it << "  选手姓名： " << (*MAP_Speaker).second.name << "  选手成绩： " << (*MAP_Speaker).second.score[0] << endl;
		}
	}
	if (MyIndex == 2)
	{
		for (vector<int>::iterator it = winers.begin(); it != winers.end(); it++)
		{
			map<int, Speaker>::iterator MAP_Speaker = this->ma_Speaker.find(*it);
			cout << "选手编号： " << *it << "选手姓名： " << (*MAP_Speaker).second.name << "选手成绩： " << (*MAP_Speaker).second.score[1] << endl;
		}
	}
	if (MyIndex == 3)
	{
		for (vector<int>::iterator it = winer.begin(); it != winer.end(); it++)
		{
			map<int, Speaker>::iterator MAP_Speaker = this->ma_Speaker.find(*it);
			cout << "选手编号： " << *it << "选手姓名： " << (*MAP_Speaker).second.name << "选手成绩： " << (*MAP_Speaker).second.score[1] << endl;
		}
	}
}

void SpeechManager::StartSpeechGame()
{
	this->MyIndex = 1;
	cout << "现在进行第一场比赛" << endl;
	this->SpeechDraw();
	cout << "按任意键开始比赛" << endl;
	system("pause");
	this->BeginCompetition();
	cout << "比赛结束：" << endl << "以下是选手分数 ：" << endl;
	this->ShowSpeakers();
	this->MyIndex = 2;
	this->SpeakersQualify();
	cout << "以下是晋级选手 ：" << endl;
	this->ShowSpeakers();
	system("pause");
	cout << "现在进行第二场比赛" << endl;
	cout << "抽取结果如下" << endl;
	this->SpeechDraw();
	this->BeginCompetition();
	cout << "以下是选手分数" << endl;
	this->ShowSpeakers();
	system("pause");
	this->MyIndex = 3;
	this->SpeakersQualify();
	cout << "恭喜以下选手" << endl;
	this->ShowSpeakers();
	system("pause");
}

void SpeechManager::SpeechDraw()
{
	srand((unsigned int)time(NULL));
	if (this->MyIndex == 1)
	{
		random_shuffle(this->Speakers.begin(), this->Speakers.end());
		cout << "抽签结果如下: " << endl;
		this->ShowSpeakers();
	}
	if (this->MyIndex == 2)
	{
		random_shuffle(this->winers.begin(), this->winers.end());
		cout << "抽签结果如下: " << endl;
		this->ShowSpeakers();
	}
}

void SpeechManager::BeginCompetition()
{
	srand((unsigned int)time(NULL));
	multimap<double, int , SortingOfScores> TempSTL;
	if (this->MyIndex == 1)
	{
		for (vector<int>::iterator it = Speakers.begin(); it != Speakers.end(); it++)
		{
			map<int, Speaker>::iterator MAP_Speaker = this->ma_Speaker.find(*it);
			MAP_Speaker->second.score[0] = (double)(rand() % 40 + 60 + rand() % 40 + 60 + rand() % 40 + 60) / 3;
			TempSTL.insert(make_pair(MAP_Speaker->second.score[0], *it));
		}
		this->Speakers.clear();
		for (multimap<double, int, SortingOfScores>::iterator It = TempSTL.begin(); It != TempSTL.end(); It++)
		{
			this->Speakers.push_back(It->second);
		}
		TempSTL.clear();
	}
	if (this->MyIndex == 2)
	{
		for (vector<int>::iterator it = winers.begin(); it != winers.end(); it++)
		{
			map<int, Speaker>::iterator MAP_Speaker = this->ma_Speaker.find(*it);
			MAP_Speaker->second.score[1] = (double)(rand() % 40 + 60 + rand() % 40 + 60 + rand() % 40 + 60) / 3;
			TempSTL.insert(make_pair(MAP_Speaker->second.score[1], *it));
		}
		this->winers.clear();
		for (multimap<double, int, SortingOfScores>::iterator It = TempSTL.begin(); It != TempSTL.end(); It++)
		{
			this->winers.push_back(It->second);
		}
		TempSTL.clear();
	}
	
}

void SpeechManager::SpeakersQualify()
{
	if (this->MyIndex == 2)
	{
		
		for (vector<int>::iterator it = Speakers.begin(), Temp = Speakers.begin(); Temp != Speakers.end(); it++, Temp+=2)
		{
			winers.push_back(*it);
		}
	}
	if (this->MyIndex == 3)
	{

		for (vector<int>::iterator it = winers.begin(), Temp = winers.begin(); Temp != winers.end(); it++, Temp+=2)
		{
			winer.push_back(*it);
		}
	}
}

void SpeechManager::ExitSpeech()
{
	cout << "感谢您的使用" << endl;
}

SpeechManager::~SpeechManager()
{

}







////////////////////////////////////////////////////////////////////
//                          _ooOoo_                               //
//                         o8888888o                              //
//                         88" . "88                              //
//                         (| ^_^ |)                              //
//                         O\  =  /O                              //
//                      ____/`---'\____                           //
//                    .'  \\|     |//  `.                         //
//                   /  \\|||  :  |||//  \                        //
//                  /  _||||| -:- |||||-  \                       //
//                  |   | \\\  -  /// |   |                       //
//                  | \_|  ''\---/''  |   |                       //
//                  \  .-\__  `-`  ___/-. /                       //
//                ___`. .'  /--.--\  `. . ___                     //
//              ."" '<  `.___\_<|>_/___.'  >'"".                  //
//            | | :  `- \`.;`\ _ /`;.`/ - ` : | |                 //
//            \  \ `-.   \_ __\ /__ _/   .-` /  /                 //
//      ========`-.____`-.___\_____/___.-`____.-'========         //
//                           `=---='                              //
//      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^        //
//         佛祖保佑       永无BUG     永不修改                      //
////////////////////////////////////////////////////////////////////