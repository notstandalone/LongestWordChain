#include <iostream>
#include <fstream>

#include "input.h"
#include "Wordlist.h"
using namespace std;


/*检查输入,分析输入，*/
void paraAnalysis(int argc, char * argv[], char opt[][5], int & flag_wc, char & head, char & tail, bool & para_loop, string filePath)
{
	bool Tag_w = false;
	bool Tag_c = false;
	bool Tag_r = false;

	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], opt[_w]) == 0)
		{
			if (Tag_w)
			{
				cout << "-w should occur once" << endl;
				exit(-1);
			}
			if (flag_wc != 1)
			{
				Tag_w = true;
				flag_wc = 0;
			}
			else
			{
				cout << "parameter error:-w and -c can't occur simultaneously!" << endl;
				exit(-1);
			}
		}
		else if (strcmp(argv[i], opt[_c]) == 0)
		{
			if (Tag_c)
			{
				cout << "-c should occur once" << endl;
				exit(-1);
			}
			if (flag_wc != 0)
			{
				Tag_c = true;
				flag_wc = 1;
			}
			else
			{
				cout << "parameter error:-w and -c can't occur simultaneously!" << endl;
				exit(-1);
			}
		}
		else if (strcmp(argv[i], opt[_h]) == 0)
		{
			if (head != '\0')
			{
				cout << "-h should occur once" << endl;
				exit(-1);
			}

			if (isalpha(argv[i+1][0]) && strlen(argv[i + 1]) == 1)
			{
				if (isupper(argv[i + 1][0]))
				{
					head = tolower(argv[i + 1][0]);
				}
				else
				{
					head = argv[i + 1][0];
				}
				i++;
			}
			else
			{
				cout << "Should be a character after -h." << endl;
				exit(-1);
			}
		}
		else if (strcmp(argv[i], opt[_t]) == 0)
		{
			if (tail != '\0')
			{
				cout << "-t should occur once" << endl;
				exit(-1);
			}

			if (isalpha(argv[i + 1][0]) && strlen(argv[i+1]) == 1)
			{
				if (isupper(argv[i + 1][0]))
				{
					tail = tolower(argv[i + 1][0]);
				}
				else
				{
					tail = argv[i + 1][0];
				}
				i++;
			}
			else
			{
				cout << "Should be a character after -t." << endl;
				exit(-1);
			}
		}
		else if (strcmp(argv[i], opt[_r]) == 0)
		{
			if (Tag_r)
			{
				cout << "-r should occur once" << endl;
				exit(-1);
			}
			Tag_r = true;
			para_loop = true;
		}
		else
		{
			if (i == argc - 1)
			{
				filePath = argv[i];
			}
			else
			{
				cout << "occur unknow charactor!" << endl;
				exit(-1);
			}
		}
	}
}

/*处理文本，得到单词words*/
int getWord(char *words[], string path)
{
	ifstream fin;				//open wordlist file;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "can't open the file" << endl;
		exit(-1);
	}

	char word[1000];
	char ch;
	int lens = 0;
	int k = 0;
	while (fin.get(ch))
	{
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		{
			if (ch >= 'A' && ch <= 'Z') {
				ch = ch - 'A' + 'a';
			}
			word[k] = ch;
			k++;
		}
		else if (k != 0)
		{
			words[lens] = new char[k + 1];
			for (int i = 0; i < k; i++) 
			{
				words[lens][i] = word[i];
			}
			words[lens][k] = '\0';
			lens++;
			k = 0;
		}
	}
	fin.close();
	return lens;
}
