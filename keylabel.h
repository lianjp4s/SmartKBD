#ifndef KEYLABEL_H
#define KEYLABEL_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QHBoxLayout>

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>

#include "remapdialog.h"

#include <QMouseEvent>

class KeyLabel : public QLabel
{
	Q_OBJECT
public:
	explicit KeyLabel(int keyID, QWidget *parent = nullptr);

signals:

private:
	int m_keyID;
	int m_width;
	int m_xPos;
	int m_yPos;

	RemapDialog *remapDialog;

public:
	void setLocation(int x, int y, int width);

private slots:
	void mousePressEvent(QMouseEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);

	void on_remapDialog_keymapChanged(int keyval);
};

#endif // KEYLABEL_H
