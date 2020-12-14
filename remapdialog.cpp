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
	mainLyt->addWidget(tipLbl, 0, 0, 1, 3);
	mainLyt->addWidget(settingKeyLEdit, 1, 0, 1, 3);
	QPushButton *cancelBtn;
	okBtn = new QPushButton(tr("确定"));
	cancelBtn = new QPushButton(tr("取消"));
	mainLyt->addWidget(okBtn, 2, 1);
	mainLyt->addWidget(cancelBtn, 2, 2);
	this->setLayout(mainLyt);

	connect(okBtn, &QPushButton::clicked, this, &RemapDialog::on_okBtn_clicked);
	connect(cancelBtn, &QPushButton::clicked, this, &RemapDialog::on_cancelBtn_clicked);
}


void RemapDialog::on_okBtn_clicked()
{
	emit keymapChanged(destKey);
	this->close();
}

void RemapDialog::on_cancelBtn_clicked()
{
	this->close();
}

void RemapDialog::keyPressEvent(QKeyEvent *event)
{
	destKey = lKeyProcessGetVKCode();
	settingKeyLEdit->setText(KeyNameList.at(destKey));
}

void RemapDialog::showEvent(QShowEvent *event)
{
	settingKeyLEdit->setText(KeyNameList.at(destKey));
}

void RemapDialog::setDefaultKey(int keyval)
{
	destKey = keyval;
}
