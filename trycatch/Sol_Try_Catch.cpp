#include <iostream>


bool simulate(int input1, bool input2, bool input3, bool input4) throw(int)
{
	bool interm_result = false;

	if (input1 < 0 || input1 > 1)
	{
		throw(-1);
	}
	else
	{
		bool y = (bool)input1;
		interm_result = input2 && input3;
		interm_result = interm_result || input4;
		interm_result = interm_result && y;
	}

    return interm_result;
}


int main()
{
	std::cout << "1:" << simulate(1, false, false, true) << std::endl;
	try
	{
		std::cout << "2:" << simulate(-1, false, false, true) << std::endl;
	}
	catch (int e)
	{
		std::cout << "exception caught while calling simulate with error:" << e << std::endl;
	}	
}