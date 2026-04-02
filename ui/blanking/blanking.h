#ifndef BLANKING_H
#define BLANKING_H

#include <QWidget>
#include <QPushButton>


#include "../../src/shm_data.hpp"
#include "../../src/util/ring_buffer.hpp"
#include "../../src/enum/spindle_operation.h"

namespace Ui {
class Blanking;
}

class Blanking : public QWidget
{
    Q_OBJECT

    private slots:
        double getMotorNum(int motorType, QString model) const;
        void on_pushButton_pressed();
        void on_pushButton_released();
        void on_pushButton_2_clicked();
        void on_pushButton_3_clicked();
        void on_pushButton_4_pressed();
        void on_pushButton_4_released();
        void on_pushButton_5_clicked();
        void on_pushButton_6_clicked();
        void on_pushButton_7_clicked();
        void on_pushButton_8_clicked();
        void on_pushButton_9_clicked();
        void on_pushButton_10_pressed();
        void on_pushButton_10_released();
        void on_pushButton_11_pressed();
        void on_pushButton_11_released();
        void on_pushButton_12_clicked();
        void on_pushButton_13_clicked();
        void on_pushButton_14_clicked();
        void on_pushButton_15_clicked();
        void on_pushButton_16_clicked();
        void on_pushButton_17_clicked();
        void on_pushButton_18_clicked();
        void on_pushButton_19_pressed();
        void on_pushButton_19_released();
        void on_pushButton_20_pressed();
        void on_pushButton_20_released();
        void on_pushButton_21_clicked();
        void on_pushButton_22_clicked();
        void on_pushButton_23_clicked();
        void on_pushButton_24_clicked();
        void on_pushButton_25_clicked();
        void on_pushButton_26_clicked();
        void on_pushButton_27_clicked();
        void on_pushButton_28_clicked();
        void on_pushButton_29_clicked();
        void on_pushButton_30_clicked();
        void on_pushButton_31_clicked();
        void on_pushButton_32_clicked();
        void on_pushButton_34_clicked();
        void on_pushButton_35_clicked();


    public:
        explicit Blanking(QWidget *parent = nullptr);
        ~Blanking();

    private:
        Ui::Blanking *ui;
        RingBuffer<RINGBUFFER> buffer;
        RingBuffer<RINGBUFFER> buffer_M;

        /** 取轮进退：颜色由最近点击的上/下使能决定，定时器不覆盖 */
        enum class PickWheelAdvanceRetreatUiHighlight { Neutral, UpperGreen, LowerRed };
        PickWheelAdvanceRetreatUiHighlight pick_wheel_advance_ui_highlight_ = PickWheelAdvanceRetreatUiHighlight::Neutral;

        /** 收线轮压轮气缸升/降：颜色由最近点击的一侧决定，定时器不覆盖 */
        enum class WireWindPressWheelUiHighlight { Neutral, LiftGreen, LowGreen };
        WireWindPressWheelUiHighlight wire_wind_press_wheel_ui_highlight_ = WireWindPressWheelUiHighlight::Neutral;

        /** 双向阀升/降取轮升降：同上，由最近点击的一侧决定 */
        enum class PickWheelLiftPairUiHighlight { Neutral, LiftGreen, LowGreen };
        PickWheelLiftPairUiHighlight pick_wheel_lift_pair_ui_highlight_ = PickWheelLiftPairUiHighlight::Neutral;

        /** 摇篮仓前门开/关：颜色由最近点击决定（与收线压轮阀一致） */
        enum class CradleBinFrontDoorUiHighlight { Neutral, OpenGreen, CloseGreen };
        CradleBinFrontDoorUiHighlight cradle_bin_front_door_ui_highlight_ = CradleBinFrontDoorUiHighlight::Neutral;

    //电机操作执行函数
    void executeOperation( int motorType, SpindleOperation operation, double speed, double acceleration, double position);

    //颜色操作函数
    void setEnableButtonState(QPushButton* enableButton, QPushButton* disableButton, bool isEnabled);

    /** 与 data_monitor_page「手动」一致：当前为自动模式时切手动，双缓冲各推一条 */
    void push_mode_fsm_manual_if_auto_dual();

    /** 模式非手动时切为手动（双缓冲各推一条 MODE_EVENT_MANUAL） */
    void push_mode_fsm_ensure_manual_dual();

    /** 与 data_monitor_page IO 控制一致：IO 手动命令写入 buffer_P + buffer_M */
    void push_io_manual_dual(const COMMOND_GROUPS& cmd);

    /** 收线轮压轮气缸升/降：按 wire_wind_press_wheel_ui_highlight_ 刷新按钮颜色 */
    void applyWireWindPressWheelButtonColors();

    /** 取轮进退：按 pick_wheel_advance_ui_highlight_ 刷新按钮颜色 */
    void applyPickWheelAdvanceRetreatButtonColors();

    /** 双向阀升/降取轮升降：按 pick_wheel_lift_pair_ui_highlight_ 刷新按钮颜色 */
    void applyPickWheelLiftPairButtonColors();

    /** 摇篮仓前门开/关按钮配色 */
    void applyCradleBinFrontDoorButtonColors();
    };

#endif // BLANKING_H
