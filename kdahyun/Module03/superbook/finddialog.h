#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QPushButton;
QT_END_NAMESPACE

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    FindDialog(QWidget *parent = 0);

private:
    QPushButton *findButton;
    QLineEdit *lineEdit;
    QString findText;
};

#endif