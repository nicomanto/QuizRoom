# QuizRoom

[![Linux Build badge](https://img.shields.io/gitlab/pipeline/nicomanto/progetto_p2/master?label=Linux%20build)](https://shields.io/)

## Descrizione
QuizRoom è un applicazione desktop (sviluppata con **Qt**) che permette di creare/eseguire dei quiz. L'applicativo è stato pensato soprattutto per essere usato in ambito educativo tra professori e studenti.
Maggiori informazioni possono essere trovate nei file `relazione_mantovani.pdf` e `relazione_petrea.pdf`.

### Requisiti
Qt 5.12.5 o successivo

### Compilazione
L'applicativo è stato creato per essere eseguito in ambiente Linux, anche se Windows è supportato. Per l'eseguibile già compilato si rimanda alla repository su *GitLab* https://gitlab.com/nicomanto/progetto_p2.
Per eseguire il programma in ambiente Linux (dopo aver scaricato Qt) si deve scrivere il seguente comando : `./Progetto_P2`

Se invece si desidera avere il codice sorgente, per eseguire l'applicazione bisogna:

1. scaricare la *repository* da *GitHub*
2. aprire il terminale (prompt dei comandi)
3. spostarsi nella repository appena scaricata
4. scrivere `qmake Progetto_P2.pro` e successivamente `make`
5. eseguire con il comando `./Progetto_P2`

## Divisione Model-Control-View (MCV)
Il progetto è diviso in cartelle contenenti i file raggruppati per diversa categoria:
*  **Model**: contiene i modelli (struttura) del nostro software
*  **Control**: contiene `controlller.h` e `controller.cpp` i quali garantiscono lo scambio di dati fra GUI e modello
*  **View**: contiene la GUI (interfaccia grafica) del nostro software 
*  **Resources**: contiene la cartella **Style_sheet** contenente i fogli di stile (**css**). Inoltre contiene la cartella **Images** con le immagini utilizzate all'interno dell'app

## Valutazione
Il progetto è stato valutato fra ottimo ed eccellente, qui di seguito alcune considerazioni:

### Vincoli obbligatori
* Warning non gravi durante la compilazione (unused parameter, sign compare)

### Orientamento ad oggetti
* Incapsulamento
* Modularità (modello logico e la GUI sono separati)
* Estensibilità ed evolvibilità, polimorfismo


### Funzionalità
* Sono utilizzate diverse gerarchie
* Sistema di autenticazione multi-utente
* Sistema di gestione di quiz/compiti


### GUI
* Visualizza i diversi tipi di dato in maniera opportuna
* Usabile e intuitiva
* Robusta, gestisce ridimensionamento
* Aspetti grafici ben curati
