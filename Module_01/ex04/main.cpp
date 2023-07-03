#include <iostream>
#include <fstream>

int main (int c, char **v) 
{
	(void)c;
	(void)v;
	std::string b;
	char a[11];
	a[10] = 0;
	std::fstream myfile;
	myfile.open ("example.txt");
	// myfile << "Writing this to a file.\n";
	while(myfile.read(a,10))
	{
		// myfile.read();
		
		std::cout << a;
	}
	myfile.close();
	return 0;
}