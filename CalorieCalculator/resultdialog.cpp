#include "resultdialog.h"
#include "ui_resultdialog.h"

ResultDialog::ResultDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResultDialog)
{
    ui->setupUi(this);
    init();
}

ResultDialog::~ResultDialog()
{
    delete ui;
}

void ResultDialog::addItem(int row, int column, const QString &label)
{
    ui->tableWidget->setItem(row, column, new QTableWidgetItem(label));
}

void ResultDialog::setText(const QString &text)
{
    ui->txtTDEE->setText(text);
}

int ResultDialog::getRowCount() const
{
    return ui->tableWidget->rowCount();
}

int ResultDialog::getColumnCount() const
{
    return ui->tableWidget->columnCount();
}

void ResultDialog::on_buttonBox_accepted()
{
    accept();
}

void ResultDialog::init()
{
    this->setWindowTitle("Result");
    this->setFixedSize(500, 300);

    QStringList headerLabels;
    headerLabels.append("Activity Level");
    headerLabels.append("Calories");

    ui->txtTDEE->setReadOnly(true);

    ui->tableWidget->setColumnCount(headerLabels.count());
    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
}
