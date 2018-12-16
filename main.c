#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bombassign(int[][2]);///ASSIGN THE BOMB COORDINATES
int randomgen();///GENERATE A RANDOM NUMBER
void bombkill();///DISPLAY THE BOMB IMAGE
void bombhit(int[][2],int*,int*);///CHECK WHETER THE PLAYER HIT THE BOMB OR NOT
void bombshow(int*,int*,int[][2],char*,char[][12]);///SHOW THE BOMB ON THE GRID MINUS ONE
void exitshow();
int token(int);

///MAIN FUNCTION
int main(){
        ///REZA
        ///MAZE GRID
    printf("\n\n");
    char maze[12][12] = {};
    char dot = '.';
    char playerposition = 'X';
    char playermove;
    int row;
    int col;
    int bomb[20][2];
    char replay = 'y';
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
    bombassign(bomb);///ASSIGN THE BOMB COORDINATES
    for(; x<11 && y<11 && (replay == 'y'||replay == 'Y'); ){
        do{
            printf("Your move : ");
            scanf(" %c", &playermove);
            if(playermove!='w' && playermove!='W' && playermove!='s' && playermove!='S' && playermove!='a' && playermove!=
            'A' &&
            playermove!='d' && playermove!='D' && playermove!='b' && playermove!='B' && playermove!='e' && playermove
            !='E' &&
            playermove!='n' && playermove!='N'){
                printf("\n(Invalid move)");
            }
        }while(playermove!='w' && playermove!='W' && playermove!='s' && playermove!='S' && playermove!='a' && playermove
        !='A' &&
        playermove!='d' && playermove!='D' && playermove!='b' && playermove!='B' && playermove!='e' && playermove
        !='E' &&
        playermove!='n' && playermove!='N');
        switch(playermove){
            case 'w': case 'W':
                maze[--x][y]=playerposition;
                break;
            case 's': case 'S':
                maze[++x][y]=playerposition;
                break;
            case 'a': case 'A':
                maze[x][--y]=playerposition;
                break;
            case 'd': case 'D':
                maze[x][++y]=playerposition;
                break;
            case 'b': case 'B':
                bombshow(&row,&col,bomb,&dot,maze);
                token(1);
                ///SHOW THE BOMB ON THE GRID MINUS ONE
                break;
            case 'e': case 'E':
                ///exitshow();
                token(2);
                break;
            case 'n': case 'N':
                replay = 'n';
                break;
        }
        system("cls");
        printf("\n\n");
        bombhit(bomb,&x,&y);///CHECK WHETER THE PLAYER HIT THE BOMB OR NOT
        for(int row=1; row<12 && (replay == 'y'||replay == 'Y'); row++){
            if(row!=11){
                printf("\t%2d", row);
            }
            for(int col=1; col<11; col++){
                if(row!=11){
                    if((playermove=='w' || playermove=='W') && row==x && col==y){
                        printf("       ");
                        maze[x][y] = playerposition;
                        printf("%c", playerposition);
                    }else if((playermove=='s' || playermove=='s') && row==x && col==y){
                        printf("       ");
                        maze[x][y] = playerposition;
                        printf("%c", playerposition);
                    }else if((playermove=='a' || playermove=='A') && row==x && col==y){
                        printf("       ");
                        maze[x][y] = playerposition;
                        printf("%c", playerposition);
                    }else if((playermove=='d' || playermove=='D') && row==x && col==y){
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
int randomgen(){///GENERATE A RANDOM NUMBER
    return rand()% 7 + 2;
}
void bombhit(int bomb[][2],int *x, int *y){///CHECK WHETER THE PLAYER HIT THE BOMB OR NOT
    int i;
    for(i=0;i<20;i++){
        if(bomb[i][0]==*x&&bomb[i][1]==*y){
            system("cls");
            bombkill();
            ///implement token decrease
        }
    }
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

int token(int a){
    int tokens = 5;
    tokens = tokens - a;
    return tokens;
}
