#include "mdp_oubli.h"
#include "ui_mdp_oubli.h"
#include "mainwindow.h"
#include <QCoreApplication>
#include <QMessageBox>
#include <QSslSocket>


mdp_oubli::mdp_oubli(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mdp_oubli)
{
    ui->setupUi(this);
}

mdp_oubli::~mdp_oubli()
{
    delete ui;
}

void mdp_oubli::on_pushButton_4_clicked()
{
    QSqlQuery query;

    QString email_compte=ui->lineEdit_3->text();
    if ((ui->lineEdit_3->text()=="" ) )
    {
        QMessageBox::information(this, QObject::tr("ok"),
                                 QObject::tr("Remplir les cases vides\n"));


    }
    else
    {
        query.prepare("SELECT EMAIL_COMP,MDP_COMP from compte WHERE  EMAIL_COMP=:email_compte ");
        query.bindValue(":email_compte", email_compte);
        if (query.exec())
        {
            if (query.next())
            {

            QMessageBox::information(this, QObject::tr("ok"),
                                     QObject::tr("Mot de passe envoyée\n"));
            }
            else
            {
                QMessageBox::information(this, QObject::tr("ok"),
                                         QObject::tr("Email  incorrecte\n"));

            }
          }
   }



}

void mdp_oubli::on_pushButton_5_clicked()
{
    hide();
    MainWindow *newmain= new MainWindow();
    newmain->show();
}
