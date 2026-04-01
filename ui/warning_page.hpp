#pragma once

#include <QDateTime>
#include <QLabel>
#include <QPushButton>
#include <QTableWidget>
#include <QHeaderView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>

class WarningPage : public QWidget
{
public:
    explicit WarningPage(QWidget *parent = nullptr);
    ~WarningPage();

private:
    /**
     * ⚠️ 报警页面当前只做“前端展示 + 翻页交互”，数据源先用假数据。
     *
     * 后续对接后端时，建议后端提供（或你自己在共享内存/网络协议中整理出）如下字段：
     * - alarm_time:   报警发生时间（建议毫秒时间戳或 ISO8601 字符串）
     * - alarm_text:   报警内容（中文字符串）
     * - clear_time:   解除时间（可为空：表示未解除/未确认）
     *
     * 对接方式建议：
     * 1) 后端推送“新增报警” → 前端 append 到 records_，必要时保持按 alarm_time 倒序
     * 2) 后端推送“解除报警(id)” → 前端按 id 定位记录，更新 clear_time
     * 3) 若数据量很大：可让后端支持分页查询（page/pageSize）或按时间范围查询
     *
     * 当前实现为了便于你和后端沟通，保留了清晰的数据结构 `AlarmRecord`，
     * 并把“刷新表格/翻页”封装到 `update_table_for_current_page()` 中。
     */

    struct AlarmRecord {
        // 这里的字段名/类型就是给后端对接时对照用的
        QDateTime alarm_time;   // 报警时间
        QString alarm_text;     // 报警内容
        QDateTime clear_time;   // 解除时间（无效则表示未解除）
        bool cleared{false};    // 是否已解除（clear_time 是否有效的显式标记）
    };

    // ====== UI 控件 ======
    QLabel* title_{nullptr};
    QTableWidget* table_{nullptr};

    QPushButton* btn_prev_item_{nullptr};
    QPushButton* btn_next_item_{nullptr};
    QPushButton* btn_prev_page_{nullptr};
    QPushButton* btn_next_page_{nullptr};

    // ====== 数据与分页状态 ======
    QVector<AlarmRecord> records_;  // 报警记录（当前用假数据，后续接后端时替换为真实数据）
    int page_size_{8};             // 每页显示条数（按你图片大概 8~10 行，这里取 8）
    int current_page_{0};          // 当前页（从 0 开始）
    int current_row_in_page_{0};   // 当前页内选中行（用于“上一条/下一条”）

    // 生成几条假数据（后续删除/替换为后端数据写入）
    void seed_fake_data();

    // 把 records_ 的 current_page_ 这一页渲染到表格
    void update_table_for_current_page();

    // 更新按钮 enabled 状态，避免翻页越界
    void update_nav_buttons();
};

// 内联函数定义
inline WarningPage::WarningPage(QWidget *parent) : QWidget(parent) {
    // =========================
    // UI：整体布局（标题 + 表格 + 底部按钮）
    // =========================
    auto* root = new QVBoxLayout(this);
    root->setContentsMargins(24, 24, 24, 24);
    root->setSpacing(12);

    title_ = new QLabel(QStringLiteral("报警查询"), this);
    {
        QFont f = title_->font();
        f.setPointSize(18);
        f.setBold(true);
        title_->setFont(f);
        title_->setAlignment(Qt::AlignCenter);
        title_->setStyleSheet("color: white; background-color: #2da8ff; padding: 8px; border-radius: 4px;");
    }
    root->addWidget(title_);

    table_ = new QTableWidget(this);
    {
        /**
         * 表格列定义（和你给的参考图一致）：
         * - 报警时间
         * - 报警内容
         * - 解除时间
         *
         * 后续后端对接时，只要把 `records_` 填上真实数据，
         * 然后调用 `update_table_for_current_page()` 即可刷新界面。
         */
        table_->setColumnCount(3);
        table_->setHorizontalHeaderLabels(
            {QStringLiteral("报警时间"), QStringLiteral("报警内容"), QStringLiteral("解除时间")});

        table_->horizontalHeader()->setStretchLastSection(true);
        table_->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
        table_->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
        table_->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);

        table_->verticalHeader()->setVisible(false);
        table_->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table_->setSelectionBehavior(QAbstractItemView::SelectRows);
        table_->setSelectionMode(QAbstractItemView::SingleSelection);
        table_->setAlternatingRowColors(true);
        table_->setShowGrid(true);
    }
    root->addWidget(table_, 1);

    // 底部按钮栏：返回（如果你以后要加）/上一条/下一条/上一页/下一页
    auto* nav = new QHBoxLayout();
    nav->setSpacing(12);

    btn_prev_item_ = new QPushButton(QStringLiteral("上一条"), this);
    btn_next_item_ = new QPushButton(QStringLiteral("下一条"), this);
    btn_prev_page_ = new QPushButton(QStringLiteral("上一页"), this);
    btn_next_page_ = new QPushButton(QStringLiteral("下一页"), this);

    for (auto* b : {btn_prev_item_, btn_next_item_, btn_prev_page_, btn_next_page_}) {
        b->setFixedHeight(36);
        b->setMinimumWidth(110);
    }

    nav->addStretch();
    nav->addWidget(btn_prev_item_);
    nav->addWidget(btn_next_item_);
    nav->addSpacing(24);
    nav->addWidget(btn_prev_page_);
    nav->addWidget(btn_next_page_);
    nav->addStretch();

    root->addLayout(nav);

    // =========================
    // 数据：填充假数据并首次渲染
    // =========================
    seed_fake_data();
    update_table_for_current_page();

    // =========================
    // 交互：翻页/上下条
    // =========================
    connect(btn_prev_page_, &QPushButton::clicked, this, [this]() {
        if (current_page_ > 0) {
            current_page_--;
            current_row_in_page_ = 0;
            update_table_for_current_page();
        }
    });
    connect(btn_next_page_, &QPushButton::clicked, this, [this]() {
        const int page_count = (records_.size() + page_size_ - 1) / page_size_;
        if (current_page_ + 1 < page_count) {
            current_page_++;
            current_row_in_page_ = 0;
            update_table_for_current_page();
        }
    });
    connect(btn_prev_item_, &QPushButton::clicked, this, [this]() {
        if (table_->rowCount() <= 0) return;
        current_row_in_page_ = qMax(0, current_row_in_page_ - 1);
        table_->selectRow(current_row_in_page_);
        update_nav_buttons();
    });
    connect(btn_next_item_, &QPushButton::clicked, this, [this]() {
        if (table_->rowCount() <= 0) return;
        current_row_in_page_ = qMin(table_->rowCount() - 1, current_row_in_page_ + 1);
        table_->selectRow(current_row_in_page_);
        update_nav_buttons();
    });
    connect(table_, &QTableWidget::cellClicked, this, [this](int row, int /*col*/) {
        current_row_in_page_ = row;
        update_nav_buttons();
    });
}

inline WarningPage::~WarningPage() {
    // 析构函数实现
}

inline void WarningPage::seed_fake_data() {
    /**
     * 假数据用于先把 UI 跑通。
     * 后续对接后端时，你可以：
     * - 删除本函数
     * - 或保留作为“无数据/离线模式”的演示数据
     */
    records_.clear();

    const auto now = QDateTime::currentDateTime();
    records_.push_back({now.addSecs(-3), QStringLiteral("请启动17秒"), QDateTime(), false});
    records_.push_back({now.addSecs(-12), QStringLiteral("ATC调节失败"), now.addSecs(-5), true});
    records_.push_back({now.addSecs(-60), QStringLiteral("顶针未顶出启动"), now.addSecs(-30), true});
    records_.push_back({now.addSecs(-90), QStringLiteral("收线未到左"), QDateTime(), false});
    records_.push_back({now.addSecs(-120), QStringLiteral("断丝保护动作"), now.addSecs(-110), true});
    records_.push_back({now.addSecs(-180), QStringLiteral("钳匙开关打开"), QDateTime(), false});
    records_.push_back({now.addSecs(-240), QStringLiteral("收线未到右"), now.addSecs(-200), true});
    records_.push_back({now.addSecs(-300), QStringLiteral("请按计米清零"), now.addSecs(-295), true});
    records_.push_back({now.addSecs(-360), QStringLiteral("速度超限"), QDateTime(), false});
    records_.push_back({now.addSecs(-420), QStringLiteral("通讯异常"), now.addSecs(-410), true});

    // 默认按报警时间倒序：最新在最上面（和多数报警列表习惯一致）
    std::sort(records_.begin(), records_.end(), [](const AlarmRecord& a, const AlarmRecord& b) {
        return a.alarm_time > b.alarm_time;
    });
}

inline void WarningPage::update_table_for_current_page() {
    /**
     * 渲染规则：
     * - 当前页的数据取 records_[start, end)
     * - 未解除的报警（cleared=false）用更醒目的颜色（这里用红色字体）
     *
     * 后端对接时：你只需要更新 records_，然后调用本函数刷新即可。
     */
    const int total = records_.size();
    const int page_count = (total + page_size_ - 1) / page_size_;
    if (page_count <= 0) {
        table_->setRowCount(0);
        update_nav_buttons();
        return;
    }

    current_page_ = qBound(0, current_page_, page_count - 1);
    const int start = current_page_ * page_size_;
    const int end = qMin(total, start + page_size_);
    const int rows = end - start;

    table_->setRowCount(rows);

    for (int i = 0; i < rows; ++i) {
        const AlarmRecord& r = records_[start + i];

        const QString alarm_time = r.alarm_time.toString("yyyy-MM-dd HH:mm:ss");
        const QString clear_time = (r.cleared && r.clear_time.isValid())
                                       ? r.clear_time.toString("yyyy-MM-dd HH:mm:ss")
                                       : QString();

        auto* item_time = new QTableWidgetItem(alarm_time);
        auto* item_text = new QTableWidgetItem(r.alarm_text);
        auto* item_clear = new QTableWidgetItem(clear_time);

        // 未解除的报警更醒目（红色）
        if (!r.cleared) {
            item_time->setForeground(QBrush(QColor(200, 0, 0)));
            item_text->setForeground(QBrush(QColor(200, 0, 0)));
            item_clear->setForeground(QBrush(QColor(200, 0, 0)));
        } else {
            item_time->setForeground(QBrush(QColor(0, 120, 0)));
            item_text->setForeground(QBrush(QColor(0, 120, 0)));
            item_clear->setForeground(QBrush(QColor(0, 120, 0)));
        }

        table_->setItem(i, 0, item_time);
        table_->setItem(i, 1, item_text);
        table_->setItem(i, 2, item_clear);
    }

    // 选中当前行（如果当前行超出本页范围则归零）
    current_row_in_page_ = qBound(0, current_row_in_page_, qMax(0, rows - 1));
    if (rows > 0) {
        table_->selectRow(current_row_in_page_);
    }

    update_nav_buttons();
}

inline void WarningPage::update_nav_buttons() {
    const int total = records_.size();
    const int page_count = (total + page_size_ - 1) / page_size_;

    btn_prev_page_->setEnabled(current_page_ > 0); 
    btn_next_page_->setEnabled(current_page_ + 1 < page_count);

    const int rows = table_->rowCount();
    btn_prev_item_->setEnabled(rows > 0 && current_row_in_page_ > 0);
    btn_next_item_->setEnabled(rows > 0 && current_row_in_page_ + 1 < rows);
}