#include "mainwindow.h"
#include "qstyle.h"
#include "ui_mainwindow.h"

#include <QSqlTableModel>
#include <QSplitter>
#include <QPushButton>
#include <QWidget>
#include <QKeyEvent>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QTimer>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    b_push_show = false;
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_StyledBackground);

    //this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    //this->setAttribute(Qt::WA_TranslucentBackground);
    //this->setStyleSheet("QWidget{background-color:rgb(255, 251, 240);border-radius:50px 50px;}");
    connect(ui->toolButton,&QToolButton::clicked,this,&MainWindow::on_toolButton_clicked);

    //ui->splitter->setStretchFactor(0,10);
    //ui->splitter->setStretchFactor(1,80);
    //setWidget(splitter);

    ui->widget_3->move(-200,9);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

   if(event->button() == Qt::LeftButton){
       this->p_reltvpos = event->pos();
       b_move = true;
   }
   return QWidget::mousePressEvent(event);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
  if(b_move){
      move(event->globalPos()-p_reltvpos);
  }
  return QWidget::mouseMoveEvent(event);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
   b_move = false;
   return QWidget::mouseReleaseEvent(event);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolButton_clicked()
{
    this->close();
}

void MainWindow::receiveLogin()
{
   this->show();
}


void MainWindow::on_toolButton_9_clicked()
{
    if(!b_push_show){
        QPropertyAnimation * animation_ = new QPropertyAnimation(ui->widget_3,"geometry");
        animation_->setDuration(300);
        animation_->setStartValue(ui->widget_3->geometry());
        qDebug()<<ui->widget_3->pos().x();
        animation_->setEndValue(QRect(20,ui->widget_3->pos().y(),ui->widget_3->width(), ui->widget_3->height()));
        animation_->start();}
    else{
        QPropertyAnimation * animation_ = new QPropertyAnimation(ui->widget_3,"geometry");
        animation_->setDuration(300);
        animation_->setStartValue(ui->widget_3->geometry());
        animation_->setEndValue(QRect(-200,ui->widget_3->pos().y(),ui->widget_3->width(), ui->widget_3->height()));
        animation_->start();}
    QTimer::singleShot(300,this,[=](){
        b_push_show?ui->toolButton_9->setProperty("toolbutton","2") : ui->toolButton_9->setProperty("toolbutton","3");
        style()->polish(ui->toolButton_9);
        if(!b_push_show)
            b_push_show = true;
        else{
            b_push_show = false;
        }
    });
}

