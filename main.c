#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bombassign(int[][2]);///ASSIGN THE BOMB COORDINATES
void exitassign(int[][2]);///ASSIGN THE EXIT COORDINATES EXCEPT THE CORNERS OF MAZE
int randomgen();///GENERATE A RANDOM NUMBER
void bombkill();///DISPLAY THE BOMB IMAGE
int bombhit(int[][2],int*,int*,int,char*);///CHECK WHETHER THE PLAYER HIT THE BOMB OR NOT
void displayExit(int[][2],int*,int*);///CHECK IF THE PLAYER ENTER THE EXIT OR NOT
void bombshow(int*,int*,int[][2],char*,char[][12]);///SHOW THE BOMB ON THE GRID MINUS ONE
void exitshow(int*,int*,int[][2],char*,char[][12]);///DISPLAY THE EXIT ON THD GRID
int tokensExpense(int,int);
void check(int,char*);

int main(){
        printf("%s","++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    printf("%s","\n /@@@@@@@@@     /@@@        /@@@  /@@@@      /@@@  /@@@@@@@        /@@@      @@@      @@@      /@@@@@@@@@@@@  /@@@@@@@@");
    printf("%s","\n/ @@@@@@@@@@   / @@@       / @@@ / @@@@@    / @@@ / @@@@@@@@@     / @@@@    @@@@     @@@@@    | @@@@@@@@@@@@ / @@@@@@@@");
    printf("%s","\n| @@        @@ | @@@       | @@@ | @@@ @@   | @@@ | @@@     @@    | @@@@@  @@@@@    @@@@@@@   |/________ @@@ | @@@");
    printf("%s","\n| @@       @@  | @@@       | @@@ | @@@\\ @@  | @@@ | @@@      @@   | @@@ @@@@ @@@  /@@@@@@@@@          @@@    | @@@");
    printf("%s","\n| @@@@@@@@@    | @@@       | @@@ | @@@ \\ @@ | @@@ | @@@       @   | @@@  @@  @@@ / @@@   @@@        @@@      | @@@@@@@@");
    printf("%s","\n| @@       @@  | @@@       | @@@ | @@@  \\ @@| @@@ | @@@      @@   | @@@    | @@@ | @@@   @@@      @@@        | @@@ ");
    printf("%s","\n| @@        @@ | @@@       | @@@ | @@@   \\ @@ @@@ | @@@     @@    | @@@    | @@@ | @@@@@@@@@    @@@          | @@@");
    printf("%s","\n| @@@@@@@@@@   | @@@@@@@@@ | @@@ | @@@    \\ @@@@@ | @@@@@@@@@     | @@@    | @@@ | @@@ | @@@  /@@@@@@@@@@@@  | @@@@@@@@");
    printf("%s","\n| @@@@@@@@@    | @@@@@@@@@ | @@@ | @@@     \\ @@@@ | @@@@@@@       | @@@    | @@@ | @@@ | @@@ |@@@@@@@@@@@@   | @@@@@@@@");
    printf("%s","\n|/________/    |/________/ |/__/ |/__/      \\/__/ |/______/       |/__/    |/__/ |/__/ |/__/ |___________/   |/_______/\n");
    printf("%s","\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf(" RULE OF THE GAME");
    printf("\n         1. Initial token : 5");
    printf("\n         2. To move : press W (UP), S (DOWN), A(LEFT) and D (RIGHT)");
    printf("\n         3. Special key :");
    printf("\n                 a. Press B, the bomb location will be revealed except for 1 and 1 token remaining");
    printf("\n                 b. Press E, the exit point will be revealed. 2 token will be took away");
    printf("\n                 c. Press N, to quit game");
    printf("\n         4. Avoid the bomb. Minus 1 token for each bomb crashed");
    printf("\n         5. You will win if you find 1 of the 4 hidden exits !");
    printf("\n GOOD LUCK \n");
    printf("%s","\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

    printf("\n\n");
    system("pause");
    char maze[12][12] = {};
    char dot = '.';
    char playerposition = 'X';
    char playermove;
    int row;
    int col;
    int bomb[20][2];
    int exit[4][2];
    int tokens = 5;
    char replay = 'y';
    int lastmove[100][2];
    int count ;
    int idx;
    int updown,leftright;
    srand(time(NULL));
    for(row=1; row<12; row++){
        if(row!=11){
            printf("\t%2d", row);
        }
        for(col=1; col<11; col++){
            if(row!=11){
                if(row==5 && col==5){
                    printf("       ");
                    maze[row][col] = playerposition;
                    printf("%c", maze[row][col]);
                }else{
                    printf("       ");
                    maze[row][col]= dot;
                    printf("%c", maze[row][col]);
                }
            }
            else{
                if(col==1){
                    printf("\t");
                }
                printf("\t ");
                maze[row][col]= col;
                printf("%d", maze[row][col]);
            }
        }
        printf("\n\n");
    }
    int x=5, y=5;
    lastmove[0][0] = x;
    lastmove[0][1] = y;
    leftright = 5;
    updown = 5;
    count = 1;
    exitassign(exit);
    bombassign(bomb);///ASSIGN THE BOMB COORDINATES
    for(; x<11 && y<11 && (replay == 'y'||replay == 'Y'); ){
        do{
            printf("\nCurrent location : ");
            for(idx=0;idx<count;idx++)
            {
              printf("(%d,%d) => ",lastmove[idx][0],lastmove[idx][1]);
            }
            printf("\nYour move : ");
            scanf(" %c", &playermove);
            if(updown>10){
                updown--;
            }else if(updown<1){
                updown++;
            }else if(leftright>10){
                leftright--;
            }else if(leftright<1){
                leftright++;
            }
            switch(playermove){
            case 'w' : case 'W' :
                updown--;
                break;
            case 'a' : case 'A' :
                leftright--;
                break;
            case 's' : case 'S' :
                updown++;
                break;
            case 'd' : case 'D' :
                leftright++;
                break;
            }
            if(playermove!='w' && playermove!='W' && playermove!='s' && playermove!='S' && playermove!='a' && playermove!=
            'A' &&
            playermove!='d' && playermove!='D' && playermove!='b' && playermove!='B' && playermove!='e' && playermove
            !='E' &&
            playermove!='n' && playermove!='N' || (updown>10 || updown<1 || leftright>10 || leftright<1)){
                printf("\n(Invalid move)");
            }

if(playermove == 'b' || playermove == 'B' && tokens < 2){
                printf("\nInsufficient tokens\n");
            }
            else if(playermove == 'e' || playermove == 'E' && tokens < 3){
                printf("\nInsufficient tokens\n");
            }
        }while(playermove!='w' && playermove!='W' && playermove!='s' && playermove!='S' && playermove!='a' && playermove
        !='A' &&
        playermove!='d' && playermove!='D' && playermove!='b' && playermove!='B' && playermove!='e' && playermove
        !='E' &&
        playermove!='n' && playermove!='N' || (updown>10 || updown<1 || leftright>10 || leftright<1) || playermove == 'B' && tokens < 2 || playermove == 'e' || playermove == 'E' && tokens < 3);
        switch(playermove){
            case 'w': case 'W':
                maze[--x][y]=playerposition;
                lastmove[count][0] = x;
                lastmove[count][1] = y;
                count++;
                break;
            case 's': case 'S':
                maze[++x][y]=playerposition;
                lastmove[count][0] = x;
                lastmove[count][1] = y;
                count++;
                break;
            case 'a': case 'A':
                maze[x][--y]=playerposition;
                lastmove[count][0] = x;
                lastmove[count][1] = y;
                count++;
                break;
            case 'd': case 'D':
                maze[x][++y]=playerposition;
                lastmove[count][0] = x;
                lastmove[count][1] = y;
                count++;
                break;
            case 'b': case 'B':
                bombshow(&row,&col,bomb,&dot,maze);
                ///***implement token decrease
                tokens = tokensExpense(1,tokens);
                break;
            case 'e': case 'E':
                exitshow(&row,&col,exit,&dot,maze);
                tokens = tokensExpense(2,tokens);
                break;
            case 'n': case 'N':
                replay = 'n';
                break;
        }
        system("cls");
        printf("\n\n");
        tokens = bombhit(bomb,&x,&y,tokens,&replay);///CHECK WHETER THE PLAYER HIT THE BOMB OR NOT
        for(int row=1; row<12 && (replay == 'y'||replay == 'Y'); row++){
            if(row!=11){
                printf("\t%2d", row);
            }
            for(int col=1; col<11; col++){
                if(row!=11){
                    if(row==x && col==y){
                        printf("       ");
                        maze[x][y] = playerposition;
                        printf("%c", playerposition);
                    }else{
                        printf("       ");
                        maze[row][col]= dot;
                        printf("%c", maze[row][col]);
                    }
                }
                else{
                    if(col==1){
                        printf("\t");
                    }
                    printf("\t ");
                    maze[row][col]= col;
                    printf("%d", maze[row][col]);
                }
            }
            printf("\n\n");
        }

    }
    return 0;
}
void bombassign(int bomb[][2]){///ASSIGN THE BOMB COORDINATES
    int x,y,row;
    for(row=0;row<20;row++){
        x = randomgen();///GENERATE A RANDOM NUMBER
        y = randomgen();
        bomb[row][0] = x;
        bomb[row][1] = y;
        if(bomb[row][0]==5&&bomb[row][1]==5){
            --row;
        }
        for(int row1 = row-1;row1>=0&&row>2;row1--){
            if(bomb[row][0]==bomb[row1][0]&&bomb[row][1]==bomb[row1][1]){
                --row;
                row1 = 0;
            }
        }
    }
}
void exitassign(int exit[][2]){
    int rand,row;
    for(row=0;row<4;row++){
        rand = randomgen();
        if(row==0){
            exit[row][0]=1;
            exit[row][1]=rand;
        }else if(row==1){
            exit[row][0]=rand;
            exit[row][1]=1;
        } else if(row==2){
            exit[row][0]=10;
            exit[row][1]=rand;
        } else if(row==3){
            exit[row][0]=rand;
            exit[row][1]=10;
        }
    }
}
int randomgen(){///GENERATE A RANDOM NUMBER
    return rand()% 7 + 2;
}
int tokensExpense(int expense,int token){
    token -= expense;
    return token;
}
void check(int token,char *replay){
    if(token < 1){
        system("cls");
        printf("Game Over!\n");
        *replay = 'n';
        system("pause");
    }
}
int bombhit(int bomb[][2],int *x, int *y,int tokens, char *replay){///CHECK WHETER THE PLAYER HIT THE BOMB OR NOT
    int i;
    char r = *replay;
    for(i=0;i<20;i++){
        if(bomb[i][0]==*x&&bomb[i][1]==*y){
            system("cls");
            bombkill();
            ///implement token decrease
            tokens = tokensExpense(1,tokens);
            check(tokens,&r);
        }
    }
    *replay = r;
    return tokens;
}
void bombkill(){///DISPLAY THE BOMB IMAGE
    char a;
    printf("                                                 ,**.            \n");
    printf("                                            ,            ,       \n");
    printf("                                 .      *(   @@&. .#@@/         \n");
    printf("                              (  *@@@@%.   @@  #@@@@/. &@        \n");
    printf("                          (,     %@&/..*&@@@@,&@      @@, (@   # \n");
    printf("                    ,       .(&@@@@#/...     @@@@       @@  @,  (\n");
    printf("                 #    %@@@@@@&&&&&&@@@@@@@.  ...@@@      #@(#@   \n");
    printf("                   @@@@&&&&&&&&&&&&&&&&&&&@@@(..//@@,  #   .    #\n");
    printf("                (@@@&&&&&&&&&&&&&&&&&&&&&&&&&@@@//@@.  , *   (.  \n");
    printf("           (  .@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@&   #          \n");
    printf("          (  @@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@   /          \n");
    printf("         (  @@@&&  &&&&&&&&&&&&&&&&&####&&&&&&&&&&@@   .         \n");
    printf("           %@@&/   &&&&*   &&&&&&&&#######&&&&&&&&&@@            \n");
    printf("        /  @@&&    &&&(    &&&&&&&&########&&&&&&&&@@,  /        \n");
    printf("           @@&&   &&&&    &&&&&&&&&&#####&&&&&&&&&&@@@     (.    \n");
    printf("          .@@&&  #&&&&   #&&&&&&&&&&&&&&&&&&&&&&&&&&@@ .*,     . \n");
    printf("        .  @@&&&&&&&&&( %&&&&&&&&&&&&&&&&&&&&&&&&&&@@&//%%//@   #\n");
    printf("        /  @@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@#*@  @**@   \n");
    printf("            @@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@&//////#@   (\n");
    printf("  .          @@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@&/*//@,     , \n");
    printf("    %@@&#&@@. @@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@#%@ ,@/@       \n");
    printf("*  @@(@@////@@ .@@@&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@(#@@/(@       \n");
    printf("    @#((@////@@@//#@@&&&&&&&&&&&&&&@@@@&&&&@@@#    /@@@@&   *    \n");
    printf("     @@(((///@@/(%@#.@@@@@&&&&&&&&&@///@@@@#    ( .       (      \n");
    printf("   /   @@((////@@        (@@@@@@@@@@@///@     #                  \n");
    printf("     #   @@(////@   .  (            @@(/(@(@&   ,                \n");
    printf("       #   &@@@@#               ,  *@&@@@@//(@                   \n");
    printf("         ,        #          #    (@@@&/////(@                   \n");
    printf("                           .   @@//****/////@&  ,                \n");
    printf("                              @/**////////((@   ,                \n");
    printf("                           #  #@&(((((%@@@%    .                 \n");
    printf("                            .               *.                   \n");
    printf("                                ,(***(*\n");
    printf("\t You Hit a Bomb.Minus 1 Token\n\n");
    system("pause");
    system("cls");
}
void bombshow(int *row,int *col,int bomb[][2],char *dot,char maze[][12]){///SHOW THE BOMB ON THE GRID MINUS ONE
    system("cls");
    for((*row)=1;*row<12; (*row)++){
        if(*row !=11){
            printf("\t%2d", *row);
        }
        for((*col)=1; *col<11; (*col)++){

            if(*row!=11){
                for(int i=0;i<19;i++){
                    if(*row==bomb[i][0] && *col==bomb[i][1]){
                        maze[*row][*col] = 'B';
                        i=20;
                    }else{
                        maze[*row][*col]= *dot;
                    }
                }
                printf("       ");
                printf("%c", maze[*row][*col]);
            }
            else{
                if(*col==1){
                    printf("\t");
                }
                printf("\t ");
                maze[*row][*col]= *col;
                printf("%d", maze[*row][*col]);
            }
        }
        printf("\n\n");
    }
    printf("Bomb Coordinates : \n");
    for(int i=0;i<19;){
        for(int counter = 1;counter<4&&i<19;counter++,i++){
            printf("Bomb %2d : {%2d,%2d}\t",i+1,bomb[i][0],bomb[i][1]);
        }
        printf("\n");
    }
    system("pause");
    system("cls");
}

void exitshow(int* row, int* col, int exit[][2], char *dot, char maze[][12]){
    system("cls");
    for((*row)=1;*row<12; (*row)++){
        if(*row !=11){
            printf("\t%2d", *row);
        }
        for((*col)=1; *col<11; (*col)++){

            if(*row!=11){
                for(int i=0;i<4;i++){
                    if(*row==exit[i][0] && *col==exit[i][1]){
                        maze[*row][*col] = 'E';
                        i=4;
                    }else{
                        maze[*row][*col]= *dot;
                    }
                }
                printf("       ");
                printf("%c", maze[*row][*col]);
            }
            else{
                if(*col==1){
                    printf("\t");
                }
                printf("\t ");
                maze[*row][*col]= *col;
                printf("%d", maze[*row][*col]);
            }
        }
        printf("\n\n");
    }
    printf("Exit Coordinates : \n");
    for(int i=0;i<4;){
        for(int counter = 1;counter<4&&i<4;counter++,i++){
            printf("Exit %2d : {%2d,%2d}\t",i+1,exit[i][0],exit[i][1]);
        }
        printf("\n");
    }
    system("pause");
    system("cls");
}
