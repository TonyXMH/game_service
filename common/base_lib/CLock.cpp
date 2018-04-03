#include "CLock.h"
#include "CMutex.h"

namespace NCommon
{

CLock::CLock(CMutex& rMutex) : m_rMutex(rMutex)
{
	Success = m_rMutex.lock();
}

CLock::~CLock()
{
	if (Success == 0) m_rMutex.unLock();
}


}