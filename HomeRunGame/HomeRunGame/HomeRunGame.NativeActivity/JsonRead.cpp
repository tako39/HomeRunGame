#include "JsonRead.hpp"
#include "DxLib.h"

JsonRead::JsonRead(const std::string str_) : 
	str		(str_),
	del		("\r\n\r\n"),
	json	(""),
	maxNum	(10),
	no		(new std::string[maxNum]()),
	nNum	(0),
	score	(new std::string[maxNum]()),
	sNum(0),
	rank	(new std::string[maxNum]()),
	rNum	(0)
{
	Run();
}

JsonRead::~JsonRead() {
	
}

int JsonRead::GetNum() const {
	int num = std::min(nNum, std::min(sNum, rNum));
	return num;
}

std::string *JsonRead::GetNo() const {
	return no;
}

std::string *JsonRead::GetScore() const {
	return score;
}

std::string *JsonRead::GetRank() const {
	return rank;
}

void JsonRead::Run() {
	StringSplit();
	JsonConvert();
}

void JsonRead::StringSplit() {
	int first = 0;
	int last = str.find_first_of(del);

	std::vector<std::string> res;
	while (first < str.size()) {
		std::string subStr(str, first, last - first);
		res.push_back(subStr);
		
		first = last + 1;
		last = str.find_first_of(del, first);
		if (last == std::string::npos) {
			last = str.size();
		}
	}

	int size = (int)res.size();
	if (size <= 0) return;

	json = res[size - 1];
}

void JsonRead::JsonConvert() {
	int end = (int)json.size() - 1;
	if (end < 0) return;

	std::string name = "";
	std::string value = "";
	bool isStart = false;
	bool isEven = true;
	for (int i = 0; i < (int)json.size(); i++) {
		char c = json[i];
		if (isStart == false) {
			if (c == '"') {
				isStart = true;
			}
		}
		else {
			if (c == '"') {
				if (isEven) {
				}
				else {
					SaveValue(name, value);
					name = "";
					value = "";
				}
				isStart = false;
				isEven = !isEven;
			}
			else {
				if (isEven) {
					name += c;
				}
				else {
					value += c;
				}
			}
		}
	}
}

void JsonRead::SaveValue(std::string n, std::string v) {
	if (n == "No") {
		if (nNum < maxNum) no[nNum] = v;
		nNum++;
	}
	else if (n == "Score") {
		if (sNum < maxNum) score[sNum] = v;
		sNum++;
	}
	else if (n == "Rank") {
		if (rNum < maxNum) rank[rNum] = v;
		rNum++;
	}
}