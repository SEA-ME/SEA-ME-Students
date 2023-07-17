
#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QLineEdit;
QT_END_NAMESPACE

//! [0]
class FindDialog : public QDialog
{
    Q_OBJECT

public:
    FindDialog(QWidget *parent = 0);
    QLineEdit *nameText;

private:
    QLabel *findLabel;
    QPushButton *findButton;
};
//! [0]

#endif // ADDDIALOG_H