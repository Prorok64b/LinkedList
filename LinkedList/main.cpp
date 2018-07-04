#include <iostream>
#include "LinkList.h"

int main()
{
	LinkList<char>* my_list = new LinkList<char>();

	my_list->push_back('a');
	my_list->push_back('b');
	my_list->push_back('c');

	std::cout << my_list->at(0) << std::endl;
	std::cout << my_list->at(1) << std::endl;
	std::cout << my_list->at(7) << std::endl;

	delete my_list;

	std::cin.get();

	return 0;
}