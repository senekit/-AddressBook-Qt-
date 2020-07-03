#include "adressbook.h"
#include<QWidget>
AdressBook::AdressBook(QWidget *parent)
    :QWidget(parent)
{

    QGridLayout *mainLayout = new QGridLayout;
    QVBoxLayout *buttonLayout = new QVBoxLayout;
    QVBoxLayout *buttonLayout2= new QVBoxLayout;
    nameLine = new QLineEdit;
    addressLine = new QLineEdit;
    QLabel *nameLabel = new QLabel(tr("name"));
    QLabel *addressLabel = new QLabel(tr("address"));
    addBtn = new QPushButton("ADD");
    addBtn ->show();
    next = new QPushButton("NEXT");
    next->show();
    editBtn = new QPushButton("Edit");
    editBtn->show();
    removeBtn = new QPushButton("REMOVE");
    removeBtn->show();
    findBtn = new QPushButton("FIND");
    findBtn->show();
    previous = new QPushButton ("PREVIOUS");
    previous->show();



    buttonLayout->addWidget(addBtn);
    buttonLayout->addWidget(next);
    buttonLayout2->addWidget(editBtn);
    buttonLayout2->addWidget(removeBtn);
    buttonLayout2->addWidget(findBtn);
    mainLayout->addWidget(nameLabel,0,0);
    mainLayout->addWidget(nameLine,0,1);
    mainLayout->addWidget(addressLabel,1,0);
    mainLayout->addWidget(addressLine,1,1);
    mainLayout->addWidget(addBtn,0,2,1,1);
    mainLayout->addWidget(findBtn,1,2,1,1);
    mainLayout->addWidget(editBtn,0,3,1,1);
    mainLayout->addWidget(removeBtn,1,3,1,1);
    mainLayout->addWidget(next,0,4,1,1);
    mainLayout->addWidget(previous,1,4,1,1);
    setLayout(mainLayout);
    connect(addBtn,SIGNAL(clicked()),this,SLOT(addBtnContact()));
    connect(next,SIGNAL(clicked()),this,SLOT(nextContact()));
    connect(editBtn,SIGNAL(clicked()),this,SLOT(editBtnContact()));
    connect(findBtn,SIGNAL(clicked()),this,SLOT(findBtnContact()));
    connect(removeBtn,SIGNAL(clicked()),this,SLOT(removeBtnContact()));
    connect(previous,SIGNAL(clicked()),this,SLOT(previousContact()));
}

void AdressBook::previousContact()
{
    QString name1 = nameLine->text();
    QString name2 = addressLine->text();
    QMap<QString,QString>::iterator i= map.end();
   // if(name1!=""&&name2!="")
    for(i;i!=map.begin();i--)
    if(name1==i.key())
    {
        i--;
        nameLine->setText(i.key());
        addressLine->setText(i.value());
        return;
    }
    i=map.begin();
    nameLine->setText(i.key());
    addressLine->setText(i.value());
}

void AdressBook::addBtnContact()
{
    QString name1 = nameLine->text();
    QString name2 = addressLine->text();
    if(name1==""||name2=="")
    {QMessageBox::information(this,tr("无效输入"),tr("请再次输入"));return;}
    QMap<QString,QString>::iterator i;
    for(i = map.begin();i!=map.end();i++)
    {
        QString temp = i.key();
        if(temp==name1)
        {
            QMessageBox::information(this,tr("该成员已存在"),tr("请再次输入"));
            nameLine->clear();
            addressLine->clear();
        }
    }
    map.insert(name1,name2);
    QMessageBox::information(this,tr("成功输入"),tr("请再次操作"));
    nameLine->clear();
    addressLine->clear();
    return;
}

void AdressBook::nextContact()
{
    QString name1 = nameLine->text();
    QString name2 = addressLine->text();
    QMap<QString,QString>::iterator i= map.begin();
   // if(name1!=""&&name2!="")
    for(i;i!=map.end();i++)
    if(name1==i.key())
    {
        i++;
        nameLine->setText(i.key());
        addressLine->setText(i.value());
        return;
    }
    i=map.begin();
    nameLine->setText(i.key());
    addressLine->setText(i.value());
}

void AdressBook::editBtnContact()
{
    QString name1 = nameLine->text();
    QString name2 = addressLine->text();
    map.remove(name1);
    map.insert(name1,name2);
    QMessageBox::information(this,tr("修改成功"),tr("请继续操作"));
    nameLine->clear();
    addressLine->clear();
}

void AdressBook::removeBtnContact()
{
    QString name1 = nameLine->text();
    map.remove(name1);
    QMessageBox::information(this,tr("删除成功"),tr("已成功删除%1").arg(name1));
    nameLine->clear();
    addressLine->clear();
}

void AdressBook::findBtnContact()
{
    QString name1 = nameLine->text();
    if(!map.contains(name1))
        QMessageBox::information(this,tr("查找失败"),tr("未输入%1").arg(name1));
    else
    {
        QString name2 = map.value(name1);
        addressLine->setText(name2);
    }
}















