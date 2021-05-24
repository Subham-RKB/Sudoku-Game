#include<stdio.h>
#include<graphics.h>
#define SIZE 9
int sudoku[9][9];
void print_grid_sudoku()
{
    int i,j,hor,ver,x1,y1;
    char cc;
    for(hor=0;hor<9;hor++)
            {
                for(ver=0;ver<9;ver++)
                {
                    cc = sudoku[hor][ver]+'0';
                    char chh[2] = {cc};
                    x1 = 60*(ver+2)+30;
                    y1 = 60*(hor+1)+40;
                    settextstyle(10,0,6);
                    outtextxy(x1+15,y1+5,chh);
                }
            }
}
//function to check if all cells are assigned or not
//if there is any unassigned cell
//then this function will change the values of
//row and col accordingly
int number_unassigned(int *row, int *col)
{
    int num_unassign = 0;
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            //cell is unassigned
            if(sudoku[i][j] == 0)
            {
                //changing the values of row and col
                *row = i;
                *col = j;
                //there is one or more unassigned cells
                num_unassign = 1;
                return num_unassign;
            }
        }
    }
    return num_unassign;
}
//function to check if we can put a
//value in a paticular cell or not
int is_safe(int n, int r, int c)
{
    int i,j;
    //checking in row
    for(i=0;i<SIZE;i++)
    {
        //there is a cell with same value
        if(sudoku[r][i] == n)
            return 0;
    }
    //checking column
    for(i=0;i<SIZE;i++)
    {
        //there is a cell with the value equal to i
        if(sudoku[i][c] == n)
            return 0;
    }
    //checking sub sudoku
    int row_start = (r/3)*3;
    int col_start = (c/3)*3;
    for(i=row_start;i<row_start+3;i++)
    {
        for(j=col_start;j<col_start+3;j++)
        {
            if(sudoku[i][j]==n)
                return 0;
        }
    }
    return 1;
}
//function to solve sudoku
//using backtracking
int solve_sudoku()
{
    int row;
    int col;
    //if all cells are assigned then the sudoku is already solved
    //pass by reference because number_unassigned will change the values of row and col
    if(number_unassigned(&row, &col) == 0)
        return 1;
    int n,i;
    //number between 1 to 9
    for(i=1;i<=SIZE;i++)
    {
        //if we can assign i to the cell or not
        //the cell is sudoku[row][col]
        if(is_safe(i, row, col))
        {
            sudoku[row][col] = i;
            //backtracking
            if(solve_sudoku())
                return 1;
            //if we can't proceed with this solution
            //reassign the cell
            sudoku[row][col]=0;
        }
    }
    return 0;
}

void sudokusolver()
{
    int hor,ver,x1,y1;
    if (solve_sudoku())
    {
        print_grid_sudoku();
    }
    else
    {
        for(hor=0;hor<9;hor++)
            {
                for(ver=0;ver<9;ver++)
                {
                    char zero_sen[2]={'0'};
                    sudoku[hor][ver]=0;
                    x1 = 60*(ver+2)+30;
                    y1 = 60*(hor+1)+40;
                    settextstyle(10,0,6);
                    outtextxy(x1+15,y1+5,zero_sen);
                }
            }
        printf("No solution\n");
    }
}

void sudokuvalueinput()
{
    int i,j;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            sudoku[i][j]=0;
        }
    }
}
void makeblue(int c,int d,int*x1,int*y1,int*x2,int*y2)
{
    *x1 = c;
    *y1 = d;
    *x2 = *x1 + 60;
    *y2 = *y1 + 60;
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    rectangle(*x1,*y1,*x2,*y2);
    floodfill(*x1+1,*y1+1,WHITE);
}

void makered(int x1,int y1,int x2,int y2)
{
    setfillstyle(SOLID_FILL,LIGHTRED);
    rectangle(x1,y1,x2,y2);
    floodfill(x1+1,y1+1,WHITE);
}
void inputnumber(int x1,int y1,char ch)
{
    int i,j,k;
    char ch1[2];
    ch1[0]=ch;
    ch1[1]='\0';
    settextstyle(10,0,6);
    outtextxy(x1+15,y1+5,ch1);
    j = (x1/60)-2;
    i = (y1/60)-1;
    k = ch - '0';
    sudoku[i][j] = k;
}
void reset_sudoku()
{
    int hor,ver,x1,y1;
    for(hor=0;hor<9;hor++)
            {
                for(ver=0;ver<9;ver++)
                {
                    char zero_sen[2]={'0'};
                    sudoku[hor][ver]=0;
                    x1 = 60*(ver+2)+30;
                    y1 = 60*(hor+1)+40;
                    settextstyle(10,0,6);
                    outtextxy(x1+15,y1+5,zero_sen);
                }
            }
}

void graphicsportion()
{
    int gd = DETECT,gm;
    //initgraph(&gd,&gm,NULL);
    initwindow(1000,750);
    setbkcolor(7);
    int x1,y1,x2,y2,a,b,c,d;
    int i,j;
    x1 = 150;
    y1 = 100;
    a = x1;
    b = y1;
    c = x1;
    d = y1;
    for(i=1;i<10;i++)
    {
        x1 = a;
        for(j=1;j<10;j++)
        {
            x2 = x1 + 60;
            y2 = y1 + 60;
            setfillstyle(SOLID_FILL,LIGHTGRAY);
            rectangle(x1,y1,x2,y2);
            floodfill(x1+1,y1+1,WHITE);
            x1+=60;
        }
        y1+=60;

    }
    setfillstyle(SOLID_FILL,LIGHTRED);
    rectangle(a,b,a+60,b+60);
    floodfill(a+1,b+1,WHITE);
    char ch;
    do
    {
        ch = getch();
        if(ch=='d'||ch=='a'||ch=='w'||ch=='s')
        {
            if(ch=='d')
            {
                if(c!=630)
                {
                    makeblue(c,d,&x1,&y1,&x2,&y2);
                    x1+=60;
                    x2+=60;
                    makered(x1,y1,x2,y2);
                    c+=60;
                }
                else if(d!=580)
                {
                    makeblue(c,d,&x1,&y1,&x2,&y2);
                    x1 = a;
                    y1 = d + 60;
                    x2 = x1 + 60;
                    y2 = y1 + 60;
                    makered(x1,y1,x2,y2);
                    c = a;
                    d+=60;
                }
            }
             if(ch=='a')
            {
                if(c!=a)
                {
                    makeblue(c,d,&x1,&y1,&x2,&y2);
                    x1-=60;
                    x2-=60;
                    makered(x1,y1,x2,y2);
                    c-=60;
                }
                else if(d!=b)
                {
                    makeblue(c,d,&x1,&y1,&x2,&y2);
                    x1 = 630;
                    y1 = d - 60;
                    x2 = x1 + 60;
                    y2 = y1 + 60;
                    makered(x1,y1,x2,y2);
                    c = 630;
                    d-=60;
                }
            }
            if(ch=='s')
            {
                if(d!=580)
                {
                    makeblue(c,d,&x1,&y1,&x2,&y2);
                    y1+=60;
                    y2+=60;
                    makered(x1,y1,x2,y2);
                    d+=60;
                }
                else if(c!=630)
                {
                    makeblue(c,d,&x1,&y1,&x2,&y2);
                    x1 = c+60;
                    y1 = b;
                    x2 = x1 + 60;
                    y2 = y1 + 60;
                    makered(x1,y1,x2,y2);
                    c+=60;
                    d = b;
                }
            }
            if(ch=='w')
            {
                if(d!=b)
                {
                    makeblue(c,d,&x1,&y1,&x2,&y2);
                    y1-=60;
                    y2-=60;
                    makered(x1,y1,x2,y2);
                    d-=60;
                }
                else if(c!=a)
                {
                    makeblue(c,d,&x1,&y1,&x2,&y2);
                    x1 = c-60;
                    y1 = 580;
                    x2 = x1 + 60;
                    y2 = y1 + 60;
                    makered(x1,y1,x2,y2);
                    c-=60;
                    d = 580;
                }
            }
        }
        else if(int(ch)>=48 && int(ch)<=57)
        {
            inputnumber(c,d,ch);
        }
        else if(ch=='k')
        {
            sudokusolver();
        }
        else if(ch=='r')
        {
            reset_sudoku();
        }
    }while(ch!=' ');

    getch();
    closegraph();
}

int main()
{
    int sudoku[9][9];
    sudokuvalueinput();
    graphicsportion();

}
