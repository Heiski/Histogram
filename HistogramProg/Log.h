#ifndef LOGGER_H
#define LOGGER_H

#include <vector>
#include <iostream>


class Logger
{

public:
		Logger();
		/*
		* This Might lead memory overflow if not somehow limited how to use
		* In this case I think it doesnt matter cause data size shuold be small
		* In proper applications 
		* 		
		*/
		std::vector<int> vec;


};

#endif