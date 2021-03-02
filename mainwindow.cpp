#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}
MainWindow::~MainWindow()
{
  delete ui;
}


class User
{
  int age;       // private
  QString name;  // private
  QString name;
  static int total_count;
  static std::vector<User> users_;

public:
  explicit User(QString name, int age = 18)
  {
    if (age >= 18)
    {
      this->age = age;
    }
    else
    {
      this->age = 18;
    }
    explicit User(QString name)
    {
      this->name = name;
      total_count++;
    }

    QString getName()
    {
      return name;
    }
    int getAge()
    {
      return age;

      void add_student(User user)
      {
        users_.push_back(user);
      }
      static int getTotalCount()
      {
        return total_count;

        void delete_student_index(int index)
        {
          users_.erase(index + users_.begin());
        }
        static std::vector<User> users_;

        void delete_student_name(QString name)
        {
          for (int i = 0; i < users_.size(); i++)
          {
            if (name == users_[i].name)
            {
              users_.erase(users_.begin() + i);
            }
          }
        }

        size_t getTotalCount()
        {
          return users_.size();
        }
      };

      int User::total_count = 0;
      std::vector<User> User::users_;
      void MainWindow::on_submitPushButton_clicked()
      {
        qDebug() << "User clicked on submit button";
        // ui->nameLineEdit->setText("Aufar");
        User student(ui->nameLineEdit->text(), ui->ageLineEdit->text().toInt());
        QMessageBox msg(QMessageBox::Information, "New student arrived!", "Hello " + student.getName() + "!");
        // qDebug() << "Name:" << student.getName();
        // qDebug() << "Age:" << student.getAge();
        qDebug() << msg.exec();
        qDebug() << User::getTotalCount();
        User::users_.push_back(student);
        // qDebug() << "Last student age:" << User::users_.end()->getAge();
        // qDebug() << "Last student name:" << User::users_.end()->getName();
        qDebug() << "Total count:" << User::users_.size();
        qDebug() << "First student name ([0]):" << User::users_[0].getName();
        qDebug() << "First student name (at):" << User::users_.at(0).getName();
        qDebug() << "------------------------";
      }