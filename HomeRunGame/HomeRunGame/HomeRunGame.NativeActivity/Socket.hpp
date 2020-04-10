#ifndef ___Class_Socket
#define ___Class_Socket

#include <string>

class HttpRequest;

class Socket {
public:
	Socket(const int type, const int score_);
	~Socket();
	bool Run();
	std::string GetResponse() const;

private:
	bool MakeSocket();
	bool Connetion();
	bool Write();
	bool Read();
	void Close();
	bool Write_Title();
	bool Write_Result();

private:
	const int type;
	const char *httpPath;
	const char *httpHost;
	const int port;
	const int timeOut;
	int sock;
	char buf[2048];
	unsigned int **addrptr;
	int score;
	std::string response;
};

#endif // !___Class_Socket