#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <ctime>
#include "Speech.hh"
using namespace std;

//排序
class SortingOfScores
{
public:
	bool operator()(double a,double b) const;
};



//设计管理类

class SpeechManager
{
public:

	vector<int> Speakers;

	vector<int> winers;

	vector<int> winer;

	map<int, Speaker> ma_Speaker;

	int MyIndex;

	//构造和析构
	SpeechManager();

	void ShowMenu();

	void initSpeech();

	void CreatSpeakers();

	void ShowSpeakers();

	void StartSpeechGame();

	void SpeechDraw();

	void BeginCompetition();

	void SpeakersQualify();

	void ExitSpeech();

	~SpeechManager();

};