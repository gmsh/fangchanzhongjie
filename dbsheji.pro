SOURCES += main.cpp \
    logindialog.cpp \
    dbconnect.cpp \
    yuangongguanlidialog.cpp \
    canshuguanlidialog.cpp \
    quanxianzushezhidialog.cpp \
    quanxianzuguanlidialog.cpp \
    datedelegate.cpp \
    combodelegate.cpp \
    mainwindow.cpp
QT += sql
RESOURCES += main.qrc
OTHER_FILES += welcome.png \
    xitongshezhi.png \
    genjinchaxun.png \
    qiehuandenglu.png \
    qianyuechengjiao.png \
    tuichuxitong.png \
    tianjiakehu.png \
    tianjiafangyuan.png \
    ruanjianbangzhu.png \
    renwuguanli.png \
    cash.png \
    quanxian.png \
    modify.png \
    laiyuan.png \
    fencheng.png \
    delete.png \
    add.png \
    preparedb.sql
FORMS += logindialog.ui \
    mainwindow.ui \
    fangyuandialog.ui \
    keyuandialog.ui \
    canshuguanlidialog.ui \
    quanxianzushezhidialog.ui \
    quanxianzuguanlidialog.ui \
    yuangongguanlidialog.ui \
    yuangongxinxidialog.ui
HEADERS += logindialog.h \
    dbconnect.h \
    yuangongguanlidialog.h \
    canshuguanlidialog.h \
    quanxianzushezhidialog.h \
    quanxianzuguanlidialog.h \
    datedelegate.h \
    combodelegate.h \
    mainwindow.h
