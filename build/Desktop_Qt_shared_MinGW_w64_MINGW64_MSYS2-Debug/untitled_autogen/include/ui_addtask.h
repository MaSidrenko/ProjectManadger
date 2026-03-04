/********************************************************************************
** Form generated from reading UI file 'addtask.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTASK_H
#define UI_ADDTASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddTask
{
public:
    QLineEdit *lineEdit_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QLabel *label_6;
    QLineEdit *lineEdit_6;
    QLabel *label_7;
    QComboBox *comboBox;
    QDateEdit *dateEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *AddTask)
    {
        if (AddTask->objectName().isEmpty())
            AddTask->setObjectName("AddTask");
        AddTask->resize(391, 423);
        lineEdit_3 = new QLineEdit(AddTask);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(70, 190, 251, 24));
        label = new QLabel(AddTask);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 361, 41));
        label_2 = new QLabel(AddTask);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 90, 361, 41));
        label_3 = new QLabel(AddTask);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 150, 361, 41));
        label_4 = new QLabel(AddTask);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 190, 49, 21));
        lineEdit_4 = new QLineEdit(AddTask);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(70, 220, 251, 24));
        label_5 = new QLabel(AddTask);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 220, 49, 21));
        lineEdit_5 = new QLineEdit(AddTask);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(70, 250, 251, 24));
        label_6 = new QLabel(AddTask);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 250, 61, 21));
        lineEdit_6 = new QLineEdit(AddTask);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(70, 280, 251, 24));
        label_7 = new QLabel(AddTask);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 280, 61, 21));
        comboBox = new QComboBox(AddTask);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(10, 70, 361, 24));
        dateEdit = new QDateEdit(AddTask);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(10, 130, 361, 25));
        pushButton = new QPushButton(AddTask);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(290, 390, 91, 24));

        retranslateUi(AddTask);

        QMetaObject::connectSlotsByName(AddTask);
    } // setupUi

    void retranslateUi(QDialog *AddTask)
    {
        AddTask->setWindowTitle(QCoreApplication::translate("AddTask", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddTask", "<html><head/><body><p><span style=\" font-size:20pt;\">Priority</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("AddTask", "<html><head/><body><p><span style=\" font-size:20pt;\">deadline</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("AddTask", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt;\">Task_info(JSON):</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("AddTask", "<html><head/><body><p align=\"right\">LP</p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("AddTask", "<html><head/><body><p align=\"right\">Tech</p><p align=\"right\"><br/></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("AddTask", "<html><head/><body><p align=\"right\">Framework</p><p align=\"right\"><br/></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("AddTask", "<html><head/><body><p align=\"right\">Who does</p><p align=\"right\"><br/></p></body></html>", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("AddTask", "Lower", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("AddTask", "Medium", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("AddTask", "Higher", nullptr));

        pushButton->setText(QCoreApplication::translate("AddTask", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddTask: public Ui_AddTask {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTASK_H
