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
    QString * filterChengqu_0;
    QString * filterLeixing_0;
    QString * filterZhuangtai_0;
    QString * filterChengqu_1;
    QString * filterLeixing_1;
    QString * filterZhuangtai_1;
    QString * filterChengqu_2;
    QString * filterLeixing_2;
    QString * filterZhuangtai_2;
    QString * filterChengqu_3;
    QString * filterLeixing_3;
    QString * filterZhuangtai_3;
    QString * filterChengqu_4;
    QString * filterLeixing_4;
    QString * filterZhuangtai_4;
    QString * filterChengqu_5;
    QString * filterLeixing_5;
    QString * filterZhuangtai_5;
private slots:
    void on_actionXitongShezhi_triggered();
    void on_actionRuanjianBangzhu_triggered();
    void on_actionTuichuXitong_triggered();
    void on_actionYuangongGuanli_triggerd();
    void on_actionQuanxianzuGuanli_triggered();
    void on_actionCanshuShezhi_triggerd();
    void on_actionTianjiaFangyuan_triggered();
    void on_actionTianjiaKehu_triggered();
    void on_modifyPushButton_0_triggerd();//typos but no fix
    void on_modifyPushButton_3_triggerd();
    void on_deletePushButton_0_triggerd();
    void on_deletePushButton_3_triggerd();
    void on_taskTreeWidget_itemActivated ( QTreeWidgetItem * item, int column );
    void on_stackedWidget_currentChanged ( int index );

    void on_tableView_0_clicked();
    void on_tableView_1_clicked();
    void on_tableView_2_clicked();
    void on_tableView_3_clicked();
    void on_tableView_4_clicked();
    void on_tableView_5_clicked();

    void on_chengquComboBox_0_currentIndexChanged ( const QString & text ) ;
    void on_chengquComboBox_1_currentIndexChanged ( const QString & text ) ;
    void on_chengquComboBox_2_currentIndexChanged ( const QString & text ) ;
    void on_chengquComboBox_3_currentIndexChanged ( const QString & text ) ;
    void on_chengquComboBox_4_currentIndexChanged ( const QString & text ) ;
    void on_chengquComboBox_5_currentIndexChanged ( const QString & text ) ;

    void on_fangwuLeixingComboBox_0_currentIndexChanged ( const QString & text ) ;
    void on_fangwuLeixingComboBox_1_currentIndexChanged ( const QString & text ) ;
    void on_fangwuLeixingComboBox_2_currentIndexChanged ( const QString & text ) ;
    void on_fangwuLeixingComboBox_3_currentIndexChanged ( const QString & text ) ;
    void on_fangwuLeixingComboBox_4_currentIndexChanged ( const QString & text ) ;
    void on_fangwuLeixingComboBox_5_currentIndexChanged ( const QString & text ) ;

    void on_fangwuZhuangtaiComboBox_0_currentIndexChanged ( const QString & text ) ;
    void on_fangwuZhuangtaiComboBox_1_currentIndexChanged ( const QString & text ) ;
    void on_fangwuZhuangtaiComboBox_2_currentIndexChanged ( const QString & text ) ;

    void on_kehuZhuangtaiComboBox_3_currentIndexChanged ( const QString & text ) ;
    void on_kehuZhuangtaiComboBox_4_currentIndexChanged ( const QString & text ) ;
    void on_kehuZhuangtaiComboBox_5_currentIndexChanged ( const QString & text ) ;

    void on_actionQianyueChengjiao_triggered();
};

#endif // MAINWINDOW_H
