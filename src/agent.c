#include "agent.h"
#include <stdio.h>
#include <string.h>

#include <gtk/gtk.h>

int ajouter_agent(char *filename, agent a) {
    FILE *f = fopen(filename, "a");
    if (f != NULL) {
        fprintf(f, "%d %d %d %s %s %s %d %s\n", a.ID_agent, a.ID_parking, a.ID_service,
                a.nom_agent, a.prenom_agent, a.sexe, a.numero_tel, a.fonction_agent);
        fclose(f);
        return 1;
    }
    return -1;
}

int modifier_agent(char *filename, int ID, agent nouv) {
    int tr = 0;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("tempo.txt", "w");
    agent a;

    if (f != NULL && f2 != NULL) {
        while (fscanf(f, "%d %d %d %s %s %s %d %s\n", &a.ID_agent, &a.ID_parking, &a.ID_service,
                      a.nom_agent, a.prenom_agent, a.sexe, &a.numero_tel, a.fonction_agent) != EOF) {
            if (a.ID_agent == ID) {
                fprintf(f2, "%d %d %d %s %s %s %d %s\n", nouv.ID_agent, nouv.ID_parking, nouv.ID_service,
                        nouv.nom_agent, nouv.prenom_agent, nouv.sexe, nouv.numero_tel, nouv.fonction_agent);
                tr = 1;
            } else {
                fprintf(f2, "%d %d %d %s %s %s %d %s\n", a.ID_agent, a.ID_parking, a.ID_service,
                        a.nom_agent, a.prenom_agent, a.sexe, a.numero_tel, a.fonction_agent);
            }
        }
        fclose(f);
        fclose(f2);
        remove(filename);
        rename("tempo.txt", filename);
    } else {
        tr = -1;
    }
    return tr;
}

int supprimer_agent(char *filename, int ID) {
    int tr = 0;
    agent a;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("nouv.txt", "w");
printf("here");
    if (f != NULL && f2 != NULL) {
        while (fscanf(f, "%d %d %d %s %s %s %d %s\n", &a.ID_agent, &a.ID_parking, &a.ID_service,
                      a.nom_agent, a.prenom_agent, a.sexe, &a.numero_tel, a.fonction_agent) != EOF) {
            if (a.ID_agent == ID) {
                tr = 1;
            } else {
                fprintf(f2, "%d %d %d %s %s %s %d %s\n", a.ID_agent, a.ID_parking, a.ID_service,
                        a.nom_agent, a.prenom_agent, a.sexe, a.numero_tel, a.fonction_agent);
            }
        }
        fclose(f);
        fclose(f2);
        remove(filename);
        rename("nouv.txt", filename);
    } else {
        tr = -1;
    }
    return tr;
}

agent chercher_agent(char *filename, int ID) {
    agent a;
    a.ID_agent = -1;
    FILE *f = fopen(filename, "r");

    if (f != NULL) {
        while (fscanf(f, "%d %d %d %s %s %s %d %s\n", &a.ID_agent, &a.ID_parking, &a.ID_service,
                      a.nom_agent, a.prenom_agent, a.sexe, &a.numero_tel, a.fonction_agent) != EOF) {
            if (a.ID_agent == ID) {
                fclose(f);
                return a;
            }
        }
        fclose(f);
    }
    return a;
}

int afficher_agent(char *filename) {
    agent a;
    FILE *f = fopen(filename, "r");

    if (f != NULL) {
        while (fscanf(f, "%d %d %d %s %s %s %d %s\n", &a.ID_agent, &a.ID_parking, &a.ID_service,
                      a.nom_agent, a.prenom_agent, a.sexe, &a.numero_tel, a.fonction_agent) != EOF) {
            printf("%d %d %d %s %s %s %d %s\n", a.ID_agent, a.ID_parking, a.ID_service,
                   a.nom_agent, a.prenom_agent, a.sexe, a.numero_tel, a.fonction_agent);
        }
        fclose(f);
        return 1;
    }
    return -1;
}


void afficher_reservation(char*file_reservation,char date_reservation[]) {
reservation res ;
FILE*f=fopen("reservation.txt","r");
if (f!=NULL) {
while (fscanf(f,"%d" "%d" "%d" "%d" "%s" "%s",&res.id_reservation,&res.id_client,&res.id_parking,&res.duree_reservation,res.nom_parking,res.date_reservation)!=EOF){

    if(strcmp(res.date_reservation,date_reservation)==0) {
    printf("id_reservation: %d\n",res.id_reservation);
     printf("id_client: %d\n",res.id_client);
      printf("id_parking: %d\n",res.id_parking);
        printf("durée_reservation: %d\n",res.duree_reservation);
         printf("nom_parking: %s\n",res.nom_parking);
            printf("date_resevation: %s\n",res.date_reservation); 

 }
     }


fclose(f);
}else{
printf("echec affichage :impossible d'ovrir le fichier.\n"); 
 }
   }

    
/*

void afficher_agent(GtkWidget* treeview1,char*l)
{
	GtkListStore *adstore;
	GtkTreeViewColumn *adcolumn;
	GtkCellRenderer *cellad;
	FILE *f;
	Utilisateur u;
        int i;
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_INT,
				     G_TYPE_INT,
          	       	             G_TYPE_INT,
				     G_TYPE_INT
                                     );
        f=fopen(l,"r");
while(fscanf(f,"%s %s %d %d %d %d ",u.nom,u.prenom,&u.mdp,&u.sexe,&u.role,&u.id)!=EOF)
        {GtkTreeIter pIter;
         gtk_list_store_append(adstore, &pIter);
         gtk_list_store_set(adstore, &pIter,
                            0,u.nom,
                            1,u.prenom,
                            2,u.mdp,
                            3,u.sexe,
                            4,u.role,
                            5,u.id,
                            -1);}
        fclose(f);
if(i==0)
{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("nom",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("prenom",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("mot de passe",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("sexe(0:HOMME | 1:Femme)",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("role",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("id",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);



i++;}


  gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );
}
*/





