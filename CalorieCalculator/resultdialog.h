#ifndef RESULTDIALOG_H
#define RESULTDIALOG_H

#include <QDialog>

namespace Ui {
class ResultDialog;
}

class ResultDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ResultDialog(QWidget *parent = nullptr);
    ~ResultDialog();
    void addItem(int row, int column, const QString& label);
    void addLblTxt(const QString &text);
    void setText(const QString& text);
    int getRowCount() const;
    int getColumnCount() const;
    void setUnits(const QString &newUnits);
    void setHeaderUnits(const QString& units);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ResultDialog *ui;
    void init();
    QString units;
    QStringList headerLabels;
};

#endif // RESULTDIALOG_H
