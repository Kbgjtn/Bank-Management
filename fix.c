/** 
* @title: FINAL PROJECT - BANK MANAGEMENT SYSTEM
* @desc: A program to manage several saving accounts. The program must have a feature to create new account and save its data. The new account will have
data about account’s owner name, conta  cts, its creation date, and its initial saving sum (in IDR). The program also needs to have a feature to deposit and withdraw some value from an account. There is a limit for deposit and withdraw that must be enforced by the program. The minimum
amount of deposit is Rp. 100.000. Any value below that limit should be responded by proper error message. The maximum value of withdrawal is Rp. 5.000.000. Any value exceeds that limit should be responded by proper error message. The program also needs to have a feature to close an account. If this feature is chosen, the account data should be deleted from the program.
* @uthors: coocobolo
*/

// file lib-header
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// pre-process
#define lli long long int
#define MAX_SIZE 1000

/**
 * @description: structure bank data untuk menyimpan data client dan waktu pembuatan 
 * @declare: char Name[50], pin[10], NoPhone[30], Adress[200], year[5], month[15], day[3]
 */

typedef struct bankData {
    lli saldo;
    char name[50];
    char pin[10];

    struct clientData {
        char noPhone[30];
        char address[200];
    } Person;

    struct  createdTime {
        char year[5];
        char month[15];
        char day[3];
    } Times;
} BankData;

// initialization functions
int optionFeatures(char *act);
int validationUser(int hasil);
char *toLowerCase(char *words, size_t length);
void team15();
void accountInfo();
void closeAccount();
void createAccount();
void createFileData();
void display(char act);
void displayTransaction();
void nowUser(char *pin, char *username);
void printall();
void transaction();


/**
 * @description: main function
 * @declare: action, count
 * @callfunction: team15()
 * @return value 0 & exit program
 */


int main() {
    // declare variable
    char action;
    int count;
    
    do {
        team15();
        
        printf("\t\t     Do you Have Account?[Y/N]\n");
        printf("\t\t     Input: ");
        scanf("%c", &action);

        // tolower
        
        if ((action != 'y') || (action != 'Y') || (action != 'N') || (action != 'n')) {
            printf("\n\n\t\t     ALERT: INCORRECT, PLEASE TRY AGAIN!");
            getchar();
        }
        if ((action == 'y') || (action == 'Y') || (action == 'N') || (action == 'n')) {
            optionFeatures(&action);
        }
        
        system("cls") || system("clear");

    } while ((action != 'y') || (action != 'Y') || (action != 'N') || (action != 'n'));    

    getchar();

    // return value 0   
    return 0;
}

/**
 * @description: void funnction parameter untuk menampilkan fitur menu berdasarkan inputan
 * @param: char act
 * @output: menampilkan fitur menu berdasarkan inputan
 */

void display(char act) {
    if (act == 'y') {
        printf("\t\t     _________________________________________\n");
        printf("\t\t    |                                         |\n");
        printf("\t\t    |         - PROGRAM   FEATURES -          |\n");
        printf("\t\t    |                                         |\n");
        printf("\t\t    |                                         |\n");
        printf("\t\t    |   1 ->  ACCOUNT INFO                    |\n");
        printf("\t\t    |   2 ->  DEPOSIT / WITHDRAW CASH         |\n");
        printf("\t\t    |   3 ->  CLOSE ACCOUNT                   |\n");
        printf("\t\t    |   0 ->  EXIT                            |\n");
        printf("\t\t    |                                         |\n");
        printf("\t\t    |                                         |\n");
        printf("\t\t    |       - - - C C B L  B A N K - - -      |\n");
        printf("\t\t    |_________________________________________|\n");
    
    } else if (act == 'n') {
        printf("\t\t     _________________________________________\n");
        printf("\t\t    |                                         |\n");
        printf("\t\t    |         - PROGRAM   FEATURES -          |\n");
        printf("\t\t    |                                         |\n");
        printf("\t\t    |   1 -> CREATE FILE DATA                 |\n");
        printf("\t\t    |   2 -> CREATE ACCOUNT                   |\n");
        printf("\t\t    |   0 -> MAIN PROGRAM                     |\n");
        printf("\t\t    |                                         |\n");
        printf("\t\t    |       - - - C C B L  B A N K - - -      |\n");
        printf("\t\t    |_________________________________________|\n");
    }
}

/**
 * @description: prosedur untuk  menampilkan data diri client
 * @objek: dataset ke bankData
 * @declare: int find
 * @declare: char pin[9] , username[50]
 * @call: team15(), 
 * @input: username dan pin client
 * @output: data diri client
 */

void accountInfo() {
    BankData dataset;
    
    // call stream file & open file
    FILE *stream;
    stream = fopen("bank.txt", "r");
    
    // declare variables
    int find;
    char pin[9];
    char username[50];
    
    team15();

    printf("\n\n\t\t\t\t    ---------\n");
    printf("\t\t\t\t    | LOGIN |\n");
    printf("\t\t\t\t    ---------\n");

    fflush(stdin);
    printf("\n\t\t     NAME\t: ");
    scanf("%[^\n]s", username);

    fflush(stdin);
    printf("\t\t     PIN \t: ");
    scanf("%[^\n]s", pin);

    system("cls") || system("clear");
    team15();

    while(fread(&dataset, sizeof(BankData), 1, stream)) {
        if ( (strcmp(dataset.pin, pin) == 0) && (strcmp(dataset.name, username) == 0) ) {
            printf("\n\t\t\t\t\t\t    ACCOUNT INFO");
            printf("\n\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
            // name
            printf("\n\n\t\t      >>  NAMA");
            printf("\n\n\t\t            %s\n", dataset.name);
            // pin
            printf("\n\t\t      >>  PIN");
            printf("\n\n\t\t            *********\n");
            // number phone
            printf("\n\t\t      >>  NUMBER PHONE");
            printf("\n\n\t\t            %s\n", dataset.Person.noPhone);
            // address
            printf("\n\t\t      >>  ADDRESS");
            printf("\n\n\t\t             %s\n", dataset.Person.address);
            // time Created
            printf("\n\t\t      >>  TIME CREATED");
            printf("\n\n\t\t             %s/%s/%s\n", dataset.Times.day, dataset.Times.month, dataset.Times.year);
            printf("\n\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
            printf("\n\t\t   OUTPUT: PRESS ENTER TO RETURN TO THE MAIN MENU!");
        }
    }
    // clese file stream
    fclose(stream);
}

/**
 * @description: void function paramater untuk memeriksa akun yang digunakan saat login
 * @objek: datasets ke bankData
 * @output: saldo user
 */

void nowUser(char *pin, char *userName) {
    BankData datasets;
    
    // call stream file & open file
    FILE *stream;
    stream = fopen("bank.txt", "r");
    
    // declare variables
    lli total = 0, scale = 1;

    while (fread(&datasets, sizeof(BankData), 1, stream)) {
        if ((strcmp(datasets.pin, pin) == 0) && (strcmp(datasets.name, userName) == 0)) {
            printf("\n\t\t     _______________________________________\n");
            printf("\n\t\t        >> CARD NUMBER                ");
            printf("\n\n\t\t              **** **** **** ****\n");
            printf("\n\t\t        >> NAME");
            printf("\n\n\t\t              %s\n", datasets.name);
            printf("\n\t\t        >> WALLET: [IDR]");
            
            while (datasets.saldo >= 1000) {
                total = total + scale * (datasets.saldo % 1000);
                datasets.saldo /= 1000;
                scale *= 1000;
            }
    
            printf ("\n\n\t\t              Rp%lld", datasets.saldo);
    
            while (!scale) {
                scale /= 1000;
                datasets.saldo = total / scale;
                total %= scale;
                printf (".%03lld", datasets.saldo);
            }

            printf("\n\t\t     _______________________________________\n");
        }
    } 
    // close file stream
    fclose(stream);
}

/**
 * @description: prosedur melakukan deposit dan withdraw
 * @objek: datasets ke bankData
 * @input: char username dan char pin , int choose, int option, int find, long long integer idr
 * @call: team15(), nowUser(pin, username)
 * @output: jumlah saldo(wallet idr) setelah melakukan transaksi
 */ 

void transaction() {
    BankData datasets;
    
    // call stream file & open file
    FILE *stream, *windowLog;

    // declare variables
    char pin[9], userName[50], choose;
    lli find, option, idr;

    printf("\n\n\t\t\t\t    ---------\n");
    printf("\t\t\t\t    | LOGIN |\n");
    printf("\t\t\t\t    ---------\n");

    // username
    fflush(stdin);
    printf("\n\t\t     NAME\t: ");
    scanf("%[^\n]s", userName);

    // pin
    fflush(stdin);
    printf("\t\t     PIN \t: ");
    scanf("%[^\n]s", pin);
    
    system("cls") || system("clear");
    team15();
    
    stream = fopen("bank.txt", "r");
    
    nowUser(pin, userName);

    while (fread(&datasets, sizeof(BankData), 1, stream)) {
        if ((strcmp(datasets.pin, pin) == 0) && (strcmp(datasets.name, userName) == 0)) {
            if (!datasets.saldo) {
                printf("\n\t\t     ALERT: WALLET(IDR) NOW Rp%lld, TO MAKE A TRANSACTIOB. PLEASE MAKE A DEPOSIT!\n", datasets.saldo);
            }
        }
    }

    // exit stream file
    fclose(stream);
   
    stream = fopen("bank.txt", "r");
    windowLog = fopen("window-log.txt", "w");
    
    printf("\n\n\t\t     Do you want to make a transaction now? [y|N]");
    printf("\n\t\t     Input: ");
    scanf(" %c", &choose);
    
    system("cls") || system("clear");
    // call function
    team15();
    nowUser(pin, userName);
    
    if ((choose == 'y') || (choose == 'Y')) {
        do {
            system("cls") || system("clear");
            // call function
            team15();
            nowUser(pin, userName);
            printf("\n\t\t     ALERT: CHOOSE FEATURES U WANNA USE!\n");
            
            // call function
            displayTransaction();
            printf("\t\t     Input: ");
            scanf("%lld", &option);
            
            system("cls") || system("clear");
            
            switch (option) {
                case 1:
                    nowUser(pin, userName);
                    printf("\n\t\t     ALERT: MINIMUM DEPOSITE Rp100.000\n");
                    printf("\n\t\t     DEPOSIT AMOUNT: ");
                    scanf("%lld", &idr);
                    
                    if (idr < 100000) {
                        printf("\n\t\t    ALERT: MINIMUM DEPOSITE Rp100.000\n");
                        idr = 0;
                    }

                    stream = fopen("bank.txt", "r");
                    windowLog = fopen("windowlog.txt", "w");
                    
                    while ( fread (&datasets, sizeof(BankData), 1, stream) ) {
                        if ( (strcmp(datasets.pin, pin) == 0) && (strcmp(datasets.name, userName) == 0)) {
                            if (!idr) {
                                find = 0;
                            } 
                            else if (idr) {
                                datasets.saldo = datasets.saldo + idr;
                                find = 1;
                            }
                        }
                        fwrite(&datasets, sizeof(BankData), 1, windowLog);
                    }
                    
                    // exit streams file
                    fclose(stream);
                    fclose(windowLog);
                    
                    if (!find) {
                        printf("\n\t\t     ALERT: YOUR DEPOSIT WAS NOT SUCCESSFUL!\n");
                    }
                    else if (find) {
                        windowLog = fopen("windowlog.txt", "r");
                        stream = fopen("bank.txt", "w");
                        while ( fread(&datasets, sizeof(BankData), 1, windowLog)) {
                            fwrite (&datasets, sizeof(BankData), 1, stream);
                        }
                        
                        // exit streams file
                        fclose(stream);
                        fclose(windowLog);
                        printf("\n\t\t     ALERT: DEPOSIT AMOUNT: Rp%lld SUCCESSFULLY ADDED!\n", idr);
                    }
                    
                    getchar();
                    break;

                case 2:
                    system("cls") || system("clear");
                    
                    nowUser(pin, userName);

                    printf("\n\t\t     ALERT: MAXIMUM WITHDRAW Rp5.000.000\n");
                    printf("\n\t\t     WITHDRAW AMOUNT: ");
                    scanf("%lld", &idr);
                    
                    if ((idr > 5000000) || (idr < 0)) {
                        idr = 0;
                    }
                    
                    // initialize stream & windowLog file
                    stream = fopen("bank.txt", "r");
                    windowLog = fopen("windowlog.txt", "w");
                    
                    while ( fread(&datasets, sizeof(BankData), 1, stream) ) {
                        if ( (strcmp(datasets.pin, pin) == 0) && (strcmp(datasets.name, userName) == 0) ) {
                            if (datasets.saldo < idr) {
                                find = 0;
                            }
                            else if (datasets.saldo >= idr) {
                                datasets.saldo = datasets.saldo - idr;
                                find = 1;
                            }
                        }
                        // write file
                        fwrite(&datasets, sizeof(BankData), 1, windowLog);
                    }

                    // close streams file
                    fclose(stream);
                    fclose(windowLog);
                    
                    if (find) {
                        windowLog = fopen("windowlog.txt", "r");
                        stream = fopen("bank.txt", "w");
                        
                        while (fread(&datasets, sizeof(BankData), 1, windowLog)) {
                            fwrite (&datasets, sizeof(BankData), 1, stream);
                        }
                        
                        // close stream & windowLog
                        fclose(stream);
                        fclose(windowLog);
                        
                        if (idr > 0 && idr <= 5000000) {
                            printf("\n\t\t     ALERT: WITHDRAW AMOUNT: Rp%lld SUCCESSFULLY!\n", idr);
                            getchar();
                        }
                    }else if (find == 0) {
                        printf("\n\t\t     ALERT: WITHDRAW WAS NOT SUCCESSFULLY! CHECK AGAIN!\n");
                        printf("\n\t\t     ALERT: YOUR WALLET IS NOT ENOUGH!\n");
                        printf("\n\t\t     ALERT: TRANSACTION FAILED!\n");
                    }
                    break;
                case 0:
                    printf("\n\t\t     ALERT: RETURN TO THE MAIN PROGRAM\n");
                    break;
                default:
                    printf("\n\t\t     ALERT: INCORRECT, PLEASE TRY AGAIN\n");
                    break;
            }
            getchar();
        } while (option != 0);
    }else if ((choose == 'n') || (choose == 'N')) {
        printf("\n\t\t     ALERT: RETURN TO THE MAIN PROGRAM\n");
        getchar();
    }else {
        printf("\n\t\t     ALERT: INCORRECT, PLEASE TRY AGAIN\n");
        getchar();
    }

    fclose(stream);
    fclose(windowlog);

    printf("\n\t\t     PRESS ENTER TO RETURN TO THE MAIN MENU!");
}

/**
 * @description: prosedur yang menutup akan user
 * @objek: datasets ke bankData
 * @decare: int found, char pin, username, delete
 * @input: username dan pin client dan kata 'Delete' untuk menutup tabungan
 * @output: tampilan sukses jika berhasil dihapus dan tampilan sukses apabila tidak berhasil dihapus
 * @author: Naufal Daffa
 */

void closeAccount() {
    bankData datasets;
    FILE *stream, *windowlog;

    stream = fopen("bank.txt", "r");
    windowlog = fopen("windowlog.txt", "w");
    
    int found;
    char pin[9];
    char username[50];
    char delete[7];

    // input name & pin
    printf("\n\t\t\t\t     DELETE ACCOUNT");
    printf("\n\t\t     - - - - - - - - - - - - - - - - - - - - - -");
    fflush(stdin);
    printf("\n\t\t     ACCOUNT NAME : ");
    scanf("%[^\n]s", username);
    fflush(stdin);
    printf("\t\t     ACCOUNT PIN  : ");
    scanf("%[^\n]s", pin);
    printf("\t\t     - - - - - - - - - - - - - - - - - - - - - -\n");


    while (fread(&datasets, sizeof(bankData), 1, stream)) {
        if((strcmp(datasets.pin, pin) == 0) && (strcmp(datasets.Name, username) == 0)) {
            found = 1;
        }
        if((strcmp(datasets.pin, pin) != 0) && (strcmp(datasets.Name, username) != 0)) {
            fwrite(&datasets, sizeof(bankData), 1, windowlog);
            continue;
        }
    }
    fclose(stream);
    fclose(windowlog);

    printf("\n\t\t     ALERT: WRITE \"Delete\" TO CONTINUE.\n");
    printf("\n\t\t     Input: ");
    scanf(" %[^\n]s", delete);
    
    if ((strcmp(delete, "Delete") != 0)) {
        found = 0;
    }else if ((strcmp(delete, "Delete") != 0)){
        found = 1;
    }
    
    if (found == 1) {
        windowlog = fopen("windowlog.txt", "r");
        stream = fopen("bank.txt", "w");

        while (fread(&datasets, sizeof(bankData), 1, windowlog)) {
            fwrite (&datasets, sizeof(bankData), 1, stream);
        }
        fclose(stream);
        fclose(windowlog);
        
        printf("\n\t\t     ALERT: ACCOUNT CLOSURE WAS SUCCESSFUL");
        getchar();
        printf("\n\t\t     ALERT: PRESS ENTER TO EXIT THE PROGRAM");
        getchar();
        // exit program
        exit(1);
    }else if (found == 0) {
        printf("\n\t\t     ALERT: ACCOUNT CLOSURE WAS NOT SUCCESSFUL");
    }
}

// for maintenance

void printall() {
    bankData datasets;
    FILE *stream;
    stream = fopen("bank.txt", "r");

    while(fread(&datasets, sizeof(bankData), 1, stream)) {
        printf("\n\t\t     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
        printf("\n\t\t     Nama: %s\n", datasets.Name);
        printf("\n\t\t     PIN: %s\n", datasets.pin);
        printf("\n\t\t     No HP: %s\n", datasets.person.NoPhone);
        printf("\n\t\t     Address: %s\n", datasets.person.Address);
        printf("\n\t\t     Created: %s/%s/%s\n", datasets.times.year, datasets.times.month, datasets.times.day);
        printf("\n\t\t     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    }
    fclose(stream);
    
}

/**
 * @description: prosedur membuat akun disertai data client
 * @objek: pointer dataset ke struct bankData
 * @input: banyak akun yang dibuat(n)
 * @output: tampilkan sukses jika akun berhasil dibuat, serta gagal jika akun tidak berhasil dibuat
 * @author: Chrysant M
 */

void createAccount() {
    bankData *dataset;
    FILE *stream;
    stream = fopen("bank.txt", "a");
    int n, i;

    dataset = (bankData*) calloc(n, sizeof(bankData));
    printf("\t\t     How many account u wanna create: ");
    scanf("%d", &n);


    for (i = 0; i < n; i++) {
        printf("\n\t\t\t\t          ___________________________\n");
        printf("\n\t\t\t\t               CREATE ACCOUNT #%d", i+1);
        printf("\n\t\t\t\t          ___________________________\n");
        
        // input nama client
        fflush(stdin);
        printf("\n\t\t     ____________________________________________________________________\n\n");
        printf("\n\t\t      >> NAME         : ");
        scanf("%[^\n]s", dataset[i].Name);
        
        // input kontak client
        fflush(stdin);
        printf("\n\t\t      >> NUMBER PHONE : ");
        scanf("%[^\n]s", dataset[i].person.NoPhone);

        // input alamat client
        fflush(stdin);
        printf("\n\t\t      >> ADDRESS      : ");
        scanf("%[^\n]s", dataset[i].person.Address);

        // input pin akun
        fflush(stdin);
        printf("\n\t\t      >> PIN          : ");
        scanf("%[^\n]s", dataset[i].pin);
        
        // input tahun pembuatan akun
        fflush(stdin);
        printf("\n\t\t      >> YEAR         : ");
        scanf("%[^\n]s", dataset[i].times.year);

        // input bulan pembuatan akun
        fflush(stdin);
        printf("\n\t\t      >> MONTH        : ");
        scanf("%[^\n]s", dataset[i].times.month);

        // input tanggal pembuatan akun
        fflush(stdin);
        printf("\n\t\t      >> DAY          : ");
        scanf("%[^\n]s", dataset[i].times.day);

        fwrite(&dataset[i], sizeof(bankData), 1, stream);
        printf("\n\t\t     ALERT: ACCOUNT #%d CREATED SUCCESSFULLY.\n", i+1);
        printf("\n\t\t     ____________________________________________________________________\n\n");
    }

    if (stream) {
        printf("\n\t\t     ALERT: %d ACCOUNT CREATED SUCCESSFULLY.\n", n);
    } else if (stream == NULL) {
        printf("\n\t\t     ALERT: DATA FILE WAS NOT CREATED SUCCESSFULLY.\n");
    }

    getchar();
    fclose(stream);
}

/**
 * @description: prosedur yang membuat file dengan nama bank.txt
 * @objek: pointer dataset ke struct bankData
 * @output: tampilkan sukses jika file data  berhasil dibuat, serta gagal jika file data tidak berhasil dibuat
 * @author: Ayasha K
 */

void createFileData() {
    bankData *dataset;
    FILE *stream;
    stream = fopen("bank.txt", "w");
    
    if (stream) {
        printf("\n\t\t     ALERT: DATA FILE CREATED SUCCESSFULLY.\n");
    } else {
        printf("\n\t\t     ALERT: DATA FILE WAS NOT CREATED SUCCESSFULLY.\n");
    }
    
    fclose(stream);
    getchar();
}

/**
 * @description: fungsi yang memiliki mengeksekusi opsi fitur yang diinputkan
 * @param: char *act
 * @declare: int valid, option, count
 * @call: team15(), display(), accountInfo(), transaction(), closeAccount(), createFileData(), createAccount()
 * @author: Naufal Daffa
 * @return: mengeksekusi prosedur atau fungsi berdasarkan fitur dan input
 */

int optionFeatures(char *act) {
    int valid = 0, option, count = 5;
    do {
        if ((*act == 'y') || (*act == 'Y')) {        
            system("cls") || system("clear");
            team15();
            
            do {
                count--;
                if (count == 0) {
                    getchar();
                    printf("\n\t\t     ALERT: EXIT , YOU EXCEED THE MAXIMUM LIMIT!");
                    return(1);
                }
                valid = validationUser(0);
                printf("\n\t\t     ALERT: SORRY, YOUR PIN OR USERNAME WAS INCORRECT.\n");
                printf("\t\t            PLEASE DOUBLE-CHECK YOUR PASSWORD.\n");
            } while (valid==0);
            system("cls") || system("clear");

            do {
                team15();
                printf("\n\t\t     ALERT: CHOOSE FEATURES U WANNA USE!\n");

                // function calls
                display('y');
                printf("\t\t     Input: ");

                // input option
                scanf("%d", &option);
                system("cls") || system("clear");

                // condition option of feature
                switch(option) {
                    case 1:
                        // function create call
                        accountInfo();
                        getchar();
                        break;
                    case 2:
                        // function create call
                        team15();   
                        transaction(); 
                        break;
                    case 3:
                        // function deposite or withdraw call
                        closeAccount();
                        getchar();
                        break;
                    case 0:
                        // exit program
                        printf("\n\t\t     Output: Exit Program!\n");
                        exit(1);
                        break;
                    default:
                        // else condition
                        team15();
                        printf("\n\t\t     Output: INCORRECT, FEATURE NOT FOUND!\n");
                        break;
                }
                getchar();
                system("cls") || system("clear");
            } while (option != 0);
        }else if (*act == 'n' || *act == 'N') {
            system("cls") || system("clear");
            team15();
            printf("\n\t\t     ALERT: PLEASE CREATE UR ACCOUNT FIRST!\n");
            do {       
                // function calls
                display('n');
                printf("\t\t     Input: ");
                scanf("%d", &option);

                // condition option of feature
                switch(option) {
                    case 1:
                        createFileData();
                        break;
                    case 2:
                        // function create call
                        system("cls") || system("clear");
                        team15();
                        createAccount();
                        break;
                    case 0:
                        // exit program
                        printf("\n\t\t     ALERT: MAIN PROGRAM!");
                        *act = 'y';
                        break;
                    default:
                        // else condition
                        printf("\n\t\t\t    Output: Incorrect, Feature Not Found!\n");
                        break;
                }
                printf("\n\t\t     PRESS ENTER TO CONTINUE!");
                getchar();
                system("cls") || system("clear");
                team15();
            } while(option != 0);
        }
    }while (1);
}

/**
 * @description: fungsi pengecekan akun dan memastikan user memiliki akun untuk login
 * @param: int hasil
 * @return: hasil = 1 jika valid, serta hasil = 0 jika tidak valid dengan Nama dan Pin
 * @writer: Naufal Daffa
 */ 

int validationUser(int hasil) {
    FILE *stream;
    bankData dataset;
    stream = fopen("bank.txt", "r");
    
    if (stream == NULL) {
        printf("\n\t\t     ALERT: FILE NOT FOUND\n");
        exit(1);
    }
    
    char pin[9];
    char username[50];
    hasil = 0;

    // input name & pin
    printf("\n\n\t\t\t\t    ---------\n");
    printf("\t\t\t\t    | LOGIN |\n");
    printf("\t\t\t\t    ---------\n");

    fflush(stdin);
    printf("\n\t\t     NAME\t: ");
    scanf("%[^\n]s", username);

    fflush(stdin);
    printf("\t\t     PIN \t: ");
    scanf("%[^\n]s", pin);
    
    // Validation
    while(fread(&Dataset, sizeof(bankData), 1, stream)){
        if((strcmp(dataset.pin, pin) == 0) && (strcmp(dataset.Name, username) == 0)) {
            hasil = 1;
            return hasil;
        }else if ((strcmp(dataset.pin, pin) != 0) || (strcmp(dataset.Name, username) != 0)) {
            hasil = 0;
            continue;
        }
    }
        
    fclose(stream);
    return 0;
}

/**
 * @description: prosedur menampilkan fitur menu transaksi.
 * @writer: Chrysant
 */

void displayTransaction() {
    printf("\t\t     _________________________________________\n");
    printf("\t\t    |                                         |\n");
    printf("\t\t    |         - TRANSACTION   FEATURES -      |\n");
    printf("\t\t    |                                         |\n");
    printf("\t\t    |   1 -> DEPOSIT                          |\n");
    printf("\t\t    |   2 -> WITHDRAW                         |\n");
    printf("\t\t    |   0 -> MAIN PROGRAM                     |\n");
    printf("\t\t    |                                         |\n");
    printf("\t\t    |_________________________________________|\n");
}

/**
 * @description: prosedur untuk menampilkan "Team 15"
 */

void team15() {
    printf("\n\n");
    printf("\t\t __________ \t  _______ \t   ______ \t _____________  \t\n");
    printf("\t\t|___    ___|\t |   ____|\t /   _   \\\t|     ___     |\t\n");
    printf("\t\t    |  |    \t |  |____ \t|   ___   |\t|    +___+    |\t ====\n");
    printf("\t\t    |  |    \t |   ____|\t|  |   |  |\t|  |  | |  |  |\t\" 15 \"\n");
    printf("\t\t    |  |    \t |  |____ \t|  |   |  |\t|  |  | |  |  |\t ====\n");
    printf("\t\t    |__|    \t |_______|\t|__|   |__|\t|__|  |_|  |__|\t\n\n\n");
    printf("\t\t| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |\n\n\n");
}