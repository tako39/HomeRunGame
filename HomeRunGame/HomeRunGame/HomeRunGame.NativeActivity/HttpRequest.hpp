#ifndef ___Class_HttpRequest
#define ___Class_HttpRequest

#include <string>

class Socket;
class JsonRead;

class HttpRequest {
public:
	enum class Type {
		Ranking = 0,
		Result  = 1,
	};

	HttpRequest(Type type_, const int score_ = 0);
	~HttpRequest();
	bool IsConnect() const;
	int GetNum() const;
	std::string GetNo   (const int i) const;
	std::string GetScore(const int i) const;
	std::string GetRank (const int i) const;

private:
	Socket *const socket;
	bool isConnect;
	int num;
	std::string *no;
	std::string *score;
	std::string *rank;
};

#endif // !___Class_HttpRequest