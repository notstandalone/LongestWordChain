// Wordlist.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <string>

#include "pch.h"
#include "Wordlist.h"
#include "Core.h"
#include "input.h"

using namespace std;

char *words[100005];			//存储从文本中提取出的单词；
int lens = 0;					//文本单词的个数；
char *result[30];				//结果链；
int result_lens = 0;			//结果链长度

int main(int argc, char *argv[])
{
	int  flag_wc = -1; //如果为0表示-w, 如何为1表示-c, 否则报错；
	bool enable_loop = false;
	char head = '\0';
	char tail = '\0';
	string filePath;
	
	//handle input;
	paraAnalysis(argc, argv, opt, flag_wc, head, tail, enable_loop, filePath);
	lens = getWord(words, filePath);	

	if (flag_wc == 0)
	{
		result_lens = gen_chain_word(words, lens, result, head, tail, enable_loop);
		for (int i = 0; i < result_lens; i++)
		{
			cout << result[i] << endl;
		}
	}
	else
	{
		result_lens = gen_chain_char(words, lens, result, head, tail, enable_loop);
		for (int i = 0; i < result_lens; i++)
		{
			cout << result[i] << endl;
		}
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
