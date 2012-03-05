#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <qchartglobal.h>
#include <qchartview.h>
#include <QWidget>

class QSpinBox;
class QCheckBox;
class QGridLayout;

QTCOMMERCIALCHART_USE_NAMESPACE

#define RealList QList<qreal>
class DataSerieDialog;

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = 0);

signals:

private:
    void initBackroundCombo(QGridLayout *grid);
    void initScaleControls(QGridLayout *grid);
    void initThemeCombo(QGridLayout *grid);
    void initCheckboxes(QGridLayout *grid);

private slots:
    void addSeries();
    void addSeries(QString series, int columnCount, int rowCount, QString dataCharacteristics, bool labelsEnabled);
    void backgroundChanged(int itemIndex);
    void autoScaleChanged(int value);
    void xMinChanged(int value);
    void xMaxChanged(int value);
    void yMinChanged(int value);
    void yMaxChanged(int value);
    void antiAliasToggled(bool enabled);
    void setCurrentSeries(QSeries *series);
    void changeChartTheme(int themeIndex);
    QList<RealList> generateTestData(int columnCount, int rowCount, QString dataCharacteristics);
    QStringList generateLabels(int count);

private:
    DataSerieDialog *m_addSerieDialog;
    QChartView *m_chartView;
    QCheckBox *m_autoScaleCheck;
    QSpinBox *m_xMinSpin;
    QSpinBox *m_xMaxSpin;
    QSpinBox *m_yMinSpin;
    QSpinBox *m_yMaxSpin;
    QString m_defaultSeriesName;
    QSeries *m_currentSeries;
    QGridLayout *m_scatterLayout;
};

#endif // MAINWIDGET_H
