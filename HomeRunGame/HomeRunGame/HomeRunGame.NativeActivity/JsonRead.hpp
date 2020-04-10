#ifndef ___Class_JsonRead
#define ___Class_JsonRead

#include <string>
#include <vector>

class JsonRead {
public:
	JsonRead(const std::string str_);
	~JsonRead();
	int GetNum() const;
	std::string *GetNo()    const;
	std::string *GetScore() const;
	std::string *GetRank()  const;
	
private:
	void Run();
	void StringSplit();
	void JsonConvert();
	void SaveValue(std::string n, std::string v);

private:
	const std::string str;
	const std::string del;
	std::string json;

	const int maxNum;
	std::string *no;
	int nNum;
	std::string *score;
	int sNum;
	std::string *rank;
	int rNum;
};

#endif // !___Class_JsonRead