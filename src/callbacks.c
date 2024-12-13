#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "agent.h"
int ia;
int tr;
char sexe[20]="Homme";
agent agent_chercher ;
int confirmer_supprimer_iheb=0;

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
    GtkWidget *ajouter_label_verif_ik;



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
        ajouter_label_verif_ik=lookup_widget(button,"ajouter_label_verif_ik");

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
        agent_chercher= chercher_agent("agent.txt",a.ID_agent);
        if(!strcmp(a.nom_agent,"")){
                gtk_label_set_text(GTK_LABEL(ajouter_label_verif_ik),"nom obligatoire");
        }
        else if(!strcmp(a.sexe,"")){
                //set text 
                gtk_label_set_text(GTK_LABEL(ajouter_label_verif_ik),"sexe obligatoire");
        }
        else if(!strcmp(a.fonction_agent,"")){
                //set text 
                gtk_label_set_text(GTK_LABEL(ajouter_label_verif_ik),"fonction obligatoire");
        }
        else if(!strcmp(a.prenom_agent,"")){
                //set text 
        }
        else if(!strcmp(num,"")){
                //set text 
        }
        else if(!strcmp(id_ag,"")){
                //set text 
        }
        else if(!strcmp(id_ser,"")){
                //set text 
        }
        else if(!strcmp(id_park,"")){
                //set text 
        }
        
        else if(!(agent_chercher.ID_agent==-1)){
                gtk_label_set_text(GTK_LABEL(ajouter_label_verif_ik),"id agent deja utilise");
        }
        
        else{
	ia=ajouter_agent("agent.txt",a);
        if(ia==1){
                //set text to bien ajoutee
        }
        else{
                //set text erreur
        }
        }

}




void
on_chercheriheb_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *entryID_agent;
        GtkWidget *entryNom_agent;
    GtkWidget *entryPrenom_agent;
    GtkWidget *entryFonction_agent;
    GtkWidget *entryNumero_tel;
    GtkWidget *entryID_parking;
    GtkWidget *entryID_service;
    GtkWidget *homme_agent;
    GtkWidget *femme_agent;
    GtkWidget *labelout;
        char id_ag[15];
        int ID_rech;
        char tel[8];
        char ser_ag[20];
        char par_ag[20];
        

        entryNom_agent=lookup_widget(button,"entry_nom_agent");
        entryID_agent=lookup_widget(button,"entry_id_agent");
        entryPrenom_agent=lookup_widget(button,"entry_prenom_agent");
	entryFonction_agent=lookup_widget(button,"comboboxentry_fonction1");
        entryNumero_tel=lookup_widget(button,"entry_numero_tel");
	entryID_service=lookup_widget(button,"entry_id_service");
	entryID_parking=lookup_widget(button,"entry_id_parking");
        homme_agent=lookup_widget(button,"radioiheb_hm");
        femme_agent=lookup_widget(button,"radioiheb_fm");
        labelout = lookup_widget(button,"label_iheb_modif_out");

        strcpy(id_ag,gtk_entry_get_text(GTK_ENTRY(entryID_agent)));

        ID_rech=atoi(id_ag);

        agent_chercher= chercher_agent( "agent.txt",  ID_rech);
        if(agent_chercher.ID_agent==ID_rech){
                gtk_label_set_text(GTK_LABEL(labelout),"");
                gtk_entry_set_text(GTK_ENTRY(entryNom_agent), agent_chercher.nom_agent);
                gtk_entry_set_text(GTK_ENTRY(entryPrenom_agent), agent_chercher.prenom_agent);
   if (!strcmp(agent_chercher.sexe,"Homme")) {
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(homme_agent), 1);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(femme_agent), 0);
}else {
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(homme_agent), 0);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(femme_agent), 1);
}

    sprintf(tel,"%d",agent_chercher.numero_tel);
    sprintf(ser_ag,"%d",agent_chercher.ID_service);
    sprintf(par_ag,"%d",agent_chercher.ID_parking);

    gtk_entry_set_text(GTK_ENTRY(entryNumero_tel), tel);
    gtk_entry_set_text(GTK_ENTRY(entryID_service), ser_ag);
    gtk_entry_set_text(GTK_ENTRY(entryID_parking), par_ag);
        }
        else{
                
                gtk_label_set_text(GTK_LABEL(labelout),"non trouvé");

                gtk_entry_set_text(GTK_ENTRY(entryNumero_tel), "");
                gtk_entry_set_text(GTK_ENTRY(entryID_service), "");
                gtk_entry_set_text(GTK_ENTRY(entryID_parking), "");
                 gtk_entry_set_text(GTK_ENTRY(entryNom_agent), "");
                gtk_entry_set_text(GTK_ENTRY(entryPrenom_agent), "");
    

        }


}


void
on_modifier_iheb_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
        agent a ;
    GtkWidget *entryID_agent1;
    GtkWidget *entryNom_agent1;
    GtkWidget *entryPrenom_agent1;
    GtkWidget *entryFonction_agent1;
    GtkWidget *entryNumero_tel1;
    GtkWidget *entryID_parking1;
    GtkWidget *entryID_service1;
    GtkWidget *affiche1;
    GtkWidget *modifier;
    GtkWidget *labelout;
    GtkWidget *treeview2;

   char nom_agent[10] ,prenom_agent[10], fonction_agent[20];
   char id_ag[15], id_ser[15], id_park[15], num[10];
   int ID_agent, ID_service, ID_parking, numero_tel ;
	
	entryNom_agent1=lookup_widget(button,"entry_nom_agent");
	entryPrenom_agent1=lookup_widget(button,"entry_prenom_agent");
	entryID_agent1=lookup_widget(button,"entry_id_agent");
	entryFonction_agent1=lookup_widget(button,"comboboxentry_fonction1");
        entryNumero_tel1=lookup_widget(button,"entry_numero_tel");
	entryID_service1=lookup_widget(button,"entry_id_service");
	entryID_parking1=lookup_widget(button,"entry_id_parking");
        labelout=lookup_widget(button,"label_iheb_modif_out");
         modifier = lookup_widget(button, "modifieriheb");

        strcpy(id_ag,gtk_entry_get_text(GTK_ENTRY(entryID_agent1)));
	strcpy(a.prenom_agent,gtk_entry_get_text(GTK_ENTRY(entryPrenom_agent1)));
	strcpy(a.nom_agent,gtk_entry_get_text(GTK_ENTRY(entryNom_agent1)));
        strcpy(a.fonction_agent,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryFonction_agent1)));
	strcpy(id_ser,gtk_entry_get_text(GTK_ENTRY(entryID_service1)));
	strcpy(id_park,gtk_entry_get_text(GTK_ENTRY(entryID_parking1)));
	strcpy(num,gtk_entry_get_text(GTK_ENTRY(entryNumero_tel1)));
	
	a.ID_agent = atoi(id_ag);
        a.numero_tel = atoi(num);
        a.ID_parking = atoi(id_park);
        a.ID_service = atoi(id_ser);
	strcpy(a.sexe,sexe);
    


         
	tr = modifier_agent("agent.txt",agent_chercher.ID_agent,a);
        gtk_widget_destroy(modifier);
	affiche1=create_ihebwindow();
	gtk_widget_show(affiche1);
	treeview2=lookup_widget(affiche1, "treeviewnk") ;
	afficher_agent(treeview2,"agent.txt");
        
	
if(tr==-1){gtk_label_set_text(GTK_LABEL(labelout),"Erreur");}	
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
if(confirmer_supprimer_iheb==1){
strcpy(id77,gtk_entry_get_text(GTK_ENTRY(entry_supp_iheb_id) ) );

ident=atoi(id77);
uuioi=supprimer_agent("agent.txt",ident);
agent_chercher.ID_agent=-1;
GtkWidget* suprim;
GtkWidget* affiche;
suprim=lookup_widget(button,"supprimeriheb");
gtk_widget_destroy(suprim);
affiche=create_ihebwindow();
gtk_widget_show(affiche);
confirmer_supprimer_iheb=0;
//treeview2=lookup_widget(affiche, "treeviewnk") ;	
//afficher_agent(treeview2,"agent.txt");
}
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
GtkWidget *treeview1, *affiche,*affiche1;
affiche1 = lookup_widget(button, "ihebwindow");
gtk_widget_destroy(affiche1);
affiche=create_ihebwindow();
treeview1=lookup_widget(affiche, "treeviewnk");
afficher_agent(treeview1,"agent.txt");
 gtk_widget_show(affiche);


}

// chercher nav
void
on_btn_chercher_iheb_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
       GtkWidget *entryID_agent;
        GtkWidget *entryNom_agent;
    GtkWidget *entryPrenom_agent;
    GtkWidget *entryFonction_agent;
    GtkWidget *entryNumero_tel;
    GtkWidget *entryID_parking;
    GtkWidget *entryID_service;
    GtkWidget *homme_agent;
    GtkWidget *femme_agent;
    GtkWidget *labelout;
    GtkWidget *entrychercheriheb;
    GtkWidget *non_trouve_label_home;

        char id_ag[15];
        int ID_rech;
        char tel[8];
        char ser_ag[20];
        char par_ag[20];
        
        entrychercheriheb=lookup_widget(button,"entrychercheriheb");
        non_trouve_label_home=lookup_widget(button,"non_trouve_label_home");


        strcpy(id_ag,gtk_entry_get_text(GTK_ENTRY(entrychercheriheb)));
        

        ID_rech=atoi(id_ag);

        agent_chercher= chercher_agent( "agent.txt",  ID_rech);
        if(agent_chercher.ID_agent==ID_rech)
        {
                 gtk_label_set_text(GTK_LABEL(non_trouve_label_home)," agent trouvé");
    
 }
        else
        {
                
                gtk_label_set_text(GTK_LABEL(non_trouve_label_home),"non trouvé");

        }




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
           GtkWidget *ihebwindow,*supprimeriheb,*treeview1;
	
	ihebwindow=create_ihebwindow();

        supprimeriheb=lookup_widget(button,"supprimeriheb");
	gtk_widget_destroy(supprimeriheb);
	treeview1=lookup_widget(ihebwindow, "treeviewnk");
        afficher_agent(treeview1,"agent.txt");
	gtk_widget_show(ihebwindow);




}


void
on_confirmer_ihebsup_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{


 if(confirmer_supprimer_iheb == 1){ confirmer_supprimer_iheb=0;}
 else{
 confirmer_supprimer_iheb=1;
 }

}






void
on_button_precedent_iheb_ajout_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *ihebwindow,*ajouteriheb;
	
	ihebwindow=create_ihebwindow();

        ajouteriheb=lookup_widget(button,"ajouteriheb");
	gtk_widget_destroy(ajouteriheb);
	
	gtk_widget_show(ihebwindow);
}


void
on_btn_modifier_iheb_nav_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *ihebwindow,*modifieriheb;
 GtkWidget *entryID_agent;
        GtkWidget *entryNom_agent;
    GtkWidget *entryPrenom_agent;
    GtkWidget *entryFonction_agent;
    GtkWidget *entryNumero_tel;
    GtkWidget *entryID_parking;
    GtkWidget *entryID_service;
    GtkWidget *homme_agent;
    GtkWidget *femme_agent;

 char tel[8];
char ser_ag[20];
char par_ag[20];
char id_ag[10];


	
	ihebwindow=lookup_widget(button,"ihebwindow");
	gtk_widget_destroy(ihebwindow);
        modifieriheb=create_modifieriheb();
	if(agent_chercher.ID_agent == 0){
                gtk_widget_show(modifieriheb);
        }
        else if (agent_chercher.ID_agent!=-1 && agent_chercher.ID_agent !=0)
        { 
        entryNom_agent=lookup_widget(modifieriheb,"entry_nom_agent");
	entryPrenom_agent=lookup_widget(modifieriheb,"entry_prenom_agent");
	entryID_agent=lookup_widget(modifieriheb,"entry_id_agent");
	entryFonction_agent=lookup_widget(modifieriheb,"comboboxentry_fonction1");
        entryNumero_tel=lookup_widget(modifieriheb,"entry_numero_tel");
	entryID_service=lookup_widget(modifieriheb,"entry_id_service");
	entryID_parking=lookup_widget(modifieriheb,"entry_id_parking");

        homme_agent=lookup_widget(modifieriheb,"radioiheb_hm");
        femme_agent=lookup_widget(modifieriheb,"radioiheb_fm");


        gtk_entry_set_text(GTK_ENTRY(entryNom_agent), agent_chercher.nom_agent);
        gtk_entry_set_text(GTK_ENTRY(entryPrenom_agent), agent_chercher.prenom_agent);
   if (!strcmp(agent_chercher.sexe,"Homme")) {
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(homme_agent), 1);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(femme_agent), 0);
}else {
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(homme_agent), 0);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(femme_agent), 1);
}

    sprintf(tel,"%d",agent_chercher.numero_tel);
    sprintf(ser_ag,"%d",agent_chercher.ID_service);
    sprintf(par_ag,"%d",agent_chercher.ID_parking);
    sprintf(id_ag,"%d",agent_chercher.ID_agent);

    gtk_entry_set_text(GTK_ENTRY(entryNumero_tel), tel);
    gtk_entry_set_text(GTK_ENTRY(entryID_service), ser_ag);
    gtk_entry_set_text(GTK_ENTRY(entryID_parking), par_ag);
    gtk_entry_set_text(GTK_ENTRY(entryID_agent), id_ag);    
	
        gtk_widget_show(modifieriheb);

        }
	
}


void
on_precedent_iheb_modifier_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ihebwindow,*modifieriheb;
	
	ihebwindow=create_ihebwindow();

        modifieriheb=lookup_widget(button,"modifieriheb");
	gtk_widget_destroy(modifieriheb);
	
	gtk_widget_show(ihebwindow);
}







void
on_btn_reservation_iheb_nav_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *ihebwindow,*reserveriheb,*treeview;
	
	ihebwindow=lookup_widget(button,"ihebwindow");

	gtk_widget_destroy(ihebwindow);
	reserveriheb=create_reserveriheb();
        treeview= lookup_widget(reserveriheb,"treeview_reservation_ik");
        afficher_reservation(treeview,"reservation.txt");

	gtk_widget_show(reserveriheb);
}






void
on_button_precedent_iheb_reservation_clicked (GtkButton       *button,
                                              gpointer         user_data)
{
GtkWidget *ihebwindow,*reserveriheb,*treeview1;
	
	ihebwindow=create_ihebwindow();
        reserveriheb=lookup_widget(button,"reserveriheb");
	gtk_widget_destroy(reserveriheb);
        treeview1=lookup_widget(ihebwindow, "treeviewnk");
        afficher_agent(treeview1,"agent.txt");
	
	gtk_widget_show(ihebwindow);
}


void
on_afficher_par_fonction_kh_button_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
        int fonction;
        GtkWidget *spinbutton_fonction_agent_kh,*treeview;

        spinbutton_fonction_agent_kh = lookup_widget(button, "spinbutton_fonction_agent_kh");
        treeview = lookup_widget(button, "treeviewnk");

        fonction=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_fonction_agent_kh));
        AgentParFonction(fonction);
        afficher_agent(treeview,"agentParFonction.txt");
}


            





void
on_calander_resrver_iheb_day_selected_double_click
                                        (GtkCalendar     *calendar,
                                        gpointer         user_data)
{

date date_reservation;
        GtkWidget *date_de_reservation_calendar,*treeview;

        date_de_reservation_calendar = lookup_widget(calendar, "calander_resrver_iheb");
        treeview = lookup_widget(calendar, "treeview_reservation_ik");

        gtk_calendar_get_date(GTK_CALENDAR(date_de_reservation_calendar),
                                    &date_reservation.annee,
                                    &date_reservation.mois,
                                    &date_reservation.jour);
        ReservationParDate(date_reservation);
        afficher_reservation(treeview,"reservationParDate.txt");
}


void
on_calander_resrver_iheb_day_selected  (GtkCalendar     *calendar,
                                        gpointer         user_data)
{
        

}


void
on_afficher_res_par_date_ik_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
        date date_reservation;
        GtkWidget *date_de_reservation_calendar,*treeview;

        date_de_reservation_calendar = lookup_widget(button, "calander_resrver_iheb");
        treeview = lookup_widget(button, "treeview_reservation_ik");

        gtk_calendar_get_date(GTK_CALENDAR(date_de_reservation_calendar),
                                    &date_reservation.annee,
                                    &date_reservation.mois,
                                    &date_reservation.jour);
        ReservationParDate(date_reservation);
        afficher_reservation(treeview,"reservationParDate.txt");

        

}

