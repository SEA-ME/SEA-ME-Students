QT += widgets
requires(qtConfig(listview))

SOURCES   = adddialog.cpp \
            finddialog.cpp \
            addresswidget.cpp \
            main.cpp \
            mainwindow.cpp \
            newaddresstab.cpp \
            tablemodel.cpp
HEADERS   = adddialog.h \
            finddialog.h \
            addresswidget.h \
            mainwindow.h \
            newaddresstab.h \
            tablemodel.h

# install
#target.path = $$[QT_INSTALL_EXAMPLES]/widgets/itemviews/testqt
INSTALLS += target

FORMS += \
    form.ui
