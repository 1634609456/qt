#pragma once

#include <QStyledItemDelegate>
#include <QPainter>
#include <QApplication>

class LightDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit LightDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

    void paint(QPainter *painter, const QStyleOptionViewItem &option, 
               const QModelIndex &index) const override
    {
        bool isOn = index.data(Qt::DisplayRole).toInt() != 0;

        QStyledItemDelegate::paint(painter, option, QModelIndex());

        painter->save();

        int size = qMin(option.rect.width(), option.rect.height()) - 8;
        QRect lightRect = option.rect;
        lightRect.setSize(QSize(size, size));
        lightRect.moveCenter(option.rect.center());

        QColor lightColor = isOn ? QColor(16, 124, 16) : QColor(160, 160, 160);
        QColor borderColor = lightColor.darker(150);

        painter->setRenderHint(QPainter::Antialiasing, true);
        painter->setBrush(lightColor);
        painter->setPen(QPen(borderColor, 1));
        painter->drawEllipse(lightRect);

        painter->restore();
    }

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        return {20, 20};
    }
};