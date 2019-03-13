#pragma once
#ifndef INPUT_H_
#define INPUT_H_

void paraAnalysis(int argc, char * argv[], char opt[][5], int & flag_wc, char & head, char & tail, bool & para_loop, string filePath);
int getWord(char *words[], string path);

#endif // !INPUT_H_