#include "address.h"

Address::Address(std::string a) {
	std::string delim = ":";
	ip = a.substr(0, a.find(delim));
	port = a.substr(a.find(delim) + 1, a.length() - 1);
}

bool operator>(const Address& a, const Address& b) {
	return (a.ip + a.port) > (b.ip + b.port);
}
bool operator<(const Address& a, const Address& b) {
	return (a.ip + a.port) < (b.ip + b.port);
}

std::ostream& operator<<(std::ostream& os, const Address& a) {
	os<<a.ip<<":"<<a.port;
	return os;
}

bool Address::isMatch(const Address& a, const Address& b) {
	//TODO: Make a algorithm that also supports addresses like 192.*.1.1:20
	
	if(a.port == "*" || a.port == b.port)
		if(a.ip == "*" || a.ip == b.ip)
			return true;
	return false;
}
