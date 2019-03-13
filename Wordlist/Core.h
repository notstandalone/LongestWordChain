#pragma once
#ifndef CORE_H_
#define CORE_H_

#include <vector>

#include "Node.h"
#include "Wordlist.h"

class Core
{
private:
	std::vector<Node*> *topologyWord;
	int weight[ALPHA_LENGTH];

	void charToVector(char* words[]);
	void topologySort(std::vector<Node*> *topologyWord, int weight[]);		//Õÿ∆À≈≈–Ú£ª
	void dynamicProgramAlgo();

public:
	static int gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
	static int gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
};


#endif // !CORE_H_
