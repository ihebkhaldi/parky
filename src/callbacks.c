#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "agent.h"
int ia;
char sexe[20];


void
on_radioiheb_h_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
	{strcpy(sexe,"Homme");}
}


void
on_radioiheb_f_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
	{strcpy(sexe,"Femme");}
}


void
on_ajouter_iheb_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
agent a ;
    GtkWidget *entryID_agent;
    GtkWidget *entryNom_agent;
    GtkWidget *entryPrenom_agent;
    GtkWidget *entryFonction_agent;
    GtkWidget *entryNumero_tel;
    GtkWidget *entryID_parking;
    GtkWidget *entryID_service;



   char nom_agent[10] ,prenom_agent[10], fonction_agent[20];
   char id_ag[15], id_ser[15], id_park[15], num[10];
   int ID_agent, ID_service, ID_parking, numero_tel ;
	
	entryNom_agent=lookup_widget(button,"entry_nom_agent");
	entryPrenom_agent=lookup_widget(button,"entry_prenom_agent");
	entryID_agent=lookup_widget(button,"entry_id_agent");
	entryFonction_agent=lookup_widget(button,"comboboxentry_fonction1");
        entryNumero_tel=lookup_widget(button,"entry_numero_tel");
	entryID_service=lookup_widget(button,"entry_id_service");
	entryID_parking=lookup_widget(button,"entry_id_parking");

        strcpy(id_ag,gtk_entry_get_text(GTK_ENTRY(entryID_agent)));
	strcpy(a.prenom_agent,gtk_entry_get_text(GTK_ENTRY(entryPrenom_agent)));
	strcpy(a.nom_agent,gtk_entry_get_text(GTK_ENTRY(entryNom_agent)));
        strcpy(a.fonction_agent,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryFonction_agent)));
	strcpy(id_ser,gtk_entry_get_text(GTK_ENTRY(entryID_service)));
	strcpy(id_park,gtk_entry_get_text(GTK_ENTRY(entryID_parking)));
	strcpy(num,gtk_entry_get_text(GTK_ENTRY(entryNumero_tel)));
	
	a.ID_agent = atoi(id_ag);
        a.numero_tel = atoi(num);
        a.ID_parking = atoi(id_park);
        a.ID_service = atoi(id_ser);
	strcpy(a.sexe,sexe);

	ia=ajouter_agent("agent.txt",a);

}


void
on_afficher_reservation_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_chercheriheb_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_modifier_iheb_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_supprimiheb_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
char id77[50];
int ident,uuioi;
agent a ;
GtkWidget *entry_supp_iheb_id;
GtkWidget* treeview2;
entry_supp_iheb_id=lookup_widget(button,"entry_supp_iheb_id");

strcpy(id77,gtk_entry_get_text(GTK_ENTRY(entry_supp_iheb_id) ) );

ident=atoi(id77);
uuioi=supprimer_agent("agent.txt",555);
GtkWidget* suprim;
GtkWidget* affiche;
suprim=lookup_widget(button,"supprimeriheb");
gtk_widget_destroy(suprim);
affiche=create_ihebwindow();
gtk_widget_show(affiche);
//treeview2=lookup_widget(affiche, "treeviewnk") ;	
//afficher_agent(treeview2,"agent.txt");
}


void
on_btn_ajout_iheb_nav_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *ihebwindow,*ajouteriheb;
	
	ihebwindow=lookup_widget(button,"ihebwindow");
	gtk_widget_destroy(ihebwindow);
	ajouteriheb=create_ajouteriheb();
	gtk_widget_show(ajouteriheb);

}


void
on_btn_modifier_iheb_nav_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_btn_supprimer_iheb_nav_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *ihebwindow,*supprimeriheb;
	
	ihebwindow=lookup_widget(button,"ihebwindow");
	gtk_widget_destroy(ihebwindow);
	supprimeriheb=create_supprimeriheb();
	gtk_widget_show(supprimeriheb);

}


void
on_btn_actualise_iheb_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_btn_chercher_iheb_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Accueil_iheb_nav_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_treeviewnk_row_iheb_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_precedent_iheb_supp_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{       
           GtkWidget *ihebwindow,*supprimeriheb;
	
	ihebwindow=create_ihebwindow();

        supprimeriheb=lookup_widget(button,"supprimeriheb");
	gtk_widget_destroy(supprimeriheb);
	
	gtk_widget_show(ihebwindow);


}


void
on_confirmer_ihebsup_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}





