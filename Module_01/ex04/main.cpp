#include <iostream>
#include <fstream>

int main (int c, char **v) 
{
	(void)c;
	(void)v;
	std::string a("aaaaa");
	std::string a2("bbbbbb");
	std::string b("aaaaasdasdasdfsdfsdfaaaaa");
	// char a[11];
	// a[10] = 0;
	// std::fstream myfile;
	// myfile.open ("example.txt");
	// myfile << "Writing this to a file.\n";
	// while(myfile.read(a,10))
	// {
	// 	// myfile.read();
		
	// 	std::cout << a;
	// }
	// myfile.close();
	size_t pos = b.find(a);
	while ( pos != std::string::npos ) {
		b.erase(pos, a.length());
		b.insert(pos, a2);
		pos = b.find(a);
	}
	std::cout << b << std::endl;
	return 0;
}