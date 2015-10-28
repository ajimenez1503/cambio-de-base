//compilar g++ -o interfaz interfaz.cpp `pkg-config --libs --cflags gtk+-2.0`
/* (C) Programmed by:
   Antonio Jimenez Martínez

Sotware:cambio de base - interfaz
Version:0.2

Este programa es capaz de realizar cambios de base, lo aplicamos sobre numeros naturales.
Escribe letras mayusculas en la representación de bases >10.

*/
#include "funciones.h"

using namespace std;

int baseE,baseS;
GtkWidget *label;//etiqueta para mostrar el texto. Tiene que se global, para que las funciones accedan a ella.

//muestra cadena en el label
void mostrar_formula(GtkWidget *widget, GtkEntry* entry)
{
    string aa;
    const char * cadena;
    cadena=gtk_entry_get_text(entry);
    aa=cambiobase(baseE,baseS,cadena);
    gtk_label_set_text(GTK_LABEL(label), aa.c_str());//escribe en label el valor de buf
    //cout<<aa<<endl;
}


//funcion para cambiar el formato del texto de label
void select_font(GtkWidget *widget, gpointer label)
{
    gint result;
    GtkWidget *dialog = gtk_font_selection_dialog_new("Select Font");
    result = gtk_dialog_run(GTK_DIALOG(dialog));
    if (result == GTK_RESPONSE_OK || result == GTK_RESPONSE_APPLY)
    {
        PangoFontDescription *font_desc;
        gchar *fontname = gtk_font_selection_dialog_get_font_name(
                              GTK_FONT_SELECTION_DIALOG(dialog));

        font_desc = pango_font_description_from_string(fontname);

        gtk_widget_modify_font(GTK_WIDGET(label), font_desc);

        g_free(fontname);
    }
    gtk_widget_destroy(dialog);
}

void combo_selectedE(GtkWidget *widget, gpointer window)
{
    gchar *text =  gtk_combo_box_get_active_text(GTK_COMBO_BOX(widget));
    baseE=atoi(text);
    //cout<<"Base de entrada: "<<baseE<<endl;
    g_free(text);
}


void combo_selectedS(GtkWidget *widget, gpointer window)
{
    gchar *text =  gtk_combo_box_get_active_text(GTK_COMBO_BOX(widget));
    baseS=atoi(text);
    //cout<<"Base de salida: "<<baseS<<endl;
    g_free(text);
}

int main(int argc, char** argv) {


	GtkWidget *labelE;//etiqueta para mostrar base entrada
	GtkWidget *labelS;//etiqueta para mostrar base salida
    GtkWidget *label1;//etiqueta para mostrar el texto
    GtkWidget *window;//ventana principal
    GtkWidget *frame;//cremaos un planel con los diferentes botones
    GtkWidget *calcular;//creamos un boton para calcular
    GtkWidget *entry1;//entrada de texto
    GtkWidget *comboE;//para seleccionar base entrada
    GtkWidget *comboS;//para seleccionar base salida


    GtkWidget *menubar;
    GtkWidget *filemenu;
    GtkWidget *file;
    GtkWidget *quit;
    GtkWidget *font;

    gtk_init(&argc, &argv);//aqui se inicializa GTK+ lbrary

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);//creamos una GtkWindow widge
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);//centramos la ventana
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 500);//determinamos el tamaño
    gtk_window_set_title(GTK_WINDOW(window), "cambio de base");//le ponemos un titulo a la ventana

    frame = gtk_fixed_new();//creamos un panel
    gtk_container_add(GTK_CONTAINER(window), frame);//añadimos el panel a la ventana


    //creamos el menu
    menubar = gtk_menu_bar_new();//creamos el menus
    filemenu = gtk_menu_new();//creamos el 1º apartado menu

    file = gtk_menu_item_new_with_label("menu");
    quit = gtk_menu_item_new_with_label("salir");
    font = gtk_menu_item_new_with_label("formato");

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(file), filemenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), font);
    gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), quit);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), file);
    gtk_fixed_put(GTK_FIXED(frame),menubar,0,0);
    //creamos el menu


    //creamos combo de base de entrada
    comboE = gtk_combo_box_new_text();
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboE), "2");
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboE), "3");
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboE), "4");
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboE), "5");
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboE), "6");
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboE), "7");
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboE), "8");
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboE), "9");
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboE), "10");
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboE), "11");
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboE), "12");
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboE), "13");
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboE), "14");
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboE), "15");
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboE), "16");


    //creamos combo de base de salida
    comboS = gtk_combo_box_new_text();
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboS), "2");
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboS), "3");
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboS), "4");
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboS), "5");
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboS), "6");
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboS), "7");
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboS), "8");
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboS), "9");
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboS), "10");
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboS), "11");
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboS), "12");
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboS), "13");
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboS), "14");
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboS), "15");
    gtk_combo_box_append_text(GTK_COMBO_BOX(comboS), "16");


    gtk_fixed_put(GTK_FIXED(frame), comboE, 50, 100);

    gtk_fixed_put(GTK_FIXED(frame), comboS, 250, 100);


    calcular = gtk_button_new_with_label("Calcular");//creamos el boton escribe
    gtk_widget_set_size_request(calcular, 80, 35);//determinamso el tamaño del boton escribe
    gtk_fixed_put(GTK_FIXED(frame), calcular, 50, 400);//situamos el boton en la ventana


    label1 = gtk_label_new("Escriba numero: ");//creamos una etiqueta
    gtk_fixed_put(GTK_FIXED(frame), label1, 50, 300);//situamos la etiqueta en la ventana

	labelE = gtk_label_new("Base entrada: ");//creamos una etiqueta
    gtk_fixed_put(GTK_FIXED(frame), labelE, 50, 50);//situamos la etiqueta en la ventana

	labelS = gtk_label_new("Base salida: ");//creamos una etiqueta
    gtk_fixed_put(GTK_FIXED(frame), labelS, 250, 50);//situamos la etiqueta en la ventana

    label = gtk_label_new("0");//creamos una etiqueta con el numero 0
    gtk_fixed_put(GTK_FIXED(frame), label, 250, 400);//situamos la etiqueta en la ventana

    entry1 = gtk_entry_new();//creamos una entiqueta para introducir texto
    gtk_fixed_put(GTK_FIXED(frame), entry1, 250,300);//situamos la etiqueta en la ventana

    //gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("logo.ico"));//pone de icono de la ventana la foto "logo.ico"
    gtk_widget_show_all(window);//mostrmaos la ventana



    g_signal_connect(G_OBJECT(font), "activate", G_CALLBACK(select_font), label);
    //cuando le damos al boton font, accedemos a una ventna para cmabiar el formato

    //g_signal_connect(G_OBJECT(binfo),  "activate",G_CALLBACK(show_about), (gpointer) window);
    //cuando le damos al boton binfo, accedemos a una ventna que nos muestra información sobre el sistema.

    g_signal_connect(entry1, "activate",G_CALLBACK(mostrar_formula),entry1);
    //utilizamos dos señales para que se muestre en la etiqueta:
    //hacer enter en la escritura
    //hacer click en el boton
    g_signal_connect(calcular, "clicked",G_CALLBACK(mostrar_formula), entry1);
    //conectamos la funcion mostrar_formula con el boton MOSTRAR.


    g_signal_connect(window, "destroy",G_CALLBACK (gtk_main_quit), NULL);
    //cuando le damos a x se cierra el programa.

    g_signal_connect(G_OBJECT(quit), "activate",G_CALLBACK(gtk_main_quit), NULL);


    g_signal_connect(G_OBJECT(comboE), "changed",G_CALLBACK(combo_selectedE),(gpointer) label);

    g_signal_connect(G_OBJECT(comboS), "changed",G_CALLBACK(combo_selectedS),(gpointer) label);

    gtk_main();//la aplicación entra en un main loop


    return 0;
}
