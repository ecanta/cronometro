<h1>Cronometro</h1>

Questo è un semplice cronometro in C++ che permette di misurare la durata di più eventi e visualizzarli al termine dell'esecuzione

<h2>Controlli</h2>

Durante l'esecuzione del programma, i controlli sono i seguenti:
+ Barra spaziatrice (`SPACE`):
  + Alla prima pressione, avvia il cronometro.
  + Pressioni successive registrano uno split, cioè un intervallo temporale.
+ Tasto Invio (`ENTER`):
  + Termina la misurazione e mostra il riepilogo di tutti i tempi registrati.
 
<h2>Esempio di output</h2>

```
0 min & 4.33 sec  
0 min & 5.93 sec  
0 min & 6.71 sec  
0 min & 7.49 sec  
0 min & 9.21 sec  
0 min & 10.76 sec  
0 min & 11.89 sec  

TEMPI:
#1  : 0 min & 4.35 sec  
#2  : 0 min & 1.59 sec  
#3  : 0 min & 0.78 sec  
#4  : 0 min & 0.77 sec  
#5  : 0 min & 1.72 sec  
#6  : 0 min & 1.54 sec  
#7  : 0 min & 1.14 sec  

```

I tempi vengono visualizzati con colori ANSI per distinguere visivamente i tempi più rilevanti (se il terminale supporta).
