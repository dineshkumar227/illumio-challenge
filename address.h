#include<string>
#include<fstream>

class Address {
	std::string ip;
	std::string port;
	
	public:
	Address(std::string a);

	friend bool operator>(const Address& a, const Address& b);
	friend bool operator<(const Address& a, const Address& b);
	friend std::ostream& operator<<(std::ostream& os, const Address& a);
	static bool isMatch(Address a, Address b);
}
