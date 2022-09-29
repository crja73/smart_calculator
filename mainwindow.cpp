#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtMath"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->slozhenie->click();//приводим программу в режим сложения изначально
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_res_clicked()//кнопка результат
{
    double op1, op2, res;//переменная для двух операндов и результата
    bool flag;
    if(ui->slozhenie->isChecked())//выбрано сложение
    {
        op1=ui->operand1->text().toDouble(&flag);//присвоение значения переменной операнда 1
        if(flag == true)//проверка корректности преобразования операнда 1
        {
            op2=ui->operand2->text().toDouble(&flag);//присвоение значения переменной операнда 2
            if(flag == true)//проверка корректности преобразования операнда 2
            {
                res = op1 + op2;//считаем сумму
                ui->resultat->setNum(res);//вывод результата
                ui->resultat->setVisible(true);//показываем результат
                ui->error->setVisible(false);//скрываем текст с ошибкой
            }
            else
            {
                ui->error->setText("Ошибка слагаемого 2");//вывод ошибки
                ui->resultat->setVisible(false);//скрываем результат
                ui->error->setVisible(true);//показываем текст с ошибкой
            }
        }
        else
        {
            ui->error->setText("Ошибка слагаемого 1");//вывод ошибки
            op2 = ui->operand2->text().toDouble(&flag);
            if (flag == false)
            {
                 ui->error->setText("Ошибка обоих операндов");
            }
            ui->resultat->setVisible(false);//скрываем результат
            ui->error->setVisible(true);//показываем текст с ошибкой
        }

    }
    if(ui->vichitanie->isChecked())//выбрано вычитание
    {
        op1=ui->operand1->text().toDouble(&flag);//присвоение значения переменной операнда 1
        if(flag == true)//проверка корректности преобразования операнда 1
        {
            op2=ui->operand2->text().toDouble(&flag);//присвоение значения переменной операнда 2
            if(flag == true)//проверка корректности преобразования операнда 2
            {
                res= op1 - op2;//вычитаем разность
                ui->resultat->setNum(res);//вывод результата
                ui->resultat->setVisible(true);//показываем результат
                ui->error->setVisible(false);//скрываем текст с ошибкой
            }
            else
            {
                ui->error->setText("Ошибка вычитаемого");//вывод ошибки
                ui->resultat->setVisible(false);//скрываем результат
                ui->error->setVisible(true);//показываем текст с ошибкой
            }
        }
        else
        {
            ui->error->setText("Ошибка уменьшаемого");//вывод ошибки
            op2 = ui->operand2->text().toDouble(&flag);
            if (flag == false)
            {
                 ui->error->setText("Ошибка обоих операндов");
            }
            ui->resultat->setVisible(false);//скрываем результат
            ui->error->setVisible(true);//показываем текст с ошибкой
        }

    }
    if(ui->umnozhenie->isChecked())//выбрано умножение
    {
        op1=ui->operand1->text().toDouble(&flag);//присвоение значения переменной операнда 1
        if(flag == true)//проверка корректности преобразования операнда 1
        {
            op2=ui->operand2->text().toDouble(&flag);//присвоение значения переменной операнда 2
            if(flag == true)//проверка корректности преобразования операнда 2
            {
                res= op1 * op2;//умножаем
                ui->resultat->setNum(res);//вывод результата
                ui->resultat->setVisible(true);//показываем результат
                ui->error->setVisible(false);//скрываем текст с ошибкой
            }
            else
            {
                ui->error->setText("Ошибка множителя");//вывод ошибки
                ui->resultat->setVisible(false);//скрываем результат
                ui->error->setVisible(true);//показываем текст с ошибкой
            }
        }
        else
        {
            ui->error->setText("Ошибка умножаемого");//вывод ошибки
            op2 = ui->operand2->text().toInt(&flag);
            if (flag == false)
            {
                 ui->error->setText("Ошибка обоих операндов");
            }
            ui->resultat->setVisible(false);//скрываем результат
            ui->error->setVisible(true);//показываем текст с ошибкой
        }

    }
    if(ui->delenie->isChecked())//выбрано деление
    {
        op1=ui->operand1->text().toDouble(&flag);//присвоение значения переменной операнда 1
        if(flag == true)//проверка корректности преобразования операнда 1
        {
            op2=ui->operand2->text().toDouble(&flag);//присвоение значения переменной операнда 2
            if(flag == true)//проверка корректности преобразования операнда 2
            {
                if(abs(op2) > (10e-7))
                {
                    res= op1 / op2;//деление
                    ui->resultat->setNum(res);//вывод результата
                    ui->resultat->setVisible(true);//показываем результат
                    ui->error->setVisible(false);//скрываем текст с ошибкой
                }
                if(abs(op2) < (10e-7))
                {
                    ui->error->setVisible(true);
                    ui->error->setText("Нельзя делить на ноль");
                }
            }
            else
            {
                ui->error->setText("Ошибка делителя");//вывод ошибки
                ui->resultat->setVisible(false);//скрываем результат
                ui->error->setVisible(true);//показываем текст с ошибкой
            }
        }
        else
        {
            ui->error->setText("Ошибка делимого");//вывод ошибки
            op2 = ui->operand2->text().toDouble(&flag);
            if (flag == false)
            {
                 ui->error->setText("Ошибка обоих операндов");
            }
            ui->resultat->setVisible(false);//скрываем результат
            ui->error->setVisible(true);//показываем текст с ошибкой
        }

    }
    if(ui->sin->isChecked())
    {
        op1=ui->operand1->text().toDouble(&flag);
        if(flag==true)
        {
            op1=qDegreesToRadians(op1);
            res=qSin(op1);
            ui->resultat->setNum(res);//вывод результата
            ui->resultat->setVisible(true);//показываем результат
            ui->error->setVisible(false);//скрываем текст с ошибкой
        }
        else
        {
            ui->resultat->hide();//скрываем результат
            ui->error->show();//показываем текст с ошибкой
            ui->error->setText("Ошибка начального");//вывод ошибки
        }
    }
    if(ui->cos->isChecked())
    {
        op1=ui->operand1->text().toDouble(&flag);
        if(flag==true)
        {
            op1=qDegreesToRadians(op1);
            res=qCos(op1);
            ui->resultat->setNum(res);//вывод результата
            ui->resultat->setVisible(true);//показываем результат
            ui->error->setVisible(false);//скрываем текст с ошибкой
        }
        else
        {
            ui->resultat->hide();//скрываем результат
            ui->error->show();//показываем текст с ошибкой
            ui->error->setText("Ошибка начального");//вывод ошибки
        }
    }
    if(ui->tg->isChecked())
    {
        op1=ui->operand1->text().toDouble(&flag);
        if(flag==true)
        {
            op1=qDegreesToRadians(op1);
            res=qTan(op1);
            if ((abs(res) > 10e+3) or (abs(res) < (-10e+3)))
            {
                ui->resultat->hide();
                ui->error->show();//показываем текст с ошибкой
                ui->error->setText("Вы вышли за рамки области определения tg");//вывод ошибки
            }
            else
            {
                ui->resultat->setNum(res);//вывод результата
                ui->resultat->setVisible(true);//показываем результат
                ui->error->setVisible(false);//скрываем текст с ошибкой
            }

        }
        else
        {
            ui->resultat->hide();//скрываем результат
            ui->error->show();//показываем текст с ошибкой
            ui->error->setText("Ошибка угла");//вывод ошибки
        }
    }
    if(ui->ctg->isChecked())
    {
        op1=ui->operand1->text().toDouble(&flag);
        if(flag==true)
        {
            op1=qDegreesToRadians(op1);
            res=1/qTan(op1);
            if ((abs(res) > 10e+3) or (abs(res) < (-10e+3)))
            {
                ui->resultat->hide();
                ui->error->show();//показываем текст с ошибкой
                ui->error->setText("Вы вышли за рамки области определения ctg");//вывод ошибки
            }
            else
            {
                ui->resultat->setNum(res);//вывод результата
                ui->resultat->setVisible(true);//показываем результат
                ui->error->setVisible(false);//скрываем текст с ошибкой
            }

        }
        else
        {
            ui->resultat->hide();//скрываем результат
            ui->error->show();//показываем текст с ошибкой
            ui->error->setText("Ошибка угла");//вывод ошибки
        }
    }
    if(ui->asin->isChecked())
    {
        op1=ui->operand1->text().toDouble(&flag);
        if((flag==true) and ((abs(op1) +1) > 2))
        {
            ui->resultat->hide();
            ui->error->show();//показываем текст с ошибкой
            ui->error->setText("Синус может принимать значения от -1 до 1");//вывод ошибки
        }
        else if(flag!=true)
        {
            ui->resultat->hide();//скрываем результат
            ui->error->show();//показываем текст с ошибкой
            ui->error->setText("Ошибка угла");//вывод ошибки
        }
        else
        {
            res=qAsin(op1);
            res=qRadiansToDegrees(res);
            ui->resultat->setNum(res);//вывод результата
            ui->resultat->setVisible(true);//показываем результат
            ui->error->setVisible(false);//скрываем текст с ошибкой
        }
    }
    if(ui->acos->isChecked())
    {
        op1=ui->operand1->text().toDouble(&flag);
        if((flag==true) and ((abs(op1) +1) > 2))
        {
            ui->resultat->hide();
            ui->error->show();//показываем текст с ошибкой
            ui->error->setText("Косинус может принимать значения от -1 до 1");//вывод ошибки
        }
        else if(flag!=true)
        {
            ui->resultat->hide();//скрываем результат
            ui->error->show();//показываем текст с ошибкой
            ui->error->setText("Ошибка угла");//вывод ошибки
        }
        else
        {
            res=qAcos(op1);
            res=qRadiansToDegrees(res);
            ui->resultat->setNum(res);//вывод результата
            ui->resultat->setVisible(true);//показываем результат
            ui->error->setVisible(false);//скрываем текст с ошибкой
        }
    }
    if(ui->atg->isChecked())
    {
        op1=ui->operand1->text().toDouble(&flag);
        if(flag==true)
        {
            res=qAtan(op1);
            res=qRadiansToDegrees(res);
            ui->resultat->setNum(res);//вывод результата
            ui->resultat->setVisible(true);//показываем результат
            ui->error->setVisible(false);//скрываем текст с ошибкой
        }
        else
        {
            ui->resultat->hide();//скрываем результат
            ui->error->show();//показываем текст с ошибкой
            ui->error->setText("Ошибка угла");//вывод ошибки
        }
    }
    if(ui->actg->isChecked())
    {
        op1=ui->operand1->text().toDouble(&flag);
        if(flag==true)
        {
            if (abs(op1) > 10e-3)
            {
                res=qAtan(1/op1);
                res=qRadiansToDegrees(res);
                ui->resultat->setNum(res);//вывод результата
                ui->resultat->setVisible(true);//показываем результат
                ui->error->setVisible(false);//скрываем текст с ошибкой
            }
            else
            {
                res=1.57079633;
                res=qRadiansToDegrees(res);
                ui->resultat->setNum(res);//вывод результата
                ui->resultat->setVisible(true);//показываем результат
                ui->error->setVisible(false);//скрываем текст с ошибкой
            }
        }
        else
        {
            ui->resultat->hide();//скрываем результат
            ui->error->show();//показываем текст с ошибкой
            ui->error->setText("Ошибка угла");//вывод ошибки
        }
    }
    if(ui->kvadrat->isChecked())
    {
        op1=ui->operand1->text().toDouble(&flag);
        if(flag == true)
        {
            res=op1*op1;
            ui->resultat->setNum(res);//вывод результата
            ui->resultat->setVisible(true);//показываем результат
            ui->error->setVisible(false);//скрываем текст с ошибкой
        }
        else
        {
            ui->resultat->hide();//скрываем результат
            ui->error->show();//показываем текст с ошибкой
            ui->error->setText("Ошибка начального");//вывод ошибки
        }
    }
    if(ui->koren->isChecked())
    {
        op1=ui->operand1->text().toDouble(&flag);
        if (op1 < 0)
        {
            ui->resultat->hide();//скрываем результат
            ui->error->show();//показываем текст с ошибкой
            ui->error->setText("Введите неотрицательное число");//вывод ошибки
        }
        else if (flag != true)
        {
            ui->resultat->hide();//скрываем результат
            ui->error->show();//показываем текст с ошибкой
            ui->error->setText("Ошибка начального");//вывод ошибки
        }
        else
        {
            res = qSqrt(op1);
            ui->resultat->setNum(res);//вывод результата
            ui->resultat->setVisible(true);//показываем результат
            ui->error->setVisible(false);//скрываем текст с ошибкой
        }
    }
}

void MainWindow::on_slozhenie_clicked()//режим сложения
{
    ui->label->setText("Слагаемое 1");//меняем текст операнда 1
    ui->label_2->setText("Слагаемое 2");//меняем текст операнда 1
    ui->res->setText("Сумма");//меняем текст кнопки
    ui->operand2->show();
    ui->label_2->show();

    ui->resultat->hide();//прячем предыдущий результат
    ui->error->setVisible(false);//выдаем текст в случае ошибки
}

void MainWindow::on_vichitanie_clicked()
{
    ui->label->setText("Уменьшаемое");//меняем текст операнда 1
    ui->label_2->setText("Вычитаемое");//меняем текст операнда 1
    ui->res->setText("Разность");//меняем текст кнопки
    ui->operand2->show();
    ui->label_2->show();

    ui->resultat->hide();//прячем предыдущий результат
    ui->error->setVisible(false);//выдаем текст в случае ошибки
}

void MainWindow::on_umnozhenie_clicked()
{
    ui->label->setText("Умножаемое");//меняем текст операнда 1
    ui->label_2->setText("Множитель");//меняем текст операнда 1
    ui->res->setText("Произведение");//меняем текст кнопки
    ui->operand2->show();
    ui->label_2->show();

    ui->resultat->hide();//прячем предыдущий результат
    ui->error->setVisible(false);//выдаем текст в случае ошибки
}

void MainWindow::on_delenie_clicked()
{
    ui->label->setText("Делимое");//меняем текст операнда 1
    ui->label_2->setText("Делитель");//меняем текст операнда 1
    ui->res->setText("Частное");//меняем текст кнопки
    ui->operand2->show();
    ui->label_2->show();

    ui->resultat->hide();//прячем предыдущий результат
    ui->error->setVisible(false);//выдаем текст в случае ошибки
}

void MainWindow::on_sin_clicked()
{
    ui->operand2->hide();
    ui->label_2->hide();
    ui->label->setText("Начальное");
    ui->res->setText("Результат");

    ui->resultat->hide();//прячем предыдущий результат
    ui->error->setVisible(false);//выдаем текст в случае ошибки
}

void MainWindow::on_cos_clicked()
{
    ui->operand2->hide();
    ui->label_2->hide();
    ui->label->setText("Начальное");
    ui->res->setText("Результат");

    ui->resultat->hide();//прячем предыдущий результат
    ui->error->setVisible(false);//выдаем текст в случае ошибки
}

void MainWindow::on_tg_clicked()
{
    ui->operand2->hide();
    ui->label_2->hide();
    ui->label->setText("Начальное");
    ui->res->setText("Результат");

    ui->resultat->hide();//прячем предыдущий результат
    ui->error->setVisible(false);//выдаем текст в случае ошибки
}

void MainWindow::on_ctg_clicked()
{
    ui->operand2->hide();
    ui->label_2->hide();
    ui->label->setText("Начальное");
    ui->res->setText("Результат");

    ui->resultat->hide();//прячем предыдущий результат
    ui->error->setVisible(false);//выдаем текст в случае ошибки
}

void MainWindow::on_asin_clicked()
{
    ui->operand2->hide();
    ui->label_2->hide();
    ui->label->setText("Начальное");
    ui->res->setText("Результат");

    ui->resultat->hide();//прячем предыдущий результат
    ui->error->setVisible(false);//выдаем текст в случае ошибки
}

void MainWindow::on_acos_clicked()
{
    ui->operand2->hide();
    ui->label_2->hide();
    ui->label->setText("Начальное");
    ui->res->setText("Результат");

    ui->resultat->hide();//прячем предыдущий результат
    ui->error->setVisible(false);//выдаем текст в случае ошибки
}

void MainWindow::on_atg_clicked()
{
    ui->operand2->hide();
    ui->label_2->hide();
    ui->label->setText("Начальное");
    ui->res->setText("Результат");

    ui->resultat->hide();//прячем предыдущий результат
    ui->error->setVisible(false);//выдаем текст в случае ошибки
}

void MainWindow::on_actg_clicked()
{
    ui->operand2->hide();
    ui->label_2->hide();
    ui->label->setText("Начальное");
    ui->res->setText("Результат");

    ui->resultat->hide();//прячем предыдущий результат
    ui->error->setVisible(false);//выдаем текст в случае ошибки
}
