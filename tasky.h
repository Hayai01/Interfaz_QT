#ifndef TASKY_H
#define TASKY_H

#include <QMainWindow>
#include <QtDebug>
#include <QMessageBox>
#include <QFile>

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


    void on_backgroundButton_clicked();

private:
    Ui::tasky *ui;
    QList<Tarea*> m_tareas;
    const QString ARCHIVO = "tareas.csv";

    enum Columna
    {
        TAREA,ASIGNATURA,FECHA,HORA
    };
    void aplicarEstiloFondo();
    void agregarTarea(Tarea *t);
    void limpiarBuffer();
    void guardar();
    void cargar();


};
#endif // TASKY_H
