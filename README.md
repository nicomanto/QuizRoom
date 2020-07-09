# QuizRoom
QuizRoom è un applicazione desktop (sviluppata con **Qt**) che permette di creare/eseguire dei quiz. L'applicativo è stato pensato sopratutto per essere usato in ambito educativo tra professori e studenti.
Maggiori informazioni possono essere trovate nei file `relazione_mantovani.pdf` e `relazione_petrea.pdf`.

All'interno dell'artifacts (archivio scaricabile alla voce **build** del download) si trova l'eseguibile **Progetto_P2**. Per eseguire il programma in ambiente Linux (dopo aver scaricato Qt) si deve scrivere il seguente comando : `./Progetto_P2`

## Divisione Model-Control-View (MCV)
Il progetto è diviso in cartelle contenenti i file raggruppati per diversa categoria:
*  **Model**: contiene i modelli (struttura) del nostro software
*  **Control**: contiene `controlller.h` e `controller.cpp`
*  **View**: contiene la GUI (interfaccia grafica) del nostro software 
*  **Resources**: contiene la cartella **Style_sheet** contenente i fogli di stile (**css**). Inoltre contiene la cartella **Images** con le immagini utilizzate all'interno dell'app

## Valutazione
Il progetto è stato valutato fra ottimo ed eccellente, qui di seguito alcune considerazioni:

**Vincoli obbligatori**
* Warning non gravi durante la compilazione (unused parameter, sign compare)

**Orientamento ad oggetti**
* Incapsulamento
* Modularità (modello logico e la GUI sono separati)
* Estensibilità ed evolvibilità, polimorfismo


**Funzionalità**
* Sono utilizzate diverse gerarchie
* Sistema di autenticazione multi-utente
* Sistema di gestione di quiz/compiti


**GUI**
* Visualizza i diversi tipi di dato in maniera opportuna
* Usabile e intuitiva
* Robusta, gestisce ridimensionamento
* Aspetti grafici ben curati