#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QtGui/QMainWindow>

class DBConnect;
class QMenu;
class MainWindow
    :public QMainWindow, public Ui::appMainWindow
{
    Q_OBJECT
public:
    MainWindow(DBConnect * dbcon);
    ~MainWindow();
private:
    DBConnect *dbcon;
    QMenu * xitongShezhiMenu;
    QAction * actionYuangongGuanli;
    QAction * actionQuanxianzuGuanli;
    QAction * actionCanshuShezhi;
    QIcon * quanxianzuIcon;
private slots:
    void on_actionXitongShezhi_triggered();
    void on_actionRuanjianBangzhu_triggered();
    void on_actionTuichuXitong_triggered();
    void on_actionYuangongGuanli_triggerd();
    void on_actionQuanxianzuGuanli_triggered();
    void on_actionCanshuShezhi_triggerd();
};

#endif // MAINWINDOW_H