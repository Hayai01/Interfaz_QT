#include "tasky.h"
#include "ui_tasky.h"

tasky::tasky(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::tasky)
{
    ui->setupUi(this);
        limpiarBuffer();
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
    if(nombre.length()==0){
        QMessageBox::warning(this,"Agregar tarea","el nombre de la tarea no puede estar vacio");
        return;
    }
    QString asignatura = ui->cmbAsignatura->currentText();
    QDate fecha = ui->dFecha->date();
    QTime hora = ui->dHora->time();

    //Crear una Tarea

    Tarea *t = new Tarea(nombre,asignatura,fecha,hora);
    agregarTarea(t);
    limpiarBuffer();

    //limpiar campos


}

void tasky::agregarTarea(Tarea *t)
{
    m_tareas.push_back(t);
    int rowCount = ui->tblTareas->rowCount(); // Obtener el número actual de filas
        ui->tblTareas->insertRow(rowCount); // Insertar una nueva fila al final

        // Establecer los datos en la nueva fila
        ui->tblTareas->setItem(rowCount, 0, new QTableWidgetItem(t->nombre()));
        ui->tblTareas->setItem(rowCount, 1, new QTableWidgetItem(t->asignatura()));
        ui->tblTareas->setItem(rowCount, 2, new QTableWidgetItem(t->fecha().toString("dd/MM/yyyy")));
        ui->tblTareas->setItem(rowCount, 3, new QTableWidgetItem(t->hora().toString("hh:mm:ss")));
}

void tasky::limpiarBuffer()
{
    QDate hoy = QDate::currentDate();
    QTime ahora = QTime::currentTime();
    ui->dFecha->setMinimumDate(hoy);
    ui->dHora->setMinimumTime(ahora);
    ui->dFecha->setDate(hoy);
    ui->dHora->setTime(ahora);

    ui->txtTarea->clear();
    ui->cmbAsignatura->setCurrentIndex(0);


    ui->txtTarea->setFocus();

}








