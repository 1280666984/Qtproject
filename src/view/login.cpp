#include "login.h"
#include "ui_login.h"
#include "control.h"
#include <QKeyEvent>
#include <QLineEdit>
#include <QMessageBox>
#include <QMouseEvent>
#include <QMovie>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QString>
#include <QTimer>



Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    //无边框
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_StyledBackground);
    //this->setAttribute(Qt::WA_TranslucentBackground);

    //窗口判断移动变量初始化
    m_move = false;
    //单例数据库获取
    //_m    = MySql::getmysql();

    //动画初始化
    QMovie * movie =new QMovie(this);
    movie->setFileName(":/qrc/lib1.gif");
    movie->start();
    ui->label->setMovie(movie);


    //账号的的添加列表问题
    ui->comboBox->setEditable(true);
    lineEdit = new QLineEdit(this);
    ui->comboBox->setLineEdit(lineEdit);


    //eventFilter 事件分发器的安装
    ui->comboBox->installEventFilter(this);
    ui->lineEdit_2->installEventFilter(this);
    this->installEventFilter(this);

    m_b_login = false;

}

Login::~Login()
{
    delete ui;
}


void Login::keyPressEvent(QKeyEvent *event)
{
    //空格触发login登录
    if(event->key() == Qt::Key_Space)
    {
        emit ui->toolButton_3->clicked();
    }
    return QWidget::keyPressEvent(event);
}

void Login::mousePressEvent(QMouseEvent *event)
{

   if(event->button() == Qt::LeftButton){
       this->reltvpos = event->pos();
       m_move = true;
   }
   return QWidget::mousePressEvent(event);
}

void Login::mouseMoveEvent(QMouseEvent *event)
{
  if(m_move){
      move(event->globalPos()-reltvpos);
  }
  return QWidget::mouseMoveEvent(event);
}

void Login::mouseReleaseEvent(QMouseEvent *event)
{
   m_move = false;
   return QWidget::mouseReleaseEvent(event);
}

bool Login::eventFilter(QObject *wcg, QEvent *event)
{
    if( this == wcg ){
        if(event ->type() ==QEvent::MouseButtonPress){
            if(ui->comboBox->hasFocus()){
                ui->comboBox->clearFocus();
            }
            else if(ui->lineEdit_2->hasFocus()){
                ui->lineEdit_2->clearFocus();
            }
        }
    }
    return QWidget::eventFilter(wcg,event);
}
//最小化
void Login::on_toolButton_clicked()
{
    this->showMinimized();
}
//关闭
void Login::on_toolButton_2_clicked()
{
    this->close();
}
void Login::on_toolButton_3_clicked()
{

    ui->comboBox->addItem(lineEdit->text());
    QString username = lineEdit->text();
    QString password = ui->lineEdit_2->text();
    qDebug()<<username<<password;
    if(username == "" || password == ""){
        QMessageBox::information(this,"警告","输入不能为空",QMessageBox::Ok);
    }
    else
    {
        emit signals_login(username,password,m_b_login);
    }
}
//注册问题
void Login::on_toolButton_4_clicked()
{
    ui->toolButton_4->setEnabled(false);

    QLabel *label = new QLabel(this);

    label->resize(ui->stackedWidget->size());
    label->setPixmap(ui->stackedWidget->grab());
    label->setAttribute(Qt::WA_TranslucentBackground);
    label->show();

    QPropertyAnimation *animation= new QPropertyAnimation(label,"geometry");
    animation->setDuration(1000);
    animation->setStartValue(ui->stackedWidget->geometry());
    animation->setEndValue(QRect(-ui->stackedWidget->width(), ui->stackedWidget->pos().y(), ui->stackedWidget->width(), ui->stackedWidget->height()));
    if(!ui->stackedWidget->currentIndex()){
    ui->stackedWidget->setCurrentWidget(ui->page_2);}
    else{
    ui->stackedWidget->setCurrentWidget(ui->page);}
    QPropertyAnimation * animation_ = new QPropertyAnimation(ui->stackedWidget,"geometry");
    animation_->setDuration(1000);
    animation_->setStartValue(QRect(ui->stackedWidget->width()*2,ui->stackedWidget->pos().y(),ui->stackedWidget->width(), ui->stackedWidget->height()));
    animation_->setEndValue(ui->stackedWidget->geometry());
    QParallelAnimationGroup *group = new QParallelAnimationGroup;
    group->addAnimation(animation);
    group->addAnimation(animation_);
    group->start();


    QTimer::singleShot(1100,this,[=](){label->deleteLater();
        animation->deleteLater();
        animation_->deleteLater();
        group->deleteLater();
        if(ui->stackedWidget->currentIndex())
            ui->toolButton_4->setText("返回");
        else{ui->toolButton_4->setText("注册");}
        ui->toolButton_4->setEnabled(true);
    });
}

void Login::on_toolButton_11_clicked()
{

}
void Login::slot_LoginOver()
{
    if(m_b_login){
        this->hide();
        emit signals_MainwindowsShow();}
    else{
        QMessageBox::information(this,"警告","用户密码错误！",QMessageBox::Ok);}
}
