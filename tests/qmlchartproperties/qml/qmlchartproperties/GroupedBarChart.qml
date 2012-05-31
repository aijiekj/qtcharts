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

import QtQuick 1.0
import QtCommercial.Chart 1.0

ChartView {
    title: "Grouped bar series"
    anchors.fill: parent
    theme: ChartView.ChartThemeLight
    legend: ChartView.LegendBottom
    // TODO: labels defined by x-axis, not by bar series
    axisXLabels: ["0", "2008", "1", "2009", "2", "2010", "3", "2012"]

    property variant series: daSeries

    GroupedBarSeries {
        id: daSeries
        barCategories: [ "2008", "2009", "2010", "2011", "2012" ]
        BarSet { name: "Bob"; values: [2, 2, 3, 4, 5, 6] }
        BarSet { name: "Susan"; values: [5, 1, 2, 4, 1, 7] }
        BarSet { name: "James"; values: [3, 5, 8, 13, 5, 8] }
    }
}