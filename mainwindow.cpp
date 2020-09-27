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
    int age_;
    QString name_;
public:
    explicit User(QString name, int age=18){
        if(age>=18){
            this->age_=age;
        }else{
            this->age_=18;
        }
        this->name_=name;
    }
    static void addUser(User user){
        users.push_back(user);
    }
    static void addUser(QString name, int age=18){
        User user(name, age);
        addUser(user);
    }
    static bool removeUser(unsigned long index){
        if (index<getTotalCount() && index>=0){
            users.erase(users.begin()+index);
            return true;
        }
        return false;
    }
    static unsigned long removeUser(QString name){
        int erased = 0;
        for(auto i=users.begin(); i<users.end(); i++){
            if(i->name_ == name){
                users.erase(i);
                erased++;
            }
        }
        return erased;
    }
    QString getName(){
        return name_;
    }
    int getAge(){
        return age_;
    }
    static unsigned long getTotalCount(){
        return users.size();
    }
    static std::vector<User> users;
};

std::vector<User> User::users;

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
    User::users.push_back(student);
    //qDebug() << "Last student age:" << User::users_.end()->getAge();
    //qDebug() << "Last student name:" << User::users_.end()->getName();
    qDebug() << "Total count:" << User::users.size();
    qDebug() << "First student name ([0]):" << User::users[0].getName();
    qDebug() << "First student name (at):" << User::users.at(0).getName();
    qDebug() << "------------------------";
}
