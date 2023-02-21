#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Run();




public slots:
    void receiveLogin();
private slots:
    void on_toolButton_clicked();
    void on_toolButton_9_clicked();

private:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event );
    void mouseReleaseEvent(QMouseEvent * event);
//    bool eventFilter(QObject *wcg , QEvent * event);
private:
    Ui::MainWindow *ui;
    QPoint p_reltvpos;
    bool b_move;
    bool b_push_show;
};
#endif // MAINWINDOW_H
