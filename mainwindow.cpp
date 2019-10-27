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
    static std::vector<User> users_;


public:

    static void addStudent(User user){
        users_.push_back(user);
    }
    static void removeStudentByIndex(int index){
        std::vector<User>::iterator iterator_ = users_.begin();
        if(index < users_.size())
        users_.erase(iterator_ + index);
        users_.shrink_to_fit();
    }
    static bool removeByName(QString studentName){
        std::vector<User>::iterator iterator_= users_.begin();
        while(iterator_ != users_.end()){
            if( (*iterator_).getName() == studentName ){
                users_.erase(iterator_);
                users_.shrink_to_fit();
                return true;
            }
            iterator_++;
        }
        return false;
    }

   static  int getStudentListSize(){
        return users_.size();
    }


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

};

int User::total_count = 0;
std::vector<User> User::users_;

void MainWindow::on_submitPushButton_clicked()
{
    User a("a"), b("b"), c("c");
    User::addStudent(a);
    qDebug() << User::getStudentListSize();
    User::addStudent(b);
    qDebug() << User::getStudentListSize();
    User::addStudent(c);

    qDebug() << User::getStudentListSize();

    User::removeByName("c");
    qDebug() << User::getStudentListSize();

    User::removeStudentByIndex(0);
    qDebug() << User::getStudentListSize();



    /*qDebug() << "User clicked on submit button";
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
*/
}
