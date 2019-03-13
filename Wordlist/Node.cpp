#include <string>

#include "pch.h"
#include "Node.h"

Node::Node(char head, char tail, int length, std::string word)
{
	this->head = head;
	this->tail = tail;
	this->length = length;
	this->word = word;
}

Node::Node()
{
	head = '\0';
	tail = '\0';
	length = 0;
	word = "";
}

char Node::getHead()
{
	return head;
}

char Node::getTail()
{
	return tail;
}

int Node::getLength()
{
	return length;
}

std::string Node::getWord()
{
	return word;
}
