#include "mainwindow.h"
#include "ui_mainwindow.h"

double firstNum;
bool userIsTypingSecondNumber = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //associtate button press with slot
    //do this for all buttons
    connect(ui->pushButton_0, SIGNAL(released()), this, SLOT(digits_pressed()));
    connect(ui->pushButton_1, SIGNAL(released()), this, SLOT(digits_pressed()));
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(digits_pressed()));
    connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(digits_pressed()));
    connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(digits_pressed()));
    connect(ui->pushButton_5, SIGNAL(released()), this, SLOT(digits_pressed()));
    connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(digits_pressed()));
    connect(ui->pushButton_7, SIGNAL(released()), this, SLOT(digits_pressed()));
    connect(ui->pushButton_8, SIGNAL(released()), this, SLOT(digits_pressed()));
    connect(ui->pushButton_9, SIGNAL(released()), this, SLOT(digits_pressed()));
    connect(ui->pushButton_plusOrMinus, SIGNAL(released()), this, SLOT(unary_operation_pressed()));

    connect(ui->pushButton_plus, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pushButton_minus, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pushButton_divide, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pushButton_modulus, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pushButton_multiplication, SIGNAL(released()), this, SLOT(binary_operation_pressed()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_multiplication->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_modulus->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//gets whether digit was pressed (function definition)
void MainWindow::digits_pressed() {
    QPushButton * button = (QPushButton*)sender();
    double labelNumber;
    QString newLabel;

    if ((ui->pushButton_plus->isChecked() || ui->pushButton_minus->isChecked()
            || ui->pushButton_multiplication->isChecked() || ui->pushButton_divide->isChecked()
            || ui->pushButton_modulus->isChecked()) && (!userIsTypingSecondNumber)) {
        labelNumber = button->text().toDouble();
        userIsTypingSecondNumber = true;
        newLabel = QString::number(labelNumber, 'g', 15);   //cpnverts from q string to number
    } else {
        if (ui->label->text().contains('.') && button->text() == "0") {
            newLabel = ui->label->text() + button->text();
        } else {
            labelNumber = (ui->label->text() + button->text()).toDouble();
            newLabel = QString::number(labelNumber, 'g', 15);
        }

    }

    ui->label->setText(newLabel);

}


void MainWindow::on_pushButton_decimal_released() {
    ui->label->setText(ui->label->text() + ".");
}

void MainWindow::unary_operation_pressed() {
    QPushButton * button =(QPushButton*) sender();
    double labelNumber;
    QString newLabel;

    if (button->text() == "+/-") {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber, 'g', 15);   //cpnverts from q string to number
        ui->label->setText(newLabel);
    }

//    if (button->text() == "%") {
//        labelNumber = ui->label->text().toInt();
//        labelNumber = labelNumber * -1;
//        newLabel = QString::number(labelNumber, 'g', 15);   //cpnverts from q string to number
//        ui->label->setText(newLabel);
//    }
}

void MainWindow::on_pushButton_clear_released(){
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiplication->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    ui->pushButton_modulus->setChecked(false);

    userIsTypingSecondNumber = false;

    ui->label->setText("0");
}

void MainWindow::on_pushButton_equal_released(){
    double labelNum, secondNum;
    QString newLabel;
    secondNum = ui->label->text().toDouble();

    if (ui->pushButton_plus->isChecked()) {
        labelNum = firstNum + secondNum;
        newLabel = QString::number(labelNum, 'g', 15);
        ui->label->setText(newLabel);
        ui->pushButton_minus->setChecked(false);
    }
    else if (ui->pushButton_minus->isChecked()) {
        labelNum = firstNum - secondNum;
        newLabel = QString::number(labelNum, 'g', 15);
        ui->label->setText(newLabel);
        ui->pushButton_multiplication->setChecked(false);
    }
    else if (ui->pushButton_multiplication->isChecked()) {
        labelNum = firstNum * secondNum;
        newLabel = QString::number(labelNum, 'g', 15);
        ui->label->setText(newLabel);
        ui->pushButton_divide->setChecked(false);
    }
    else if (ui->pushButton_divide->isChecked()) {
        labelNum = firstNum / secondNum;
        newLabel = QString::number(labelNum, 'g', 15);
        ui->label->setText(newLabel);
        ui->pushButton_modulus->setChecked(false);
    }
    else if (ui->pushButton_modulus->isChecked()) {
        labelNum = firstNum / secondNum;
        newLabel = QString::number(labelNum, 'g', 15);
        ui->label->setText(newLabel);
        ui->pushButton_plus->setChecked(false);
    }

    userIsTypingSecondNumber = false;
}

void MainWindow::binary_operation_pressed(){
    QPushButton * button =(QPushButton*) sender();
    firstNum = ui->label->text().toDouble();
    button->setChecked(true);   //sets the button being pressed to true
}
