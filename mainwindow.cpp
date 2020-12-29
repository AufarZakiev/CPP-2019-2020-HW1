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

    static void addStud(User user)
    {
        users.push_back(user);
    }

    static void deleteStudIndex(unsigned int index)
    {
        users.erase(users.begin() + index);
    }

    static void deleteStudName(QString name)
    {
        for (unsigned int i = 0; i < users.size(); i++)
        {
            if (name == users[i].name)
            {
                users.erase(users.begin() + i);
            }
        }
    }

    static size_t getSumOfStud()
    {
        return users.size();
    }

    QString getName(){
        return name;
    }
    int getAge(){
        return age;
    }

    static int getTotalCount()
    {
        return total_count;
    }

    static std::vector<User> users;
};

int User::total_count = 0;
std::vector<User> User::users;


void MainWindow::on_submitPushButton_clicked()
{
    qDebug() << "User clicked on submit button";
    // ui->nameLineEdit->setText("Aufar");
    User student(ui->nameLineEdit->text(), ui->ageLineEdit->text().toInt());

//    QMessageBox msg(QMessageBox::Information,"New student arrived!",
//                    "Hello "+ student.getName() + "!");
    // qDebug() << "Name:" << student.getName();
    // qDebug() << "Age:" << student.getAge();
//    qDebug() << msg.exec();
    qDebug() << User::getTotalCount();
//    User::users.push_back(student);
    //qDebug() << "Last student age:" << User::users_.end()->getAge();
    //qDebug() << "Last student name:" << User::users_.end()->getName();
    qDebug() << "Total count:" << User::users.size();
    qDebug() << "First student name ([0]):" << User::users[0].getName();
    qDebug() << "First student name (at):" << User::users.at(0).getName();
    qDebug() << "------------------------";
}
