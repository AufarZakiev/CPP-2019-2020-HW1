#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <vector>

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
    static int total_count_;

public:
    explicit User(QString name, int age=18){
        if(age >= 18){
            this->age_=age;
        }
        else{
            this->age_=18;
        }
        this->name_=name;
        total_count_++;
    }

    static void addStudents(User new_user){
        users_.push_back(new_user);
    }

    static size_t getNum(){
        return users_.size();
    }

    static void deleteStudentByNumber(int num){
        users_.erase(users_.begin() + num);
    }

    static void deleteStudentByName(QString name){
        for(unsigned int i = 0; i < users_.size(); i++) {
            if(users_[i].getName() == name){
                users_.erase(users_.begin() + i);
            }
            else{
                qDebug() << "Nothing happened!";
            }
        }
    }

    QString getName(){
        return name_;
    }

    int getAge(){
        return age_;
    }

    static int getTotalCount(){
        return total_count_;
    }

    static std::vector<User> users_;
};

int User::total_count_ = 0;
std::vector<User> User::users_;

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
