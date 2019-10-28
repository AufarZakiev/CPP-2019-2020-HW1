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
private:
    int age_; // private
    QString name_; //private

public:
    static std::vector<User> users_;
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

    static unsigned long getTotalCount(){
        qDebug() << "Сработал метод getTotalCunt()";
        return users_.size();
    }

    static void addStudent(QString name, int age){
        qDebug() << "Сработал метод addStudent(" << name << ", " << age << ");";
        User::users_.push_back(*new User(name, age));
    }

    static void deleteByIndex(int index){
        qDebug() << "Сработал метод deleteByIndex(" << index << ");";
        users_.erase(users_.begin() + index);
    }

    static void deleteByName(QString name){
        qDebug() << "Сработал метод deleteByName(" << name << ");";
        for (unsigned long i = 0; i < users_.size(); i++){
            if (users_[i].getName() == name)
                users_.erase(users_.begin() + i);
        }
    }
};

std::vector<User> User::users_;

void MainWindow::on_submitPushButton_clicked()
{
    qDebug() << "User clicked on submit button";
    QString name = ui->nameLineEdit->text();
    int age = ui->ageLineEdit->text().toInt();
    User::addStudent(name, age);

    QMessageBox msg(QMessageBox::Information,"New student arrived!",
                    "Hello " + User::users_[User::users_.size() - 1].getName() + "!");
    qDebug() << msg.exec();

    qDebug() << "Total count:" << User::getTotalCount();

    qDebug() << "------------------------";
}
