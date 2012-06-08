/****************************************************************************
**
** Copyright (C) 2012 Digia Plc
** All rights reserved.
** For any questions to Digia, please use contact form at http://qt.digia.com
**
** This file is part of the Qt Commercial Charts Add-on.
**
** $QT_BEGIN_LICENSE$
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.
**
** If you have questions regarding the use of this file, please use
** contact form at http://qt.digia.com
** $QT_END_LICENSE$
**
****************************************************************************/

#include "stackedbaranimation_p.h"
#include "stackedbarchartitem_p.h"
#include <QTimer>

Q_DECLARE_METATYPE(QVector<QRectF>)

QTCOMMERCIALCHART_BEGIN_NAMESPACE

StackedBarAnimation::StackedBarAnimation(BarChartItem *item)
    :ChartAnimation(item),
    m_item(item)
{
    setEasingCurve(QEasingCurve::OutQuart);
}

StackedBarAnimation::~StackedBarAnimation()
{
}

QVariant StackedBarAnimation::interpolated(const QVariant &from, const QVariant &to, qreal progress) const
{
    QVector<QRectF> startVector = qVariantValue<QVector<QRectF> >(from);
    QVector<QRectF> endVector = qVariantValue<QVector<QRectF> >(to);
    QVector<QRectF> result;

    Q_ASSERT(startVector.count() == endVector.count());

    qreal zeroPos = ((m_item->geometry().height() + m_item->geometry().y()) * (1 - progress));

    for(int i = 0; i < startVector.count(); i++) {
        qreal w = endVector[i].width();
        qreal h = startVector[i].height() + ((endVector[i].height() - startVector[i].height()) * progress);
        qreal x = endVector[i].topLeft().x();
        qreal y = startVector[i].topLeft().y() + ((endVector[i].topLeft().y() - startVector[i].topLeft().y()) * progress)
                + zeroPos;

        QRectF value(x,y,w,h);
        result << value;
    }
    return qVariantFromValue(result);
}

void StackedBarAnimation::updateCurrentValue(const QVariant &value)
{
    QVector<QRectF> layout = qVariantValue<QVector<QRectF> >(value);
    m_item->setLayout(layout);
}


void StackedBarAnimation::updateLayout(const QVector<QRectF> &oldLayout, const QVector<QRectF> &newLayout)
{
    setDuration(ChartAnimationDuration);
    setKeyValueAt(0.0, qVariantFromValue(oldLayout));
    setKeyValueAt(1.0, qVariantFromValue(newLayout));
    QTimer::singleShot(0, this, SLOT(start()));
}
#include "moc_stackedbaranimation_p.cpp"

QTCOMMERCIALCHART_END_NAMESPACE