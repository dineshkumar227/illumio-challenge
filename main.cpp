#include <iostream>
#include <map>
#include <fstream>
#include "address.h"

using std::cout;
using std::string;
using std::map;
using std::istream;
using std::ostream;

//TODO: Separate these functions to a different file
void initialize_map(map<Address, Address, std::greater<Address>>& nat_map, istream& input_stream) {
	string line;
	while (getline(input_stream, line)) {
		Address a1(line.substr(0, line.find(":")));
		Address a2(line.substr(line.find(":") + 1, line.length() - 1));
		nat_map.insert(std::make_pair(a1, a2));
	}
}

void output_matches(ostream& output_stream, istream& flow_stream, map<Address, Address, std::greater<Address>> nat_map) {
	string line;
	while (getline(flow_stream, line)) {
		Address to_translate(line);
		bool found_match = false;
		for (auto i = nat_map.begin(); i != nat_map.end(); i++) {
			if(Address::isMatch(i->first, to_translate)) {
				output_stream<<to_translate<<"->"<<i->second;
				found_match = true;
				break;
			}
		}
		if (!found_match)
			output_stream<<"No nat match for "<<to_translate;
		output_stream<<"\n";
	}
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		cout<<"Invalid number of arguments, expected: ./simple_nat nat_file flow_file";
		return -1;
	}

	map<Address, Address, std::greater<Address>> nat_map;
	
	std::ifstream nat_file(argv[1]);
	initialize_map(nat_map, nat_file);
	nat_file.close();

	std::ifstream flow_file(argv[2]);
	std::ofstream out_file("OUTPUT");
	output_matches(out_file, flow_file, nat_map);
	flow_file.close();
	out_file.close();

	return 0;
}
