#include "CUdp.h"
#include "../base_lib/MacroDefine.h"
#include "../base_lib/ErrorCode.h"


using namespace NCommon;
using namespace NErrorCode;

namespace NConnect
{

	CUdp::CUdp(const char* ip, const int port) : CSocket(ip, port)
	{
	}

	CUdp::~CUdp()
	{
	}

	int CUdp::create(int listenNum)
	{
		int rc = open(SOCK_DGRAM);  // udp连接socket
		if (rc != Success)
		{
			return rc;
		}

		rc = setNoBlock();
		if (rc != Success)
		{
			return rc;
		}

		rc = bind();

		return rc;
	}

	void CUdp::destroy()
	{
		close();
	}

	size_t CUdp::recvFrom(void *buf, size_t len, struct sockaddr *src_addr, socklen_t *addrlen)
	{
		return ::recvfrom(m_fd, buf, len, 0, src_addr, addrlen);
	}

	size_t CUdp::sendTo(const void *buf, size_t len, const struct sockaddr *dest_addr, socklen_t addrlen)
	{
		return ::sendto(m_fd, buf, len, 0, dest_addr, addrlen);
	}

}
