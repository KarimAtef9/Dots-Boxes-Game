#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

struct Player {
    int score;
    char symbol;
    int moves;
    int Moves_left;
    int existent;
    char name[100];
    int help;
} player1, player2;

void highScore() {
    FILE *text = fopen("highscore.txt", "r+");
    if(text == NULL) {//if file does not exist, create it
        text = fopen("highscore.txt", "wb");
    }
    if (text != NULL) {
        fseek(text, 0, SEEK_END);
        if (player1.score > player2.score) {
            fprintf(text, "%s %d\n", player1.name, player1.score);
        } else if (player1.score < player2.score) {
            if (player2.existent == 1) {
                fprintf(text, "%s %d\n", player2.name, player2.score);
            }
        } else {
            fprintf(text, "%s %d\n", player1.name, player1.score);
            if (player2.existent == 1) {
                fprintf(text, "%s %d\n", player2.name, player2.score);
            }
        }
        fclose(text);
    }
}

struct highscore {
    int score;
    char name[100];
} allhighscore[100];

void name() {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
    printf("Enter player 1 name :\n");
    SetConsoleTextAttribute(hConsole, 15);
    scanf(" %[^\t\n]s", &player1.name);
    SetConsoleTextAttribute(hConsole, 11);
    if (player2.existent == 1) {
        printf("Enter player 2 name :\n");
        SetConsoleTextAttribute(hConsole, 15);
        scanf(" %[^\t\n]s", &player2.name);
        SetConsoleTextAttribute(hConsole, 11);
    }
    SetConsoleTextAttribute(hConsole, 15);
    system("cls");
    printf("\n\t\tGamed Started\n\n\n");
}

void color(int n, int m, char a[][m], int r1, int r2, int c1, int c2, int clr[][m], int counter) {
    if (player1.help == 1) {
        counter--;
    }
    if (counter % 2 != 0) {
        if (r1 == r2) {
            if (c1 < c2) {
                clr[r1 * 4 - 3][c1 * 4 - 2] = 9;
                clr[r1 * 4 - 3][c1 * 4 - 1] = 9;
                clr[r1 * 4 - 3][c1 * 4] = 9;
            } else {
                clr[r1 * 4 - 3][c2 * 4 - 2] = 9;
                clr[r1 * 4 - 3][c2 * 4 - 1] = 9;
                clr[r1 * 4 - 3][c2 * 4] = 9;
            }
        } else if (c1 == c2) {
            if (r1 < r2) {
                clr[r1 * 4 - 2][c1 * 4 - 3] = 9;
                clr[r1 * 4 - 1][c1 * 4 - 3] = 9;
                clr[r1 * 4][c1 * 4 - 3] = 9;
            } else {
                clr[r2 * 4 - 2][c1 * 4 - 3] = 9;
                clr[r2 * 4 - 1][c1 * 4 - 3] = 9;
                clr[r2 * 4][c1 * 4 - 3] = 9;
            }
        }
    } else {
        if (r1 == r2) {
            if (c1 < c2) {
                if (player2.existent == 1) {
                    clr[r1 * 4 - 3][c1 * 4 - 2] = 12;
                    clr[r1 * 4 - 3][c1 * 4 - 1] = 12;
                    clr[r1 * 4 - 3][c1 * 4] = 12;
                } else {
                    clr[r1 * 4 - 3][c1 * 4 - 2] = 13;
                    clr[r1 * 4 - 3][c1 * 4 - 1] = 13;
                    clr[r1 * 4 - 3][c1 * 4] = 13;
                }
            } else {
                if (player2.existent == 1) {
                    clr[r1 * 4 - 3][c2 * 4 - 2] = 12;
                    clr[r1 * 4 - 3][c2 * 4 - 1] = 12;
                    clr[r1 * 4 - 3][c2 * 4] = 12;
                } else {
                    clr[r1 * 4 - 3][c2 * 4 - 2] = 13;
                    clr[r1 * 4 - 3][c2 * 4 - 1] = 13;
                    clr[r1 * 4 - 3][c2 * 4] = 13;
                }
            }
        } else if (c1 == c2) {
            if (r1 < r2) {
                if (player2.existent == 1) {
                    clr[r1 * 4 - 2][c1 * 4 - 3] = 12;
                    clr[r1 * 4 - 1][c1 * 4 - 3] = 12;
                    clr[r1 * 4][c1 * 4 - 3] = 12;
                } else {
                    clr[r1 * 4 - 2][c1 * 4 - 3] = 13;
                    clr[r1 * 4 - 1][c1 * 4 - 3] = 13;
                    clr[r1 * 4][c1 * 4 - 3] = 13;
                }
            } else {
                if (player2.existent == 1) {
                    clr[r2 * 4 - 2][c1 * 4 - 3] = 12;
                    clr[r2 * 4 - 1][c1 * 4 - 3] = 12;
                    clr[r2 * 4][c1 * 4 - 3] = 12;
                } else {
                    clr[r2 * 4 - 2][c1 * 4 - 3] = 13;
                    clr[r2 * 4 - 1][c1 * 4 - 3] = 13;
                    clr[r2 * 4][c1 * 4 - 3] = 13;
                }
            }
        }
    }
}

void print_array(int n, int m, char a[][m], int counter, int clr[n][m]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            HANDLE hConsole;
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, clr[i][j]);
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
}

void prnt_a(int n, int m, char a[][m]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }

}

void digram(int n, int m, char a[n][m], int clr[][m]) {
    int i, j, k = 1;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            clr[i][j] = 0;
            a[i][j] = 32;
        }
    }
    for (i = 1; i < n; i = i + 4) {
        clr[0][i] = 15;
        clr[i][0] = 15;
        a[0][i] = k + 48;
        a[i][0] = k + 48;
        k++;
        for (j = 1; j < m; j = j + 4) {
            clr[i][j] = 15;
            a[i][j] = 42;
        }
    }
}

void level() {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
    int x;
    int n, m;
    printf("1)Beginner mode\n2)Expert mode\n3)Previous Menu\n");
    printf("Enter the mode :\n");
    char c[1];
    SetConsoleTextAttribute(hConsole, 15);
    scanf("%s", c);
    SetConsoleTextAttribute(hConsole, 11);
    x = c[0] - 48;
    system("cls");
    switch (x) {
        case 1:
            n = 10, m = 10;
            break;
        case 2:
            n = 18, m = 18;
            break;
        case 3:
            system("cls");
            Game_mode();
            break;
        default:
            system("cls");
            printf("Select one of the two modes above\n");
            level();
    }
    SetConsoleTextAttribute(hConsole, 15);
    char a[n][m];
    int clr[n][m];
    name(player1, player2);
    digram(n, m, a, clr);
    prnt_a(n, m, a);
    declaration(player1, player2);
    clock_t begin = clock();
    draw(n, m, a, clr, 0, 1, begin);
}

void level_computer() {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
    int x;
    int n, m;
    printf("1)Beginner mode\n2)Expert mode\n3)Previous Menu\n");
    printf("Select the difficulty :\n");
    SetConsoleTextAttribute(hConsole, 15);
    scanf("%d", &x);
    SetConsoleTextAttribute(hConsole, 11);
    system("cls");
    switch (x) {
        case 1:
            n = 10, m = 10;
            break;
        case 2:
            n = 18, m = 18;
            break;
        case 3 :
            system("cls");
            Game_mode();
            break;
        default:
            system("cls");
            printf("Select one of the two choices\n");
            level();
    }
    SetConsoleTextAttribute(hConsole, 15);
    char a[n][m];
    int clr[n][m];
    name(player1, player2);
    digram(n, m, a, clr);
    prnt_a(n, m, a);
    declaration(player1, player2);
    clock_t begin = clock();
    draw_Computer(n, m, a, clr, 0, 1, begin);
}

void Game_mode() {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
    int x;
    int n, m;
    printf("1)Vs Human\n2)Vs Computer\n3)Previous Menu\n");
    printf("Enter the mode :\n");
    char s[4];
    SetConsoleTextAttribute(hConsole, 15);
    scanf("%s", s);
    SetConsoleTextAttribute(hConsole, 11);
    x = s[0] - 48;
    system("cls");
    switch (x) {
        case 1 :
            player2.existent = 1;
            level();
            break;
        case 2 :
            player2.existent = 0;
            level_computer();
            break;
        case 3 :
            system("cls");
            Main_Menu();
            break;
        default:
            system("cls");
            printf("Select one of the two modes\n");
            Game_mode();
    }
    SetConsoleTextAttribute(hConsole, 15);
}

void Main_Menu() {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
    int n;
    printf("1) Start Game\n");
    printf("2) Leader Board\n");
    printf("3) Load Game\n");
    printf("4) Exit\n");
    char c[1];
    SetConsoleTextAttribute(hConsole, 15);
    scanf("%s", c);
    SetConsoleTextAttribute(hConsole, 11);
    n = c[0] - 48;
    switch (n) {
        case 1 :
            printf("\n\t\tGamed Started\n\n\n");
            system("cls");
            Game_mode();
            break;
        case 2 :
            system("cls");
            printf("\n\t\tLeader Board\n\n\n");
            sort_highscore();
        case 3 :
            load();
            break;
        case 4 :
            printf("Thank you for playing \n");
            SetConsoleTextAttribute(hConsole, 15);
            exit(0);
            break;
        default:
            system("cls");
            printf("Please select one of the following :\n");
            Main_Menu();
            break;
    }
}

void menu() {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    char s[1];
    SetConsoleTextAttribute(hConsole, 11);
    printf("\n1)Main menu\n2)Exit \n");
    SetConsoleTextAttribute(hConsole, 15);
    scanf("%s", s);
    switch (s[0]) {
        case '1':
            system("cls");
            Main_Menu();
        case '2':
            SetConsoleTextAttribute(hConsole, 11);
            printf("Thank you for playing!");
            SetConsoleTextAttribute(hConsole, 15);
            exit(0);
            break;
        default :
            system("cls");
            printf("Please Select option from below :\n");
            menu();
    }
}

void sort_highscore() {
    int i, j;
    FILE *text;
    text = fopen("highscore.txt", "r+");
    for (i = 0; i < 100; i++) {
        fscanf(text, "%s %d", allhighscore[i].name, &allhighscore[i].score);
    }
    for (i = 0; i < 100; i++) {
        for (j = i + 1; j < 100; j++) {
            if (strcmp(allhighscore[i].name, allhighscore[j].name) == 0) {
                if (allhighscore[i].score > allhighscore[j].score) {
                    memset(allhighscore[j].name, 0, 5);
                    allhighscore[j].score = 0;
                } else {
                    memset(allhighscore[i].name, 0, 5);
                    allhighscore[i].score = 0;
                }
            }
        }

    }
    for (i = 0; i < 100; i++) {
        for (j = i + 1; j < 100; j++) {
            if (allhighscore[i].score < allhighscore[j].score) {
                int temp = allhighscore[i].score;
                allhighscore[i].score = allhighscore[j].score;
                allhighscore[j].score = temp;
                char temp2[10];
                strcpy(temp2, allhighscore[i].name);
                strcpy(allhighscore[i].name, allhighscore[j].name);
                strcpy(allhighscore[j].name, temp2);
            }
        }
    }
    for (i = 0; i < 10; i++) {
        printf("%s %d\n", allhighscore[i].name, allhighscore[i].score);
    }
    fseek(text, 0, SEEK_END);
    for (i = 0; i < 10; i++) {
        fprintf(text, "%s %d\n", allhighscore[i].name, allhighscore[i].score);
    }
    fclose(text);
    menu();
}

void Steps_and_Movements(int n, int m, char a[n][m], int r1, int c1, int r2, int c2, int counter) {
    if (r1 == r2) {
        if (c1 < c2) {
            a[r1 * 4 - 3][c1 * 4 - 2] = 45;
            a[r1 * 4 - 3][c1 * 4 - 1] = 45;
            a[r1 * 4 - 3][c1 * 4] = 45;
        } else {
            a[r1 * 4 - 3][c2 * 4 - 2] = 45;
            a[r1 * 4 - 3][c2 * 4 - 1] = 45;
            a[r1 * 4 - 3][c2 * 4] = 45;
        }
    } else if (c1 == c2) {
        if (r1 < r2) {
            a[r1 * 4 - 2][c1 * 4 - 3] = 124;
            a[r1 * 4 - 1][c1 * 4 - 3] = 124;
            a[r1 * 4][c1 * 4 - 3] = 124;
        } else {
            a[r2 * 4 - 2][c1 * 4 - 3] = 124;
            a[r2 * 4 - 1][c1 * 4 - 3] = 124;
            a[r2 * 4][c1 * 4 - 3] = 124;
        }
    }

    if (counter % 2 == 0) {
        player2.moves++;
    } else {
        player1.moves++;
    }
}

void Close_the_box(int n, int m, char c[n][m], int *counter, int clr[n][m]) {
    int i, j, k = *counter;
    player1.help = 0;
    for (i = 1; i < n; i++) {
        for (j = 1; j < m; j++) {
            if (c[i][j] == 124 && c[i][j - 4] == 124 && c[i - 2][j - 2] == 45 && c[i + 2][j - 2] == 45) {
                if ((c[i][j - 2] != '*') && (c[i][j - 2] != 124) && (c[i][j - 2] != 45) && (c[i][j - 2] != '\0') &&
                    (c[i][j - 2] != 65) && (c[i][j - 2] != 66) && (c[i][j - 2] != 67)) {
                    // we need to change it for each player
                    if (*counter % 2 == 0) {
                        if (player2.existent == 1) {
                            clr[i][j - 2] = 12;
                            c[i][j - 2] = 'B';
                        } else {
                            clr[i][j - 2] = 13;
                            c[i][j - 2] = 'C';
                        }
                        player2.score++;
                        player1.help = 1;
                        k = 1;
                    } else {
                        clr[i][j - 2] = 9;
                        c[i][j - 2] = 'A';
                        player1.score++;
                        player1.help = 1;
                        k = 0;
                    }
                }
            }
        }
    }
    *counter = k;
}

void declaration() {
    player1.score = 0;
    player2.score = 0;
    player1.symbol = 'A';
    player2.symbol = 'B';
    player1.moves = 0;
    player2.moves = 0;
    player1.Moves_left = 12;
    player2.Moves_left = 40;
}

void Data_displayed(int counter, int n, clock_t begin) {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (counter % 2 == 0) {
        if (player2.existent == 1) {
            SetConsoleTextAttribute(hConsole, 12);
            printf("\n%s turn !", player2.name);
        } else {
            SetConsoleTextAttribute(hConsole, 13);
            printf("\nComputer turn !");
        }
    } else {
        SetConsoleTextAttribute(hConsole, 9);
        printf("\n%s turn !", player1.name);
    }
    SetConsoleTextAttribute(hConsole, 9);
    if (player2.existent == 1) {
        printf("\n%s score : %d", player1.name, player1.score);
        printf("\n%s moves : %d", player1.name, player1.moves);
        SetConsoleTextAttribute(hConsole, 12);
        printf("\n%s score : %d", player2.name, player2.score);
        printf("\n%s moves : %d", player2.name, player2.moves);
    } else {
        printf("\n%s score : %d", player1.name, player1.score);
        printf("\n%s moves : %d", player1.name, player1.moves);
        SetConsoleTextAttribute(hConsole, 13);
        printf("\nComputer score : %d", player2.score);
        printf("\nComputer moves : %d", player2.moves);
    }
    SetConsoleTextAttribute(hConsole, 15);
    if (n == 10) {
        printf("\nMoves left : %d\n", player1.Moves_left);
    } else {
        printf("\nMoves left : %d\n", player2.Moves_left);
    }
    clock_t end = clock();
    int time_spent = (int) (end - begin) / CLOCKS_PER_SEC;
    printf("Time taken : %.2d:%.2d\n\n", time_spent / 60, time_spent % 60);
    SetConsoleTextAttribute(hConsole, 11);
    printf("For undo please type \"undo\"\n");
    printf("For redo please type \"redo\"\n");
    printf("For exit please type \"exit\"\n");
    printf("For Main Menu please type \"menu\"\n");
    SetConsoleTextAttribute(hConsole, 15);
}

void Data_displayed_Game_Over(clock_t begin) {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 9);
    printf("\n%s score : %d", player1.name, player1.score);
    printf("\n%s moves : %d", player1.name, player1.moves);
    if (player2.existent == 1) {
        SetConsoleTextAttribute(hConsole, 12);
        printf("\n%s score : %d", player2.name, player2.score);
        printf("\n%s moves : %d", player2.name, player2.moves);
    } else {
        SetConsoleTextAttribute(hConsole, 13);
        printf("\nComputer score : %d", player2.score);
        printf("\nComputer moves : %d\n", player2.moves);
    }
    SetConsoleTextAttribute(hConsole, 15);
    clock_t end = clock();
    int time_spent = (int) (end - begin) / CLOCKS_PER_SEC;
    printf("Time taken : %.2d:%.2d\n", time_spent / 60, time_spent % 60);
}

void Game_Over(clock_t begin) {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    char s[1];
    if (player1.score > player2.score) {
        if (player2.existent == 1) {
            SetConsoleTextAttribute(hConsole, 9);
            printf("\n%s Win !\n\n", player1.name);
            printf("\n%s score : %d", player1.name, player1.score);
            printf("\n%s moves : %d", player1.name, player1.moves);
            SetConsoleTextAttribute(hConsole, 12);
            printf("\n%s score : %d", player2.name, player2.score);
            printf("\n%s moves : %d", player2.name, player2.moves);
        } else {
            SetConsoleTextAttribute(hConsole, 9);
            printf("\n%s Win !\n\n", player1.name);
            printf("\n%s score : %d", player1.name, player1.score);
            printf("\n%s moves : %d", player1.name, player1.moves);
            SetConsoleTextAttribute(hConsole, 13);
            printf("\nComputer score : %d", player2.score);
            printf("\nComputer moves : %d", player2.moves);
        }
    } else if (player1.score < player2.score) {
        if (player2.existent == 1) {
            SetConsoleTextAttribute(hConsole, 12);
            printf("\n%s Win !\n\n", player2.name);
            printf("\n%s score : %d", player2.name, player2.score);
            printf("\n%s moves : %d", player2.name, player2.moves);
            SetConsoleTextAttribute(hConsole, 9);
            printf("\n%s score : %d", player1.name, player1.score);
            printf("\n%s moves : %d", player1.name, player1.moves);
        } else {
            SetConsoleTextAttribute(hConsole, 13);
            printf("\nComputer Win !\n\n");
            printf("\nComputer score : %d", player2.score);
            printf("\nComputer moves : %d", player2.moves);
            SetConsoleTextAttribute(hConsole, 9);
            printf("\n%s score : %d", player1.name, player1.score);
            printf("\n%s moves : %d", player1.name, player1.moves);
        }
    } else {
        SetConsoleTextAttribute(hConsole, 10);
        printf("\nDraw !\n\n");
        printf("\n%s score : %d", player1.name, player1.score);
        printf("\n%s moves : %d", player1.name, player1.moves);
        if (player2.existent == 1) {
            printf("\n%s score : %d", player2.name, player2.score);
            printf("\n%s moves : %d", player2.name, player2.moves);
        } else {
            printf("\nComputer score : %d", player2.score);
            printf("\nComputer moves : %d", player2.moves);
        }
    }
    SetConsoleTextAttribute(hConsole, 15);
    clock_t end = clock();
    int time_spent = (int) (end - begin) / CLOCKS_PER_SEC;
    printf("\nTime taken : %.2d:%.2d\n", time_spent / 60, time_spent % 60);
    highScore();
    menu();
}

void fasterComputer(int *r1, int *c1, int *r2, int *c2, int k) {
    if (k == 3) {
        char moves[12][4] = {"1112", "1121", "1213", "1222", "1323", "2122", "2131", "2223", "2232", "2333", "3132",
                             "3233"};
        int num = (rand() % 13);
        *r1 = moves[num][0] - 48;
        *c1 = moves[num][1] - 48;
        *r2 = moves[num][2] - 48;
        *c2 = moves[num][3] - 48;
    } else {
        char moves[40][4] = {"1112", "1121", "1213", "1222", "1314", "1323", "1415", "1424", "1525",
                             "2122", "2131", "2223", "2232", "2324", "2333", "2425", "2434", "2535",
                             "3132", "3141", "3233", "3242", "3334", "3343", "3435", "3444", "3545",
                             "4142", "4151", "4243", "4252", "4344", "4353", "4445", "4454", "4555",
                             "5152", "5253", "5354", "5455"};
        int num = (rand() % 41);
        *r1 = moves[num][0] - 48;
        *c1 = moves[num][1] - 48;
        *r2 = moves[num][2] - 48;
        *c2 = moves[num][3] - 48;
    }
}

// old version (not used now)
void Computer(int *r1, int *c1, int *r2, int *c2, int k) {
    if (k == 3) {
        if (*r1 == *r2) {
            srand(time(NULL));
            *r1 = (rand() % k) + 1;
            if (*r1 == 3) {
                *r1 = (rand() % k) + 1;
            }
            *c1 = (rand() % k) + 1;
            *r2 = *r1 + 1;
            *c2 = *c1;
        } else {
            srand(time(NULL));
            *r1 = (rand() % k) + 1;
            *c1 = (rand() % k) + 1;
            if (*c1 == 3) {
                *c1 = (rand() % k) + 1;
            }
            *r2 = *r1;
            *c2 = *c1 + 1;
        }
    } else {
        if (*r1 == *r2) {
            srand(time(NULL));
            *r1 = (rand() % k) + 1;
            if (*r1 == 5) {
                *r1 = (rand() % k) + 1;
            }
            *c1 = (rand() % k) + 1;
            *r2 = *r1 + 1;
            *c2 = *c1;
        } else {
            srand(time(NULL));
            *r1 = (rand() % k) + 1;
            *c1 = (rand() % k) + 1;
            if (*c1 == 5) {
                *c1 = (rand() % k) + 1;
            }
            *r2 = *r1;
            *c2 = *c1 + 1;
        }
    }


}

void Undo(int *r1, int *c1, int *r2, int *c2, int i, int g, int arr[g]) {
    *c2 = arr[i - 1];
    *r2 = arr[i - 2];
    *c1 = arr[i - 3];
    *r1 = arr[i - 4];
}

void Redo(int *r1, int *c1, int *r2, int *c2, int i, int g, int arr[g]) {
    *c2 = arr[i - 1];
    *r2 = arr[i - 2];
    *c1 = arr[i - 3];
    *r1 = arr[i - 4];
}

void Undo_Steps_and_Movements(int n, int m, char a[n][m], int r1, int c1, int r2, int c2, int counter) {
    if (r1 == r2) {
        if (c1 < c2) {
            a[r1 * 4 - 3][c1 * 4 - 2] = 32;
            a[r1 * 4 - 3][c1 * 4 - 1] = 32;
            a[r1 * 4 - 3][c1 * 4] = 32;
        } else {
            a[r1 * 4 - 3][c2 * 4 - 2] = 32;
            a[r1 * 4 - 3][c2 * 4 - 1] = 32;
            a[r1 * 4 - 3][c2 * 4] = 32;
        }
    } else if (c1 == c2) {
        if (r1 < r2) {
            a[r1 * 4 - 2][c1 * 4 - 3] = 32;
            a[r1 * 4 - 1][c1 * 4 - 3] = 32;
            a[r1 * 4][c1 * 4 - 3] = 32;
        } else {
            a[r2 * 4 - 2][c1 * 4 - 3] = 32;
            a[r2 * 4 - 1][c1 * 4 - 3] = 32;
            a[r2 * 4][c1 * 4 - 3] = 32;
        }
    }

    if (counter % 2 == 0) {
        player1.moves--;
    } else {
        player2.moves--;
    }
}

void Undo_Close_the_box(int n, int m, char c[n][m], int *counter, int clr[n][m]) {
    int i, j, k = *counter;
    player1.help = 0;
    for (i = 1; i < n; i++) {
        for (j = 1; j < m; j++) {
            if (c[i][j] != 124 || c[i][j - 4] != 124 || c[i - 2][j - 2] != 45 || c[i + 2][j - 2] != 45) {
                if ((c[i][j - 2] == 65) || (c[i][j - 2] == 66) || (c[i][j - 2] == 67)) {
                    // we need to change it for each player
                    if (*counter % 2 == 0) {
                        if (player2.existent == 1) {
                            c[i][j - 2] = 32;
                        } else {
                            c[i][j - 2] = 32;
                        }
                        player1.help = 1;
                        player2.score--;
                        k = 1;
                    } else {
                        c[i][j - 2] = 32;
                        player1.help = 1;
                        player1.score--;
                        k = 0;
                    }
                }
            }
        }
    }
    if (*counter % 2 == 0 && player1.help == 1) {
        player2.moves--;
        player1.moves++;
    } else if (*counter % 2 != 0 && player1.help == 1) {
        player1.moves--;
        player2.moves++;
    }
    *counter = k;
}

void Undo_Close_the_box_Computer(int n, int m, char c[n][m], int counter, int clr[n][m]) {
    int i, j;
    for (i = 1; i < n; i++) {
        for (j = 1; j < m; j++) {
            if (c[i][j] != 124 || c[i][j - 4] != 124 || c[i - 2][j - 2] != 45 || c[i + 2][j - 2] != 45) {
                if ((c[i][j - 2] == 65) || (c[i][j - 2] == 66) || (c[i][j - 2] == 67)) {
                    // we need to change it for each player
                    if (counter % 2 == 0) {
                        if (player2.existent == 1) {

                            c[i][j - 2] = 32;
                        } else {

                            c[i][j - 2] = 32;
                        }
                        player1.score--;
                    } else {

                        c[i][j - 2] = 32;
                        player2.score--;
                    }
                }
            }
        }
    }
}

void Close_the_box_Computer(int n, int m, char c[n][m], int counter, int clr[n][m]) {
    int i, j;
    player2.help = 9;
    player1.help = 0;
    for (i = 1; i < n; i++) {
        for (j = 1; j < m; j++) {
            if (c[i][j] == 124 && c[i][j - 4] == 124 && c[i - 2][j - 2] == 45 && c[i + 2][j - 2] == 45) {
                if ((c[i][j - 2] != '*') && (c[i][j - 2] != 124) && (c[i][j - 2] != 45) && (c[i][j - 2] != '\0') &&
                    (c[i][j - 2] != 65) && (c[i][j - 2] != 66) && (c[i][j - 2] != 67)) {
                    // we need to change it for each player
                    if (counter % 2 == 0) {
                        if (player2.existent == 1) {
                            clr[i][j - 2] = 12;
                            c[i][j - 2] = 'B';
                        } else {
                            clr[i][j - 2] = 13;
                            c[i][j - 2] = 'C';
                        }
                        player2.score++;
                        player1.help = 1;
                        player2.help = 1;
                    } else {
                        clr[i][j - 2] = 9;
                        c[i][j - 2] = 'A';
                        player1.score++;
                        player1.help = 1;
                        player2.help = 0;
                    }
                }
            }
        }
    }
}

void draw_Computer(int n, int m, char a[][m], int clr[][m], int i, int counter, clock_t begin) {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int r1, r2, c1, c2;

    if (n == 10) {
        int g = 48, arr[g], arrC[g], i1 = 0, i2 = 0, k = 3, j1 = 0, j2 = 0;
        for (i; i < 12; i++) {
            if (counter % 2 == 0) {
                fasterComputer(&r1, &c1, &r2, &c2, k);

                if ((((r1 == r2 && (c1 - c2 < 2 && c1 - c2 > -2)) || (c1 == c2 && (r1 - r2 < 2 && r1 - r2 > -2))) &&
                     (r1 != r2 || c1 != c2))
                    && (r1 > 0 && r1 < 4 && c1 > 0 && c1 < 4 && r2 > 0 && r2 < 4 && c2 > 0 && c2 < 4)) {
                    if ((r1 == r2 && c1 < c2 && a[r1 * 4 - 3][c1 * 4 - 1] == 45) ||
                        (r1 == r2 && c1 > c2 && a[r1 * 4 - 3][c2 * 4 - 1] == 45) ||
                        (c1 == c2 && r1 < r2 && a[r1 * 4 - 1][c1 * 4 - 3] == 124) ||
                        (c1 == c2 && r1 > r2 && a[r2 * 4 - 1][c1 * 4 - 3] == 124)) {
                        i--;
                    } else {
                        Data_displayed(counter, n, begin);
                        system("cls");
                        // steps and movements dy 7atsa3edny fe 7kayet el counter we el alwan -------------------------------
                        Steps_and_Movements(n, m, a, r1, c1, r2, c2, counter);
                        arrC[i2] = r1;
                        arrC[i2 + 1] = c1;
                        arrC[i2 + 2] = r2;
                        arrC[i2 + 3] = c2;
                        i2 = i2 + 4;
                        j2 = i2;
                        Close_the_box_Computer(n, m, a, counter, clr);
                        if (player2.help == 1 || player2.help == 0) {
                            counter = 1;
                        }
                        player1.Moves_left--;

                        color(n, m, a, r1, r2, c1, c2, clr, counter);
                        counter++;
                        print_array(n, m, a, counter, clr);
                    }
                } else {
                    i--;
                }
            } else {
                Data_displayed(counter, n, begin);
                printf("Enter the two points numbers starting with the rows :\n");
                char p[4];
                scanf("%s", p);
                if (strcmp(p, "undo") == 0) {
                    counter = 1;
                    if ((player1.moves == 0 && player2.moves == 0) || i2 == 0) {
                        system("cls");

                        print_array(n, m, a, counter, clr);
                        printf("\nNo more undo !");
                    } else {
                        Undo(&r1, &c1, &r2, &c2, i2, g, arrC);
                        Undo_Steps_and_Movements(n, m, a, r1, c1, r2, c2, counter);
                        Undo_Close_the_box_Computer(n, m, a, &counter, clr);
                        system("cls");
                        print_array(n, m, a, counter, clr);
                        counter--;
                        i2 = i2 - 4;
                        player1.Moves_left++;
                        i--;

                        Undo(&r1, &c1, &r2, &c2, i1, g, arr);
                        Undo_Steps_and_Movements(n, m, a, r1, c1, r2, c2, counter);
                        Undo_Close_the_box_Computer(n, m, a, &counter, clr);
                        system("cls");
                        print_array(n, m, a, counter, clr);
                        counter--;
                        i1 = i1 - 4;
                        player1.Moves_left++;
                        i--;

                    }
                    i--;
                } else if (strcmp(p, "redo") == 0) {
                    counter = 1;
                    if (i1 == j1) {
                        system("cls");

                        print_array(n, m, a, counter, clr);
                        printf("\nNo more redo !");
                    } else {
                        i1 = i1 + 4;
                        Redo(&r1, &c1, &r2, &c2, i1, g, arr);
                        Steps_and_Movements(n, m, a, r1, c1, r2, c2, counter);
                        Close_the_box_Computer(n, m, a, counter, clr);
                        system("cls");
                        print_array(n, m, a, counter, clr);
                        counter++;
                        player1.Moves_left--;
                        i++;

                        i2 = i2 + 4;
                        Redo(&r1, &c1, &r2, &c2, i2, g, arrC);
                        Steps_and_Movements(n, m, a, r1, c1, r2, c2, counter);
                        Close_the_box_Computer(n, m, a, counter, clr);
                        system("cls");
                        print_array(n, m, a, counter, clr);
                        counter++;
                        player1.Moves_left--;
                        i++;
                    }
                    i--;
                } else if (strcmp(p, "exit") == 0) {
                    SetConsoleTextAttribute(hConsole, 11);
                    printf("Thank you for playing !\n");
                    SetConsoleTextAttribute(hConsole, 15);
                    exit(0);
                } else if (strcmp(p, "menu") == 0) {
                    system("cls");
                    Main_Menu();
                } else if (strcmp(p, "save") == 0) {
                    system("cls");
                    clock_t end1 = clock();
                    save(n, m, 2, i, counter, a, clr, begin - end1);
                    print_array(n, m, a, counter, clr);
                    printf("\nGame Saved");
                    i--;
                } else {
                    counter = 1;
                    r1 = p[0] - 48;
                    c1 = p[1] - 48;
                    r2 = p[2] - 48;
                    c2 = p[3] - 48;
                    //to check if the inputs are valid or not
                    if (r1 > 0 && r1 < 4 && c1 > 0 && c1 < 4 && r2 > 0 && r2 < 4 && c2 > 0 && c2 < 4) {
                        if (((r1 == r2 && (c1 - c2 < 2 && c1 - c2 > -2)) ||
                             (c1 == c2 && (r1 - r2 < 2 && r1 - r2 > -2))) && (r1 != r2 || c1 != c2)) {
                            if ((r1 == r2 && c1 < c2 && a[r1 * 4 - 3][c1 * 4 - 1] == 45) ||
                                (r1 == r2 && c1 > c2 && a[r1 * 4 - 3][c2 * 4 - 1] == 45) ||
                                (c1 == c2 && r1 < r2 && a[r1 * 4 - 1][c1 * 4 - 3] == 124) ||
                                (c1 == c2 && r1 > r2 && a[r2 * 4 - 1][c1 * 4 - 3] == 124)) {
                                system("cls");
                                print_array(n, m, a, counter, clr);
                                printf("Please select an empty line.\n");
                                i--;
                            } else {
                                system("cls");
                                // steps and movements dy 7atsa3edny fe 7kayet el counter we el alwan--------------------
                                Steps_and_Movements(n, m, a, r1, c1, r2, c2, counter);
                                arr[i1] = r1;
                                arr[i1 + 1] = c1;
                                arr[i1 + 2] = r2;
                                arr[i1 + 3] = c2;
                                i1 = i1 + 4;
                                j1 = i1;
                                Close_the_box_Computer(n, m, a, counter, clr);
                                if (player2.help == 1 || player2.help == 0) {
                                    counter = 0;
                                }
                                player1.Moves_left--;

                                color(n, m, a, r1, r2, c1, c2, clr, counter);
                                counter++;
                                print_array(n, m, a, counter, clr);
                            }
                        } else {
                            system("cls");
                            print_array(n, m, a, counter, clr);
                            printf("Please select two successive points.\n");
                            i--;
                        }
                    } else {
                        system("cls");
                        print_array(n, m, a, counter, clr);
                        printf("Please enter two valid numbers.\n");
                        i--;
                    }
                }

            }

        }
        Game_Over(begin);
        Data_displayed_Game_Over(begin);
    } else if (n == 18) {
        int g = 160, arr[g], arrC[g], i1 = 0, i2 = 0, k = 5, j1 = 0, j2 = 0;
        for (i = 0; i < 40; i++) {
            if (counter % 2 == 0) {
                fasterComputer(&r1, &c1, &r2, &c2, k);
                if ((((r1 == r2 && (c1 - c2 < 2 && c1 - c2 > -2)) || (c1 == c2 && (r1 - r2 < 2 && r1 - r2 > -2))) &&
                     (r1 != r2 || c1 != c2))
                    && (r1 > 0 && r1 < 6 && c1 > 0 && c1 < 6 && r2 > 0 && r2 < 6 && c2 > 0 && c2 < 6)) {
                    if ((r1 == r2 && c1 < c2 && a[r1 * 4 - 3][c1 * 4 - 1] == 45) ||
                        (r1 == r2 && c1 > c2 && a[r1 * 4 - 3][c2 * 4 - 1] == 45) ||
                        (c1 == c2 && r1 < r2 && a[r1 * 4 - 1][c1 * 4 - 3] == 124) ||
                        (c1 == c2 && r1 > r2 && a[r2 * 4 - 1][c1 * 4 - 3] == 124)) {
                        i--;
                    } else {
                        system("cls");
                        // steps and movements dy 7atsa3edny fe 7kayet el counter we el alwan -------------------------------
                        Steps_and_Movements(n, m, a, r1, c1, r2, c2, counter);
                        arrC[i2] = r1;
                        arrC[i2 + 1] = c1;
                        arrC[i2 + 2] = r2;
                        arrC[i2 + 3] = c2;
                        i2 = i2 + 4;
                        j2 = i2;
                        Close_the_box_Computer(n, m, a, counter, clr);
                        if (player2.help == 1 || player2.help == 0) {
                            counter = 1;
                        }
                        player2.Moves_left--;

                        color(n, m, a, r1, r2, c1, c2, clr, counter);
                        counter++;
                        print_array(n, m, a, counter, clr);
                    }
                } else {
                    i--;
                }
            } else {
                Data_displayed(counter, n, begin);
                printf("Enter the two points numbers starting with the rows :\n");
                char p[4];
                scanf("%s", p);
                if (strcmp(p, "undo") == 0) {
                    if ((player1.moves == 0 && player2.moves == 0) || i2 == 0) {
                        system("cls");

                        print_array(n, m, a, counter, clr);
                        printf("\nNo more undo !");
                    } else {
                        Undo(&r1, &c1, &r2, &c2, i2, g, arrC);
                        Undo_Steps_and_Movements(n, m, a, r1, c1, r2, c2, counter);
                        Undo_Close_the_box_Computer(n, m, a, &counter, clr);
                        system("cls");
                        print_array(n, m, a, counter, clr);
                        counter--;
                        i2 = i2 - 4;
                        player2.Moves_left++;
                        i--;

                        Undo(&r1, &c1, &r2, &c2, i1, g, arr);
                        Undo_Steps_and_Movements(n, m, a, r1, c1, r2, c2, counter);
                        Undo_Close_the_box_Computer(n, m, a, &counter, clr);
                        system("cls");
                        print_array(n, m, a, counter, clr);
                        counter--;
                        i1 = i1 - 4;
                        player2.Moves_left++;
                        i--;

                    }
                    i--;
                } else if (strcmp(p, "redo") == 0) {
                    if (i1 == j1) {
                        system("cls");

                        print_array(n, m, a, counter, clr);
                        printf("\nNo more redo !");
                    } else {
                        i1 = i1 + 4;
                        Redo(&r1, &c1, &r2, &c2, i1, g, arr);
                        Steps_and_Movements(n, m, a, r1, c1, r2, c2, counter);
                        Close_the_box_Computer(n, m, a, counter, clr);
                        system("cls");
                        print_array(n, m, a, counter, clr);
                        counter++;
                        player2.Moves_left--;
                        i++;

                        i2 = i2 + 4;
                        Redo(&r1, &c1, &r2, &c2, i2, g, arrC);
                        Steps_and_Movements(n, m, a, r1, c1, r2, c2, counter);
                        Close_the_box_Computer(n, m, a, counter, clr);
                        system("cls");
                        print_array(n, m, a, counter, clr);
                        counter++;
                        player2.Moves_left--;
                        i++;
                    }
                    i--;
                } else if (strcmp(p, "exit") == 0) {
                    SetConsoleTextAttribute(hConsole, 11);
                    printf("Thank you for playing !\n");
                    SetConsoleTextAttribute(hConsole, 15);
                    exit(0);
                } else if (strcmp(p, "menu") == 0) {
                    system("cls");
                    Main_Menu();
                } else if (strcmp(p, "save") == 0) {
                    system("cls");
                    clock_t end1 = clock();
                    save(n, m, 2, i, counter, a, clr, begin - end1);
                    print_array(n, m, a, counter, clr);
                    printf("\nGame Saved");
                    i--;
                } else {
                    r1 = p[0] - 48;
                    c1 = p[1] - 48;
                    r2 = p[2] - 48;
                    c2 = p[3] - 48;
                    if (r1 > 0 && r1 < 6 && c1 > 0 && c1 < 6 && r2 > 0 && r2 < 6 && c2 > 0 &&
                        c2 < 6)//to check if the inputs are valid or not
                    {
                        if (((r1 == r2 && (c1 - c2 < 2 && c1 - c2 > -2)) ||
                             (c1 == c2 && (r1 - r2 < 2 && r1 - r2 > -2))) && (r1 != r2 || c1 != c2)) {
                            if ((r1 == r2 && c1 < c2 && a[r1 * 4 - 3][c1 * 4 - 1] == 45) ||
                                (r1 == r2 && c1 > c2 && a[r1 * 4 - 3][c2 * 4 - 1] == 45) ||
                                (c1 == c2 && r1 < r2 && a[r1 * 4 - 1][c1 * 4 - 3] == 124) ||
                                (c1 == c2 && r1 > r2 && a[r2 * 4 - 1][c1 * 4 - 3] == 124)) {
                                system("cls");
                                print_array(n, m, a, counter, clr);
                                printf("Please select an empty line.\n");
                                i--;
                            } else {
                                system("cls");
                                // steps and movements dy 7atsa3edny fe 7kayet el counter we el alwan -------------
                                Steps_and_Movements(n, m, a, r1, c1, r2, c2, counter);
                                arr[i1] = r1;
                                arr[i1 + 1] = c1;
                                arr[i1 + 2] = r2;
                                arr[i1 + 3] = c2;
                                i1 = i1 + 4;
                                j1 = i1;
                                Close_the_box_Computer(n, m, a, counter, clr);
                                if (player2.help == 1 || player2.help == 0) {
                                    counter = 0;
                                }
                                player2.Moves_left--;

                                color(n, m, a, r1, r2, c1, c2, clr, counter);
                                counter++;
                                print_array(n, m, a, counter, clr);
                            }
                        } else {
                            system("cls");
                            print_array(n, m, a, counter, clr);
                            printf("Please select two successive points.\n");
                            i--;
                        }
                    } else {
                        system("cls");
                        print_array(n, m, a, counter, clr);
                        printf("Please enter two valid numbers.\n");
                        i--;
                    }
                }

            }

        }
        Game_Over(begin);
        Data_displayed_Game_Over(begin);
    }

}

void draw(int n, int m, char a[][m], int clr[][m], int i, int counter, clock_t begin) {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (n == 10) {
        int g = 48, arr[g], i1 = 0, j = 0;
        for (i; i < 12; i++) {
            int r1, r2, c1, c2;
            Data_displayed(counter, n, begin);
            printf("Enter the two points numbers starting with the rows :\n");
            char p[4];
            scanf("%s", p);
            if (strcmp(p, "undo") == 0) {
                if ((player1.moves == 0 && player2.moves == 0) || i1 == 0) {
                    system("cls");

                    print_array(n, m, a, counter, clr);
                    printf("\nNo more undo !");
                } else {
                    Undo(&r1, &c1, &r2, &c2, i1, g, arr);
                    Undo_Steps_and_Movements(n, m, a, r1, c1, r2, c2, counter);
                    Undo_Close_the_box(n, m, a, &counter, clr);
                    system("cls");
                    print_array(n, m, a, counter, clr);
                    counter--;
                    i1 = i1 - 4;
                    player1.Moves_left++;
                    i--;
                }
                i--;
            } else if (strcmp(p, "redo") == 0) {
                if (i1 == j) {
                    system("cls");

                    print_array(n, m, a, counter, clr);
                    printf("\nNo more redo !");
                } else {
                    i1 = i1 + 4;
                    Redo(&r1, &c1, &r2, &c2, i1, g, arr);
                    Steps_and_Movements(n, m, a, r1, c1, r2, c2, counter);
                    Close_the_box(n, m, a, &counter, clr);
                    system("cls");
                    print_array(n, m, a, counter, clr);
                    counter++;
                    player1.Moves_left--;
                    i++;
                }
                i--;
            } else if (strcmp(p, "exit") == 0) {
                SetConsoleTextAttribute(hConsole, 11);
                printf("Thank you for playing !\n");
                SetConsoleTextAttribute(hConsole, 15);
                exit(0);
            } else if (strcmp(p, "menu") == 0) {
                system("cls");
                Main_Menu();
            } else if (strcmp(p, "save") == 0) {
                system("cls");
                clock_t end1 = clock();
                save(n, m, 1, i, counter, a, clr, begin - end1);
                print_array(n, m, a, counter, clr);
                printf("\nGame Saved");
                i--;
            } else {
                r1 = p[0] - 48;
                c1 = p[1] - 48;
                r2 = p[2] - 48;
                c2 = p[3] - 48;
                //to check if the inputs are valid or not
                if (r1 > 0 && r1 < 4 && c1 > 0 && c1 < 4 && r2 > 0 && r2 < 4 && c2 > 0 && c2 < 4) {
                    if (((r1 == r2 && (c1 - c2 < 2 && c1 - c2 > -2)) || (c1 == c2 && (r1 - r2 < 2 && r1 - r2 > -2))) &&
                        (r1 != r2 || c1 != c2)) {
                        if ((r1 == r2 && c1 < c2 && a[r1 * 4 - 3][c1 * 4 - 1] == 45) ||
                            (r1 == r2 && c1 > c2 && a[r1 * 4 - 3][c2 * 4 - 1] == 45) ||
                            (c1 == c2 && r1 < r2 && a[r1 * 4 - 1][c1 * 4 - 3] == 124) ||
                            (c1 == c2 && r1 > r2 && a[r2 * 4 - 1][c1 * 4 - 3] == 124)) {
                            system("cls");
                            print_array(n, m, a, counter, clr);
                            printf("Please select an empty line.\n");
                            i--;
                        } else {
                            system("cls");
                            // steps and movements dy 7atsa3edny fe 7kayet el counter we el alwan -------------------------------
                            Steps_and_Movements(n, m, a, r1, c1, r2, c2, counter);
                            arr[i1] = r1;
                            arr[i1 + 1] = c1;
                            arr[i1 + 2] = r2;
                            arr[i1 + 3] = c2;
                            i1 = i1 + 4;
                            j = i1;
                            Close_the_box(n, m, a, &counter, clr);
                            player1.Moves_left--;

                            color(n, m, a, r1, r2, c1, c2, clr, counter);
                            counter++;
                            print_array(n, m, a, counter, clr);
                        }
                    } else {
                        system("cls");
                        print_array(n, m, a, counter, clr);
                        printf("Please select two successive points.\n");
                        i--;
                    }
                } else {
                    system("cls");
                    print_array(n, m, a, counter, clr);
                    printf("Please enter two valid numbers.\n");
                    i--;
                }
            }

        }
        Game_Over(begin);
        Data_displayed_Game_Over(begin);
    } else if (n == 18) {
        int g = 160, arr[g], i1 = 0, j = 0;
        for (i = 0; i < 40; i++) {
            int r1, r2, c1, c2;
            Data_displayed(counter, n, begin);
            printf("Enter the two points numbers starting with the rows :\n");
            char p[4];
            scanf("%s", p);
            if (strcmp(p, "undo") == 0) {
                if ((player1.moves == 0 && player2.moves == 0) || i1 == 0) {
                    system("cls");

                    print_array(n, m, a, counter, clr);
                    printf("\nNo more undo !");
                } else {
                    Undo(&r1, &c1, &r2, &c2, i1, g, arr);
                    Undo_Steps_and_Movements(n, m, a, r1, c1, r2, c2, counter);
                    Undo_Close_the_box(n, m, a, &counter, clr);
                    system("cls");
                    print_array(n, m, a, counter, clr);
                    counter--;
                    i1 = i1 - 4;
                    player2.Moves_left++;
                    i--;
                }
                i--;
            } else if (strcmp(p, "redo") == 0) {
                if (i1 == j) {
                    system("cls");

                    print_array(n, m, a, counter, clr);
                    printf("\nNo more redo !");
                } else {
                    i1 = i1 + 4;
                    Redo(&r1, &c1, &r2, &c2, i1, g, arr);
                    Steps_and_Movements(n, m, a, r1, c1, r2, c2, counter);
                    Close_the_box(n, m, a, &counter, clr);
                    system("cls");
                    print_array(n, m, a, counter, clr);
                    counter++;
                    player2.Moves_left--;
                    i++;
                }
                i--;
            } else if (strcmp(p, "exit") == 0) {
                SetConsoleTextAttribute(hConsole, 11);
                printf("Thank you for playing !\n");
                SetConsoleTextAttribute(hConsole, 15);
                exit(0);
            } else if (strcmp(p, "menu") == 0) {
                system("cls");
                Main_Menu();
            } else if (strcmp(p, "save") == 0) {
                system("cls");
                clock_t end1 = clock();
                save(n, m, 1, i, counter, a, clr, begin - end1);
                print_array(n, m, a, counter, clr);
                printf("\nGame Saved");
                i--;
            } else {
                r1 = p[0] - 48;
                c1 = p[1] - 48;
                r2 = p[2] - 48;
                c2 = p[3] - 48;
                if (r1 > 0 && r1 < 6 && c1 > 0 && c1 < 6 && r2 > 0 && r2 < 6 && c2 > 0 &&
                    c2 < 6)//to check if the inputs are valid or not
                {
                    if (((r1 == r2 && (c1 - c2 < 2 && c1 - c2 > -2)) || (c1 == c2 && (r1 - r2 < 2 && r1 - r2 > -2))) &&
                        (r1 != r2 || c1 != c2)) {
                        if ((r1 == r2 && c1 < c2 && a[r1 * 4 - 3][c1 * 4 - 1] == 45) ||
                            (r1 == r2 && c1 > c2 && a[r1 * 4 - 3][c2 * 4 - 1] == 45) ||
                            (c1 == c2 && r1 < r2 && a[r1 * 4 - 1][c1 * 4 - 3] == 124) ||
                            (c1 == c2 && r1 > r2 && a[r2 * 4 - 1][c1 * 4 - 3] == 124)) {
                            system("cls");
                            print_array(n, m, a, counter, clr);
                            printf("Please select an empty line.\n");
                            i--;
                        } else {
                            system("cls");
                            // steps and movements dy 7atsa3edny fe 7kayet el counter we el alwan -------------------------------
                            Steps_and_Movements(n, m, a, r1, c1, r2, c2, counter);
                            arr[i1] = r1;
                            arr[i1 + 1] = c1;
                            arr[i1 + 2] = r2;
                            arr[i1 + 3] = c2;
                            i1 = i1 + 4;
                            j = i1;
                            Close_the_box(n, m, a, &counter, clr);
                            player2.Moves_left--;
                            color(n, m, a, r1, r2, c1, c2, clr, counter);
                            counter++;
                            print_array(n, m, a, counter, clr);
                        }
                    } else {
                        system("cls");
                        print_array(n, m, a, counter, clr);
                        printf("Please select two successive points.\n");
                        i--;
                    }
                } else {
                    system("cls");
                    print_array(n, m, a, counter, clr);
                    printf("Please enter two valid numbers.\n");
                    i--;
                }
            }

        }
        Game_Over(begin);
        Data_displayed_Game_Over(begin);
    }

}


int main() {
    Main_Menu();

    return 0;
}

void save(int n, int m, int type, int i, int counter, char a[n][m], int clr[n][m], clock_t end) {
    FILE *file = fopen("save.dat", "w");
    if (file != NULL) {
        // save players data
        fwrite(&player1, sizeof(struct Player), 1, file);
        fwrite(&player2, sizeof(struct Player), 1, file);
        // save game type
        putw(type, file);
        putw(i, file);
        putw(counter, file);
        putw(n, file);
        putw(m, file);

        for (int i1 = 0; i1 < n; i1++) {
            for (int j1 = 0; j1 < m; j1++) {
                putw(a[i1][j1], file);
            }
        }

        for (int i1 = 0; i1 < n; i1++) {
            for (int j1 = 0; j1 < m; j1++) {
                putw(clr[i1][j1], file);
            }
        }

        putw(end, file);

        fclose(file);
    }
}

void load() {
    FILE *infile;
    infile = fopen("save.dat", "r");

    fread(&player1, sizeof(struct Player), 1, infile);
    fread(&player2, sizeof(struct Player), 1, infile);
    int game_type = getw(infile);
    int i = getw(infile);
    int counter = getw(infile);
    int n = getw(infile);
    int m = getw(infile);
    char a[n][m];
    int clr[n][m];

    for (int i1 = 0; i1 < n; i1++) {
        for (int j1 = 0; j1 < m; j1++) {
            a[i1][j1] = getw(infile);
        }
    }
    for (int i1 = 0; i1 < n; i1++) {
        for (int j1 = 0; j1 < m; j1++) {
            clr[i1][j1] = getw(infile);
        }
    }

    clock_t begin = getw(infile) + clock();

    fclose(infile);

    if (game_type == 1) {
        system("cls");
        print_array(n, m, a, counter, clr);
        draw(n, m, a, clr, i, counter, begin);
    } else {
        system("cls");
        print_array(n, m, a, counter, clr);
        draw_Computer(n, m, a, clr, i, counter, begin);
    }

}

