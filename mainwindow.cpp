#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>


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
    int age_; // private
    QString name_; //private
public:
    explicit User(QString name, int age=18){
        if(age>=18){
            this->age_=age;
        }else{
            this->age_=18;
        }
        this->name_=name;
    }
    QString getName(){
        return name_;
    }
    int getAge(){
        return age_;
    }

private:    static std::vector<User> users_;

public:
    static void deleteByIndex(int index){
        User::users_.erase(User::users_.begin()+index);
    }

    static void deleteByName(QString nameDel){
        for (int i=0; i < User::getTotalCount(); i++) {
            if (User::users_[i].getName()==nameDel)
            {
                User::users_.erase(User::users_.begin()+i);
                break;
            }
        }
    }

    static int getTotalCount(){
        return User::users_.size();
    }

    static void addStudent(QString name, int age){
        User student(name, age);
        User::users_.push_back(student);
    }
};

std::vector<User> User::users_;

void MainWindow::on_submitPushButton_clicked()
{
    qDebug() << "User added the student";

    //User student(ui->nameLineEdit->text(), ui->ageLineEdit->text().toInt());
    //QMessageBox msg(QMessageBox::Information,"New student arrived!",
    //                "Hello, "+ student.getName() + "!");
    //qDebug() << msg.exec();
    //User::users_.push_back(student);
    QString name = ui->nameLineEdit->text();
    int age = ui->ageLineEdit->text().toInt();
    User::addStudent(name, age);

    qDebug() << "------------------------";
}

void MainWindow::on_deleteByIndex_clicked()
{
    qDebug() << "User deleted the student by index";

    int index(ui->indexEditLine->text().toInt());
    //User::users_.erase(User::users_.begin()+index);
    for (int i = 0; i < User::getTotalCount(); i++)
        if (index == i)
        {
            User::deleteByIndex(i);
            break;
        }

    qDebug() << "------------------------";
}

void MainWindow::on_deleteByName_clicked()
{
    qDebug() << "User deleted student by name";

    QString nameDel(ui->nameEditLineDel->text());
    User::deleteByName(nameDel);

    qDebug() << "------------------------";
}

void MainWindow::on_totalCount_clicked()
{
    qDebug() << "User got the total count";

    //qDebug() << User::users_.size();
    qDebug() << User::getTotalCount();

    qDebug() << "------------------------";
}
