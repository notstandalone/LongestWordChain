//Node.h -- Node class interface
//version 00
#ifndef NODE00_H_
#define NODE00_H_

#include <string>

class Node
{
private:
	std::string word;
	char head;
	char tail;
	int length;

public:
	Node(char head, char tail, int length, std::string word);
	Node();
	char getHead();
	char getTail();
	int getLength();
	std::string getWord();
};

#endif // !NODE00_H_
