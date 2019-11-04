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
    int age;
    QString name;
    //static int total_count;
    static std::vector<User> users_;
public:
    explicit User(QString name, int age=18){
        if(age>=18){
            this->age=age;
        }else{
            this->age=18;
        }
        this->name=name;
    }
    QString getName(){
        return name;
    }
    int getAge(){
        return age;
    }
    
    static void addStudent(User user){
        users_.push_back(user);
    }
    
    static long TotalCount(){
        return users_.size();
    }
    
    static void delStudent(long index){
        users_.erase(users_.begin()+ index);
    }
    
    static void delStudent(QString name){
        long index = -1;
        for (long i = 0 ; i < users_.size();i++)
        {
            if (users_.at(i).getName() == name)
            index = i;
        }
        if (index != -1){
            users_.erase(users_.begin()+ index);
            
        } else{
            qDebug() << "User is not found";
        }
        }
};

std::vector<User> User::users_;

void MainWindow::on_submitPushButton_clicked()
{
    qDebug() << "User clicked on submit button";
    // ui->nameLineEdit->setText("Aufar");
    User student(ui->nameLineEdit->text(), ui->ageLineEdit->text().toInt());
    User::addStudent(student);
    User::delStudent(0);
    qDebug() << User::TotalCount();
    qDebug() << "------------------------";

}

