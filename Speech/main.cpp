#define _CRT_SECURE_NO_WARINGS 1
#include "Speech.hh"
#include "manager.hh"
#include <iostream>
using namespace std;

int main()
{
	SpeechManager Manager;
	do
	{
		system("cls");
		Manager.ShowMenu();
		cout << "输入选择" << endl;
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
			//开始演讲比赛
		case 1:
			Manager.initSpeech();
			Manager.CreatSpeakers();
			Manager.StartSpeechGame();
			Manager.initSpeech();
			break;
			//查看往届比赛
		case 2:
			Manager.EnquiryHistoryMarks();
			break;
			//清空比赛记录
		case 3:
			Manager.ClearHistoryMarks();
			break;
		case 0:
			Manager.ExitSpeech();
			exit(0);
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			break;
		}
	} while (true);
	return 0;
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