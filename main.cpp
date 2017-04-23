#include <iostream>
#include <stdlib.h>

#include "seqLinearList.hpp"

int main(){

	cs202::LinearList<int> L;

	L.push_back(21);
	L.push_back(22);

	cs202::LinearList<int>::iterator it(L.begin());

	std::cout<<it;

}