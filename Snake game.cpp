#include<bits/stdc++.h>
#include<conio.h>

using namespace std;
bool gameplay=true;
int width=25,height=25;
int x,y,fruit_x,fruit_y;
char ch,prev_ch; // ch is command and prev_ch is previous command(and we can use it if we get a wrong command)
int pos_x[1000],pos_y[1000],n=0;
long long score;
void setup(){
	x=width/2;
	y=height/2;
	while(fruit_x<=0||fruit_y<=0||fruit_x>=width-1||fruit_y>=height-1){
	fruit_x=rand() % width ;
	fruit_y=rand() % height;
	}
	ch='d';
	prev_ch='d';
}

void draw(){
	system("cls");
	bool space=true;
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			
			if(i==0||i==height-1||j==0||j==width-1)
				cout<<"#";
			else if(x==j&&y==i)
				cout<<"O";
			else if(fruit_x==j&&fruit_y==i)
				cout<<"F";
			else{
				for(int k=0;k<n;k++){
					if(pos_x[k]==j&&pos_y[k]==i){
						cout<<"o";
						space=false;
						break;
					}
				}
				if(space)
				cout<<" ";
				
				space=true;
			}
				
		}
		cout<<"\n";
	}
	cout<<"SCORE : "<<score;
	
}
void input(){
	if(kbhit()){
		ch=getch();
		// if get something other than w,s,a,d then we take previous command
		if(ch!='w'&&ch!='s'&&ch!='a'&&ch!='d')
			ch=prev_ch;
		// next four cases are written because so that snake don't go in backward direction. And can only go in left and right direction
		else if(prev_ch=='w'&&ch=='s')
			ch=prev_ch;
		else if(prev_ch=='s'&&ch=='w')
			ch=prev_ch;
		else if(prev_ch=='a'&&ch=='d')
			ch=prev_ch;
		else if(prev_ch=='d'&&ch=='a')
			ch=prev_ch;	
		// next case is if command is acceptable then we store it in previous command
		else
			prev_ch=ch;
		
	}
	
}

void logic(){
	
	if(x==0||x==width-1||y==0||y==height-1)
		gameplay=false;
	
	else if(x==fruit_x&&y==fruit_y){
		score+=10;
		n++;
		fruit_x=rand() % width ;
		fruit_y=rand() % height;
		while(fruit_x<=0||fruit_y<=0||fruit_x>=width-1||fruit_y>=height-1){
			fruit_x=rand() % width ;
			fruit_y=rand() % height;
		}		
	}
	
	for(int i=0;i<n;i++){
		if(x==pos_x[i]&&y==pos_y[i])
			gameplay=false;
	}
	
	for(int i=n-1;i>0;i--){
		pos_x[i]=pos_x[i-1];
		pos_y[i]=pos_y[i-1];
	}
	
	pos_x[0]=x;
	pos_y[0]=y;
	
	switch(ch){
		case 'w':
			y--;
			break;
		case 's':
			y++;
			break;
		case 'a':
			x--;
			break;
		case 'd':
			x++;
			break;
		default:
			break;
	}	
}

int main(){
	setup();
	while(gameplay){
		draw();
		input();
		logic();
	}
	return 0;
}
