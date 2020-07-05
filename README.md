# QuizRoom
QuizRoom è un applicazione desktop (sviluppata con **Qt**) che permette di creare/eseguire dei quiz. L'applicativo è stato pensato sopratutto per essere usato in ambito educativo tra professori e studenti.
Maggiori informazioni possono essere trovate nei file `relazione_mantovani.pdf` e `relazione_petrea.pdf`.

All'interno dell'artifacts (archivio scaricabile di nome **build**) si trova l'eseguibile **Progetto_P2**. Per eseguire il programma in ambiente Linux (dopo aver scaricato Qt) si deve scrivere il seguente comando : `./Progetto_P2`

## Divisione Model-Control-View (MCV)
Il progetto è diviso in cartelle contenenti i file raggruppati per diversa categoria:
*  **Model**: contiene i modelli (struttura) del nostro software
*  **Control**: contiene `controlller.h` e `controller.cpp`
*  **View**: contiene la GUI (interfaccia grafica) del nostro software 
*  **Resources**: contiene il foglio di stile `(style.css)` per gli elementi dell'app e le immagini dell'app