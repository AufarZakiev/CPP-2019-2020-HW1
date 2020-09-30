#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <cstdlib>
#include <ctime>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


class User{
    int age; // private
    QString name; //private
    int id; //private
    static int total_count;
public:
    explicit User(QString name, int age=18){
        if(age>=18){
            this->age=age;
        }else{
            this->age=18;
        }
        srand(time(NULL));
        this->id=rand() % age + 1;
        this->name=name;
        total_count++;
    }
    QString getName(){
        return this->name;
    }
    int getAge(){
        return this->age;
    }
    int getId() {
        return this->id;
    }
    static int getTotalCount(){
        return total_count;
    }
    static std::vector<User> users_;
};

int User::total_count = 0;
std::vector<User> User::users_;

void MainWindow::on_totalPushButton_clicked()
{
    QString total;
    total.setNum(User::getTotalCount());
    QMessageBox msg(QMessageBox::Information, "Total students.", total);
    qDebug() << msg.exec();
}

void MainWindow::on_deletePushButton_clicked()
{
    bool ok;
    int id;
    int flag = 0;
    int i;

    QString str = ui->idLineEdit->text();
    id = str.toInt(&ok, 10);
    for (i = 0; i < User::users_.size(); ++i)
    {
        if (User::users_[i].getId() == id)
        {
            User::users_.erase(User::users_.begin() + i);
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        QMessageBox msg(QMessageBox::Information, "Deleted",
                        "Deleted "+ User::users_[i].getName());
        qDebug() << msg.exec();
    }
    else
    {
        QMessageBox msg1(QMessageBox::Information, "Exeption",
                        "Not finded "+ str);
        qDebug() << msg1.exec();

    }
}

void MainWindow::on_deleteNamePushButton_clicked()
{
    QString name;
    int flag = 0;
    int i;

    QString str = ui->delNameLineEdit->text();
    for (i = 0; i < User::users_.size(); ++i)
    {
        if (User::users_[i].getName().compare(name) == 0)
        {
            User::users_.erase(User::users_.begin() + i);
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        QMessageBox msg(QMessageBox::Information, "Deleted",
                        "Deleted "+ User::users_[i].getName());
        qDebug() << msg.exec();
    }
    else
    {
        QMessageBox msg1(QMessageBox::Information, "Exeption",
                        "Not finded "+ str);
        qDebug() << msg1.exec();

    }
}

void MainWindow::on_submitPushButton_clicked()
{
    qDebug() << "User clicked on submit button";
    // ui->nameLineEdit->setText("Aufar");
    User student(ui->nameLineEdit->text(), ui->ageLineEdit->text().toInt());

    QMessageBox msg(QMessageBox::Information,"New student arrived!",
                    "Hello "+ student.getName() + "!");
    // qDebug() << "Name:" << student.getName();
    // qDebug() << "Age:" << student.getAge();
    qDebug() << msg.exec();
    qDebug() << User::getTotalCount();
    User::users_.push_back(student);
    //qDebug() << "Last student age:" << User::users_.end()->getAge();
    //qDebug() << "Last student name:" << User::users_.end()->getName();
    qDebug() << "Total count:" << User::users_.size();
    qDebug() << "First student name ([0]):" << User::users_[0].getName();
    qDebug() << "First student name (at):" << User::users_.at(0).getName();
    qDebug() << "------------------------";
}
