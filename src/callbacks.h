#include <gtk/gtk.h>


void
on_radioiheb_h_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radioiheb_f_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ajouter_iheb_clicked                (GtkButton       *button,
                                        gpointer         user_data);


void
on_chercheriheb_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifier_iheb_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimiheb_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_ajout_iheb_nav_clicked          (GtkButton       *button,
                                        gpointer         user_data);


void
on_btn_supprimer_iheb_nav_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_actualise_iheb_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_chercher_iheb_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_Accueil_iheb_nav_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewnk_row_iheb_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_precedent_iheb_supp_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_confirmer_ihebsup_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_btn_ajout_iheb_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_precedent_iheb_ajout_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_modifier_iheb_nav_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_precedent_iheb_modifier_clicked     (GtkButton       *button,
                                        gpointer         user_data);


void
on_button_precedent_iheb_reservation_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);



void
on_btn_reservation_iheb_nav_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_precedent_iheb_reservation_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_afficher_par_fonction_kh_button_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_calander_resrver_iheb_day_selected_double_click
                                        (GtkCalendar     *calendar,
                                        gpointer         user_data);

void
on_calander_resrver_iheb_day_selected  (GtkCalendar     *calendar,
                                        gpointer         user_data);

void
on_afficher_res_par_date_ik_clicked    (GtkButton       *button,
                                        gpointer         user_data);
