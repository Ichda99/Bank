#include <iostream>
#include "clsBankClient.h"

using namespace std;

int main()
{
	clsBankClient Client1 = clsBankClient::Find("A101");
	Client1.Print();

	clsBankClient Client2 = clsBankClient::Find("A102", "1234");
	Client2.Print();


	system("pause>0");
	return 0;
}