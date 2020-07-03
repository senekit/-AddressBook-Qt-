#ifndef ADRESSBOOK_H
#define ADRESSBOOK_H
#include<QWidget>
#include<QLabel>
#include<QLayout>
#include<QGridLayout>
#include<QPushButton>
#include<QMap>
#include<QLineEdit>
#include<QMessageBox>
class AdressBook:public QWidget
{
    Q_OBJECT
public:
    AdressBook(QWidget *parent = 0);
public slots:
    void addBtnContact();
    void editBtnContact();
    void removeBtnContact();
    void findBtnContact();
    void nextContact();
    void previousContact();
private:
    QPushButton *addBtn;
    QPushButton *editBtn;
    QPushButton *removeBtn;
    QPushButton *findBtn;
    QPushButton *next;
    QPushButton *previous;
    QString name;
    QString address;
    QLineEdit *nameLine;
    QLineEdit *addressLine;
    QMap<QString ,QString>map;

};

#endif // ADRESSBOOK_H
