/*
 * ============================================================================
 * COSESTRANE - Header File
 * ============================================================================
 * Gioco di avventura testuale con esplorazione di due mondi paralleli
 * Creato da: Hanaji Tancre'
 * Anno: 2025-2026
 * Corso: Programmazione Procedurale
 * ============================================================================
 */

#ifndef GAMELIB_H
#define GAMELIB_H

/* ============================================================================
 * COSTANTI DI GIOCO
 * ============================================================================ */

/* Parametri base giocatore */
#define PV_INIZIALI  80
#define ZONE_MINIME  15
#define NOME_MAX     50
#define ZAINO_MAX     3

/* Probabilità generazione nemici Mondo Reale (%) */
#define PROB_NESSUN_NEMICO_MR    40
#define PROB_DEMOCANE_MR         30  /* 40-70% = Democane */
/* 70-100% = Billi */

/* Probabilità generazione nemici Soprasotto (%) */
#define PROB_NESSUN_NEMICO_SS    50

/* Probabilità generazione oggetti (%) */
#define PROB_NESSUN_OGGETTO      50
#define PROB_BICICLETTA          15  /* 50-65% */
#define PROB_MAGLIETTA           15  /* 65-80% */
#define PROB_BUSSOLA             10  /* 80-90% */
/* 90-100% = Schitarrata */

/* Statistiche nemici */
#define HP_BILLI                 20
#define ATTACCO_BILLI             5
#define DIFESA_BILLI              3

#define HP_DEMOCANE              35
#define ATTACCO_DEMOCANE          8
#define DIFESA_DEMOCANE           5

#define HP_DEMOTORZONE           60
#define ATTACCO_DEMOTORZONE      12
#define DIFESA_DEMOTORZONE        7

/* Bonus oggetti */
#define BONUS_BICICLETTA_FORTUNA     3
#define BONUS_MAGLIETTA_ATTACCO      5
#define BONUS_BUSSOLA_FORTUNA        2
#define BONUS_SCHITARRATA_ATTACCO    3
#define BONUS_SCHITARRATA_DIFESA     3

/* Modifiche abilità */
#define MODIFICA_ATTACCO_DIFESA      3
#define BONUS_UNDICI_ATTACCO         4
#define BONUS_UNDICI_DIFESA          4
#define MALUS_UNDICI_FORTUNA         7

/* Combattimento */
#define COSTO_ATTACCO_POTENZIATO     3
#define MOLTIPLICATORE_POTENZIATO  1.5
#define BONUS_DIFESA_TEMPORANEO      5

/* ============================================================================
 * ENUMERAZIONI
 * ============================================================================ */

/**
 * Tipi di zona disponibili nel gioco
 * Ogni tipo rappresenta un ambiente diverso con caratteristiche uniche
 */
typedef enum {
    BOSCO,
    SCUOLA,
    LABORATORIO,
    CAVERNA,
    STRADA,
    GIARDINO,
    SUPERMERCATO,
    CENTRALE_ELETTRICA,
    DEPOSITO_ABBANDONATO,
    STAZIONE_POLIZIA
} Tipo_zona;

/**
 * Tipi di nemico che il giocatore può incontrare
 * NESSUN_NEMICO: zona sicura
 * BILLI: nemico debole, presente solo nel Mondo Reale
 * DEMOCANE: nemico medio, presente in entrambi i mondi
 * DEMOTORZONE: boss finale, solo una volta nel Soprasotto
 */
typedef enum {
    NESSUN_NEMICO,
    BILLI,
    DEMOCANE,
    DEMOTORZONE
} Tipo_nemico;

/**
 * Tipi di oggetto raccoglibili
 * Ogni oggetto fornisce bonus diversi quando utilizzato
 */
typedef enum {
    NESSUN_OGGETTO,
    BICICLETTA,              /* +3 Fortuna */
    MAGLIETTA_FUOCOINFERNO,  /* +5 Attacco */
    BUSSOLA,                 /* +2 Fortuna */
    SCHITARRATA_METALLICA    /* +3 Attacco, +3 Difesa */
} Tipo_oggetto;

/**
 * I due mondi paralleli del gioco
 * MONDO_REALE: dimensione normale, punto di partenza
 * SOPRASOTTO: dimensione oscura e pericolosa, contiene il boss finale
 */
typedef enum {
    MONDO_REALE,
    SOPRASOTTO
} Tipo_mondo;

/* ============================================================================
 * STRUTTURE DATI
 * ============================================================================ */

/* Forward declaration per dipendenza circolare */
typedef struct Zona_soprasotto Zona_soprasotto;

/**
 * Struttura per una zona del Mondo Reale
 * Implementa una lista doppiamente concatenata
 * Ogni zona è collegata alla corrispondente zona del Soprasotto
 */
typedef struct Zona_mondoreale {
    Tipo_zona tipo;                      /* Tipo di ambiente della zona */
    Tipo_nemico nemico;                  /* Nemico presente (se presente) */
    Tipo_oggetto oggetto;                /* Oggetto presente (se presente) */
    struct Zona_mondoreale* avanti;      /* Puntatore alla zona successiva */
    struct Zona_mondoreale* indietro;    /* Puntatore alla zona precedente */
    Zona_soprasotto* link_soprasotto;    /* Link alla zona parallela nel Soprasotto */
} Zona_mondoreale;

/**
 * Struttura per una zona del Soprasotto
 * Implementa una lista doppiamente concatenata
 * Ogni zona è collegata alla corrispondente zona del Mondo Reale
 */
struct Zona_soprasotto {
    Tipo_zona tipo;                      /* Tipo di ambiente (stesso del Mondo Reale) */
    Tipo_nemico nemico;                  /* Nemico presente (Democane o Demotorzone) */
    struct Zona_soprasotto* avanti;      /* Puntatore alla zona successiva */
    struct Zona_soprasotto* indietro;    /* Puntatore alla zona precedente */
    Zona_mondoreale* link_mondoreale;    /* Link alla zona parallela nel Mondo Reale */
};

/**
 * Struttura che rappresenta un giocatore
 * Contiene tutte le statistiche, la posizione e l'inventario
 */
typedef struct Giocatore {
    char nome[NOME_MAX];                 /* Nome del giocatore */
    Tipo_mondo mondo;                    /* Mondo in cui si trova attualmente */
    Zona_mondoreale* pos_mondoreale;     /* Posizione nel Mondo Reale */
    Zona_soprasotto* pos_soprasotto;     /* Posizione nel Soprasotto */
    int attacco_psichico;                /* Statistica di attacco */
    int difesa_psichica;                 /* Statistica di difesa */
    int fortuna;                         /* Statistica di fortuna */
    int punti_vita;                      /* Punti vita correnti */
    Tipo_oggetto zaino[ZAINO_MAX];       /* Inventario oggetti */
} Giocatore;

/* ============================================================================
 * FUNZIONI PUBBLICHE
 * ============================================================================ */

/**
 * Inizializza il gioco configurando giocatori e mappa
 * Permette di:
 * - Scegliere il numero di giocatori (1-4)
 * - Impostare nomi e abilità per ogni giocatore
 * - Creare e personalizzare la mappa di gioco
 * - Validare la mappa prima di iniziare la partita
 */
void imposta_gioco(void);

/**
 * Avvia la partita vera e propria
 * Gestisce i turni dei giocatori fino alla vittoria o alla sconfitta
 * Prerequisito: deve essere stata chiamata imposta_gioco() con successo
 */
void gioca(void);

/**
 * Termina il gioco liberando tutta la memoria allocata
 * Pulisce le strutture dati di giocatori e mappe
 */
void termina_gioco(void);

/**
 * Visualizza i crediti del gioco
 * Mostra autore, statistiche di gioco e ultimi vincitori
 */
void crediti(void);

#endif /* GAMELIB_H */