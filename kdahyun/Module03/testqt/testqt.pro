QT += widgets
requires(qtConfig(listview))

SOURCES   = adddialog.cpp \
            finddialog.cpp \
            addresswidget.cpp \
            main.cpp \
            mainwindow.cpp \
            newaddresstab.cpp \
            bookmarktab.cpp \
            secdialog.cpp \
            tablemodel.cpp
HEADERS   = adddialog.h \
            finddialog.h \
            addresswidget.h \
            mainwindow.h \
            newaddresstab.h \
            bookmarktab.h \
            secdialog.h \
            tablemodel.h

FORMS += \
    dialog.ui \
    mainwindow.ui \
    secdialog.ui

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/itemviews/testqt
INSTALLS += target

FORMS +=
