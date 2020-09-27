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
    static int totalCount_;
public:
    explicit User(QString name, int age=18){
        if(age>=18){
            this->age_=age;
        }else{
            this->age_=18;
        }
        this->name_=name;
        totalCount_++;
    }
    static bool addUser(User user){
        if(totalCount_ == INT_MAX){
            return false;
        }
        users.push_back(user);
        return true;
    }
    static bool addUser(QString name, int age=18){
        User user(name, age);
        return addUser(user);
    }
    static bool removeUser(int index){
        if (index<totalCount_ && index>=0){
            users.erase(users.begin()+index);
            totalCount_--;
            return true;
        }
        return false;
    }
    static int removeUser(QString name){
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
    static int getTotalCount(){
        return totalCount_;
    }
    static std::vector<User> users;
};

int User::totalCount_ = 0;
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
