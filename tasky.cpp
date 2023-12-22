#include "tasky.h"
#include "ui_tasky.h"

bool colorFondoBlanco = true;

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
    //cargar Tareas desde el archivo
    cargar();

}

tasky::~tasky()
{
    delete ui;
}


void tasky::on_btnAgregar_clicked()
{
    /*
     1)cuando se abra la aplicacion hay que leer el archivo
     2)

    */

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
    guardar();
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

void tasky::guardar()
{

    // Abrir el archivo y guardar
    QFile archivo(ARCHIVO);
    if (archivo.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream salida(&archivo);


        foreach(auto *t , m_tareas){
           salida << t->nombre() << ";" <<t->asignatura() <<";";
           salida << t->fecha().toString("dd/MM/yyyy")<<";";
           salida << t->hora().toString("hh:mm")<< "\n";
        }

        archivo.close();
/*
        for (int i=0; i<filas; i++) {
            QTableWidgetItem *nombre = ui->tblTareas->item(i, NOMBRE);
            QTableWidgetItem *apellido = ui->tblTareas->item(i, APELLIDO);
            QTableWidgetItem *telefono = ui->tblTareas->item(i, TELEFONO);
            QTableWidgetItem *email = ui->tblTareas->item(i, EMAIL);
            salida << nombre->text() << ";" << apellido->text() << ";";
            salida << telefono->text() << ";" << email->text() << "\n";
        }
        archivo.close();
        QMessageBox::information(this,"Guardar contactos","Contactos guardados con éxito");
    }else{
        QMessageBox::critical(this,"Guardar contactos", "No se puede escribir sobre " + ARCHIVO);
    }*/
    }
}

void tasky::cargar()
{
    // Verificar si el archivo existe
        QFile archivo(ARCHIVO);
        if (!archivo.exists())
            return;

        // cargar datos
        if (archivo.open(QFile::ReadOnly)) {
            QTextStream entrada(&archivo);
            while(!entrada.atEnd()){
                //leer una linea del archivo
                QString linea = entrada.readLine();
                //Separarlo en un vector por /
                QStringList datos = linea.split(";");
                //obtener datos
                QString nombre = datos[0];
                QString asignatura = datos[1];
                QStringList fecha = datos[2].split("/");
                QDate f(fecha[2].toInt(),fecha[1].toInt(),fecha[0].toInt());
                QStringList hora = datos[3].split(":");
                QTime h(hora[0].toInt(),hora[1].toInt());

                Tarea *t = new Tarea(nombre,asignatura,f,h);

                agregarTarea(t);

            }
            archivo.close();
        }
}

void tasky::aplicarEstiloFondo()
{
    // Crear un objeto de estilo en función del color de fondo actual
    QString estilo = colorFondoBlanco ? "background-color: white;" : "background-color: rgb(37, 37, 37); color: white;";

    // Aplicar el estilo al centralWidget
    ui->centralwidget->setStyleSheet(estilo);
}

void tasky::on_backgroundButton_clicked()
{
    // Cambiar entre blanco y negro
    colorFondoBlanco = !colorFondoBlanco;

    // Aplicar el estilo correspondiente al centralWidget
    aplicarEstiloFondo();
}






