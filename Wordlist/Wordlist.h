#pragma once
#ifndef WORDLIST_H_

#define WORDLIST_H_

/*静态全局变量，参数表*/
static char opt[5][5] = {
	"-w", "-c", "-r", "-h", "-t"
};


enum
{
	_w,
	_c,
	_r,
	_h,
	_t
};

#endif // !WORDLIST_H_

