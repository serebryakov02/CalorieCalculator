#include "dialog.h"
#include "ui_dialog.h"
#include "chooseformuladialog.h"
#include "resultdialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    init();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::init()
{
    this->setWindowTitle("Calorie Calculator");
    this->setFixedSize(400, 300);

    ui->spnBoxAge->setMinimum(15);
    ui->spnBoxAge->setMaximum(80);
    ui->spnBoxHeight->setMaximum(222);
    ui->spnBoxWeight->setMaximum(200);

    m_activityLvls.append("Sedendary");
    m_activityLvls.append("Lightly active");
    m_activityLvls.append("Moderately active");
    m_activityLvls.append("Very active");
    m_activityLvls.append("Extremely active");

    m_multipliers.append(1.2);
    m_multipliers.append(1.375);
    m_multipliers.append(1.55);
    m_multipliers.append(1.725);
    m_multipliers.append(1.9);

    ui->cmbBoxActivityLevel->clear();
    ui->cmbBoxActivityLevel->insertItems(0, m_activityLvls);
}

double Dialog::calculateBMR_MifflinStJeor() const
{
    int weight = ui->spnBoxWeight->value();
    int height = ui->spnBoxHeight->value();
    int age = ui->spnBoxAge->value();

    if (ui->cmbBoxUnitsHeight->currentText() == "in")
        height *= 2.54;

    if (ui->cmbBoxUnitsWeight->currentText() == "lb")
        weight *= 0.453592;
    if (ui->cmbBoxUnitsWeight->currentText() == "st")
        weight *= 6.35029;

    if (ui->cmbBoxGender->currentText() == "Male")
        return 10 * weight + 6.25 * height - 5 * age + 5;
    else if (ui->cmbBoxGender->currentText() == "Female")
        return 10 * weight + 6.25 * height - 5 * age - 161;
    else
        return 0.0;
}

double Dialog::calculateBMR_HarrisBenedict() const
{
    int weight = ui->spnBoxWeight->value();
    int height = ui->spnBoxHeight->value();
    int age = ui->spnBoxAge->value();

    if (ui->cmbBoxGender->currentText() == "Male")
        return 66.47 + 13.75 * weight + 5.003 * height - 6.755 * age;
    else if (ui->cmbBoxGender->currentText() == "Female")
        return 655.1 + 9.563 * weight + 1.850 * height - 4.676 * age;
    else
        return 0.0;
}

void Dialog::calculate()
{
    ChooseFormulaDialog* chooseFormulaDialog = new ChooseFormulaDialog(this);
    int result = chooseFormulaDialog->exec();

    if (result == QDialog::Accepted)
    {
        double BMR = 0.0;
        QString formulaName = chooseFormulaDialog->formulaName();
        if (formulaName == "Mifflin-St Jeor")
            BMR = calculateBMR_MifflinStJeor();
        else if (formulaName == "Harris-Benedict")
            BMR = calculateBMR_HarrisBenedict();

        double TDEE = BMR;

        auto index = m_activityLvls.indexOf(ui->cmbBoxActivityLevel->currentText());
        TDEE *= m_multipliers[index];

        ResultDialog* resultDialog = new ResultDialog(this);
        resultDialog->setText(QString::number(TDEE));
        resultDialog->addItem(0, 0, "Basal Metabolic Rate (BMR)");
        resultDialog->addItem(0, 1, QString::number(BMR));
        resultDialog->addItem(1, 0, m_activityLvls[0]);
        resultDialog->addItem(1, 1, QString::number(BMR * m_multipliers[0]));
        resultDialog->addItem(2, 0, m_activityLvls[1]);
        resultDialog->addItem(2, 1, QString::number(BMR * m_multipliers[1]));
        resultDialog->addItem(3, 0, m_activityLvls[2]);
        resultDialog->addItem(3, 1, QString::number(BMR * m_multipliers[2]));
        resultDialog->addItem(4, 0, m_activityLvls[3]);
        resultDialog->addItem(4, 1, QString::number(BMR * m_multipliers[3]));

        resultDialog->exec();
    }
}

void Dialog::on_btnCalculate_clicked()
{
    calculate();
}
