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
on_afficher_reservation_clicked        (GtkButton       *button,
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
on_btn_modifier_iheb_nav_clicked       (GtkButton       *button,
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
