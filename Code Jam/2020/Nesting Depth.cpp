#include <iostream>
#include <string>
#include <vector>

std::string deleted(std::string newStr) {
	// delete
	std::string result = "";
	int cnt = 2;
	for (int i = 0; i < newStr.size() - 1; i++) {
		char a1 = newStr[i];
		char a2 = newStr[i + 1];

		if (a1 == ')' && a2 == '(') {
			cnt -= 1;
		}
		else if (cnt != 2) {
			cnt = 2;
			continue;
		}
		else {
			result += a1;
		}
	}result += newStr[newStr.size() - 1];
	return result;
}

std::string solve(std::string str) {
	// add p
	std::string newStr = "";
	for (int i = 0; i < str.size(); i++) {
		int n = str[i] - 48;
		
		for (int j = 0; j < n; j++) {
			newStr += "(";
		}
		newStr += str[i];
		for (int j = 0; j < n; j++) {
			newStr += ")";
		}
	}

	// check
	std::string result = newStr;

	while (1) {
	redo:
		result = deleted(result);

		for (int i = 0; i < result.size()-1; i++) {
			char a1 = result[i];
			char a2 = result[i + 1];

			if (a1 == ')' && a2 == '(') {
				goto redo;
			}
		}
		return result;
	}
}

int main() {
	int N;
	std::string str;
	std::cin >> N;
	
	for (int i = 0; i < N; i++) {
		std::cin >> str;
		std::cout << "Case #" << i + 1 << ": " << solve(str) << "\n" ;
	}
}