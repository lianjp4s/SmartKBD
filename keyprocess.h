#ifndef KEYPROCESS_H
#define KEYPROCESS_H

#include <qt_windows.h>

class KeyProcess
{

public:
	KeyProcess();
	~KeyProcess();
private:
	HHOOK hhkLowLevelKybd;

public:
	void startProcess();
};

#endif // KEYPROCESS_H