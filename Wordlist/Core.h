#pragma once
#ifndef CORE_H_
#define CORE_H_

int gen_chain(char * words[], int len, char * result[]);
int gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
int gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop);

#endif // !CORE_H_
