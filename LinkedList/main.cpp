#include <iostream>
#include "LinkList.h"

int main()
{
	//for (;;) {
		LinkList<char>* my_list = new LinkList<char>();

		my_list->push_back('a');
		my_list->push_back('b');
		my_list->push_back('c');
		push_front(&my_list, 'm');

		std::cout << my_list->at(0) << std::endl;
		std::cout << my_list->at(1) << std::endl;
		std::cout << my_list->at(2) << std::endl;

		my_list->Release();
	//}
		
	std::cin.get();

	return 0;
}