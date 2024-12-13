#include "agent.h"
#include <stdio.h>
#include <string.h>

#include <gtk/gtk.h>
enum
{
    ID,
    Id_Client,
    Id_Parking,
    Duree_Reservation,
    Date_Reservation,
    Nom_Parking,
    COLUMNS
};
enum{
     ID_agent,
     ID_parking,
     ID_service,
     nom_agent,
     prenom_agent,
     sexe,
     numero_tel,
     fonction_agent,
    COLUMNS1
};


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
        while ((fscanf(f, "%d %d %d %s %s %s %d %s\n", &a.ID_agent, &a.ID_parking, &a.ID_service,
                      a.nom_agent, a.prenom_agent, a.sexe, &a.numero_tel, a.fonction_agent)) != EOF) {
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

    if (f != NULL && f2 != NULL) {
        while (fscanf(f, "%d %d %d %s %s %s %d %s\n", &a.ID_agent, &a.ID_parking, &a.ID_service,
                      a.nom_agent, a.prenom_agent, a.sexe, &a.numero_tel, a.fonction_agent) != EOF) {
            if (a.ID_agent == ID) {
                tr = 1;
            } 
            else {
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
        while (fscanf(f, "%d %d %d %s %s %s %d %s\n", &a.ID_agent, &a.ID_parking, &a.ID_service,a.nom_agent, 
                            a.prenom_agent, a.sexe, &a.numero_tel, a.fonction_agent) != EOF) {
            if (a.ID_agent == ID) {
                fclose(f);
                return a;
            }
           

        }
        fclose(f);
    }
    a.ID_agent=-1;
    return a;
}
/*
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
*/
    


void afficher_agent(GtkWidget* treeview1,char*filename)
{
	GtkListStore *adstore;
	GtkTreeViewColumn *adcolumn;
	GtkCellRenderer *cellad;
	FILE *f;
	agent a;
        int i;
        adstore=NULL;
    
    adstore = gtk_tree_view_get_model(treeview1);
        if(adstore==NULL){
            cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ID",
                                                            cellad,
                                                            "text", ID_agent,
                                                            NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ID parking",
                                                            cellad,
                                                            "text", Id_Parking,
                                                            NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ID service",
                                                            cellad,
                                                            "text", ID_service,
                                                            NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Nom",
                                                            cellad,
                                                            "text", nom_agent,
                                                            NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Prénom",
                                                            cellad,
                                                            "text", prenom_agent,
                                                            NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Sexe",
                                                            cellad,
                                                            "text", sexe,
                                                            NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Numero tel",
                                                            cellad,
                                                            "text", numero_tel,
                                                            NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Fonction   ",
                                                            cellad,
                                                            "text",fonction_agent,
                                                            NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
        }
        adstore = gtk_list_store_new(COLUMNS1,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING);
        
        f=fopen(filename,"r");
while(fscanf(f,"%d %d %d %s %s %s %d %s", &a.ID_agent, &a.ID_parking, &a.ID_service,
                   a.nom_agent, a.prenom_agent, a.sexe, &a.numero_tel, a.fonction_agent)!=EOF)
        {GtkTreeIter pIter;
         gtk_list_store_append(adstore, &pIter);
         gtk_list_store_set(adstore, &pIter,
                            0,a.ID_agent,
                            1,a.ID_parking,
                            2,a.ID_service,
                            3,a.nom_agent,
                            4,a.prenom_agent,
                            5,a.sexe,
                            6,a.numero_tel,
                            7,a.fonction_agent,
                            -1);}
        fclose(f);



  gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );
    g_object_unref(adstore);

}

void ReservationParDate(date date_reservation){
reservation res;
FILE *f = fopen("reservation.txt", "r");
FILE *f1 = fopen("reservationParDate.txt", "w");
if(f!=NULL && f1!=NULL){
    while(fscanf(f,"%d %d %d %d %s %d %d %d\n",&res.id_reservation,&res.id_client,&res.id_parking,&res.duree_reservation,
        res.nom_parking,&res.date_reservation.jour,&res.date_reservation.mois,&res.date_reservation.annee
    )!=EOF){
        
        if((res.date_reservation.jour == date_reservation.jour) && (res.date_reservation.mois == date_reservation.mois+1) && (res.date_reservation.annee == date_reservation.annee)){
            
            fprintf(f1,"%d %d %d %d %s %d %d %d\n",res.id_reservation,res.id_client,res.id_parking,res.duree_reservation,
        res.nom_parking,res.date_reservation.jour,res.date_reservation.mois,res.date_reservation.annee);
        }


    }
    fclose(f);
    fclose(f1);


}

}


void afficher_reservation(GtkWidget* treeview1,char*filename)
{
	GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    FILE *f;
    reservation res;
    f=fopen(filename,"r");
    char *buf1;
    store = NULL;
    store = gtk_tree_view_get_model(treeview1);
    if (store == NULL)
    {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text", ID, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Id Client", renderer, "text", Id_Client, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Id parking", renderer, "text", Id_Parking, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Duree Reservation", renderer, "text", Duree_Reservation, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Nom Parking", renderer, "text", Nom_Parking, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), column);
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Date Reservation", renderer, "text", Date_Reservation, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), column);
        
    }
    store = gtk_list_store_new(COLUMNS, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING);
    while((fscanf(f,"%d %d %d %d %s %d %d %d",&res.id_reservation,&res.id_client,&res.id_parking,&res.duree_reservation,res.nom_parking,
    &res.date_reservation.jour,&res.date_reservation.mois,&res.date_reservation.annee))!=EOF)
            {
            buf1=g_strdup_printf("%d %d %d",res.date_reservation.jour,res.date_reservation.mois,res.date_reservation.annee);
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, ID,res.id_reservation, Id_Client, res.id_client, Id_Parking, res.id_parking, Duree_Reservation, res.duree_reservation, Nom_Parking, res.nom_parking,Date_Reservation, buf1, -1);
            g_free(buf1);
            }
        
    
    gtk_tree_view_set_model(GTK_TREE_VIEW(treeview1), GTK_TREE_MODEL(store));
    g_object_unref(store);
    fclose(f);
}

void AgentParFonction(int fonction){
    agent a;
    char role[20];
    
    FILE *f = fopen("agent.txt", "r+");
    FILE *f2 = fopen("agentParFonction.txt", "w+");
    if(fonction==1){
        strcpy(role,"1-securite_parking");
    }
    else{
        strcpy(role,"2-tarif_parking");
    }
    if (f != NULL && f2 != NULL) {
        while (fscanf(f,"%d %d %d %s %s %s %d %s\n", &a.ID_agent, &a.ID_parking, &a.ID_service,
                   a.nom_agent, a.prenom_agent, a.sexe, &a.numero_tel, a.fonction_agent)!=EOF) {
           
            
            if (!strcmp(role,a.fonction_agent)) {
                fprintf(f2, "%d %d %d %s %s %s %d %s\n", a.ID_agent, a.ID_parking, a.ID_service,
                        a.nom_agent, a.prenom_agent, a.sexe, a.numero_tel, a.fonction_agent);
            }
        }
        fclose(f);
        fclose(f2);
    }
}

