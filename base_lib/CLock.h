#ifndef CLOCK_H
#define CLOCK_H

namespace NCommon
{

class CMutex;

class CLock
{
public:
	CLock(CMutex& rMutex);
	int Success;
	
	~CLock();

private:
    // 禁止拷贝、赋值
	CLock();
	CLock(const CLock&);
	CLock& operator =(const CLock&);
	
private:
	CMutex& m_rMutex;
};

}

#endif // CLOCK_H