#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int row(int i,int j,int a[9][9]){
	int c=0;
	for(int k=0;k<9;k++){
		if(a[i][j]==a[i][k]){
			c=c+1;
		}
	}
	return c;
} 
int col(int i,int j,int a[9][9]){
	int d=0;
	for(int k=0;k<9;k++){
		if(a[k][j]==a[i][j]){
			d=d+1;
		}
	}
	return d;
} 
int box(int i,int j,int a[9][9]){
	int e=0;
	if(i<=3 && j<=3){
		for(int k=0;k<3;k++){
			for(int l=0;l<3;l++){
				if(a[i][j]==a[k][l]){
					e=e+1;
				}
			}
		}
		
	}
	else if(i<=3 && (j>3 && j<=6)){
		for(int k=0;k<3;k++){
			for(int l=3;l<6;l++){
				if(a[i][j]==a[k][l]){
					e=e+1;
				}
			}
		}
		
	}
	else if(i<=3 && (j>6 && j<=9)){
		for(int k=0;k<3;k++){
			for(int l=6;l<9;l++){
				if(a[i][j]==a[k][l]){
					e=e+1;
				}
			}
		}
		
	}
	else if((i>3&&i<=6) && j<=3){
		for(int k=3;k<6;k++){
			for(int l=0;l<3;l++){
				if(a[i][j]==a[k][l]){
					e=e+1;
				}
			}
		}
		
	}
	else if((i>3 && i<=6) && (j>3 && j<=6)){
		for(int k=3;k<6;k++){
			for(int l=3;l<6;l++){
				if(a[i][j]==a[k][l]){
					e=e+1;
				}
			}
		}
		
	}
	else if((i>6 && i<=9) && (j>6 && j<=9)){
		for(int k=6;k<9;k++){
			for(int l=6;l<9;l++){
				if(a[i][j]==a[k][l]){
					e=e+1;
				}
			}
		}
		
	}
		else if((i>6&&i<=9) && j<=3){
		for(int k=6;k<9;k++){
			for(int l=0;l<3;l++){
				if(a[i][j]==a[k][l]){
					e=e+1;
				}
			}
		}
		
	}
	else if((i>6 && i<=9) && (j>3 && j<=6)){
		for(int k=6;k<9;k++){
			for(int l=3;l<6;l++){
				if(a[i][j]==a[k][l]){
					e=e+1;
				}
			}
		}
		
	}
	else if((i>6 && i<=9) && (j>6 && j<=9)){
		for(int k=6;k<9;k++){
			for(int l=6;l<9;l++){
				if(a[i][j]==a[k][l]){
					e=e+1;
				}
			}
		}
		
	}
	return e;
	
}	
void generator(int gen[9][9]){
    int h,p,m;
    srand(time(0));
	int aa=(rand()%(25-10+1))+10;
	int a[9][9]={{0,0,0,0,0,0,0,0,0},
				 {0,0,0,0,0,0,0,0,0},
				 {0,0,0,0,0,0,0,0,0},
				 {0,0,0,0,0,0,0,0,0},
				 {0,0,0,0,0,0,0,0,0},
				 {0,0,0,0,0,0,0,0,0},
				 {0,0,0,0,0,0,0,0,0},
				 {0,0,0,0,0,0,0,0,0},
				 {0,0,0,0,0,0,0,0,0}};
	for(int i=0;i<aa;i++){
		int t=rand()%10;
		int g=rand()%10;
		a[t][g]=(rand()%(9-1+1))+1;
		h=row(t,g,a);
		p=col(t,g,a);
		m=box(t,g,a);
		if(h>1||p>1||m>1){
			a[t][g]=0;
		}
		}
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				gen[i][j]=a[i][j];
			}
		}
}
