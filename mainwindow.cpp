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
    static int getTotalCount(){
        return total_count;
    }
    static std::vector<User> users_;

    static void addStudent(User user) {
        User::users_.push_back(user);
    }

    static void deleteByName(QString name) {
        int count = User::getTotalCount();
        for(int i = 0; i < count; i++) {
            if(User::users_[i].name == name){
                User::users_.erase(User::users_.begin() + i);
            }
        }
    }

    static void deleteByIndex(int index) {
        User::users_.erase(User::users_.begin() + index);
    }
};

int User::total_count = 0;
std::vector<User> User::users_;

void MainWindow::on_submitPushButton_clicked()
{
    qDebug() << "User clicked on submit button";

    QString studentName = ui->nameLineEdit->text();
    int studentAge = ui->ageLineEdit->text().toInt();

    if (!studentName.trimmed().isEmpty()) {

        User student(studentName, studentAge);
        QString GreetingMsg = "Hello " + student.getName();

        QMessageBox msg(QMessageBox::Information, "New student arrived !", GreetingMsg);
        msg.exec();

        qDebug() << "Student name: "
                 << student.getName()
                 << "\nStudent age: "
                 << student.getAge();

        qDebug() << student.getTotalCount();
    }
    else {
        QMessageBox msg(QMessageBox::Warning, "Student name", "Please, enter student name");
        msg.exec();
    }

    //qDebug() << "First student name ([0]):" << User::users_[0].getName();
    //qDebug() << "First student name (at):" << User::users_.at(0).getName();
    qDebug() << "------------------------";
}
