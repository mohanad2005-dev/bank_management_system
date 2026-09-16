#include <iostream>
#include "clsLoginScreen.h"
using namespace std;

template <class t> class Headd
{
	t x;

public:

	Headd(t f)
	{
		x = f;
	}

	t Print()
	{
		return x;
	}
};

int main()
{
	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
			break;
	}

	system("pause > 0");

	return 0;
}
