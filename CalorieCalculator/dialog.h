#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    double calculateBMR_MifflinStJeor() const;
    double calculateBMR_HarrisBenedict() const;
    void calculate();

private slots:
    void on_btnCalculate_clicked();

private:
    Ui::Dialog *ui;
    QStringList m_activityLvls;
    QVector<double> m_multipliers;
    void init();
};

#endif // DIALOG_H
