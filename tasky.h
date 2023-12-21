#ifndef TASKY_H
#define TASKY_H

#include <QMainWindow>
#include <QtDebug>
#include <QMessageBox>

#include "tarea.h"

QT_BEGIN_NAMESPACE
namespace Ui { class tasky; }
QT_END_NAMESPACE

class tasky : public QMainWindow
{
    Q_OBJECT

public:
    tasky(QWidget *parent = nullptr);
    ~tasky();

private slots:
    void on_btnAgregar_clicked();
    void agregarTarea(Tarea *t);
    void limpiarBuffer();


private:
    Ui::tasky *ui;
    QList<Tarea*> m_tareas;

    enum Columna
    {
        TAREA,ASIGNATURA,FECHA,HORA
    };

};
#endif // TASKY_H
