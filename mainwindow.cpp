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
    int age; // private
    QString name; //private
    static int total_count;
public:
    explicit User(QString name, int age=18){
        if(age>=18){
            this->age=age;
        }else{
            this->age=18;
        }
        this->name=name;
        total_count++;
    }
    QString getName(){
        return name;
    }
    int getAge(){
        return age;
    }

    static std::vector<User> users_;

public:
    void deleteByIndex(int index){
        User::users_.erase(User::users_.begin()+index);
    }

    void deleteByName(int index){
        User::users_.erase(User::users_.begin()+index);
    }

    int getTotalCount(){
        return User::users_.size();
    }

    void addStudent(QString name, int age){
        User student(name, age);
        User::users_.push_back(student);
    }
};

int User::total_count = 0;
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
    User::users_[User::users_.size()].addStudent(name, age);

    qDebug() << "------------------------";
}

void MainWindow::on_deleteByIndex_clicked()
{
    qDebug() << "User deleted the student by index";

    int index(ui->indexEditLine->text().toInt());
    //User::users_.erase(User::users_.begin()+index);
    for (int i = 0; i < User::users_.size(); i++)
        if (index == i)
        {
            User::users_[i].deleteByIndex(i);
            break;
        }

    qDebug() << "------------------------";
}

void MainWindow::on_deleteByName_clicked()
{
    qDebug() << "User deleted student by name";

    QString nameDel(ui->nameEditLineDel->text());
    for (int i=0; i < User::users_.size(); i++) {
        if (User::users_[i].getName()==nameDel)
        {
            User::users_[i].deleteByName(i);
            break;
        }
    }

    qDebug() << "------------------------";
}

void MainWindow::on_totalCount_clicked()
{
    qDebug() << "User got the total count";

    //qDebug() << User::users_.size();
    qDebug() << User::users_[0].getTotalCount();

    qDebug() << "------------------------";
}
