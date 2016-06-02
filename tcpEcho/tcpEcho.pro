TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lunp
SOURCES += \
    daytimetcpsrv.c \
    str_echo.c \
    sinachldwait.c
