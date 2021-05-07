#include "commande.h"
#include "ui_commande.h"
#include "mainwindow.h"



commande::commande(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::commande)
{
    ui->setupUi(this);
    ui->tableView_13->setModel(etmm.afficher_menu());

}

commande::~commande()
{
    delete ui;
}

void commande::on_pushButton_34_clicked()
{
    hide();
    MainWindow *newmain= new MainWindow();
    newmain->show();

}

void commande::on_pushButton_33_clicked()
{
int id_commande=ui->lineEdit_10->text().toInt();
int id_elem=ui->lineEdit_32->text().toInt();
QString type_commande;
int prix_commande;
int id_client;
int id_empl;






commande_c  C(id_commande, prix_commande, type_commande, id_client, id_elem, id_empl);
bool test=C.ajouter_commande_element();
                if(test)
                {

                    ui->tableView_14->setModel(Aoc.afficher_commande_element(id_commande));


                    QMessageBox::information(this, QObject::tr("ok"),
                                             QObject::tr("Ajout effectué\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);

                }
                else
                {
                    QMessageBox::critical(this, QObject::tr("Not ok"),
                                             QObject::tr("Ajout non effectué\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);

                }
                QString res=QString::number(id_commande);
                QSqlQuery Query;

                Query.prepare("select sum(M.prix_elem) from menu M, commande C where  C.id_commande=:id_commande and M.id_elem=C.id_elem ");
                Query.bindValue(":id_commande",res);
                Query.exec();
                while (Query.next())
                {
                     total=Query.value(0).toInt();
                     QString tot=QString::number(total);
                     ui->label->setText(tot);

                }
}


void commande::on_pushButton_32_clicked()
{
    int id_commande=ui->lineEdit_10->text().toInt();
    int id_elem =ui->lineEdit_32->text().toInt();
        bool test = Aoc.supprimer_commande_element(id_elem);
        if (test)
        {
            ui->tableView_14->setModel(Aoc.afficher_commande_element(id_commande));
            QMessageBox::information(this, QObject::tr("ok"),
                                     QObject::tr("Supression effectué\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(this, QObject::tr("Not ok"),
                                     QObject::tr("Supression non effectué\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

        }
}
void commande::setData()
{
    int id = getID_commande();

    QSqlQuery query;
    QString res=QString::number(id);



    query.prepare("Select *   from commande where ID_COMMANDE= :id");
    query.bindValue(":id",res);
    query.exec();
    while(query.next())
    {
    ui->lineEdit_10->setText(query.value(getID_commande()).toString());






}
}


 void commande::on_pushButton_43_clicked()
    {
     if ((ui->lineEdit_7->text()=="" && ui->lineEdit_9->text() == "" ) && (!ui->checkBox_2->isChecked() ||  !ui->checkBox_4->isChecked() ) && (ui->lineEdit_32->text()=="" && ui->lineEdit_10->text() == "" ))
     {
         QMessageBox::information(this, QObject::tr("ok"),
                                  QObject::tr("Remplir les case vide\n"));


     }
     else
     {

         if (getModifier()==0)
         {


             int id_commande=ui->lineEdit_10->text().toInt();
             int id_elem =ui->lineEdit_32->text().toInt();
             int id_client=ui->lineEdit_7->text().toInt();
             int id_empl=ui->lineEdit_9->text().toInt();
             QString type_commande;

             if(ui->checkBox_2->isChecked())
             {
                  ui->checkBox_4->setChecked(false);
                  type_commande="livraison ";
             }
             else if (ui->checkBox_4->isChecked())
             {
                 ui->checkBox_2->setChecked(false);
                 type_commande="en place";
             }

             commande_c  C( id_commande,total, type_commande,  id_client, id_elem, id_empl);
             bool test=C.ajouter_commande();
                 if(test)
                 {


                     QMessageBox::information(this, QObject::tr("ok"),
                                              QObject::tr("Ajout effectué\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

                 }
                 else
                 {
                     QMessageBox::critical(this, QObject::tr("Not ok"),
                                              QObject::tr("Ajout non effectué\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

                 }
                 hide();
         }
         else if (getModifier()==1)
         {


             int id_commande=ui->lineEdit_10->text().toInt();
             int id_elem =ui->lineEdit_32->text().toInt();
             int id_client=ui->lineEdit_7->text().toInt();
             int id_empl=ui->lineEdit_9->text().toInt();
             QString type_commande;

             if(ui->checkBox_2->isChecked())
             {

                  ui->checkBox_4->setChecked(false);

                  type_commande="livraison";
             }
             else if (ui->checkBox_4->isChecked())
             {
                 ui->checkBox_2->setChecked(false);

                 type_commande="en place";
             }

             commande_c  C(id_commande,prix_commande, type_commande,  id_client, id_elem, id_empl);
             bool test=C.modifier_commande(id_commande);
                 if(test)
                 {


                     QMessageBox::information(this, QObject::tr("ok"),
                                              QObject::tr("Modification effectué\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

                 }
                 else
                 {
                     QMessageBox::critical(this, QObject::tr("Not ok"),
                                              QObject::tr("Modification non effectué\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

                 }
                 hide();


         }


      }


    }

