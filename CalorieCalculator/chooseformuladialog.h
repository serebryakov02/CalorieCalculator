#ifndef CHOOSEFORMULADIALOG_H
#define CHOOSEFORMULADIALOG_H

#include <QDialog>

namespace Ui {
class ChooseFormulaDialog;
}

class ChooseFormulaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseFormulaDialog(QWidget *parent = nullptr);
    ~ChooseFormulaDialog();

    QString formulaName() const;
    void setFormulaName(const QString &newFormulaName);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::ChooseFormulaDialog *ui;
    QString m_formulaName;
    void init();
};

#endif // CHOOSEFORMULADIALOG_H
