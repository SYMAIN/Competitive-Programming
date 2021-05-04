#include <iostream>
#include <vector>
#include<algorithm> 

int main()
{
	std::string dir;
	std::string location;
	std::vector<std::string> streets;
	std::vector<std::string> directions;
	streets.push_back("HOME");
	while (1) {
		std::cin >> dir;
		std::cin >> location;

		if (dir == "L") dir = "RIGHT";
		if (dir == "R") dir = "LEFT";

		directions.push_back(dir);

		if (location == "SCHOOL")
			break;
		streets.push_back(location);
	}

	reverse(streets.begin(), streets.end());
	reverse(directions.begin(), directions.end());

	for (int i = 0; i < directions.size(); ++i) {
		if (streets[i] == "HOME")
			std::cout << "Turn " << directions[i] << " into your " << streets[i] << "."<<std::endl;
		else
			std::cout << "Turn " << directions[i] << " onto " << streets[i] << " street."<<std::endl;
	}

	std::cin.get();
}