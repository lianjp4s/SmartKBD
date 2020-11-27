#include "remapdialog.h"
#include "keyname.h"
#include "keyprocess.h"
#include <QDebug>

RemapDialog::RemapDialog(QWidget *parent)
	: QDialog(parent)
{
	settingKeyLEdit = new QLineEdit;
	settingKeyLEdit->setDisabled(true);
	tipLbl = new QLabel(tr("按下想要设置成的键!"));
	mainLyt = new QGridLayout;
	mainLyt->addWidget(tipLbl, 0, 0);
	mainLyt->addWidget(settingKeyLEdit, 1, 0);
	this->setLayout(mainLyt);
}


void RemapDialog::keyPressEvent(QKeyEvent *event)
{
	settingKeyLEdit->setText(KeyNameList.at(lKeyPrecessGetVKCode()));
}
