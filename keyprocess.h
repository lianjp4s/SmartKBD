#ifndef KEYPROCESS_H
#define KEYPROCESS_H

#include <qt_windows.h>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>

int lKeyProcessGetVKCode();

class KeyProcess
{

public:
	KeyProcess();
	~KeyProcess();
private:
	HHOOK hhkLowLevelKybd;
	void refreshKeyMap();

public:
	void startProcess();
};

#endif // KEYPROCESS_H
