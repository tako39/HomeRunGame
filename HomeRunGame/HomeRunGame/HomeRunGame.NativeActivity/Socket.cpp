#include "Socket.hpp"
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

Socket::Socket(const int type_, const int score_) :
	type(type_),
	httpPath("/ranking.php"),
	httpHost("192.168.1.12"),
	port(80),
	timeOut(3),
	score(score_)
{
	
}

Socket::~Socket() {
	
}

bool Socket::Run() {
	if (!MakeSocket()) {
		Close();
		return false;
	}
	if (!Connetion()) {
		Close();
		return false;
	}
	if (!Write()) {
		Close();
		return false;
	}
	if (!Read()) {
		Close();
		return false;
	}
	Close();
	return true;
}

std::string Socket::GetResponse() const {
	return response;
}

bool Socket::MakeSocket() {
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		return false;
	}
	return true;
}

bool Socket::Connetion() {
	struct sockaddr_in addr;
	struct timeval tv;
	int result;

	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(httpHost);

	tv.tv_sec = timeOut;
	tv.tv_usec = 0;

	result = setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv));
	if (result < 0) return false;

	if (addr.sin_addr.s_addr == 0xffffffff) {
		struct hostent *host;

		host = gethostbyname(httpHost);
		if (host == NULL) {
			return false;
		}

		addrptr = (unsigned int **)host->h_addr_list;

		while (*addrptr != NULL) {
			addr.sin_addr.s_addr = *(*addrptr);

			if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
				break;
			}

			addrptr++;
		}

		if (*addrptr == NULL) {
			return false;
		}
	}
	else {
		if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) != 0) {
			return false;
		}
	}

	return true;
}

bool Socket::Write() {
	if (type == 0  /*RequestType::Ranking*/) {
		return Write_Title();
	}
	else if (type == 1  /*RequestType::Result*/) {
		return Write_Result();
	}
	return false;
}

bool Socket::Write_Title() {
	memset(buf, 0, sizeof(buf));

	snprintf(buf, sizeof(buf), "POST %s HTTP/1.1\r\n", httpPath);
	int result = write(sock, buf, (int)strlen(buf));
	if (result < 0) return false;

	snprintf(buf, sizeof(buf), "Host: %s:%d\r\n", httpHost, port);
	result = write(sock, buf, (int)strlen(buf));
	if (result < 0) return false;

	snprintf(buf, sizeof(buf), "Content-Type: application/x-www-form-urlencoded; charset=UTF-8\r\n");
	result = write(sock, buf, (int)strlen(buf));
	if (result < 0) return false;

	snprintf(buf, sizeof(buf), "Content-Length: 0\r\n");
	result = write(sock, buf, (int)strlen(buf));
	if (result < 0) return false;

	snprintf(buf, sizeof(buf), "Connection: Close\r\n");
	result = write(sock, buf, (int)strlen(buf));
	if (result < 0) return false;

	snprintf(buf, sizeof(buf), "\r\n");
	result = write(sock, buf, (int)strlen(buf));
	if (result < 0) return false;

	return true;
}

bool Socket::Write_Result() {
	char scoreStr[20];
	snprintf(scoreStr, sizeof(scoreStr), "score=%d", score);

	memset(buf, 0, sizeof(buf));

	snprintf(buf, sizeof(buf), "POST %s HTTP/1.1\r\n", httpPath);
	int result = write(sock, buf, (int)strlen(buf));
	if (result < 0) return false;

	snprintf(buf, sizeof(buf), "Host: %s:%d\r\n", httpHost, port);
	result = write(sock, buf, (int)strlen(buf));
	if (result < 0) return false;

	snprintf(buf, sizeof(buf), "Content-Type: application/x-www-form-urlencoded; charset=UTF-8\r\n");
	result = write(sock, buf, (int)strlen(buf));
	if (result < 0) return false;

	snprintf(buf, sizeof(buf), "Content-Length: %d\r\n", (int)strlen(scoreStr));
	result = write(sock, buf, (int)strlen(buf));
	if (result < 0) return false;

	snprintf(buf, sizeof(buf), "Connection: Close\r\n");
	result = write(sock, buf, (int)strlen(buf));
	if (result < 0) return false;

	snprintf(buf, sizeof(buf), "\r\n");
	result = write(sock, buf, (int)strlen(buf));
	if (result < 0) return false;

	snprintf(buf, sizeof(buf), "%s\r\n", scoreStr);
	result = write(sock, buf, (int)strlen(buf));
	if (result < 0) return false;

	return true;
}

bool Socket::Read() {
	int result = 1;
	response = "";
	std::string tmp;
	while (result > 0) {
		memset(buf, 0, sizeof(buf));
		result = read(sock, buf, sizeof(buf));
		if (result < 0) {
			return false;
		}
		tmp = buf;
		response += tmp;
	}
	return true;
}

void Socket::Close() {
	close(sock);
}