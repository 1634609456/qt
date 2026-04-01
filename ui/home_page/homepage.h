#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include <qtmetamacros.h>

#include "../../src/shm_data.hpp"
#include "../../src/util/ring_buffer.hpp"

namespace Ui {
class HomePage;
}

class HomePage : public QWidget
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);
    ~HomePage();

Q_SIGNALS:
    /**
     * 当用户权限从“游客/操作员”切换时发出。
     *
     * 用途：通知 MainWindow 去隐藏/显示左侧导航栏里的“手动控制”分组。
     * 说明：当前 `UserManager` 没有信号机制，所以由 HomePage 主动发信号。
     */
    void operatorModeChanged(bool isOperator);

    /** 主状态机“运行”为 true、“停止”为 false，供数据监控页自动启停入库定时器 */
    void mainRunStateForDbCollection(bool running);


private slots:
    void on_switchUserRoleButton_clicked();
    void updateUIBasedOnUserRole();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_18_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_20_clicked();


private:
    /** 与参数调试页一致：主状态机命令同时写入 P/M 环形缓冲 */
    void pushMainFsmCommand(MAIN_FSM_EVENT_TYPE event_type);
    /** 模式状态机（自动/手动等），双缓冲 */
    void pushModeFsmCommand(MODE_FSM_EVENT_TYPE event_type);

    Ui::HomePage *ui;
    RingBuffer<RINGBUFFER> buffer;
    RingBuffer<RINGBUFFER> buffer_m_;
};

#endif // HOMEPAGE_H
