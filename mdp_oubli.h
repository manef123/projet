#ifndef MDP_OUBLI_H
#define MDP_OUBLI_H

#include <QDialog>

namespace Ui {
class mdp_oubli;
}

class mdp_oubli : public QDialog
{
    Q_OBJECT

public:
    explicit mdp_oubli(QWidget *parent = nullptr);
    ~mdp_oubli();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();


private:
    Ui::mdp_oubli *ui;
};

#endif // MDP_OUBLI_H
