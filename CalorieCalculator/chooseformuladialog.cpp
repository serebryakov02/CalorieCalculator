#include "chooseformuladialog.h"
#include "ui_chooseformuladialog.h"

ChooseFormulaDialog::ChooseFormulaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseFormulaDialog)
{
    ui->setupUi(this);
    init();
}

ChooseFormulaDialog::~ChooseFormulaDialog()
{
    delete ui;
}

void ChooseFormulaDialog::init()
{
    this->setWindowTitle("Formula choice");
    this->setFixedSize(400, 150);
}

QString ChooseFormulaDialog::formulaName() const
{
    return m_formulaName;
}

void ChooseFormulaDialog::setFormulaName(const QString &newFormulaName)
{
    m_formulaName = newFormulaName;
}

void ChooseFormulaDialog::on_buttonBox_accepted()
{
    m_formulaName = ui->cmbBoxFormulaName->currentText();
    accept();
}

void ChooseFormulaDialog::on_buttonBox_rejected()
{
    reject();
}
