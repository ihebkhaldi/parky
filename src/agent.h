#ifndef AGENT_H_INCLUDED
#define AGENT_H_INCLUDED

#include <stdio.h>
#include <gtk/gtk.h>


typedef struct {
    int jour;
    int mois;
    int annee;
} date;

typedef struct {
    int ID_agent;
    int ID_parking;
    int ID_service;
    char nom_agent[10];
    char prenom_agent[15];
    char sexe[10];
    int numero_tel;
    char fonction_agent[20];
} agent;

typedef struct {
int id_reservation;
int id_client;
int id_parking;
int duree_reservation;
date date_reservation;
char nom_parking[20];
} reservation;

int ajouter_agent(char *filename, agent a);
int modifier_agent(char *filename, int ID, agent nouv);
int supprimer_agent(char *filename, int ID);
//int afficher_agent(char *filename);
agent chercher_agent(char *filename, int ID);
void afficher_agent(GtkWidget* treeview1,char*filename);
void afficher_reservation(GtkWidget* treeview1,char*filename);
void ReservationParDate(date date_reservation);
void AgentParFonction(int fonction);
#endif
