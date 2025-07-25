#include <iostream>
#include <boost/bind/bind.hpp>
#include <string>
using namespace std;
using namespace boost::placeholders;

class Hello
{
public:
	void say(string name) 
	{ cout << name << " say: hello world!" << endl; }
};

int main()
{
	Hello h;
	auto func = boost::bind(&Hello::say, &h, "zhang san");
	func();
	return 0;
}

