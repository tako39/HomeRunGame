#include "HttpRequest.hpp"
#include "Socket.hpp"
#include "JsonRead.hpp"

HttpRequest::HttpRequest(Type type_, const int score_) :
	socket(new Socket((int)type_, score_)),
	isConnect(false),
	num(0)
{
	if (socket->Run()) {
		isConnect = true;
		
		JsonRead *jsonRead = new JsonRead(socket->GetResponse());
		
		num = jsonRead->GetNum();
		for (int i = 0; i < num; i++) {
			no	  = jsonRead->GetNo();
			score = jsonRead->GetScore();
			rank  = jsonRead->GetRank();
		}

		delete jsonRead;
	}
}

HttpRequest::~HttpRequest() {
	delete socket;
}

bool HttpRequest::IsConnect() const {
	return isConnect;
}

int HttpRequest::GetNum() const {
	return num;
}

std::string HttpRequest::GetNo(const int i) const {
	if (!isConnect) return "";
	if (!(0 <= i && i < num)) return "";
	return no[i];
}

std::string HttpRequest::GetScore(const int i) const {
	if (!isConnect) return "";
	if (!(0 <= i && i < num)) return "";
	return score[i];
}

std::string HttpRequest::GetRank(const int i) const {
	if (!isConnect) return "";
	if (!(0 <= i && i < num)) return "";
	return rank[i];
}