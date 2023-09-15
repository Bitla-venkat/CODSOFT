#include<iostream>
#include<stdlib.h>

using namespace std;

char grid[3][3]={{'1','2','3',},{'4','5','6',},{'7','8','9',}};
int choice,row,column;
char turn='X';
bool draw=false;

bool gameover();

void display(){
    cout<<"PLAYER - 1[X]\t PLAYER - 2[O]\n\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<grid[0][0]<<"  |  "<<grid[0][1]<<"  |  "<<grid[0][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<grid[1][0]<<"  |  "<<grid[1][1]<<"  |  "<<grid[1][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<grid[2][0]<<"  |  "<<grid[2][1]<<"  |  "<<grid[2][2]<<" \n";
    cout<<"\t\t     |     |     \n";
}

void player_turn(){
    if(turn=='X'){
        cout<<"\n\t player - 1 [X] turn : ";
    }
    else if(turn=='O'){
        cout<<"\n\t player - 2 [O] turn : ";
    }
    cin>>choice;

    switch(choice){
        case 1:row=0;column=0;break;
        case 2:row=0;column=1;break;
        case 3:row=0;column=2;break;
        case 4:row=1;column=0;break;
        case 5:row=1;column=1;break;
        case 6:row=1;column=2;break;
        case 7:row=2;column=0;break;
        case 8:row=2;column=1;break;
        case 9:row=2;column=2;break;
        default:
            cout<<"Invalid Move";
    }

    if(turn=='X'&& grid[row][column]!='X'&& grid[row][column]!='O'){
        grid[row][column]='X';
        turn='O';
    }
    else if(turn=='O'&& grid[row][column]!='O'&& grid[row][column]!='X'){
        grid[row][column]='O';
        turn='X';
    }
    else {
        cout<<"Box already filled!\n Please choose another!!\n\n";
    }
    display();
    if(gameover()){
    player_turn();
    }
}

bool gameover(){
    //checking for win row and column
    for(int i=0;i<3;i++){
        if((grid[i][0]== grid[i][1]&& grid[i][0]==grid[i][2])||(grid[0][i]==grid[1][i]&&grid[0][i]==grid[2][i])){
            return false;
           }
    }
    //check for diagnol
    if((grid[0][0]==grid[1][1]&&grid[0][0]==grid[2][2])||(grid[0][2]==grid[1][1]&&grid[0][2]==grid[2][0])){
        return false;
    }
    //checking if u can continue
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[i][j]!='X'&&grid[i][j]!='O'){
                return true;
            }
        }
    }
    //if nothing works game is draw
    draw=true;
    return false;
}


int main()
{
    cout<<"\t\t\tT I C K -- T A C -- T O E -- G A M E\t\t\t";
    cout<<"\n\t\t\t\tFOR 2 PLAYERS\n\t\t\t";
    while(gameover()){
        display();
        player_turn();
        //gameover();
    }
    if(turn == 'X' && draw == false){
        cout<<"\n\n\t\tCongratulations!Player with 'O' has won the game";
    }
    else if(turn == 'O' && draw == false){
        cout<<"\n\n\t\tCongratulations!Player with 'X' has won the game";
    }
    else{
    cout<<"\n\n\t\tGAME DRAW!!!\n\n";
    }
    return 0;
}
