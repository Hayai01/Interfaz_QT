#include "tasky.h"
#include "ui_tasky.h"

tasky::tasky(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::tasky)
{
    ui->setupUi(this);
    //establecer fecha y hora actual
    QDate hoy = QDate::currentDate();
    QTime ahora = QTime::currentTime();
    ui->dFecha->setMinimumDate(hoy);
    ui->dHora->setMinimumTime(ahora);
    ui->dFecha->setDate(hoy);
    ui->dHora->setTime(ahora);

    ui->tblTareas->setColumnCount(4);
    QStringList cabecera;
    cabecera <<"Tarea"<<"Asignatura"<<"Fecha"<<"Hora";
    ui->tblTareas->setHorizontalHeaderLabels(cabecera);

}

tasky::~tasky()
{
    delete ui;
}


void tasky::on_btnAgregar_clicked()
{
    //obtener datos de la GUI
    QString nombre= ui->txtTarea->text();
    QString asignatura = ui->cmbAsignatura->currentText();
    QDate fecha = ui->dFecha->date();
    QTime hora = ui->dHora->time();

    //Crear una Tarea
    Tarea t(asignatura,fecha,hora,nombre);

    //Agregar tarea a una lista
    m_tareas.push_back(new Tarea (asignatura,fecha,hora,nombre));



    qDebug()<<t.nombre();
}

