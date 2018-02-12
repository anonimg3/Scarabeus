/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QToolButton *reset_uc_button;
    QTextBrowser *console_text;
    QToolButton *clear_button;
    QLineEdit *ip_address;
    QLineEdit *port_address;
    QGroupBox *gripper_box;
    QGridLayout *gridLayout;
    QSlider *s1_slider;
    QSlider *s2_slider;
    QSlider *speed_gripper_slider;
    QLabel *s2_label;
    QLabel *label_2;
    QLabel *s1_label;
    QLabel *label_3;
    QLabel *speed_gripper_label;
    QLabel *label_4;
    QGroupBox *control_box;
    QPushButton *right_button;
    QLabel *tcp_status_label;
    QPushButton *backward_button;
    QPushButton *stop_button;
    QPushButton *forward_button;
    QPushButton *left_button;
    QLabel *pwm_dc_label;
    QSlider *pwm_dc_slider;
    QLabel *label;
    QLabel *tcrt_5000_left_label;
    QLabel *tcrt_5000_right_label;
    QLabel *us_015_label;
    QToolButton *start_button;
    QToolButton *connect_button;
    QToolButton *gamepad_button;
    QToolButton *adc_button;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(594, 453);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        reset_uc_button = new QToolButton(centralWidget);
        reset_uc_button->setObjectName(QStringLiteral("reset_uc_button"));
        reset_uc_button->setGeometry(QRect(10, 70, 111, 23));
        console_text = new QTextBrowser(centralWidget);
        console_text->setObjectName(QStringLiteral("console_text"));
        console_text->setGeometry(QRect(370, 10, 211, 411));
        clear_button = new QToolButton(centralWidget);
        clear_button->setObjectName(QStringLiteral("clear_button"));
        clear_button->setGeometry(QRect(10, 100, 111, 23));
        ip_address = new QLineEdit(centralWidget);
        ip_address->setObjectName(QStringLiteral("ip_address"));
        ip_address->setGeometry(QRect(10, 10, 113, 20));
        ip_address->setAlignment(Qt::AlignCenter);
        port_address = new QLineEdit(centralWidget);
        port_address->setObjectName(QStringLiteral("port_address"));
        port_address->setGeometry(QRect(10, 40, 113, 20));
        port_address->setAlignment(Qt::AlignCenter);
        gripper_box = new QGroupBox(centralWidget);
        gripper_box->setObjectName(QStringLiteral("gripper_box"));
        gripper_box->setGeometry(QRect(10, 130, 351, 151));
        gridLayout = new QGridLayout(gripper_box);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        s1_slider = new QSlider(gripper_box);
        s1_slider->setObjectName(QStringLiteral("s1_slider"));
        s1_slider->setMinimum(30);
        s1_slider->setMaximum(150);
        s1_slider->setValue(60);
        s1_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(s1_slider, 3, 0, 1, 1);

        s2_slider = new QSlider(gripper_box);
        s2_slider->setObjectName(QStringLiteral("s2_slider"));
        s2_slider->setMinimum(30);
        s2_slider->setMaximum(150);
        s2_slider->setValue(85);
        s2_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(s2_slider, 5, 0, 1, 1);

        speed_gripper_slider = new QSlider(gripper_box);
        speed_gripper_slider->setObjectName(QStringLiteral("speed_gripper_slider"));
        speed_gripper_slider->setMinimum(1);
        speed_gripper_slider->setMaximum(50);
        speed_gripper_slider->setValue(5);
        speed_gripper_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(speed_gripper_slider, 1, 0, 1, 1);

        s2_label = new QLabel(gripper_box);
        s2_label->setObjectName(QStringLiteral("s2_label"));
        s2_label->setMinimumSize(QSize(35, 0));

        gridLayout->addWidget(s2_label, 5, 1, 1, 1);

        label_2 = new QLabel(gripper_box);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        s1_label = new QLabel(gripper_box);
        s1_label->setObjectName(QStringLiteral("s1_label"));
        s1_label->setMinimumSize(QSize(35, 0));

        gridLayout->addWidget(s1_label, 3, 1, 1, 1);

        label_3 = new QLabel(gripper_box);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        speed_gripper_label = new QLabel(gripper_box);
        speed_gripper_label->setObjectName(QStringLiteral("speed_gripper_label"));
        speed_gripper_label->setMinimumSize(QSize(35, 0));

        gridLayout->addWidget(speed_gripper_label, 1, 1, 1, 1);

        label_4 = new QLabel(gripper_box);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        control_box = new QGroupBox(centralWidget);
        control_box->setObjectName(QStringLiteral("control_box"));
        control_box->setGeometry(QRect(10, 290, 351, 131));
        right_button = new QPushButton(control_box);
        right_button->setObjectName(QStringLiteral("right_button"));
        right_button->setGeometry(QRect(250, 40, 80, 23));
        tcp_status_label = new QLabel(control_box);
        tcp_status_label->setObjectName(QStringLiteral("tcp_status_label"));
        tcp_status_label->setGeometry(QRect(260, 70, 71, 16));
        backward_button = new QPushButton(control_box);
        backward_button->setObjectName(QStringLiteral("backward_button"));
        backward_button->setGeometry(QRect(130, 70, 101, 23));
        stop_button = new QPushButton(control_box);
        stop_button->setObjectName(QStringLiteral("stop_button"));
        stop_button->setGeometry(QRect(130, 40, 101, 23));
        forward_button = new QPushButton(control_box);
        forward_button->setObjectName(QStringLiteral("forward_button"));
        forward_button->setGeometry(QRect(130, 10, 101, 23));
        left_button = new QPushButton(control_box);
        left_button->setObjectName(QStringLiteral("left_button"));
        left_button->setGeometry(QRect(30, 40, 80, 23));
        pwm_dc_label = new QLabel(control_box);
        pwm_dc_label->setObjectName(QStringLiteral("pwm_dc_label"));
        pwm_dc_label->setGeometry(QRect(270, 110, 71, 16));
        pwm_dc_label->setMinimumSize(QSize(35, 0));
        pwm_dc_slider = new QSlider(control_box);
        pwm_dc_slider->setObjectName(QStringLiteral("pwm_dc_slider"));
        pwm_dc_slider->setGeometry(QRect(12, 110, 251, 16));
        pwm_dc_slider->setMinimum(0);
        pwm_dc_slider->setMaximum(101);
        pwm_dc_slider->setValue(101);
        pwm_dc_slider->setOrientation(Qt::Horizontal);
        label = new QLabel(control_box);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(12, 91, 266, 13));
        tcrt_5000_left_label = new QLabel(centralWidget);
        tcrt_5000_left_label->setObjectName(QStringLiteral("tcrt_5000_left_label"));
        tcrt_5000_left_label->setGeometry(QRect(250, 40, 111, 16));
        tcrt_5000_right_label = new QLabel(centralWidget);
        tcrt_5000_right_label->setObjectName(QStringLiteral("tcrt_5000_right_label"));
        tcrt_5000_right_label->setGeometry(QRect(250, 60, 111, 16));
        us_015_label = new QLabel(centralWidget);
        us_015_label->setObjectName(QStringLiteral("us_015_label"));
        us_015_label->setGeometry(QRect(250, 80, 111, 16));
        start_button = new QToolButton(centralWidget);
        start_button->setObjectName(QStringLiteral("start_button"));
        start_button->setGeometry(QRect(130, 40, 111, 22));
        start_button->setCheckable(true);
        connect_button = new QToolButton(centralWidget);
        connect_button->setObjectName(QStringLiteral("connect_button"));
        connect_button->setGeometry(QRect(130, 10, 111, 22));
        connect_button->setCheckable(true);
        connect_button->setChecked(true);
        gamepad_button = new QToolButton(centralWidget);
        gamepad_button->setObjectName(QStringLiteral("gamepad_button"));
        gamepad_button->setGeometry(QRect(130, 70, 111, 22));
        gamepad_button->setCheckable(true);
        adc_button = new QToolButton(centralWidget);
        adc_button->setObjectName(QStringLiteral("adc_button"));
        adc_button->setGeometry(QRect(250, 10, 111, 22));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 594, 19));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Scarabeus", 0));
        reset_uc_button->setText(QApplication::translate("MainWindow", "Reset uC", 0));
        clear_button->setText(QApplication::translate("MainWindow", "Clear", 0));
        ip_address->setInputMask(QApplication::translate("MainWindow", "000.000.0.000;_", 0));
        ip_address->setText(QApplication::translate("MainWindow", "192.168.1.23", 0));
        port_address->setInputMask(QApplication::translate("MainWindow", "0000;_", 0));
        port_address->setText(QApplication::translate("MainWindow", "8899", 0));
        gripper_box->setTitle(QApplication::translate("MainWindow", "Gripper:", 0));
        s2_label->setText(QApplication::translate("MainWindow", "86\302\260", 0));
        label_2->setText(QApplication::translate("MainWindow", "Speed gripper:", 0));
        s1_label->setText(QApplication::translate("MainWindow", "45\302\260", 0));
        label_3->setText(QApplication::translate("MainWindow", "Gripper jaw:", 0));
        speed_gripper_label->setText(QApplication::translate("MainWindow", "91%", 0));
        label_4->setText(QApplication::translate("MainWindow", "Gripper:", 0));
        control_box->setTitle(QApplication::translate("MainWindow", "Control:", 0));
        right_button->setText(QApplication::translate("MainWindow", "Right", 0));
        tcp_status_label->setText(QApplication::translate("MainWindow", "wait...", 0));
        backward_button->setText(QApplication::translate("MainWindow", "Backward", 0));
        stop_button->setText(QApplication::translate("MainWindow", "Stop", 0));
        forward_button->setText(QApplication::translate("MainWindow", "Forward", 0));
        left_button->setText(QApplication::translate("MainWindow", "Left", 0));
        pwm_dc_label->setText(QApplication::translate("MainWindow", "100%", 0));
        label->setText(QApplication::translate("MainWindow", "Speed platform:", 0));
        tcrt_5000_left_label->setText(QApplication::translate("MainWindow", "<html><head/><body><p>no data</p></body></html>", 0));
        tcrt_5000_right_label->setText(QApplication::translate("MainWindow", "<html><head/><body><p>no data</p></body></html>", 0));
        us_015_label->setText(QApplication::translate("MainWindow", "<html><head/><body><p>no data</p></body></html>", 0));
        start_button->setText(QApplication::translate("MainWindow", "Start", 0));
        connect_button->setText(QApplication::translate("MainWindow", "Connect", 0));
        gamepad_button->setText(QApplication::translate("MainWindow", "Gamepad", 0));
        adc_button->setText(QApplication::translate("MainWindow", "ADC", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
