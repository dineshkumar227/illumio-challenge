#include <iostream>
#include <map>
#include <fstream>
#include "address.h"

using std::cout;
using std::string;
using std::map;
using std::ifstream;
using std::ofstream;

int main(int argc, char *argv[]) {
	if (argc != 3) {
		cout<<"Invalid number of arguments, expected: ./simple_nat nat_file flow_file";
		return -1;
	}

	map<Address, Address, std::greater<Address>> nat_map;
	
	ifstream nat_file(argv[1]);
	initialize_map(nat_map, nat_file);
	nat_file.close();

	ifstream flow_file(argv[2]);
	ofstream out_file("OUTPUT");
	output_matches(out_file, flow_file, nat_map);

	return 0;
}
