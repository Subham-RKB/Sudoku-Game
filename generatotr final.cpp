#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 9
int sudoku[9][9];
int arr[9][9];
int passed[9][9];
int FLAG;
void maketable();
void avalueinput();
int row(int i, int j,int arr[9][9]);
int col(int i, int j,int arr[9][9]);
int box(int i, int j,int arr[9][9]);
void makelightred(int x1,int y1,int x2,int y2);
void print_gen_sudoku();
int generator();
void print_grid_sudoku();
int is_safe(int n, int r, int c);
int number_unassigned(int *row, int *col);
int solve_sudoku();
void sudokusolver();
void sudokuvalueinput();
void makeblue(int c,int d,int*x1,int*y1,int*x2,int*y2);
void makered(int x1,int y1,int x2,int y2);
void inputnumber(int x1,int y1,char ch);
void reset_sudoku();
void graphics_portion();
void secondpage();
void passedvalueinput()
{
    int i,j;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            passed[i][j] = 0;
        }
    }
}
void assign_gen_to_passed()
{
    int i,j;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            passed[i][j] = arr[i][j];
        }
    }
}
void assign_sudoku_to_passed()
{
    int i,j;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            passed[i][j] = sudoku[i][j];
        }
    }
}
void maketable()
{
    int i,j;
    int x1,y1,x2,y2;
    y1 = 100;
    for(i=1;i<10;i++)
    {
        x1 =150;
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
        setbkcolor(0);
        settextstyle(10,0,4);
        outtextxy(150,641,"                           ");
        outtextxy(750,300,"PRESS");
        outtextxy(730,340,"k->SOLVE");
        outtextxy(730,380,"b->back");
        setbkcolor(7);
}
void avalueinput()
{
    int i,j;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            arr[i][j]=0;
        }
    }
}
int row(int i,int j,int arr[9][9]){//generator starts here
	int c=0,k;
	for(k=0;k<9;k++){
		if(arr[i][j]==arr[i][k]){
			c=c+1;
		}
	}
	return c;
}
int col(int i,int j,int arr[9][9]){
	int d=0,k;
	for(k=0;k<9;k++){
		if(arr[i][j]==arr[k][j]){
			d=d+1;
		}
	}
	return d;
}
int box(int i,int j,int arr[9][9]){
	int e=0,row_start,col_start,k,l;
	row_start = (i/3)*3;
	col_start = (j/3)*3;
	for(k=row_start;k<row_start+3;k++){
			for(l=col_start;l<col_start+3;l++){
				if(arr[i][j]==arr[k][l]){
					e=e+1;
				}
			}
		}
	return e;
}
void makelightred(int x1,int y1,int x2,int y2)
{
    setfillstyle(SOLID_FILL,LIGHTRED);
    rectangle(x1,y1,x2,y2);
    floodfill(x1+1,y1+1,WHITE);
}
void print_gen_sudoku()
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
                    if(sudoku[hor][ver]!=0)
                    {
                        //setbkcolor(12);
                        settextstyle(10,0,6);
                        outtextxy(x1+15,y1+5,chh);
                        makelightred(x1,y1,x1+60,y1+60);
                    }
                    else
                    {
                        //setbkcolor(7);
                        settextstyle(10,0,6);
                        outtextxy(x1+15,y1+5," ");
                    }
                }
            }
}
int generator(){
    int h,p,m;
    srand(time(0));
	int aa=(rand()%(55-15+1))+65;
	avalueinput();
	for(int i=0;i<aa;i++){
		int t=rand()%10;
		int g=rand()%10;
		arr[t][g]=(rand()%(9-1+1))+1;
		h=row(t,g,arr);
		p=col(t,g,arr);
		m=box(t,g,arr);
		if(h>1||p>1||m>1){
			arr[t][g]=0;
		}
		else
        {
            passed[t][g]=arr[t][g];
            if(solve_sudoku()==0)
            {
                arr[t][g]=0;
                passed[t][g]=0;
            }
        }
		}
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				sudoku[i][j] = arr[i][j];
			}
		}
		print_gen_sudoku();
		return 0;
}
/*int generator(){
    int h,p,m;
    srand(time(0));
	int aa=(rand()%(55-15+1))+65;
	avalueinput();
	for(int i=0;i<aa;i++){
		int t=rand()%10;
		int g=rand()%10;
		arr[t][g]=(rand()%(9-1+1))+1;
		h=row(t,g,arr);
		p=col(t,g,arr);
		m=box(t,g,arr);
            if(h>1||p>1||m>1){
                arr[t][g]=0;
                passed[t][g] = arr[t][g];
            }
		if(h>1 || p>1 ||m>1)
        {
            arr[t][g]=0;
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    sudoku[i][j] = arr[i][j];
                }
            }
            print_gen_sudoku();
            return 0;
        }
	}
}
*/
//generator ends here
void print_grid_sudoku()
{
    int i,j,hor,ver,x1,y1;
    char cc;
    for(hor=0;hor<9;hor++)
            {
                for(ver=0;ver<9;ver++)
                {
                    if(arr[hor][ver]==0)
                    {
                        cc = passed[hor][ver]+'0';
                        char chh[2] = {cc};
                        x1 = 60*(ver+2)+30;
                        y1 = 60*(hor+1)+40;
                        settextstyle(10,0,6);
                        outtextxy(x1+15,y1+5,chh);
                    }
                }
            }
}
//function to check if we can put a
//value in a paticular cell or not
int is_safe(int n, int r, int c)
{
    int i,j;
    //checking in row
    if(n!=0)
    {
    for(i=0;i<SIZE;i++)
    {
        //there is a cell with same value
        if(passed[r][i] == n && c!=i)
            return 0;
    }
    //checking column
    for(i=0;i<SIZE;i++)
    {
        //there is a cell with the value equal to i
        if(passed[i][c] == n && r!=i)
            return 0;
    }
    //checking sub sudoku
    int row_start = (r/3)*3;
    int col_start = (c/3)*3;
    for(i=row_start;i<row_start+3;i++)
    {
        for(j=col_start;j<col_start+3;j++)
        {
            if(passed[i][j]==n && r!=i && c!=j)
                return 0;
        }
    }
    return 1;
    }
    else
    {
        return 1;
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
            if(passed[i][j] == 0)
            {
                //changing the values of row and col
                *row = i;
                *col = j;
                //there is one or more unassigned cells
                num_unassign = 1;
                return num_unassign;
            }
            /*else
            {
                check_valid(i,j,sudoku[i][j]);
            }*/
        }
    }
    return num_unassign;
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
            passed[row][col] = i;
            //backtracking
            if(solve_sudoku())
                return 1;
            //if we can't proceed with this solution
            //reassign the cell
            passed[row][col]=0;
        }
    }
    return 0;
}
void sudokusolver()
{
    int FLAG = 0,i,j;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(is_safe(passed[i][j],i,j)==0)
            {
                FLAG = 1;
            }
        }
    }
    if(FLAG==0)
    {
    if (solve_sudoku())
    {
        print_grid_sudoku();
    }
    else
    {
        //maketable();
        setbkcolor(0);
        settextstyle(10,0,4);
        outtextxy(150,641,"NO SOLUTION                 ");
        setbkcolor(7);
    }
    }
    else
    {
        setbkcolor(0);
        settextstyle(10,0,4);
        outtextxy(150,641,"INVALID SUDOKU              ");
        setbkcolor(7);
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
        setfillstyle(SOLID_FILL,LIGHTGREEN);
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
    passed[i][j]=k;
    if(k!=0)
    {
    if(is_safe(k,i,j)==0)
    {
        setbkcolor(0);
        settextstyle(10,0,4);
        outtextxy(150,641,"THIS NUMBER IS REPEATED.");
        setbkcolor(7);
    }
    else
    {
        setbkcolor(0);
        settextstyle(10,0,4);
        outtextxy(150,641,"                                          ");
        setbkcolor(7);
    }
    }
    else
    {
        setbkcolor(0);
        settextstyle(10,0,4);
        outtextxy(150,641,"                                          ");
        setbkcolor(7);
    }
}
void reset_sudoku()
{
    int hor,ver,x1,y1;
    avalueinput();
    for(hor=0;hor<9;hor++)
            {
                for(ver=0;ver<9;ver++)
                {
                    //char zero_sen[2]={'0'};
                    sudoku[hor][ver]=0;
                    x1 = 60*(ver+2)+30;
                    y1 = 60*(hor+1)+40;
                    settextstyle(10,0,6);
                    outtextxy(x1+15,y1+5," ");
                }
            }
}
void graphicsportion(int sud)
{
    setbkcolor(7);
    int x1,y1,x2,y2,a,b,c,d,e,f;
    int i,j;
    x1 = 150;
    y1 = 100;
    a = x1;
    b = y1;
    c = x1;
    d = y1;
    maketable();
    if(sud == 200)
    {
        setbkcolor(0);
        outtextxy(730,420,"g->Generate");
        setbkcolor(7);
        generator();
        assign_gen_to_passed();
    }
    else
    {
        setbkcolor(0);
        outtextxy(730,420,"r->reset");
        setbkcolor(7);
    }
    setfillstyle(SOLID_FILL,LIGHTGREEN);
    rectangle(a,b,a+60,b+60);
    floodfill(a+1,b+1,WHITE);
    char ch;
    do
    {
        ch = getch();
        if(ch=='d'||ch=='a'||ch=='w'||ch=='s')
        {
            e = c;
            f = d;
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
            i = f/60-1;
            j = e/60-2;
            if(arr[i][j]!=0)
            {
                makelightred(e,f,e+60,f+60);
            }
        }
        else if(int(ch)>=48 && int(ch)<=57)
        {
            e = c;
            f = d;
            i = f/60-1;
            j = e/60-2;
            if(arr[i][j]==0)
            {
                inputnumber(c,d,ch);
            }
        }
        else if(ch=='k')
        {
            if(sud==200)
            {
                assign_gen_to_passed();
                sudokusolver();
            }
            else
            {
                assign_sudoku_to_passed();
                sudokusolver();
            }
        }
        else if(ch == 'g')
        {
            if(sud==200)
            {
                maketable();
                generator();
                assign_gen_to_passed();
            }
        }
        else if(ch=='r')
        {
            if(sud!=200)
            {
                maketable();
                reset_sudoku();
            }
        }
        else if(ch=='b')
        {
            setbkcolor(0);
        	cleardevice();
        	secondpage();
		}
    }while(ch!=' ');
    getch();
}
void startt(){
    settextstyle(10,0,7);
    outtextxy(275,20,"SudokuU");
    outtextxy(275,660,"Press F...");
    char chh;
    while(1){
	chh=getch();
	if(chh=='f'){
		//outtextxy(275,660,"                                                             ");
		cleardevice();
        secondpage();
	}
}
}
void secondpagewritten(int a,int b)
{
    settextstyle(10,0,7);
    outtextxy(375,20,"Sudoku");
    rectangle(375,a,650,b);
    settextstyle(10,0,4);
    outtextxy(400,235,"Sudoku Game");
    outtextxy(400,355,"SudokuSolver");
    outtextxy(405,475,"Instruction");
    outtextxy(450,605,"About");
}
void secondpage(){
	int a=200;
	int b=300;
    secondpagewritten(a,b);
    char ch;
    while(1){
    ch=getch();
    if(ch=='s'){
    	if(a!=575){
	    	a=a+125;
	    	b=b+125;
	    	cleardevice();
	    	secondpagewritten(a,b);
	}
    	else{
			a=200;
	    	b=300;
	    	cleardevice();
	    	secondpagewritten(a,b);
	}
	}
	else if(ch=='w'){
    	if(a!=200){
	    	a=a-125;
	    	b=b-125;
	    	cleardevice();
	    	secondpagewritten(a,b);
	}
    	else{
			a=575;
	    	b=675;
	    	cleardevice();
	    	secondpagewritten(a,b);
	}
	}
	else if(ch==13){
		if(a==200){
			cleardevice();
			settextstyle(10,0,7);
    		outtextxy(375,20,"SudokuU");
			graphicsportion(a);
		}
		if(a==325){
			cleardevice();
			cleardevice();
			settextstyle(10,0,7);
    		outtextxy(375,20,"SudokuU");
    		graphicsportion(a);
		}
		if(a==450){
			cleardevice();
    		settextstyle(10,0,7);
    		outtextxy(30,20,"INSTRUCTIONS::");
    		settextstyle(10,0,4);
    		outtextxy(30,95,"1) This Game is completely played using keyboard.");
    		outtextxy(30,130,"2) Use 'w','a','s' and 'd' as a Up,Left,Down and ");
    		outtextxy(85,165,"Right arrow respectively.");
    		char chh;
    		do
            {
                chh = getch();
                    if(chh=='b')
                    {
                        cleardevice();
                        secondpage();
                    }
			}while(chh!='b');
		}
		if(a==575){
			cleardevice();
    		settextstyle(10,0,7);
    		outtextxy(30,20,"ABOUT::");
    		settextstyle(10,0,4);
    		outtextxy(30,95,"This Game is made by very Talented Umesh Saud with");
    		outtextxy(30,130,"the help of very Untalented Subham Chapagain");
    		char chh;
    		do
            {
                chh = getch();
                    if(chh=='b')
                    {
                        cleardevice();
                        secondpage();
                    }
			}while(chh!='b');
        }
    }
}
}
int main()
{
    int sudoku[9][9];
    int gd = DETECT,gm;
    //initgraph(&gd,&gm,NULL);
    initwindow(1000,750);
    avalueinput();
    passedvalueinput();
    sudokuvalueinput();
    startt();
    closegraph();
}
