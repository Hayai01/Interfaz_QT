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

    int rowCount = ui->tblTareas->rowCount(); // Obtener el número actual de filas
        ui->tblTareas->insertRow(rowCount); // Insertar una nueva fila al final

        // Establecer los datos en la nueva fila
        ui->tblTareas->setItem(rowCount, 0, new QTableWidgetItem(nombre)); // Columna 0: Nombre
        ui->tblTareas->setItem(rowCount, 1, new QTableWidgetItem(asignatura)); // Columna 1: Asignatura
        ui->tblTareas->setItem(rowCount, 2, new QTableWidgetItem(fecha.toString("dd/MM/yyyy"))); // Columna 2: Fecha (formateada)
        ui->tblTareas->setItem(rowCount, 3, new QTableWidgetItem(hora.toString("hh:mm:ss"))); // Columna 3: Hora (formateada)
    }





