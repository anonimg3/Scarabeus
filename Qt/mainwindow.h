#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QProcess>
#include <QtGamepad/QGamepad>

#include <QtCore/QObject>
#include <QtCore/QTimer>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();
    void doConnect();
    void GamePad();
    void update();
    void load_css_style();

    void on_reset_uc_button_clicked();

    void on_clear_button_clicked();

    void on_forward_button_pressed();

    void on_forward_button_released();

    void on_left_button_pressed();

    void on_left_button_released();

    void on_right_button_pressed();

    void on_right_button_released();

    void on_backward_button_pressed();

    void on_backward_button_released();

    void on_start_button_clicked(bool checked);

    void on_connect_button_clicked(bool checked);

    void on_s1_slider_valueChanged(int value);

    void on_s2_slider_valueChanged(int value);

    void on_pwm_dc_slider_valueChanged(int value);

    void on_speed_gripper_slider_valueChanged(int value);

    void on_adc_button_clicked();

    void on_gamepad_button_clicked(bool checked);

    void on_stop_button_pressed();


private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QProcess process;
    QTimer *timer;
    uint8_t bufor_tx[5] = {0x5,0x5,0x55,0x3C,0x65}; //NOT NULL 0x0 { 5, 5, 85, 60, 101 }
    uint8_t bufor_tx_temp[5] = {0, 0, 0, 0, 0};
    QByteArray bufor_rx[4]= {0, 0, 0, 0};
    QGamepad *m_gamepad;
    double gamepad_x_button = 0;
    double gamepad_y_button = 0;
    bool lock_gamepad_gripper = true;
    uint16_t tcrt_5000_left = 0;
    uint16_t tcrt_5000_right = 0;

};

#endif // MAINWINDOW_H
